/* This code involve 2 features, traffic light as the led light up in a sequence like traffic light, and trigerring alarm when detect motion at red light*/
int led = 13;                // pin of game over led
int ledRed = 7;              // pin of red led
int ledYellow = 6;           // pin of yellow led
int ledGreen = 5;            // pin of green led
int buzzer = 9;              // pin of buzzer 
int sensor = 8;              // the pin of sensor             
int tri = 0;                 // alarm trigger variable
int led_0 = 1;               // variable for red led
int led_1 = 0;               // variable for yellow led
int led_2 = 0;               // variable for green led
void setup() {
  pinMode(led, OUTPUT);      // initalize game over LED as an output
  pinMode(buzzer,OUTPUT);    // initalize buzzer as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  pinMode(ledRed, OUTPUT);   // initalize red LED as an output
  pinMode(ledYellow, OUTPUT);// initalize yellow LED as an output
  pinMode(ledGreen, OUTPUT); // initalize green LED as an output
}

void loop(){
  while (led_2 != 1){        // loop to light up from red led to green led
    if (tri == 1 && digitalRead(sensor) == 1) // trigerring alarm and game over led when detect motion at red light 
    {
      digitalWrite(led,HIGH);
      tone (9,1000);
      delay(3000);
      noTone(9);
      digitalWrite(led,LOW);
    }
    digitalWrite(ledRed,led_0);
    digitalWrite(ledYellow,led_1);
    digitalWrite(ledGreen,led_2);
    tri = led_0;
    led_2 = led_1;
    led_1 = led_0;
    led_0 = 0;
    delay(3000);
  }
  while (led_0 != 1){         // loop to light up from green led to red led
    digitalWrite(ledRed,led_0);
    digitalWrite(ledYellow,led_1);
    digitalWrite(ledGreen,led_2);
    
    led_0 = led_1;
    led_1 = led_2;
    led_2 = 0;
    delay(3000);
  }   
}
