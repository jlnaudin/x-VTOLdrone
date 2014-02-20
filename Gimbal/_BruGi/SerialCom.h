//************************************************************************************
// general config parameter access routines
//************************************************************************************

// types of config parameters
enum confType {
  BOOL,
  INT8,
  INT16,
  INT32,
  UINT8,
  UINT16,
  UINT32
};

#define CONFIGNAME_MAX_LEN 17
typedef struct configDef {
  char name[CONFIGNAME_MAX_LEN];  // name of config parameter
  confType type;                  // type of config parameters
  void * address;                 // address of config parameter
  void (* updateFunction)(void);  // function is called when parameter update happens
} t_configDef;

t_configDef configDef;

// access decriptor as arry of bytes as well
typedef union {
  t_configDef   c;
  char          bytes[sizeof(t_configDef)];
} t_configUnion;

t_configUnion configUnion;

//
// list of all config parameters
// to be accessed by par command
//
// descriptor is stored in PROGMEN to preserve RAM space
// see http://www.arduino.cc/en/Reference/PROGMEM
// and http://jeelabs.org/2011/05/23/saving-ram-space/
const t_configDef PROGMEM configListPGM[] = {
  {"vers",             UINT8, &config.vers,             NULL},

  {"gyroPitchKp",      INT32, &config.gyroPitchKp,      &initPIDs},
  {"gyroPitchKi",      INT32, &config.gyroPitchKi,      &initPIDs},
  {"gyroPitchKd",      INT32, &config.gyroPitchKd,      &initPIDs},
  {"gyroRollKp",       INT32, &config.gyroRollKp,       &initPIDs},
  {"gyroRollKi",       INT32, &config.gyroRollKi,       &initPIDs},
  {"gyroRollKd",       INT32, &config.gyroRollKd,       &initPIDs},
  {"accTimeConstant",  INT16, &config.accTimeConstant,  &initIMU},
  {"mpuLPF",           INT8,  &config.mpuLPF,           &initMPUlpf},
  
  {"angleOffsetPitch", INT16, &config.angleOffsetPitch, NULL},
  {"angleOffsetRoll",  INT16, &config.angleOffsetRoll,  NULL},
  
  {"dirMotorPitch",    INT8,  &config.dirMotorPitch,    NULL},
  {"dirMotorRoll",     INT8,  &config.dirMotorRoll,     NULL},
  {"motorNumberPitch", UINT8, &config.motorNumberPitch, NULL},
  {"motorNumberRoll",  UINT8, &config.motorNumberRoll,  NULL},
  {"maxPWMmotorPitch", UINT8, &config.maxPWMmotorPitch, &recalcMotorStuff},
  {"maxPWMmotorRoll",  UINT8, &config.maxPWMmotorRoll,  &recalcMotorStuff},

  {"minRCPitch",       INT8,  &config.minRCPitch,        NULL},
  {"maxRCPitch",       INT8,  &config.maxRCPitch,        NULL},
  {"minRCRoll",        INT8,  &config.minRCRoll,         NULL},
  {"maxRCRoll",        INT8,  &config.maxRCRoll,         NULL},
  {"rcGain",           INT16, &config.rcGain,            NULL},
  {"rcLPF",            INT16, &config.rcLPF,             &initRC},

  {"rcModePPM",        BOOL,  &config.rcModePPM,         &initRCPins},
  {"rcChannelPitch",   INT8,  &config.rcChannelPitch,    NULL},
  {"rcChannelRoll",    INT8,  &config.rcChannelRoll,     NULL},
  {"rcMid",            INT16, &config.rcMid,             NULL},
  {"rcAbsolute",       BOOL,  &config.rcAbsolute,        NULL},
  
  {"accOutput",        BOOL,  &config.accOutput,         NULL},

  {"enableGyro",       BOOL,  &config.enableGyro,        NULL},
  {"enableACC",        BOOL,  &config.enableACC,         NULL},

  {"axisReverseZ",     BOOL,  &config.axisReverseZ,      &initSensorOrientation},
  {"axisSwapXY",       BOOL,  &config.axisSwapXY,        &initSensorOrientation},
  
  {"", BOOL, NULL, NULL} // terminating NULL required !!
};

// read bytes from program memory
void getPGMstring (PGM_P s, char * d, int numBytes) {
  char c;
  for (int i=0; i<numBytes; i++) {
    *d++ = pgm_read_byte(s++);
  }
}

// find Config Definition for named parameter
t_configDef * getConfigDef(char * name) {

  void * addr = NULL;
  bool found = false;  
  t_configDef * p = (t_configDef *)configListPGM;

  while (true) {
    getPGMstring ((PGM_P)p, configUnion.bytes, sizeof(configDef)); // read structure from program memory
    if (configUnion.c.address == NULL) break;
    if (strncmp(configUnion.c.name, name, CONFIGNAME_MAX_LEN) == 0) {
      addr = configUnion.c.address;
      found = true;
      break;
   }
   p++; 
  }
  if (found) 
      return &configUnion.c;
  else 
      return NULL;
}


// print single parameter value
void printConfig(t_configDef * def) {
  if (def != NULL) {
    Serial.print(def->name);
    Serial.print(F(" "));
    switch (def->type) {
      case BOOL   : Serial.print(*(bool *)(def->address)); break;
      case UINT8  : Serial.print(*(uint8_t *)(def->address)); break;
      case UINT16 : Serial.print(*(uint16_t *)(def->address)); break;
      case UINT32 : Serial.print(*(uint32_t *)(def->address)); break;
      case INT8   : Serial.print(*(int8_t *)(def->address)); break;
      case INT16  : Serial.print(*(int16_t *)(def->address)); break;
      case INT32  : Serial.print(*(int32_t *)(def->address)); break;
    }
    Serial.println("");
  } else {
    Serial.println(F("ERROR: illegal parameter"));    
  }
}

// write single parameter with value
void writeConfig(t_configDef * def, int32_t val) {
  if (def != NULL) {
    switch (def->type) {
      case BOOL   : *(bool *)(def->address)     = val; break;
      case UINT8  : *(uint8_t *)(def->address)  = val; break;
      case UINT16 : *(uint16_t *)(def->address) = val; break;
      case UINT32 : *(uint32_t *)(def->address) = val; break;
      case INT8   : *(int8_t *)(def->address)   = val; break;
      case INT16  : *(int16_t *)(def->address)  = val; break;
      case INT32  : *(int32_t *)(def->address)  = val; break;
    }
    // call update function
    if (def->updateFunction != NULL) def->updateFunction();
  } else {
    Serial.println(F("ERROR: illegal parameter"));    
  }
}


// print all parameters
void printConfigAll(t_configDef * p) {
  while (true) {
    getPGMstring ((PGM_P)p, configUnion.bytes, sizeof(configDef)); // read structure from program memory
    if (configUnion.c.address == NULL) break;
    printConfig(&configUnion.c);
    p++; 
  }
  Serial.println(F("done."));
}

//******************************************************************************
// general parameter modification function
//      par                           print all parameters
//      par <parameter_name>          print parameter <parameter_name>
//      par <parameter_name> <value>  set parameter <parameter_name>=<value>
//*****************************************************************************
void parameterMod() {

  char * paraName = NULL;
  char * paraValue = NULL;
  
  int32_t val = 0;

  if ((paraName = sCmd.next()) == NULL) {
    // no command parameter, print all config parameters
    printConfigAll((t_configDef *)configListPGM);
  } else if ((paraValue = sCmd.next()) == NULL) {
    // one parameter, print single parameter
    printConfig(getConfigDef(paraName));
  } else {
    // two parameters, set specified parameter
    val = atol(paraValue);
    writeConfig(getConfigDef(paraName), val);
  }
}
//************************************************************************************


void updateAllParameters() {
  recalcMotorStuff();
  initPIDs();
  initIMU();
  initMPUlpf();
  initSensorOrientation();
  initRCPins();
  initRC();
}

void setDefaultParametersAndUpdate() {
  setDefaultParameters();
  updateAllParameters();
}


void transmitUseACC()  // TODO: remove obsolete command
{
   Serial.println(1);  // dummy for bl_tool compatibility ;-)
}

void toggleACCOutput()
{
  int temp = atoi(sCmd.next());
  if(temp==1)
    config.accOutput = true;
  else
    config.accOutput = false;
}

void setUseACC() // TODO: remove obsolete command
{
  int temp = atoi(sCmd.next());
}

void transmitRCConfig()
{
  Serial.println(config.minRCPitch);
  Serial.println(config.maxRCPitch);
  Serial.println(config.minRCRoll);
  Serial.println(config.maxRCRoll);
}

void transmitRCAbsolute()
{
  Serial.println(config.rcAbsolute);
}

void setRCGain()
{
    config.rcGain = atoi(sCmd.next());
}

void transmitRCGain()
{
  Serial.println(config.rcGain);
}

void setRcMode()
{
    config.rcModePPM = atoi(sCmd.next());
    config.rcChannelPitch = atoi(sCmd.next());
    config.rcChannelRoll = atoi(sCmd.next());
    initRCPins();
}

void transmitRcMode()
{
  Serial.println(config.rcModePPM);
  Serial.println(config.rcChannelPitch);
  Serial.println(config.rcChannelRoll);
}

void setRCAbsolute()
{
  int temp = atoi(sCmd.next());
  if(temp==1)
  {
    config.rcAbsolute = true;
  }
  else
  {
    config.rcAbsolute = false;
  }
  rcData[RC_DATA_PITCH].setpoint = 0.0;
  rcData[RC_DATA_ROLL].setpoint  = 0.0;
  rcData[RC_DATA_PITCH].rcSpeed  = 0.0;
  rcData[RC_DATA_ROLL].rcSpeed   = 0.0;
}

void setRCConfig()
{
  config.minRCPitch = atoi(sCmd.next());
  config.maxRCPitch = atoi(sCmd.next());
  config.minRCRoll = atoi(sCmd.next());
  config.maxRCRoll = atoi(sCmd.next());
}

void transmitSensorOrientation()
{
  Serial.println(config.axisReverseZ);
  Serial.println(config.axisSwapXY);
}

void writeEEPROM()
{
  bool old = config.accOutput;
  config.accOutput = false; // do not save enabled OAC output mode 
  config.crc8 = crcSlow((crc *)&config, sizeof(config)-1); // set proper CRC 
  EEPROM_writeAnything(0, config);
  config.accOutput = old; 
}

void readEEPROM()
{
  EEPROM_readAnything(0, config); 
  if (config.crc8 == crcSlow((crc *)&config, sizeof(config)-1))
  { 
    updateAllParameters();
  } else {
    // crc failed intialize directly here, as readEEPROM is void
    Serial.print(F("EEPROM CRC failed, initialize EEPROM"));
    setDefaultParameters();
    writeEEPROM();
  }
}

void transmitActiveConfig()
{
  Serial.println(config.vers);
  Serial.println(config.gyroPitchKp);
  Serial.println(config.gyroPitchKi);
  Serial.println(config.gyroPitchKd);
  Serial.println(config.gyroRollKp);
  Serial.println(config.gyroRollKi);
  Serial.println(config.gyroRollKd);
  Serial.println(config.accTimeConstant);
  Serial.println(config.nPolesMotorPitch);
  Serial.println(config.nPolesMotorRoll);
  Serial.println(config.dirMotorPitch);
  Serial.println(config.dirMotorRoll);
  Serial.println(config.motorNumberPitch);
  Serial.println(config.motorNumberRoll);
  Serial.println(config.maxPWMmotorPitch);
  Serial.println(config.maxPWMmotorRoll);
}


void setPitchPID()
{
  config.gyroPitchKp = atol(sCmd.next());
  config.gyroPitchKi = atol(sCmd.next());
  config.gyroPitchKd = atol(sCmd.next());
  initPIDs();
}

void setRollPID()
{
  config.gyroRollKp = atol(sCmd.next());
  config.gyroRollKi = atol(sCmd.next());
  config.gyroRollKd = atol(sCmd.next());
  initPIDs();
}

void setMotorPWM()
{
  config.maxPWMmotorPitch = atoi(sCmd.next());
  config.maxPWMmotorRoll = atoi(sCmd.next());
  recalcMotorStuff();
}

void gyroRecalibrate()
{
  mpu.setDLPFMode(MPU6050_DLPF_BW_5);  // experimental AHa: set to slow mode during calibration
  gyroOffsetCalibration();
  initMPUlpf();
  Serial.println(F("recalibration: done"));
}

void setMotorDirNo()
{
  config.dirMotorPitch = atoi(sCmd.next());
  config.dirMotorRoll = atoi(sCmd.next());
  config.motorNumberPitch = atoi(sCmd.next());
  config.motorNumberRoll = atoi(sCmd.next());
}

void setSensorOrientation()
{
  config.axisReverseZ = atoi(sCmd.next());
  config.axisSwapXY = atoi(sCmd.next());

  initSensorOrientation();
  
}

void printHelpUsage()
{
  Serial.println(F("This gives you a list of all commands with usage:"));
  Serial.println(F("Explanations are in brackets(), use integer values only !"));
  Serial.println(F(""));
  Serial.println(F("these are the preferred commands, use them for new GUIs !!"));
  Serial.println(F(""));
  Serial.println(F("SD    (Set Defaults)"));
  Serial.println(F("WE    (Writes active config to eeprom)"));
  Serial.println(F("RE    (Restores values from eeprom to active config)"));  
  Serial.println(F("GC    (Recalibrates the Gyro Offsets)"));
  Serial.println(F("par <parName> <parValue>   (general parameter read/set command)"));
  Serial.println(F("    example usage:"));
  Serial.println(F("       par                     ... list all config parameters"));
  Serial.println(F("       par gyroPitchKi         ... list gyroPitchKi"));
  Serial.println(F("       par gyroPitchKi 12000   ... set gyroPitchKi to 12000"));
  Serial.println(F(""));
  Serial.println(F("these commands are intendend for commandline users and compatibilty with 049 GUI"));
  Serial.println(F("TC    (transmits all config values in eeprom save order)"));     
  Serial.println(F("SP gyroPitchKp gyroPitchKi gyroPitchKd    (Set PID for Pitch)"));
  Serial.println(F("SR gyroRollKp gyroRollKi gyroRollKd    (Set PID for Roll)"));
  Serial.println(F("SE maxPWMmotorPitch maxPWMmotorRoll     (Used for Power limitiation on each motor 255=high, 1=low)"));
  Serial.println(F("SM dirMotorPitch dirMotorRoll motorNumberPitch motorNumberRoll"));
  Serial.println(F("SSO reverseZ swapXY (set sensor orientation)"));
  Serial.println(F("TSO   (Transmit sensor orientation)"));
  Serial.println(F("TRC   (transmitts RC Config)"));
  Serial.println(F("SRC minRCPitch maxRCPitch minRCRoll maxRCRoll (angles -90..90)"));
  Serial.println(F("SCA rcAbsolute (1 = true, RC control is absolute; 0 = false, RC control is proportional)"));
  Serial.println(F("SRG rcGain (set RC gain)"));
  Serial.println(F("SRM modePPM channelPitch channelRoll (set RC mode: modePPM 1=PPM 0=single channels, channelPitch/Roll = channel assignment 0..7)"));
  Serial.println(F("TCA   (Transmit RC control absolute or not)"));
  Serial.println(F("TRG   (Transmit RC gain)"));
  Serial.println(F("TRM   (Transmit RC mode"));
  Serial.println(F("UAC useACC (1 = true, ACC; 0 = false, DMP)"));
  Serial.println(F("TAC   (Transmit ACC status)"));
  Serial.println(F("OAC accOutput (Toggle Angle output in ACC mode: 1 = true, 0 = false)"));
  Serial.println(F(""));
  Serial.println(F("HE     (print this output)"));
  Serial.println(F(""));
  Serial.println(F("Note: command input is case-insensitive, commands are accepted in both upper/lower case"));
}

void unrecognized(const char *command) 
{
  Serial.println(F("What? type in HE for Help ..."));
}


void setSerialProtocol()
{
  // Setup callbacks for SerialCommand commands
  sCmd.addCommand("sd", setDefaultParametersAndUpdate);   
  sCmd.addCommand("we", writeEEPROM);   
  sCmd.addCommand("re", readEEPROM); 
  sCmd.addCommand("par", parameterMod);
  sCmd.addCommand("gc", gyroRecalibrate);

  sCmd.addCommand("tc", transmitActiveConfig);
  sCmd.addCommand("sp", setPitchPID);
  sCmd.addCommand("sr", setRollPID);
  sCmd.addCommand("se", setMotorPWM);
  sCmd.addCommand("sm", setMotorDirNo);
  sCmd.addCommand("sso", setSensorOrientation);
  sCmd.addCommand("tso", transmitSensorOrientation);
  sCmd.addCommand("trc", transmitRCConfig);
  sCmd.addCommand("src", setRCConfig);
  sCmd.addCommand("srg", setRCGain);
  sCmd.addCommand("srm", setRcMode);  
  sCmd.addCommand("trm", transmitRcMode);  
  sCmd.addCommand("sca", setRCAbsolute);
  sCmd.addCommand("tca", transmitRCAbsolute);
  sCmd.addCommand("trg", transmitRCGain);
  sCmd.addCommand("uac", setUseACC);
  sCmd.addCommand("tac", transmitUseACC);
  sCmd.addCommand("oac", toggleACCOutput);

  sCmd.addCommand("he", printHelpUsage);
  sCmd.setDefaultHandler(unrecognized);      // Handler for command that isn't matched  (says "What?")
}

