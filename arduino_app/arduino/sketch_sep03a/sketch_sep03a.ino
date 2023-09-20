#include <FastLED.h>

#define LED_STRIP_PIN     7
#define LED_FLASH_PIN     8
#define MITI_PIN          12
#define NUM_LEDS    143

CRGB leds[NUM_LEDS];

byte state = 0;

unsigned long startTime = 0;  // Store when we start waiting for input
const unsigned long waitTime = 1200;  // 1000 milliseconds = 1 second
bool continue_to_led = false;

void control_LED_strip (byte r, byte g, byte b, byte mode); // mode 0 (solid), 1 (blinking)

void setup() {
  FastLED.addLeds<WS2812, LED_STRIP_PIN, GRB>(leds, NUM_LEDS);  // Set up LED strip

  pinMode(LED_FLASH_PIN, OUTPUT);  // Set up LED flash
  pinMode(MITI_PIN, OUTPUT);  // Set up MITI pin

  Serial.begin(9600);                           // Starts the serial communication at 9600 baud rate
  Serial.println("Arduino ready to receive!");  // Prints a ready message
}

void loop() {  
  // Enable Miti
  digitalWrite(MITI_PIN, HIGH);
  
  continue_to_led = false;
  // If there's no serial data available, start the timer
  if (!Serial.available()) {   
    if (startTime == 0) {  // If the timer hasn't started yet
      startTime = millis();  // Store the current time
    } else if (millis() - startTime >= waitTime) {  // If 1 second has passed without serial input
      state = 0;
      startTime = 0;  // Reset the timer
      continue_to_led = true;
    }
  } else {  // If there's serial data available
    state = Serial.read();  // Reads the incoming byte
    Serial.print("Signal Received! state: ");
    Serial.println(state);
    startTime = 0;  // Reset the timer since we received data
    continue_to_led = true;
  }

  if (continue_to_led) {
    Serial.print("LED part with state ");
    Serial.println(state);
    
    if (state == 0) {
      // SOLID GREEN
      control_LED_strip (0, 255, 0, 0); 

      // FLASH OFF
      digitalWrite(LED_FLASH_PIN, LOW);
    }
    else if (state == 1) {
      // BLINKING BLUE
      control_LED_strip (0, 0, 255, 1);

      // FLASH OFF
      digitalWrite(LED_FLASH_PIN, LOW);
    }
    else if (state == 2) {
      // SOLID BLUE
      control_LED_strip (0, 0, 255, 0);

      // FLASH OFF
      digitalWrite(LED_FLASH_PIN, LOW);
    }
    else if (state == 3) {
      // SOLID BLUE
      control_LED_strip (0, 0, 255, 0);

      // FLASH ON
      digitalWrite(LED_FLASH_PIN, HIGH);
    }
    else {
      // BLINKING RED
      control_LED_strip (255, 0, 0, 1);

      // FLASH ON
      digitalWrite(LED_FLASH_PIN, HIGH);
    }     
  } 
  

}

void control_LED_strip (byte r, byte g, byte b, byte mode) {
  if (mode == 0) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB (r, g, b);

    }
    FastLED.show();    
  }
  else if (mode == 1) {
    // turn on LEDs
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB (r, g, b);
    }
    FastLED.show();
    delay(450);

    // turn off LEDs
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB (0, 0, 0);
    }
    FastLED.show();
    delay(450);
  }
}
