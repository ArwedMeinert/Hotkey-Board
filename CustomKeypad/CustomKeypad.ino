#include <Encoder.h>
#include <Mouse.h>
#include <Keyboard.h>
#include <Keypad.h>
#include <Adafruit_NeoPixel.h>
#define PIXEL_PIN    15
#define enablePin 10
#define PIXEL_COUNT 12
Adafruit_NeoPixel pixels(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
const int CLK = 16;      // Definition der Pins. CLK an D6, DT an D5.
const int DT = 14;
const int SW = 1;       // Der Switch wird mit Pin D2 Verbunden. ACHTUNG : Verwenden Sie einen interrupt-Pin!
long altePosition = -999;
Encoder meinEncoder(DT, CLK);
const byte COLS = 4;
const byte ROWS = 3; //four rows
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', '4'},
  {'5', '6', '7', '8'},
  {'9', 'A', 'B', 'C'}
};
byte rowPins[ROWS] = {2, 3, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

//initialize an instance of clmakeeymapass NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
#define modechange 0
int casenr;
#define caseanz 2
long neuePosition;
char customKey;
bool switched;
void setup() {
  pixels.begin();
  Serial.begin(6600);
  pinMode(enablePin, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);
  pinMode(modechange, INPUT_PULLUP);

  // attachInterrupt(digitalPinToInterrupt(modechange), InterruptCase, FALLING);
  Mouse.begin();
  Keyboard.begin();
  int casenr = 1;
  switched = false;
}

void loop() {
  if (digitalRead(modechange) == LOW) {
    casenr = casenr + 1;
    if (casenr > caseanz) {
      casenr = 1;
    }
    switched = true;

  }
  if (enablePin == LOW) {
    Mouse.end();
    Keyboard.end();
  }
  if (casenr == 1) {
    int normaleFarbe1[] = {50, 0, 0};
    int gedrueckteFarbe1[] = {0, 50, 0};
    for (int i = 0; i < PIXEL_COUNT; i++) {
      pixels.setPixelColor(i, pixels.Color(normaleFarbe1[0], normaleFarbe1[1], normaleFarbe1[2]));
    }
    attachInterrupt(digitalPinToInterrupt(SW), Interrupt0, FALLING);
    neuePosition = meinEncoder.read();
    if (neuePosition != altePosition) { //Drehen des Encoders Mappen
      if (neuePosition > altePosition) {
        Mouse.move(0, 0, 1);            //Encoder nach links drehen
      }
      else {
        Mouse.move(0, 0, - 1);          //Encoder nach rechts drehen
      }
      altePosition = neuePosition;
    }
    customKey = customKeypad.getKey();

    if (customKey == '1') {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('c');
      fading(0, normaleFarbe1, gedrueckteFarbe1, 200);
      Keyboard.releaseAll();
    } else if (customKey == '2') {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('v');
      fading(1, normaleFarbe1, gedrueckteFarbe1, 200);
      Keyboard.releaseAll();
    } else if (customKey == '3') {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('u');
      fading(2, normaleFarbe1, gedrueckteFarbe1, 200);
      Keyboard.releaseAll();
    } else if (customKey == '4') {
       Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(225);
       Keyboard.press(227);
       Keyboard.press(228);
      fading(3, normaleFarbe1, gedrueckteFarbe1, 200);
      Keyboard.releaseAll();
    } else if (customKey == '5') {
     Keyboard.press(KEY_LEFT_CTRL);
       Keyboard.press(KEY_RIGHT_SHIFT);
       Keyboard.press('m');
      fading(7, normaleFarbe1, gedrueckteFarbe1, 200);
      Keyboard.releaseAll();
    } else if (customKey == '6') {
      Keyboard.print("MODE0");
      fading(6, normaleFarbe1, gedrueckteFarbe1, 200);
      Keyboard.releaseAll();
    } else if (customKey == '7') {
      Keyboard.print("MODE0");
      fading(5, normaleFarbe1, gedrueckteFarbe1, 200);
      Keyboard.releaseAll();
    } else if (customKey == '8') {
      Keyboard.print("MODE0");
      fading(4, normaleFarbe1, gedrueckteFarbe1, 200);
      Keyboard.releaseAll();
    } else if (customKey == '9') {
      Keyboard.write(22);
      fading(8, normaleFarbe1, gedrueckteFarbe1, 200);
      Keyboard.releaseAll();
    } else if (customKey == 'A') {
      Keyboard.print("MODE0");
      fading(9, normaleFarbe1, gedrueckteFarbe1, 200);
      Keyboard.releaseAll();
    } else if (customKey == 'B') {
      Keyboard.print("MODE0");
      fading(10, normaleFarbe1, gedrueckteFarbe1, 200);
      Keyboard.releaseAll();
    } else if (customKey == 'C') {
      Keyboard.print("MODE0");
      fading(11, normaleFarbe1, gedrueckteFarbe1, 200);
      Keyboard.releaseAll();
    }
    pixels.show();
  } else if (casenr == 2) {
    int normaleFarbe2[] = {0, 0, 50};
    int gedrueckteFarbe2[] = {50, 50, };
    for (int i = 0; i < PIXEL_COUNT; i++) {
      pixels.setPixelColor(i, pixels.Color(normaleFarbe2[0], normaleFarbe2[1], normaleFarbe2[2]));
    }
    pixels.show();
    attachInterrupt(digitalPinToInterrupt(SW), Interrupt1, FALLING);
    neuePosition = meinEncoder.read();
    if (neuePosition != altePosition) { //Drehen des Encoders Mappen
      if (neuePosition > altePosition) {
        Mouse.move(0, 0, 1);            //Encoder nach links drehen
      }
      else {
        Mouse.move(0, 0, - 1);          //Encoder nach rechts drehen
      }
      altePosition = neuePosition;
    }
    customKey = customKeypad.getKey();
    if (customKey == '1') {
       Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(223);
      fading(0, normaleFarbe2, gedrueckteFarbe2, 200);
      Keyboard.releaseAll();
    } else if (customKey == '2') {
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(224);
      fading(1, normaleFarbe2, gedrueckteFarbe2, 200);
      Keyboard.releaseAll();
    } else if (customKey == '3') {
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(225);
      fading(2, normaleFarbe2, gedrueckteFarbe2, 200);
      Keyboard.releaseAll();
    } else if (customKey == '4') {
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(226);
      fading(3, normaleFarbe2, gedrueckteFarbe2, 200);
      Keyboard.releaseAll();
    } else if (customKey == '5') {
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(227);
      fading(7, normaleFarbe2, gedrueckteFarbe2, 200);
      Keyboard.releaseAll();
    } else if (customKey == '6') {
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(228);
      fading(6, normaleFarbe2, gedrueckteFarbe2, 200);
      Keyboard.releaseAll();
    } else if (customKey == '7') {
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(229);
      fading(5, normaleFarbe2, gedrueckteFarbe2, 200);
      Keyboard.releaseAll();
    } else if (customKey == '8') {
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(230);
      fading(4, normaleFarbe2, gedrueckteFarbe2, 200);
      Keyboard.releaseAll();
    } else if (customKey == '9') {
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(231);
      fading(8, normaleFarbe2, gedrueckteFarbe2, 200);
      Keyboard.releaseAll();
    } else if (customKey == 'A') {
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(232);
      fading(9, normaleFarbe2, gedrueckteFarbe2, 200);
      Keyboard.releaseAll();
    } else if (customKey == 'B') {
      Keyboard.print("MODE1");
      fading(10, normaleFarbe2, gedrueckteFarbe2, 200);
      Keyboard.releaseAll();
    } else if (customKey == 'C') {
      Keyboard.print("MODE1");
      fading(11, normaleFarbe2, gedrueckteFarbe2, 200);
      Keyboard.releaseAll();
    }
    pixels.show();
  }
  if (switched == true) {
    delay(300);
    switched = false;
  }
}



void Interrupt0() {
  Mouse.click();
}
void Interrupt1() {
  Mouse.press(MOUSE_RIGHT);
  Mouse.release(MOUSE_RIGHT);
}
//void InterruptCase(){
// casenr=casenr+1;
//if (casenr>caseanz){
// casenr=1;
//}


//}

void fading(int pixel, int farbenormal[], int farbefade[], int zeit) {
  int t = zeit / 100;
  int rr;
  int gg;
  int bb;
  for (int s = 0; s < 100; s++) {
    rr = map(s, 0, 99, farbefade[0], farbenormal[0]);
    gg = map(s, 0, 99, farbefade[1], farbenormal[1]);
    bb = map(s, 0, 99, farbefade[2], farbenormal[2]);
    pixels.setPixelColor(pixel, pixels.Color(rr, gg, bb));
    pixels.show();
    delay(t);
  }
}
