#include <Arduino.h>

constexpr int notes[] = {261, 277, 293, 311, 329, 343, 369, 392, 415, 440,
						466, 493, 523, 554, 587, 622, 659, 698, 740, 784, 
						830, 880};

constexpr int speakerPin = 3;
constexpr int firstKey = 4;
constexpr int lastKey = 13;


void setup() {
	Serial.begin(9600);
	pinMode(speakerPin, OUTPUT);
	for(int i = firstKey; i <= lastKey; i++){
		pinMode(i, INPUT_PULLUP);
	}
}

void loop() {

	for(int i = firstKey; i <= lastKey; i++){
		if(digitalRead(i) == LOW){
			tone(speakerPin, notes[i - firstKey]);
			break;
		}
		if(i >= lastKey){
			noTone(speakerPin);
		}
	}
		
	delay(100);
}

