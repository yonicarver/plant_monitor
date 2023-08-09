/*
* 
* 
* 
*/



#define POWER_1_PIN 		7
#define WATER_1_SIGNAL_PIN 	A5

#define LOW_THRESHOLD	  100
#define MID_THRESHOLD   500
#define HIGH_THRESHOLD	800

#define RED_LED 2
#define GREEN_LED 3
#define BLUE_LED 4


int water_1_value = 0;	// initialize variable to store water sensor 1 value

void setup() {
	Serial.begin(9600);
	pinMode(POWER_1_PIN, OUTPUT);		// configure poower pin for water sensor 1 as an OUTPUT
	digitalWrite(POWER_1_PIN, LOW);		// turn the sensor OFF

  // init RGB LED
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);

}


void loop () {
	read_sensor();

  // cycle_led();

  print_serial_mon();
  // print_serial_plot();
  // time_delay(200);        // delay for 0.2 sec


  if ( 0 < water_1_value <  LOW_THRESHOLD ) {
    Serial.println("Water below LOW");
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);

  }
  else if ( LOW_THRESHOLD < water_1_value < MID_THRESHOLD ) {
    Serial.println("Water at LOW level");
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
  }
  else if ( MID_THRESHOLD < water_1_value < HIGH_THRESHOLD ) {
    Serial.println("Water at NOMINAL level");
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
  }
  else if ( HIGH_THRESHOLD < water_1_value ) {
    Serial.println("Water at HIGH level");
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
  }

}


void read_sensor() {
  digitalWrite(POWER_1_PIN, HIGH);	// turn the sensor ON
	delay(100);							// delay for 10 msec
	water_1_value = analogRead(WATER_1_SIGNAL_PIN);		// read the value from water sensor 1

  // digitalWrite(POWER_1_PIN, LOW);

	// delay(5000);
  delay(50);
}

void time_delay( float t ) {
  delay(t);
  float _time;
  _time = t / 1000;
  Serial.print("Delaying for: ");
  Serial.print(_time);
  Serial.println(" sec");
}

void print_serial_mon() {
  Serial.print("Water sensor 1 value: ");
  Serial.print(water_1_value);
  
}

void print_serial_plot() {
  Serial.println(water_1_value);
}

void cycle_led() {
  // digitalWrite(RED_LED, HIGH);
  // delay(500);
  digitalWrite(GREEN_LED, HIGH);
  // delay(500);
  // digitalWrite(BLUE_LED, HIGH);

  delay (1000);

  // digitalWrite(RED_LED, LOW);
  // delay(500);
  digitalWrite(GREEN_LED, LOW);
  // delay(500);
  // digitalWrite(BLUE_LED, LOW);

  delay (1000);
}