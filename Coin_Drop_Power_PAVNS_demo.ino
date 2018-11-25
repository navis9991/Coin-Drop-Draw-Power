#define relay 12
//relay output
int LED = 13; // Use the onboard Uno LED
int obstaclePin = 8; // This is our input pin
int hasObstacle = HIGH;
int S=0;// HIGH MEANS NO OBSTACLE
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
hasObstacle = digitalRead(obstaclePin); //Reads the output of the obstacle
if (hasObstacle == HIGH) //LOW means something is ahead, so illuminates the
{
digitalWrite(LED, HIGH);//Illuminates the 13th Port LED
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




