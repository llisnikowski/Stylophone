#include <Arduino.h>

constexpr int notes[] = {261, 277, 293, 311, 329, 343, 369, 392, 415, 440,
						466, 493, 523, 554, 587, 622, 659, 698, 740, 784, 
						830, 880};

constexpr int speakerPin = 3;

void setup() {
	Serial.begin(9600);
	pinMode(speakerPin, OUTPUT);
	for(int i = 4; i <= 13; i++){
		pinMode(i, INPUT_PULLUP);
	}
}

void loop() {

	for(int i = 4; i <= 13; i++){
		if(digitalRead(i) == LOW){
			tone(speakerPin, notes[i - 4]);
			break;
		}
		if(i >= 13){
			noTone(speakerPin);
		}
	}
		
	delay(100);
}

