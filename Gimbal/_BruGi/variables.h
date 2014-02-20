/*************************/
/* Config Structure      */
/*************************/

struct config_t
{
uint8_t vers;
uint8_t versEEPROM;
int32_t gyroPitchKp; 
int32_t gyroPitchKi;   
int32_t gyroPitchKd;
int32_t gyroRollKp;
int32_t gyroRollKi;
int32_t gyroRollKd;
int16_t accTimeConstant;
int8_t  mpuLPF;             // mpu LPF 0..6, 0=fastest(256Hz) 6=slowest(5Hz)
int16_t angleOffsetPitch;   // angle offset, deg*100
int16_t angleOffsetRoll;
uint8_t nPolesMotorPitch;
uint8_t nPolesMotorRoll;
int8_t dirMotorPitch;
int8_t dirMotorRoll;
uint8_t motorNumberPitch;
uint8_t motorNumberRoll;
uint8_t maxPWMmotorPitch;
uint8_t maxPWMmotorRoll;
int8_t minRCPitch;
int8_t maxRCPitch;
int8_t minRCRoll;
int8_t maxRCRoll;
int16_t rcGain;
int16_t rcLPF;             // low pass filter for RC absolute mode, units=1/10 sec
bool rcModePPM;            // RC mode, true=common RC PPM channel, false=separate RC channels 
int8_t rcChannelPitch;     // input channel for pitch
int8_t rcChannelRoll;      // input channel for roll
int16_t rcMid;             // rc channel center ms
bool rcAbsolute;
bool accOutput;
bool enableGyro;           // enable gyro attitude update
bool enableACC;            // enable acc attitude update
bool axisReverseZ;
bool axisSwapXY;
uint8_t crc8;
} config;

void recalcMotorStuff();
void initPIDs();

void setDefaultParameters()
{
  config.vers = VERSION;
  config.versEEPROM = VERSION_EEPROM;
  config.gyroPitchKp = 20000;
  config.gyroPitchKi = 10000;
  config.gyroPitchKd = 40000;
  config.gyroRollKp = 20000;
  config.gyroRollKi = 8000;
  config.gyroRollKd = 30000;
  config.accTimeConstant = 7;
  config.mpuLPF = 0;
  config.angleOffsetPitch = 0;
  config.angleOffsetRoll = 0;
  config.nPolesMotorPitch = 14;
  config.nPolesMotorRoll = 14;
  config.dirMotorPitch = 1;
  config.dirMotorRoll = -1;
  config.motorNumberPitch = 0;
  config.motorNumberRoll = 1;
  config.maxPWMmotorPitch = 80;
  config.maxPWMmotorRoll = 80;
  config.minRCPitch = -30;
  config.maxRCPitch = 30;
  config.minRCRoll = -30;
  config.maxRCRoll = 30;
  config.rcGain = 5;
  config.rcLPF = 20;              // 2 sec
  config.rcModePPM = false;
  config.rcChannelRoll = 0;
  config.rcChannelPitch = 1;
  config.rcMid = MID_RC;
  config.rcAbsolute = true;
  config.accOutput=false;
  config.enableGyro=true;
  config.enableACC=true;
  config.axisReverseZ=true;
  config.axisSwapXY=false;  
  config.crc8 = 0;  
}


typedef struct PIDdata {
  int32_t   Kp, Ki, Kd;
} PIDdata_t;

PIDdata_t pitchPIDpar,rollPIDpar;

void initPIDs(void)
{
  rollPIDpar.Kp = config.gyroRollKp/10;
  rollPIDpar.Ki = config.gyroRollKi/1000;
  rollPIDpar.Kd = config.gyroRollKd/10;

  pitchPIDpar.Kp = config.gyroPitchKp/10;
  pitchPIDpar.Ki = config.gyroPitchKi/1000;
  pitchPIDpar.Kd = config.gyroPitchKd/10;
  
}


// CRC definitions
#define POLYNOMIAL 0xD8  /* 11011 followed by 0's */
typedef uint8_t crc;



/*************************/
/* Variables             */
/*************************/



// motor drive

uint8_t pwmSinMotorPitch[256];
uint8_t pwmSinMotorRoll[256];

int currentStepMotor0 = 0;
int currentStepMotor1 = 0;
bool motorUpdate = false; 

int8_t pitchDirection = 1;
int8_t rollDirection = 1;

int freqCounter=0; // TODO: back to char later ...

int pitchMotorDrive = 0;
int rollMotorDrive = 0;

// control motor update in ISR
bool enableMotorUpdates = false;


// Variables for MPU6050
float gyroPitch;
float gyroRoll; //in deg/s

float resolutionDevider;
int16_t x_val;
int16_t y_val;
int16_t z_val;

float PitchPhiSet = 0;
float RollPhiSet = 0;
static float pitchAngleSet=0;
static float rollAngleSet=0;

int count=0;

// RC control

struct rcData_t
{
 uint32_t microsRisingEdge;
 uint32_t microsLastUpdate;
 uint16_t rx;
 bool     update;
 bool     valid;
 float    rcSpeed;
 float    setpoint;
};

rcData_t rcData[RC_DATA_SIZE];

float rcLPF_tc = 1.0;

// Gimbal State
enum gimStateType {
 GIM_IDLE=0,      // no PID
 GIM_UNLOCKED,    // PID on, fast ACC
 GIM_LOCKED       // PID on, slow ACC
};

gimStateType gimState = GIM_IDLE;
int stateCount = 0;


//*************************************
//
//  IMU
//
//*************************************
struct flags_struct {
  uint8_t SMALL_ANGLES_25 : 1;
} flags;

enum axisDef {
  ROLL,
  PITCH,
  YAW
};

typedef struct fp_vector {
  float X;
  float Y;
  float Z;
} t_fp_vector_def;

typedef union {
  float   A[3];
  t_fp_vector_def V;
} t_fp_vector;



//********************
// sensor orientation
//********************
typedef struct sensorAxisDef {
  char idx;
  int  dir;
} t_sensorAxisDef;

typedef struct sensorOrientationDef {
  t_sensorAxisDef Gyro[3];
  t_sensorAxisDef Acc[3];
} t_sensorOrientationDef;

t_sensorOrientationDef sensorDef = { 
    {{0, 1}, {1, 1}, {2, 1}},    // Gyro
    {{0, 1}, {1, 1}, {2, 1}}     // Acc
  };

// gyro calibration value
int16_t gyroOffset[3] = {0, 0, 0};



static float gyroScale=0;

static int32_t accSmooth[3];
static int16_t gyroADC[3];
static int16_t accADC[3];

static t_fp_vector EstG;

static float accLPF[3] = {0.0,};
static int32_t accMag = 0;

static float AccComplFilterConst = 0;  // filter constant for complementary filter

static int16_t acc_25deg = 25;      //** TODO: check

static int32_t angle[2]    = {0,0};  // absolute angle inclination in multiple of 0.01 degree    180 deg = 18000


// DEBUG only
uint32_t stackTop = 0xffffffff;
uint32_t stackBottom = 0;

uint32_t heapTop = 0;
uint32_t heapBottom = 0xffffffff;

