#include <SPI.h>
#include <Servo.h>
#include <Stepper.h>

const int stepsPerRevolution = 2038;// change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:

Stepper stepper(stepsPerRevolution, 5, 8, A2, A4);
Stepper rstepper(stepsPerRevolution,A4,A2,8,5);
int stepCount = 0;         // number of steps the motor has taken

Servo myservo;

int val;
char buff [50];
volatile byte indx;
volatile boolean process;
int  interruptPin = 10;
int motorPin1 = 2;
int motorPin2 = 3;
int motorPin3 = 8;
int motorPin4 = 5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myservo.attach(6);//servo pin
  pinMode(MISO,OUTPUT); //init spi
  pinMode(3,OUTPUT);
  //Init DC pins
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(20,OUTPUT);
  pinMode(22,OUTPUT);
  SPCR |= bit (SPE); // slave control register
  indx = 0; //buffer empty
  process = false;
  
  pinMode(interruptPin,INPUT);
  int val = digitalRead(interruptPin);
  //if (!val)
    //Serial.println ("wtf");
  delay(1000);
  SPI.attachInterrupt();
 // attachInterrupt(digitalPinToInterrupt(interruptPin), tester, LOW); //enable interrupt
  //val = 1;
  //Serial.print(val);
  }

ISR (SPI_STC_vect) //SPI Interrupt Service Routine
//void tester() 
{
 // digitalWrite(3,1);
  //Serial.println("work");
  byte c = SPDR; //read byte from SPI data register
  if (indx < sizeof (buff) - 1) 
    buff [indx++] = c;// save data in the next index in the array buff
 // if (c == '\r') //check for the end of the word
    process = true;
  
}  
void loop() {
//
digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, LOW);  
//   put your main code here, to run repeatedly:
//  stepper.step(-1);
//           Serial.print("steps:");
//           Serial.println(stepCount);
//           stepCount++;
//           delayMicroseconds(2000);


  if (process) {
    buff[indx] = 0;
    process = false; //reset flag
//    digitalWrite(3,0);
 //   Serial.println("work");
    Serial.print(buff); //print to serial monitor
    int i = 0;
    if (i < sizeof(buff)) {
      switch(buff[i]) {
        case 'F' : //fwd
          digitalWrite(motorPin1, HIGH);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, HIGH);
          digitalWrite(motorPin4, LOW);
          delay(6000);
          break;
        case 'B' : //Backwards (back())
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, HIGH);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, HIGH);
          delay(6000);
          break;
        case 'L' : //left
          digitalWrite(motorPin1, HIGH);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, HIGH);
          delay(6000);
          break;
        case 'R' : //right
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, HIGH);
          digitalWrite(motorPin3, HIGH);
          digitalWrite(motorPin4, LOW);
          delay(6000);
          break;  
        case 'C' : //servo (claw())
         // for (int j = 0; j <20; j++) {
            myservo.write(140);
            delay(300);
            myservo.write(90);
            delay(300);
            Serial.print("w");
        //  }
          break;   
//        case 'T' : //stepper
//         for (int j = 0; j <820; j++) {
//           stepper.step(1);
//           Serial.print("steps:");
//           Serial.println(stepCount);
//           stepCount++;
//           delayMicroseconds(2000);
//         }
//         for (int j = 0; j <820; j++) {
//           rstepper.step(1);
//           Serial.print("steps:");
//           Serial.println(stepCount);
//           stepCount++;
//           delayMicroseconds(2000);
//         }
         
         
        default:
          i++;
          break; 
        
      }
    }
  }

    //SPDR = data  //sends value to master via SPDR
    indx = 0; //reset button to zero
}
 


