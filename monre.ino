/*
// TCS230 color recognition sensor 
// Sensor connection pins to Arduino are shown in comments

Color Sensor      Arduino
-----------      --------
 VCC               5V
 GND               GND
 s0                8
 s1                9
 s2                12
 s3                11
 OUT               10
 OE                GND
*/
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 10;  
const int s3 = 11;  
const int out = 12;   
// LED pins connected to Arduino
int redLed = 2;  
int greenLed = 3;  
int blueLed = 4;
// Variables  
int red = 0;  
int green = 0;  
int blue = 0;  
    
void setup()   
{  
  Serial.begin(9600); 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  pinMode(redLed, OUTPUT);  
  pinMode(greenLed, OUTPUT);  
  pinMode(blueLed, OUTPUT);  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
}  
    
void loop() 
{  
//  color(); 
  Serial.print("R:");  
  Serial.print(red, DEC);  
  Serial.print(" G: ");  
  Serial.print(green, DEC);  
  Serial.print("|");  
  Serial.print(blue, DEC);  
  //Serial.println();  

  

 

}

   

void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}

