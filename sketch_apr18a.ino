#include <SoftwareSerial.h> //library used here is SoftwareSerial.h which allows serial communication on digital pins of arduino using software to replicate the 
functions you want to add.
char data; //A datatype is create named data to store the information/data into this.
SoftwareSerial mySerial(7, 6);  //So using this librabry function, a mySerial named function is created and which is connected to
//pin 7, 6 on arduino board. This is created so that we can connect our bot to bluethoot. After connecting we define every pin which is connected on the board.

#define m11 9
#define m12 8
#define m21 11
#define m22 10  //Arm
#define m41 2
#define m42 3
#define m51 4
#define m52 5  


// Creating a void named as setup, in this we make sure that our bot speed(Arduino input) mactches with the receiving speed (bluetooth signal) to work properly in 
//coherence for that we set both the speed to 9600 miliseconds.
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(m11, OUTPUT);   //After setting the speed using this inbuilt fucntion named pinmode, ALl the definded pins are set as output to work accordingly.
  pinMode(m12, OUTPUT);   // Pinmode's function is to set a pin in an inout or output function.
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(m41, OUTPUT);
  pinMode(m42, OUTPUT);
  pinMode(m51, OUTPUT);
  pinMode(m52, OUTPUT);
}


void forward()  // Now to begin with motion a fucntion/void naming Forward is created, in this using digitalWrite inbuiltfunction, the motor which is connected 
{                           // at the rear wheels are given commands. the function of DigitalWrite is to assign high or low value to digital pins. 
   digitalWrite(m11, LOW);  // Setting rear pin of both motor high and front pin low will motion the both in forward direction
   digitalWrite(m12, HIGH);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH);
}

void backward()
{
   digitalWrite(m11, HIGH);  // Same for backward motion just Pin commands are visa versa.
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW); 
}

void left()
{
   digitalWrite(m11, HIGH); //Same for left and for movement left rear motor(wheel) is set to move backwards 
   digitalWrite(m12, LOW);  //and for right rear motor(wheel) is set to move forward which makes the bot to move in left direction
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH);
}

void right()
{
   digitalWrite(m11, LOW);  // same as per left and for motion visa versa of left direction.
   digitalWrite(m12, HIGH);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}


void arm_open()     // As you know a motor is connected in arms of the bot using the same function arm is being opened and closed
{
   digitalWrite(m41, HIGH);
   digitalWrite(m42, LOW);
}

void arm_close()
{
   digitalWrite(m41, LOW);
   digitalWrite(m42, HIGH);
}

void arm_up()      // A last motor is attached at the base of bot to motion it up and down using same DigitalWrite function 
{
   digitalWrite(m51, LOW);
   digitalWrite(m52, HIGH);
}

void arm_down()
{
   digitalWrite(m51, HIGH);
   digitalWrite(m52, LOW);
}

void Stop()  // A void named stop is created so that if no signal or input is recieved from the user so it wont motion. therefore every pin is set for low value
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
   digitalWrite(m41, LOW);
   digitalWrite(m42, LOW);
   digitalWrite(m51, LOW);
   digitalWrite(m52, LOW);
}



void loop() {      // In last a loop is created which is basically an if else ladder, in this a while loop is opened as you know if no input is recived which is zero  
while(mySerial.available()!=0) //so no fucntion will be executed and this loop will keep on runnig but when an input is recived in the form of 1's it will be saved and 
{                              //Read after this an if else ladder is executed suppose the input character is 'F' then it will function to move forward. like this 
data=mySerial.read();         // it will check for every input and work accordingly also an inbuilt function Delay is used to keep the motion of the bot in perfect 
Serial.println(data);         // handling as speed is not a major part of the project but to be careful and steady is.
  if(data=='B')
  {backward();delay(25);}

  else if(data=='F')
  {forward();delay(25);}

  else if(data=='L')
  {left();delay(25);}

  else if(data=='R')
  {right();delay(25);}

  else if(data=='8')
  {arm_open();delay(100);}

  else if(data=='3')
  {arm_close();delay(100);}

  else if(data=='X')
  {arm_up();delay(100);}

  else if(data=='x')
  {arm_up();delay(100);}

  else if(data=='V')
  {arm_down();delay(100);}

  else if(data=='v')
  {arm_down();delay(100);}

  else
  Stop();
}

} 
