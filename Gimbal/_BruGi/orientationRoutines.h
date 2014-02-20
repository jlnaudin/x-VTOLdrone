/*************************/
/* MPU6050 Routines      */
/*************************/
/* FS_SEL | Full Scale Range   | LSB Sensitivity
 * -------+--------------------+----------------
 * 0      | +/- 250 degrees/s  | 131 LSB/deg/s
 * 1      | +/- 500 degrees/s  | 65.5 LSB/deg/s
 * 2      | +/- 1000 degrees/s | 32.8 LSB/deg/s
 * 3      | +/- 2000 degrees/s | 16.4 LSB/deg/s
 */
/*
 * AFS_SEL | Full Scale Range | LSB Sensitivity
 * --------+------------------+----------------
 * 0       | +/- 2g           | 8192 LSB/mg
 * 1       | +/- 4g           | 4096 LSB/mg
 * 2       | +/- 8g           | 2048 LSB/mg
 * 3       | +/- 16g          | 1024 LSB/mg
*/

//#define GRAVITY 16384.0f
#define GRAVITY 15500.0f

void initResolutionDevider()
{
    if(MPU6050_GYRO_FS == 0x00) resolutionDevider = 131.0;
    if(MPU6050_GYRO_FS == 0x01) resolutionDevider = 65.5;
    if(MPU6050_GYRO_FS == 0x02) resolutionDevider = 32.8;
    if(MPU6050_GYRO_FS == 0x03) resolutionDevider = 16.4;
}


// This functions performs an initial gyro offset calibration
// INCLUDING motion detection
// Board should be still for some seconds
void gyroOffsetCalibration()
{
  int i;
  #define TOL 64
  #define GYRO_INTERATIONS 2000
  int16_t prevGyro[3],gyro[3];
  float fp_gyroOffset[3];
  uint8_t tiltDetected = 0;
  int calibGCounter = GYRO_INTERATIONS;
  
  // Set voltage on all motor phases to zero 
  enableMotorUpdates = false;

  // wait 1 second
  for (i=0; i<100; i++) {
    delayMicroseconds(10000); // 1 ms 
  }
  
  while(calibGCounter>0)
  {

    if(calibGCounter==GYRO_INTERATIONS)
    {
      for (i=0; i<70; i++) { // wait 0.7sec if calibration failed
        delayMicroseconds(10000); // 10 ms 
      }
      mpu.getRotation(&gyro[0], &gyro[1], &gyro[2]); 
      for (i=0; i<3; i++) {
        fp_gyroOffset[i] = 0;
        prevGyro[i]=gyro[i];
      }
    }
    
    mpu.getRotation(&gyro[0], &gyro[1], &gyro[2]);  

    for (i=0; i<3; i++) {
      if(abs(prevGyro[i] - gyro[i]) > TOL) {
        tiltDetected++;
        //Serial.print(F(" i="));Serial.print(i);
        //Serial.print(F(" calibGCounter="));Serial.print(calibGCounter);
        //Serial.print(F(" diff="));Serial.print(prevGyro[i] - gyro[i]);
        //Serial.print(F(" gyroi="));Serial.print(gyro[i]);
        //Serial.print(F(" prevgyroi="));Serial.println(prevGyro[i]);
        break;
      }
    } 
     
    for (i=0; i<3; i++) {
        fp_gyroOffset[i] += (float)gyro[i]/GYRO_INTERATIONS;
        prevGyro[i]=gyro[i];
    }
      
    calibGCounter--;
    if(tiltDetected>=1)
    {
      Serial.println(F("Motion detected during Gyro calibration. Starting over!"));
      calibGCounter=GYRO_INTERATIONS;
      tiltDetected=0;
    }
  }

  // put result into integer
  for (i=0; i<3; i++) {
    gyroOffset[i] = fp_gyroOffset[i];
    //Serial.print(F("gyroOffset="));Serial.println(fp_gyroOffset[i], 3);
  }

  enableMotorUpdates = true;
}
       
