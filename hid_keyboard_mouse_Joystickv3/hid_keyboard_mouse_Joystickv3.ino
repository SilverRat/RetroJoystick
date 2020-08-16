/*********************************************************************
 This is an example for our nRF52 based Bluefruit LE modules

 Pick one up today in the adafruit shop!

 Adafruit invests time and resources providing this open source code,
 please support Adafruit and open-source hardware by purchasing
 products from Adafruit!

 MIT license, check LICENSE for more information
 All text above, and the splash screen below must be included in
 any redistribution
*********************************************************************/
#include <bluefruit.h>

BLEDis bledis;
BLEHidAdafruit blehid;

byte KEY_NONE               =byte(0x00);
byte KEY_A                  =byte(0x04);
byte KEY_B                  =byte(0x05);
byte KEY_C                  =byte(0x06);
byte KEY_D                  =byte(0x07);
byte KEY_E                  =byte(0x08);
byte KEY_F                  =byte(0x09);
byte KEY_G                  =byte(0x0A);
byte KEY_H                  =byte(0x0B);
byte KEY_I                  =byte(0x0C);
byte KEY_J                  =byte(0x0D);
byte KEY_K                  =byte(0x0E);
byte KEY_L                  =byte(0x0F);
byte KEY_M                  =byte(0x10);
byte KEY_N                  =byte(0x11);
byte KEY_O                  =byte(0x12);
byte KEY_P                  =byte(0x13);
byte KEY_Q                  =byte(0x14);
byte KEY_R                  =byte(0x15);
byte KEY_S                  =byte(0x16);
byte KEY_T                  =byte(0x17);
byte KEY_U                  =byte(0x18);
byte KEY_V                  =byte(0x19);
byte KEY_W                  =byte(0x1A);
byte KEY_X                  =byte(0x1B);
byte KEY_Y                  =byte(0x1C);
byte KEY_Z                  =byte(0x1D);
byte KEY_1                  =byte(0x1E);
byte KEY_2                  =byte(0x1F);
byte KEY_3                  =byte(0x20);
byte KEY_4                  =byte(0x21);
byte KEY_5                  =byte(0x22);
byte KEY_6                  =byte(0x23);
byte KEY_7                  =byte(0x24);
byte KEY_8                  =byte(0x25);
byte KEY_9                  =byte(0x26);
byte KEY_0                  =byte(0x27);
byte KEY_RETURN             =byte(0x28);
byte KEY_ESCAPE             =byte(0x29);
byte KEY_BACKSPACE          =byte(0x2A);
byte KEY_TAB                =byte(0x2B);
byte KEY_SPACE              =byte(0x2C);
byte KEY_MINUS              =byte(0x2D);
byte KEY_EQUAL              =byte(0x2E);
byte KEY_BRACKET_LEFT       =byte(0x2F);
byte KEY_BRACKET_RIGHT      =byte(0x30);
byte KEY_BACKSLASH          =byte(0x31);
byte KEY_EUROPE_1           =byte(0x32);
byte KEY_SEMICOLON          =byte(0x33);
byte KEY_APOSTROPHE         =byte(0x34);
byte KEY_GRAVE              =byte(0x35);
byte KEY_COMMA              =byte(0x36);
byte KEY_PERIOD             =byte(0x37);
byte KEY_SLASH              =byte(0x38);
byte KEY_CAPS_LOCK          =byte(0x39);
byte KEY_F1                 =byte(0x3A);
byte KEY_F2                 =byte(0x3B);
byte KEY_F3                 =byte(0x3C);
byte KEY_F4                 =byte(0x3D);
byte KEY_F5                 =byte(0x3E);
byte KEY_F6                 =byte(0x3F);
byte KEY_F7                 =byte(0x40);
byte KEY_F8                 =byte(0x41);
byte KEY_F9                 =byte(0x42);
byte KEY_F10                =byte(0x43);
byte KEY_F11                =byte(0x44);
byte KEY_F12                =byte(0x45);
byte KEY_PRINT_SCREEN       =byte(0x46);
byte KEY_SCROLL_LOCK        =byte(0x47);
byte KEY_PAUSE              =byte(0x48);
byte KEY_INSERT             =byte(0x49);
byte KEY_HOME               =byte(0x4A);
byte KEY_PAGE_UP            =byte(0x4B);
byte KEY_DELETE             =byte(0x4C);
byte KEY_END                =byte(0x4D);
byte KEY_PAGE_DOWN          =byte(0x4E);
byte KEY_ARROW_RIGHT        =byte(0x4F);
byte KEY_ARROW_LEFT         =byte(0x50);
byte KEY_ARROW_DOWN         =byte(0x51);
byte KEY_ARROW_UP           =byte(0x52);
byte KEY_NUM_LOCK           =byte(0x53);
byte KEY_KEYPAD_DIVIDE      =byte(0x54);
byte KEY_KEYPAD_MULTIPLY    =byte(0x55);
byte KEY_KEYPAD_SUBTRACT    =byte(0x56);
byte KEY_KEYPAD_ADD         =byte(0x57);
byte KEY_KEYPAD_ENTER       =byte(0x58);
byte KEY_KEYPAD_1           =byte(0x59);
byte KEY_KEYPAD_2           =byte(0x5A);
byte KEY_KEYPAD_3           =byte(0x5B);
byte KEY_KEYPAD_4           =byte(0x5C);
byte KEY_KEYPAD_5           =byte(0x5D);
byte KEY_KEYPAD_6           =byte(0x5E);
byte KEY_KEYPAD_7           =byte(0x5F);
byte KEY_KEYPAD_8           =byte(0x60);
byte KEY_KEYPAD_9           =byte(0x61);
byte KEY_KEYPAD_0           =byte(0x62);
byte KEY_KEYPAD_DECIMAL     =byte(0x63);
byte KEY_EUROPE_2           =byte(0x64);
byte KEY_APPLICATION        =byte(0x65);
byte KEY_POWER              =byte(0x66);
byte KEY_KEYPAD_EQUAL       =byte(0x67);
byte KEY_F13                =byte(0x68);
byte KEY_F14                =byte(0x69);
byte KEY_F15                =byte(0x6A);
byte KEY_CONTROL_LEFT       =byte(0xE0);
byte KEY_SHIFT_LEFT         =byte(0xE1);
byte KEY_ALT_LEFT           =byte(0xE2);
byte KEY_GUI_LEFT           =byte(0xE3);
byte KEY_CONTROL_RIGHT      =byte(0xE4);
byte KEY_SHIFT_RIGHT        =byte(0xE5);
byte KEY_ALT_RIGHT          =byte(0xE6);
byte KEY_GUI_RIGHT          =byte(0xE7);

const int keyboard = 0;
const int mouse = 1;

int val = LOW;
int keycodeCounter = 0;
uint8_t keycode[6] = {0,0,0,0,0,0};
uint8_t buttons;

const int numberOfInputs = 7;
int pins[numberOfInputs] = {2, 3, 4, 5, 12, 13, 14};
bool hasKeyPressed[numberOfInputs] = {false, false, false, false, false, false, false};
bool hasKeyPressedStateChanged[numberOfInputs] = {false, false, false, false, false, false, false};

//Karl's Table
byte keyCodes[numberOfInputs] = {KEY_ARROW_UP, KEY_ARROW_DOWN, KEY_ARROW_LEFT, KEY_ARROW_RIGHT, MOUSE_BUTTON_LEFT, KEY_PAGE_UP, KEY_PAGE_DOWN };
int keyTypes[numberOfInputs] = {keyboard, keyboard, keyboard, keyboard, mouse, keyboard, keyboard};

//Amiga Forever Joystick
//byte keyCodes[numberOfInputs] = {KEY_ARROW_UP, KEY_ARROW_DOWN, KEY_ARROW_LEFT, KEY_ARROW_RIGHT, KEY_CONTROL_RIGHT, KEY_PAGE_UP, KEY_PAGE_DOWN };
//int keyTypes[numberOfInputs] = {keyboard, keyboard, keyboard, keyboard, keyboard, keyboard, keyboard};

void setup() 
{
  //Setup pinouts
  //Name  IDE   PIN   Wire    Function
  //A0    2     15    Blue    Up Arrow
  //A1    3     16    Orange  Down Arrow
  //A2    4     17    Yellow  Left Arrow
  //A3    5     18    White   Right Arrow
  //SCK   12    26    Black   Left Mouse / Right Control (Joystick)
  //MOSI  13    27    Green   Page UP
  //MISO  14    28    Blue    Page Down
  
  // Streamlined pinMode Setup. Set pins to input with pullup resistor active.
  for (int x=0; x<numberOfInputs; x++) {
    pinMode(pins[x], INPUT_PULLUP);
  }
   
  Serial.begin(115200);
  while ( !Serial ) delay(10);   // for nrf52840 with native usb

  Serial.println("Bluefruit52 HID Keyboard Example");
  Serial.println("--------------------------------\n");

  Serial.println();
  Serial.println("Go to your devices's Bluetooth settings to pair your device");

  Bluefruit.begin();

  //Mouse testing
  // HID Device can have a min connection interval of 9*1.25 = 11.25 ms
  Bluefruit.Periph.setConnInterval(9, 16); // min = 9*1.25=11.25 ms, max = 16*1.25=20ms
  
  Bluefruit.setTxPower(4);    // Check bluefruit.h for supported values
  Bluefruit.setName("Bluefruit52");

  // Configure and Start Device Information Service
  bledis.setManufacturer("Adafruit Industries");
  bledis.setModel("Bluefruit Feather 52");
  bledis.begin();

  /* Start BLE HID
   * Note: Apple requires BLE device must have min connection interval >= 20m
   * ( The smaller the connection interval the faster we could send data).
   * However for HID and MIDI device, Apple could accept min connection interval 
   * up to 11.25 ms. Therefore BLEHidAdafruit::begin() will try to set the min and max
   * connection interval to 11.25  ms and 15 ms respectively for best performance.
   */
  blehid.begin();

  // Set callback for set LED from central
  blehid.setKeyboardLedCallback(set_keyboard_led);

  /* Set connection interval (min, max) to your perferred value.
   * Note: It is already set by BLEHidAdafruit::begin() to 11.25ms - 15ms
   * min = 9*1.25=11.25 ms, max = 12*1.25= 15 ms 
   */
  /* Bluefruit.Periph.setConnInterval(9, 12); */

  // Set up and start advertising
  startAdv();
}

void startAdv(void)
{  
  // Advertising packet
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();

  //Mouse testing
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_KEYBOARD);
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_MOUSE);
  
  // Include BLE HID service
  Bluefruit.Advertising.addService(blehid);

  // There is enough room for the dev name in the advertising packet
  Bluefruit.Advertising.addName();
  
  /* Start Advertising
   * - Enable auto advertising if disconnected
   * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
   * - Timeout for fast mode is 30 seconds
   * - Start(timeout) with timeout = 0 will advertise forever (until connected)
   * 
   * For recommended advertising interval
   * https://developer.apple.com/library/content/qa/qa1931/_index.html   
   */
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
  Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds
}

void loop() 
{
  // Since there seems to be no key specific release, I will only send HID reports on state change.
  // When the new HID report comes in, the PC will keep buttons pressed that are re-reported and release those NOT pressed.
  
  // Since this application has only one mouse function, I can keep that simple and press/release as a single unit.
  
  // Key presses will be "buffered" in the keycode array and sent once after looping all pins.
  // If I expected a backlog of keystrokes, or more than 6 per loop, I could create a secondary buffer.

  // Reset the keycodes to be sent in the HID Keyboard report.
  // If all keys are released, sending this "empty" should be the same as calling the release function for all keys.
  for (int y=0; y<6 ; y++) {
    keycode[y] = KEY_NONE;
  }

  // Reset the buttons to be sent in the HID Mouse Report.  NOTE: Only mouse buttons are supported, no wheel or movement.
  buttons = 0x00;
  
  // This counter is re-used each loop to keep track of which keycode we are setting in the HID report array.
  keycodeCounter = 0;

  //Loop Through all the pins to see if they are pressed.
  for(int x=0; x<numberOfInputs; x++) {
    val = digitalRead(pins[x]);
    
    // Debug:
    // Serial.println(val);

    // Since we are using built in pullup resistors, we are looking for low values
    if (val == LOW) {
      // Debug: 
      // Serial.print("Keypress detected on pin: ");
      // Serial.println(x);

      if (keyTypes[x] == keyboard){
        keycode[keycodeCounter] = keyCodes[x];
        keycodeCounter++;
 
        // Debug: 
        // Serial.print("Sending Keypress: ");
        // Serial.println(keyCodes[x]);
      }

      if (keyTypes[x] == mouse){
        // I can just ADD all mouse button codes into one variable and report it.    
        buttons = buttons + keyCodes[x];
        
        // Debug:
        // Serial.print("Sending Mousepress: ");
        // Serial.println(buttons);
      }

    } // End setting keycodes to report for each pin 
  } // End Loop through pins
  
  // Send a comprehensive report of keycodes after looping through all pins.
  blehid.keyboardReport(KEY_NONE, keycode);
  blehid.mouseReport(KEY_NONE, buttons, 0, 0, 0, 0);
}

/**
 * Callback invoked when received Set LED from central.
 * Must be set previously with setKeyboardLedCallback()
 *
 * The LED bit map is as follows: (also defined by KEYBOARD_LED_* )
 *    Kana (4) | Compose (3) | ScrollLock (2) | CapsLock (1) | Numlock (0)
 */
void set_keyboard_led(uint16_t conn_handle, uint8_t led_bitmap)
{
  (void) conn_handle;
  
  // light up Red Led if any bits is set
  if ( led_bitmap )
  {
    ledOn( LED_RED );
  }
  else
  {
    ledOff( LED_RED );
  }
}
