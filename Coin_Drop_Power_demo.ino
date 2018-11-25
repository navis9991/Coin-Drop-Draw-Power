#define relay 12
int LED = 13; 
int obstaclePin = 8; 
int hasObstacle = HIGH;
int S=0;
void clock();
void setup()
{
pinMode(LED, OUTPUT);
pinMode(obstaclePin, INPUT);
pinMode(relay, OUTPUT);
Serial.begin(9600);
Serial.println("Insert your Coin");
}
void loop() 
{ 
hasObstacle = digitalRead(obstaclePin); 
if (hasObstacle == HIGH) 
{
digitalWrite(LED, HIGH);
Serial.println("CHARGING");
clock();
}
else
{
digitalWrite(LED, LOW);
}delay(500);
}

void clock()
{
  S = S + 15;
 while(1){
digitalWrite(relay,HIGH);
  delay(300);
Serial.print("TIMELEFT:");
S--;
delay(600);
if(S==0)
{
Serial.println("TIME'S UP!!!!!!!!");  
digitalWrite(relay,LOW);
delay(2000);
 setup();
 break;
} 
else
{
Serial.print(S);
Serial.println("SEC ");
}
loop();}}




