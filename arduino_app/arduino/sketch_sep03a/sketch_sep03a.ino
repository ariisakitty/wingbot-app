#include <FastLED.h>

#define LED_STRIP_PIN     7
#define LED_FLASH_PIN     8
#define MITI_PIN          12
#define NUM_LEDS          143
#define ERROR_LED_START   141

CRGB leds[NUM_LEDS];

byte state = 0;
String readString;

unsigned long startTime = 0;  // Store when we start waiting for input
const unsigned long waitTime = 1200;  // 1000 milliseconds = 1 second
bool continue_to_led = false;
byte previousState = 0; // Initialize with default or power-on state

void control_LED_strip (byte r, byte g, byte b, byte mode); // mode 0 (solid), 1 (blinking)
bool isValidState(byte state);
void setErrorLEDs(bool isError);

void setup() {
  FastLED.addLeds<WS2812, LED_STRIP_PIN, GRB>(leds, NUM_LEDS);  // Set up LED strip

  pinMode(LED_FLASH_PIN, OUTPUT);  // Set up LED flash
  pinMode(MITI_PIN, OUTPUT);  // Set up MITI pin

  Serial.begin(19200);                           // Starts the serial communication at 9600 baud rate
  Serial.println("Arduino ready to receive!");  // Prints a ready message
}

void loop() {  
  // Enable Miti
  digitalWrite(MITI_PIN, HIGH);
  
  continue_to_led = false;

  
//  int serial = Serial.available();
//  Serial.print("arduino: ");
//  Serial.print(serial);
//  Serial.println(" bytes");
  
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
    char c = Serial.read();
    startTime = millis();

    if (c == '<') {
        readString = "";  // Start of new message
    } else if (c == '>') {
      // End of message. Validate and process the complete message
      byte newState = readString.toInt();

      if (isValidState(newState)) {
        setErrorLEDs(false);  // No error
        previousState = newState;  // Update only if it's a valid state
      } else {
        setErrorLEDs(true);  // Indicate error
//        Serial.print("Invalid state received: ");
//        Serial.println(newState);
      }
      
      state = previousState;  // Use the previous valid state (may be the same as newState if newState was valid)

//      Serial.print("Signal Received! state: ");
//      Serial.println(state);
      continue_to_led = true;
    } else {
      // Build the message
      readString += c;
    }  
  }
  
  if (continue_to_led) {
//    Serial.print("LED part with state ");
//    Serial.println(state);
    
    if (state == 0) {
      // powered up - BLINKING GREEN
      control_LED_strip (0, 255, 0, 1); 

      // FLASH OFF
      digitalWrite(LED_FLASH_PIN, LOW);
    }
    else if (state == 1) {
      // XVN incoming - SOLID GREEN
      control_LED_strip (0, 255, 0, 0);

      // FLASH OFF
      digitalWrite(LED_FLASH_PIN, LOW);
    }
    else if (state == 2) {
      // AD mode - SOLID BLUE
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

void control_LED_strip(byte r, byte g, byte b, byte mode) {
  if (mode == 0) {
    for (int i = 0; i < ERROR_LED_START; i++) { // Only affect the first 141 LEDs
        leds[i] = CRGB(r, g, b);
    }
    FastLED.show();    
  }
  else if (mode == 1) {
    // turn on LEDs
    for (int i = 0; i < ERROR_LED_START; i++) { // Only affect the first 141 LEDs
        leds[i] = CRGB(r, g, b);
    }
    FastLED.show();
    delay(450);

    // turn off LEDs
    for (int i = 0; i < ERROR_LED_START; i++) { // Only affect the first 141 LEDs
        leds[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
    delay(450);
  }
}


bool isValidState(byte state) {
  return (state == 0 || state == 1 || state == 2 || state == 3);
}

void setErrorLEDs(bool isError) {
  if(isError) {
      // Set both LEDs to red
      leds[ERROR_LED_START] = CRGB::Red;
      leds[ERROR_LED_START + 1] = CRGB::Red;
  } else {
      // Turn off both LEDs
      leds[ERROR_LED_START] = CRGB::Black;
      leds[ERROR_LED_START + 1] = CRGB::Black;
  }
  FastLED.show();
}
