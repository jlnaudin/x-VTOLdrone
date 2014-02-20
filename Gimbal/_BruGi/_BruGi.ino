
/*
Brushless Gimbal Controller Software by Christian Winkler and Alois Hahn (C) 2013

Brushless Gimbal Controller Hardware and Software support 
by Ludwig Fäerber, Alexander Rehfeld and Martin Eckart

Special Contributions:
  Michael Schätzel

Project homepage: http://brushlessgimbal.de/
Discussions:
http://fpv-community.de/showthread.php?20795-Brushless-Gimbal-Controller-SOFTWARE
http://fpv-community.de/showthread.php?22617-Gimbal-Brushless-Controller-V3-0-50x50mm-by-Martinez
http://fpv-community.de/showthread.php?19252-Brushless-Gimbal-Controller

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version. see <http://www.gnu.org/licenses/>

Anyhow, if you start to commercialize our work, please read on http://code.google.com/p/brushless-gimbal/ on how to contribute

// I2Cdev library collection - MPU6050 I2C device class
// Based on InvenSense MPU-6050 register map document rev. 2.0, 5/19/2011 (RM-MPU-6000A-00)
// 10/3/2011 by Jeff Rowberg <jeff@rowberg.net>
// Updates should (hopefully) always be available at https://github.com/jrowberg/i2cdevlib
*/


// FOR CHANGES PLEASE READ: ReleaseHistory.txt

// Serial Programming for Settings!!!
/* HOWTO:
- edit setDefaultParameters() in variables.h if you want to.
- Upload Firmware.
- Open Arduino Terminal and enable NL in the lower right corner of the window.
- Type in HE 
-... enjoy
*/


#define VERSION_STATUS B // A = Alpha; B = Beta , N = Normal Release
#define VERSION 49
#define VERSION_EEPROM 2 // change this number when eeprom data strcuture has changed


/*************************/
/* Include Header Files  */
/*************************/
#include <EEPROM.h>
#include <Wire.h>
#include <avr/pgmspace.h>
#include "definitions.h"
#include "MPU6050.h"
#include "SerialCommand.h"
#include "EEPROMAnything.h"
#include "PinChangeInt.h"

#include "variables.h"
MPU6050 mpu;            // Create MPU object
SerialCommand sCmd;     // Create SerialCommand object

#include "fastMathRoutines.h"     // fast Math functions required by orientationRoutines.h
#include "orientationRoutines.h"  // get Orientation from ACC
#include "RCdecode.h"             // RC Decoder to move camera by servo signal input
#include "BLcontroller.h"         // Motor Movement Functions and Timer Config
#include "SerialCom.h"            // Serial Protocol for Configuration and Communication


void initMPUlpf() {
  // Set Gyro Low Pass Filter(0..6, 0=fastest, 6=slowest)
  switch (config.mpuLPF) {
    case 0:  mpu.setDLPFMode(MPU6050_DLPF_BW_256);  break;
    case 1:  mpu.setDLPFMode(MPU6050_DLPF_BW_188);  break;
    case 2:  mpu.setDLPFMode(MPU6050_DLPF_BW_98);   break;
    case 3:  mpu.setDLPFMode(MPU6050_DLPF_BW_42);   break;
    case 4:  mpu.setDLPFMode(MPU6050_DLPF_BW_20);   break;
    case 5:  mpu.setDLPFMode(MPU6050_DLPF_BW_10);   break;
    case 6:  mpu.setDLPFMode(MPU6050_DLPF_BW_5);    break;
    default: mpu.setDLPFMode(MPU6050_DLPF_BW_256);  break;
  }
}
  
/**********************************************/
/* Initialization                             */
/**********************************************/
void setup() 
{

  // just for debugging
#ifdef STACKHEAPCHECK_ENABLE
  stackCheck();
  heapCheck();
#endif

  LEDPIN_PINMODE
  
  CH2_PINMODE
  CH3_PINMODE
  
  // Start Serial Port
  Serial.begin(115200);

  // Set Serial Protocol Commands
  setSerialProtocol();
  
  // Read Config, fill with default settings if versions do not match or CRC fails
  readEEPROM();;
  if ((config.vers != VERSION) || (config.versEEPROM != VERSION_EEPROM))
  {
    Serial.print(F("EEPROM version mismatch, initialize EEPROM"));
    setDefaultParameters();
    writeEEPROM();
  }
    
  // Init Sinus Arrays and Motor Stuff 
  recalcMotorStuff();
  
  // Init PIDs to reduce floating point operations.
  initPIDs();

  // init RC variables
  initRC();
  
  // Start I2C and Configure Frequency
  Wire.begin();
  TWSR = 0;                                  // no prescaler => prescaler = 1
  TWBR = ((16000000L / I2C_SPEED) - 16) / 2; // change the I2C clock rate
  TWCR = 1<<TWEN;                            // enable twi module, no interrupt
 
   // Init BL Controller
  initBlController();
  // Initialize MPU 
  initResolutionDevider();
  
  // Init IMU variables
  initIMU();
  
  // Auto detect MPU address
  mpu.setAddr(MPU6050_ADDRESS_AD0_HIGH);
  mpu.initialize();
  if(mpu.testConnection()) {
    Serial.println(F("MPU6050 ok (HIGH)"));  
  } else {
    mpu.setAddr(MPU6050_ADDRESS_AD0_LOW);
    mpu.initialize();
    if(mpu.testConnection()) {
      Serial.println(F("MPU6050 ok (LOW)"));  
    } else {
      Serial.println(F("MPU6050 falied"));  
    }
  }
 
  CH2_ON
  
  // set sensor orientation (from config)
  initSensorOrientation();
  
  // Init MPU Stuff
  mpu.setClockSource(MPU6050_CLOCK_PLL_ZGYRO);          // Set Clock to ZGyro
  mpu.setFullScaleGyroRange(MPU6050_GYRO_FS);           // Set Gyro Sensitivity to config.h
  mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_2);       //+- 2G
  initMPUlpf();                                         // Set Gyro Low Pass Filter
  mpu.setRate(0);                                       // 0=1kHz, 1=500Hz, 2=333Hz, 3=250Hz, 4=200Hz
  mpu.setSleepEnabled(false); 
  
  // Gyro Offset calibration
  Serial.println(F("Gyro calibration: do not move"));
  mpu.setDLPFMode(MPU6050_DLPF_BW_5);  // experimental AHa: set to slow mode during calibration
  gyroOffsetCalibration();
  initMPUlpf();
  Serial.println(F("Gyro calibration: done"));
  
  LEDPIN_ON
  
   // Init BL Controller
  initBlController();
  // motorTest();

  // Init RC-Input
  initRCPins();
  
  Serial.println(F("GO! Type HE for help, activate NL in Arduino Terminal!"));

  CH2_OFF
  CH3_OFF
 
}

/************************/
/* PID Controller       */
/************************/
int32_t ComputePID(int32_t DTms, int32_t in, int32_t setPoint, int32_t *errorSum, int32_t *errorOld, int32_t Kp, int16_t Ki, int32_t Kd)
{
  int32_t error = setPoint - in;
  int32_t Ierr;
   
  Ierr = error * Ki * DTms;
  Ierr = constrain_int32(Ierr, -(int32_t)1000*100, (int32_t)1000*100);
  *errorSum += Ierr;
 
  /*Compute PID Output*/
  int32_t out = (Kp * error) + *errorSum + Kd * (error - *errorOld) * DTms;
  *errorOld = error;

  return out / 4096;
}



/**********************************************/
/* Main Loop                                  */
/**********************************************/
void loop() 
{    
  int32_t pitchPIDVal;
  int32_t rollPIDVal;
  static int32_t pitchErrorSum;
  static int32_t rollErrorSum;
  static int32_t pitchErrorOld;
  static int32_t rollErrorOld;
  
  static char pOutCnt = 0;
  static int stateCount = 0;
  
  if (motorUpdate) // loop runs with motor ISR update rate (1000Hz)
  {
    motorUpdate = false;
    
    // update IMU data            
    readGyros();   // t=386us

    if (config.enableGyro) updateGyroAttitude(); // t=260us
    if (config.enableACC) updateACCAttitude(); // t=146us

    getAttiduteAngles(); // t=468us
    
    // Evaluate RC-Signals
    if(config.rcAbsolute==1) {
      evaluateRCAbsolute();  // t=30/142us,  returns rollRCSetPoint, pitchRCSetpoint
      utilLP_float(&pitchAngleSet, PitchPhiSet, rcLPF_tc); // t=16us
      utilLP_float(&rollAngleSet, RollPhiSet, rcLPF_tc); // t=28us
    } else {
      evaluateRCProportional(); // gives rollRCSpeed, pitchRCSpeed
      utilLP_float(&pitchAngleSet, PitchPhiSet, 0.01);
      utilLP_float(&rollAngleSet, RollPhiSet, 0.01);
    }
    
    //****************************
    // pitch PID
    //****************************
    
    // t=94us
    pitchPIDVal = ComputePID(DT_INT_MS, angle[PITCH], pitchAngleSet*1000, &pitchErrorSum, &pitchErrorOld, pitchPIDpar.Kp, pitchPIDpar.Ki, pitchPIDpar.Kd);
    // motor control
    pitchMotorDrive = pitchPIDVal * config.dirMotorPitch;


    //****************************
    // roll PID
    //****************************
    // t=94us
    rollPIDVal = ComputePID(DT_INT_MS, angle[ROLL], rollAngleSet*1000, &rollErrorSum, &rollErrorOld, rollPIDpar.Kp, rollPIDpar.Ki, rollPIDpar.Kd);

    // motor control
    rollMotorDrive = rollPIDVal * config.dirMotorRoll;
 
    //****************************
    // slow rate actions
    //****************************
    switch (count) {
    case 1:
      readACC(ROLL); break;
    case 2:
      readACC(PITCH); break;
    case 3:
      readACC(YAW); break;
    case 4:
      updateACC(); break;
    case 5:
      break;
    case 6:
      // gimbal state transitions 
      switch (gimState)
      {
        case GIM_IDLE :
          // wait 2 sec to settle ACC, before PID controlerbecomes active 
          stateCount++;
          if (stateCount >= LOOPUPDATE_FREQ/10*2)  
          {
            gimState = GIM_UNLOCKED;
            stateCount = 0;
          }
          break;
        case GIM_UNLOCKED :
          // allow PID controller to settle on ACC position
          stateCount++;
          if (stateCount >= LOOPUPDATE_FREQ/10*LOCK_TIME_SEC) 
          {
            gimState = GIM_LOCKED;
            stateCount = 0;
          }
          break;
        case GIM_LOCKED :
          // normal operation
          break;
      }
      // gimbal state actions 
      switch (gimState) {
        case GIM_IDLE :
          enableMotorUpdates = false;
          setACCFastMode(true);
          break;
        case GIM_UNLOCKED :
          enableMotorUpdates = true;
          setACCFastMode(true);
          break;
        case GIM_LOCKED :
          enableMotorUpdates = true;
          setACCFastMode(false);
          break;
      }
      break;
    case 7:
      // RC Pitch function
      if (rcData[RC_DATA_PITCH].valid) {
        if(config.rcAbsolute==1) {
            PitchPhiSet = rcData[RC_DATA_PITCH].setpoint;
        }
        else {
          if(abs(rcData[RC_DATA_PITCH].rcSpeed)>0.01) {
            PitchPhiSet += rcData[RC_DATA_PITCH].rcSpeed * 0.01;
          }
        }
      } else {
        PitchPhiSet = 0;
      }
      if (config.minRCPitch < config.maxRCPitch) {
        PitchPhiSet = constrain(PitchPhiSet, config.minRCPitch, config.maxRCPitch);
      } else {
        PitchPhiSet = constrain(PitchPhiSet, config.maxRCPitch, config.minRCPitch);
      }
      break;
    case 8:
      // RC roll function
      if (rcData[RC_DATA_ROLL].valid){
        if(config.rcAbsolute==1){
          RollPhiSet = rcData[RC_DATA_ROLL].setpoint;
        } else {
          if(abs(rcData[RC_DATA_ROLL].rcSpeed)>0.01) {
            RollPhiSet += rcData[RC_DATA_ROLL].rcSpeed * 0.01;
          }
        }
      } else {
        RollPhiSet = 0;
      }
      if (config.minRCRoll < config.maxRCRoll) {
        RollPhiSet = constrain(RollPhiSet, config.minRCRoll, config.maxRCRoll);
      } else {
        RollPhiSet = constrain(RollPhiSet, config.maxRCRoll, config.minRCRoll);
      }        
      break;
    case 9:
      // regular ACC output
      pOutCnt++;
      if (pOutCnt == (LOOPUPDATE_FREQ/10/POUT_FREQ))
      {
        // 600 us
        if(config.accOutput==1){ Serial.print(angle[PITCH]); Serial.print(F(" ACC "));Serial.println(angle[ROLL]);}
        pOutCnt = 0;
      }
      break;
    case 10:    
#ifdef STACKHEAPCHECK_ENABLE
      stackHeapEval(false);
#endif
      count=0;
      break;
    default:
      break;
    }
    count++;
       
    //****************************
    // check RC channel timeouts
    //****************************

    checkRcTimeouts();

    //****************************
    // Evaluate Serial inputs 
    //****************************
    sCmd.readSerial();

    CH2_OFF
  }

}


