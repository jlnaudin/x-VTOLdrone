#include "definitions.h"

/*
https://sites.google.com/site/qeewiki/books/avr-guide/timers-on-the-atmega328

// CS BITS
CS02	CS01    CS00 	 DESCRIPTION
0	0 	0 	 Timer/Counter0 Disabled 
0	0 	1 	 No Prescaling
0	1 	0 	 Clock / 8
0	1 	1 	 Clock / 64
1	0 	0 	 Clock / 256
1	0 	1 	 Clock / 1024

CS12	 CS11 	 CS10 	 DESCRIPTION
0	0 	0 	 Timer/Counter1 Disabled 
0	0 	1 	 No Prescaling
0	1 	0 	 Clock / 8
0	1 	1 	 Clock / 64
1	0 	0 	 Clock / 256
1	0 	1 	 Clock / 1024

CS22	 CS21 	 CS20 	 DESCRIPTION
0	0 	0 	 Timer/Counter2 Disabled 
0	0 	1 	 No Prescaling
0	1 	0 	 Clock / 8
0	1 	1 	 Clock / 32
1	0 	0 	 Clock / 64
1	0 	1 	 Clock / 128
1	1 	0 	 Clock / 256
1	1 	1 	 Clock / 1024 


// WAVEFORM GENERATOR BITS
	WGM02	WGM01	WGM00	 DESCRIPTION	 	TOP
0	0 	0	0	 Normal 	 	0xFF
1	0	0	1	 PWM, Phase Corrected	0xFF
2	0	1	0	 CTC			OCR0A
3	0	1	1	 Fast PWM		0xFF
4	1	0	0	 Reserved	 	-
5	1	0	1	 Fast PWM, Phase Corr	OCR0A
6	1	1	0	 Reserved		-
7	1	1	1	 Fast PWM		OCR0A

MODE	WGM13	WGM12	WGM11	WGM10	 DESCRIPTION            	 TOP
0	 0	 0 	0	0	 Normal 	                 0xFFFF
1	0	0	0	1	 PWM, Phase Corrected, 8bit	 0x00FF
2	0	0	1	0	 PWM, Phase Corrected, 9bit	 0x01FF
3	0	0	1	1	 PWM, Phase Corrected, 10bit 	 0x03FF 
4	0	1	0	0        CTC	                         OCR1A 
5	0	1	0	1	 Fast PWM, 8bit 	          0x00FF 
6	0	1	1	0	 Fast PWM, 9bit 	          0x01FF 
7	0	1	1	1	 Fast PWM, 10bit 	          0x03FF 
8	1	0	0	0	 PWM, Phase and Frequency Corr    ICR1 
9	1	0	0	1	 PWM, Phase and Frequency Corr    OCR1A 
10	1	0	1	0	 PWM, Phase Correct 	          ICR1 
11	1	0	1	1	 PWM, Phase Correct 	         OCR1A
12	1	1	0	0	 CTC	                         ICR1
13	1	1	0	1	 RESERVED	 
14	1	1	1	0	 Fast PWM 	                  ICR1 
15	1	1	1	1	 Fast PWM	                  OCR1A 

MODE	WGM21	WGM20	 DESCRIPTION	          TOP
0	0	0	 Normal 	         0xFF
1	0	1	 PWM Phase Corrected	 
2	1	0	 CTC	                  OCR2
3	1	1	 Fast PWM 	 



x = Timer Number
 	7 bit	 6 bit 	 5 bit 	 4 bit 	 3 bit 	 2 bit 	 1 bit 	 0 bit     Description
TCCRxA	COMxA1	 COMxA0  COMxB1  COMxB0  -	 -	 WGMx1	 WGMx0     Timer/Counter Control Register x A (x=0,2)

TCCR1B	ICNC1	 ICES1	 -	 WGM13	 WGM12	 CS12	 CS11	CS10 
TCCRxB	FOCxA    FOCxB   -       -       WGMx2   CSx2    CSx1    CSx0      Timer/Counter Control Register x B

TIMSKx	-        -       -       -       -       OCIExB  OCIExA  TOIEx     Timer/Counter Interrupt Mask Register
TIFRx	-	 -	 -	 -       -       OCFxB	 OCFxA   TOVx      Timer/Counter Interrupt Flag Register
TCNTx                                                                      Timer/Counter Register (stores the counter value)
OCRxA                                                                      Output Compare Register x A
OCRxB                                                                      Output Compare Register x B


*/
void initBlController() 
{
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

#ifdef PWM_8KHZ_FAST
  TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01)| _BV(WGM10); 
  TCCR0B = _BV(CS01);
  TCCR1A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM10); 
  TCCR1B = _BV(WGM12) | _BV(CS11);
  TCCR2A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM21)| _BV(WGM20);
  TCCR2B = _BV(CS21);
#endif

#ifdef PWM_32KHZ_PHASE
  TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM00); 
  TCCR0B = _BV(CS00);
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM10);
  TCCR1B = _BV(CS10);
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM20);
  TCCR2B = _BV(CS20);
#endif

#ifdef PWM_4KHZ_PHASE
  TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM00); 
  TCCR0B = _BV(CS01);
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM10);
  TCCR1B = _BV(CS11);
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM20);
  TCCR2B = _BV(CS21);
#endif

  TIMSK1 |= _BV(TOIE1);
  sei();

  // Enable Timer1 Interrupt for Motor Control
  OCR2A = 0;  //11  APIN
  OCR2B = 0;  //D3
  OCR1A = 0;  //D9  CPIN
  OCR1B = 0;  //D10 BPIN
  OCR0A = 0;  //D6
  OCR0B = 0;  //D5 
}

// 3 lsb of MotorPos still reserved for precision improvement (TBD) 
inline void MoveMotorPosSpeed(uint8_t motorNumber, int MotorPos, uint8_t* pwmSin)
{
  int posStep;

  if (motorNumber == 0)
  {
    posStep = MotorPos >> 3;
    posStep &= 0xff;
    PWM_A_MOTOR0 = pwmSin[(uint8_t)posStep];
    PWM_B_MOTOR0 = pwmSin[(uint8_t)(posStep + 85)];
    PWM_C_MOTOR0 = pwmSin[(uint8_t)(posStep + 170)];
  }
 
  if (motorNumber == 1)
  {
    posStep = MotorPos >> 3;
    posStep &= 0xff;
    PWM_A_MOTOR1 = pwmSin[(uint8_t)posStep];
    PWM_B_MOTOR1 = pwmSin[(uint8_t)(posStep + 85)];
    PWM_C_MOTOR1 = pwmSin[(uint8_t)(posStep + 170)];
  }
}



void fastMoveMotor(uint8_t motorNumber, int dirStep,uint8_t* pwmSin)
{
  if (motorNumber == 0)
  {
    currentStepMotor0 += dirStep;
    currentStepMotor0 &= 0xff;
    PWM_A_MOTOR0 = pwmSin[currentStepMotor0];
    PWM_B_MOTOR0 = pwmSin[(uint8_t)(currentStepMotor0 + 85)];
    PWM_C_MOTOR0 = pwmSin[(uint8_t)(currentStepMotor0 + 170)];
  }
 
  if (motorNumber == 1)
  {
    currentStepMotor1 += dirStep;
    currentStepMotor1 &= 0xff;
    PWM_A_MOTOR1 = pwmSin[currentStepMotor1] ;
    PWM_B_MOTOR1 = pwmSin[(uint8_t)(currentStepMotor1 + 85)] ;
    PWM_C_MOTOR1 = pwmSin[(uint8_t)(currentStepMotor1 + 170)] ;
  }
}

// switch off motor power
// TODO: for some reason motor control gets noisy, if call from ISR
inline void MotorOff(uint8_t motorNumber, uint8_t* pwmSin)
{
  if (motorNumber == 0)
  {
    PWM_A_MOTOR0 = pwmSin[0];
    PWM_B_MOTOR0 = pwmSin[0];
    PWM_C_MOTOR0 = pwmSin[0];
  }
 
  if (motorNumber == 1)
  {
    PWM_A_MOTOR1 = pwmSin[0];
    PWM_B_MOTOR1 = pwmSin[0];
    PWM_C_MOTOR1 = pwmSin[0];
  }
}


void calcSinusArray(uint8_t maxPWM, uint8_t *array)
{
  for(int i=0; i<N_SIN; i++)
  {
//    array[i] = maxPWM / 2.0 + sin(2.0 * i / N_SIN * 3.14159265) * maxPWM / 2.0;
    array[i] = 128 + sin(2.0 * i / N_SIN * 3.14159265) * maxPWM / 2.0;
  }  
}

void recalcMotorStuff()
{
  cli();
  calcSinusArray(config.maxPWMmotorPitch,pwmSinMotorPitch);
  calcSinusArray(config.maxPWMmotorRoll,pwmSinMotorRoll);
  sei();
}

/********************************/
/* Motor Control IRQ Routine    */
/********************************/
// motor position control
ISR( TIMER1_OVF_vect )
{
  // 0.88us / 8.1us
  freqCounter++;  
  if(freqCounter==(CC_FACTOR*1000/MOTORUPDATE_FREQ))
  {
    freqCounter=0;
    if (enableMotorUpdates)
    {
      // move pitch motor
      MoveMotorPosSpeed(config.motorNumberPitch, pitchMotorDrive, pwmSinMotorPitch); 
      // move roll motor
      MoveMotorPosSpeed(config.motorNumberRoll, rollMotorDrive, pwmSinMotorRoll);
    }
    // update event
    motorUpdate = true;
  }
}




void motorTest()
{
  #define MOT_DEL 100
  cli();
  delay(10 * CC_FACTOR);
  // Move Motors to ensure function
  for(int i=0; i<100; i++) { fastMoveMotor(config.motorNumberPitch, 1,pwmSinMotorPitch); delay(MOT_DEL * CC_FACTOR);  }
  for(int i=0; i<100; i++) { fastMoveMotor(config.motorNumberPitch, -1,pwmSinMotorPitch); delay(MOT_DEL * CC_FACTOR);  }
  delay(200 * CC_FACTOR);
  for(int i=0; i<100; i++) { fastMoveMotor(config.motorNumberRoll, 1,pwmSinMotorRoll); delay(MOT_DEL * CC_FACTOR);  }
  for(int i=0; i<100; i++) { fastMoveMotor(config.motorNumberRoll, -1,pwmSinMotorRoll); delay(MOT_DEL * CC_FACTOR);  }
  sei();  
}

