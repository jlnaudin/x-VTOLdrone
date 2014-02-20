
Arduino -> Tools -> Serial Monitor Settings
  Baudrate: 11200 Baud, NL and CR

######################################
List of serial commands:
######################################

these are the preferred commands, use them for new GUIs !!

SD    (Set Defaults)
WE    (Writes active config to eeprom)
RE    (Restores values from eeprom to active config)
GC    (Recalibrates the Gyro Offsets)
par <parName> <parValue>   (general parameter read/set command)
    example usage:
       par                     ... list all config parameters
       par gyroPitchKi         ... list gyroPitchKi
       par gyroPitchKi 12000   ... set gyroPitchKi to 12000

HE     (print this output)
HE par (print config paramter description)	   


######################################
Config Parameters (list with "he par")
######################################

vers
  firmware version
  
versEEPROM
  eeprom version

gyroPitchKp/gyroRollKp
  pid controller P-value
gyroPitchKi/gyroRollKi
  pid controller I-value
gyroPitchKd/gyroRollKd
  pid controller D-value
accTimeConstant
  time constant of ACC complementary filter.
  controls how fast the gimbal follows ACC.
  unit = 1 sec, e.g. 7 = 7 seconds
mpuLPF
  low pass filter of gyro (DLPFMode)
  legal values are 0...6, 0=fastest 6=slowest
  use slow values if high frequency oscillations occur (still experimental)

angleOffsetPitch/angleOffsetRoll
  offset of gimbal zero position
  unit = 0.01 deg, e.g. 500 = 5.00 deg

dirMotorPitch/dirMotorRoll
  motor direction
  1 = normal, -1 = reverse direction
motorNumberPitch/motorNumberRoll
  assign motor output for pitch and roll, legal values are 0 or 1
maxPWMmotorPitch/maxPWMmotorRoll
  motor power, legal range 0 to 255

minRCPitch/minRCRoll
  RC minimum set point angle, unit = 1 deg
maxRCPitch/maxRCRoll
  RC maximum set point angle, unit = 1 deg
rcGain
  RC gain in Relative mode, specifies speed of gimbal movement
rcLPF
  RC low pass filter in Absolute mode, specified speed of gimbal movement
  unit = 0.1 sec, e.g. 20 = 2.0 seconds

rcModePPM
  0 ... use two RC PWM inputs on A0 and A1
  1 ... use PPM sum input on A0

rcChannelPitch
   RC channel assignment for RC pitch, legal values are 0 to 7 in PPM mode
rcChannelRoll
   RC channel assignment for RC roll, legal values are 0 to 7 in PPM mode

rcMid
   RC center position, unit = 1 msec, default=1500
rcAbsolute
   0 ... RC Relative Mode, gimbal position is incremented/decremented by RC
   1 ... RC Absolute Mode, RC controls gimbal directly

accOutput
   1 ... enable ACC printout for GUI chart display
enableGyro/enableACC
   1 ... enable Gyro/ACC update in control loop
         just for test and adjustment purposes

axisReverseZ
   0 ... sensor is mounted with component side up
   1 ... sensor is mounted with component side down
axisSwapXY
   0 ... standard X/Y sensor orientation
   1 ... swap X/Y, exchange roll/pitch function, when sensor is rotated 90 degrees

crc
   EEPROM checksum
   