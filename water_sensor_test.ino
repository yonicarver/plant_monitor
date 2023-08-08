/*
* 
* 
* 
*/



#define POWER_1_PIN 		7
#define WATER_1_SIGNAL_PIN 	A5

#define LOW_THRESHOLD	300
#define HIGH_THRESHOLD	800

#define RED_LED 1
#define GREEN_LED 2
#define BLUE_LED 3


int water_1_value = 0;	// initialize variable to store water sensor 1 value

void setup() {
	Serial.begin(9600);
	pinMode(POWER_1_PIN, OUTPUT);		// configure poower pin for water sensor 1 as an OUTPUT
	digitalWrite(POWER_1_PIN, LOW);		// turn the sensor OFF

}


void loop () {
	digitalWrite(POWER_1_PIN, HIGH);	// turn the sensor ON
	delay(10);							// delay for 10 msec
	water_1_value = analogRead(WATER_1_SIGNAL_PIN);		// read the value from water sensor 1

	Serial.print("Water sensor 1 value: ");
	Serial.println(water_1_value);

	delay(500);

	if (water_1_value < LOW_THRESHOLD) {
		Serial.print("Water level below LOW_THRESHOLD");
	}
	else {
		Serial.print("Water level good");
	}

}