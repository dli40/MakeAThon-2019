#include <Servo.h>

Servo servoLeft;
int analogPin = A5;  
long long val=0;
int values[500];
long sum = 0, i, prev, j;
int state = 1;
int count=0;
int dif;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);              //  setup serial
  servoLeft.attach(2);
  for(i= 0; i <500; i ++)
  {
    values[i] = 0;
  }
  i = 0;
  sum = 0;
}

void loop() {
  i++;
  if(i == 50)
    i = 0;
  sum -= values[i];
    
  val = analogRead(analogPin);     // read the input pin
  
  dif = abs(val - 325);

  values[i] = dif;
  sum += values[i];

  _delay_ms(5);

  if((sum/50) > 50)
  {
    state *= -1;
    for(j= 0; j <50; j ++)
    {
      values[j] = 0;
    }
    sum = 0;
    if(state==-1)
      servoLeft.write(0);
    else
      servoLeft.write(180);
    Serial.println("delay");
    _delay_ms(1000);
  }
}
