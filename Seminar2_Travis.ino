// Define the pin number for the button
const uint8_t BTN_PIN = 2;

// Define the pin number for the LED
const uint8_t LED_PIN = 13;

// Variable to store the previous state of the button
uint8_t buttonPrevState = HIGH;

// Variable to store the current state of the LED
uint8_t ledState = LOW;

void setup()
{
  // Set the button pin as an input with an internal pull-up resistor
  pinMode(BTN_PIN, INPUT_PULLUP);

  // Set the LED pin as an output
  pinMode(LED_PIN, OUTPUT);

  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
}

void loop()
{
  // Read the current state of the button
  uint8_t buttonState = digitalRead(BTN_PIN);

  // Print the current button state, previous button state, and LED state to the serial monitor
  Serial.print(buttonState);
  Serial.print(buttonPrevState);
  Serial.print(ledState);
  Serial.println("");

  // Check if the button state has changed from HIGH to LOW (indicating a press)
  if(buttonState == LOW && buttonPrevState == HIGH)
  {
    // Toggle the LED state
    ledState = !ledState;

    // Update the LED pin with the new LED state
    digitalWrite(LED_PIN, ledState);
  }

  // Update the previous button state with the current state
  buttonPrevState = buttonState;

  // Wait for 500 milliseconds
  delay(500);
}
