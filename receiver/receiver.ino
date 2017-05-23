/*
* Stanley Cohen
* UCR CS120B Winter 2016
* receiver.ino
* 
* Receives Serial input from the Atmega1284 to control the LED Matrix
*/

#include <StandardCplusplus.h>
#include <SoftwareSerial.h>
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include <stdlib.h>
#include <vector>

#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2
// Last parameter = 'true' enables double-buffering, for flicker-free,
// buttery smooth animation.  Note that NOTHING WILL SHOW ON THE DISPLAY
// until the first call to swapBuffers().  This is normal.
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

SoftwareSerial atmega(10, 11); // RX, TX

class Ring {
  public:
    unsigned char x, y, rad;
    uint16_t clr;

    Ring(unsigned char x, unsigned char y, unsigned char rad, uint16_t clr):x(x), y(y), rad(rad), clr(clr) { } 
    void draw() {matrix.drawCircle(x, y, rad, clr);}
    void erase() {matrix.drawCircle(x, y, rad, 0);}
};

uint8_t get_val() {
  while(!atmega.available());
  return atmega.read();
}

int loc[2] = {15, 7};

void setup() {
  matrix.begin();
  // Open serial communications and wait for port to open:
  Serial.begin(250000);
  while (!Serial);
  Serial.println("Starting up...");

  // set the data rate for the Atmega1284 port
  atmega.begin(2400); //Also set on the Atmega side
}

void drawDeath(unsigned char x, unsigned char y) {
  std::vector<Ring> rings;
  while(!atmega.available()) {
    for(int x=0; x<rings.size() && !atmega.available(); x++) {
      if(rings.at(x).rad != 0) rings.at(x).erase();
      rings.at(x).rad += 2;
      if(rings.at(x).rad > 15) rings.erase (rings.begin()+x);
      else rings.at(x).draw();
    }

    rings.push_back(Ring(x, y, 0, matrix.Color444(15, rand() % 5, rand() % 5)));
    delay(50);
  }
}

void drawWin(unsigned char x, unsigned char y) {
  std::vector<Ring> rings;
  while(!atmega.available()) {
    for(int x=0; x<rings.size() && !atmega.available(); x++) {
      if(rings.at(x).rad != 0) rings.at(x).erase();
      rings.at(x).rad += 2;
      if(rings.at(x).rad > 15) rings.erase (rings.begin()+x);
      else rings.at(x).draw();
    }

    rings.push_back(Ring(x, y, 0, matrix.Color333(rand() % 8, rand() % 8, rand() % 8)));
    delay(50);
  }
}

#define SHIP matrix.Color888(0, 225, 255)
#define FINISH matrix.Color888(50, 255, 0)
#define ASTEROID matrix.Color888(255, 0, 238)
#define SPIKE matrix.Color888(255, 0, 0)
#define DISAPPEARING matrix.Color888(40, 0, 227)

void loop() {
  uint8_t val = get_val();
  Serial.print("Received: ");
  Serial.println(val);
  if(val == 0x00) { //Clear Screen
    matrix.fillScreen(0);
  } else if((uint8_t)(val << 2) == 3 << 2) { //Sart Screen
    //TODO: Make it beautiful<3
  } else {
    uint16_t color = (uint8_t)(val >> 5);
    Serial.println(color);
    
    if(color == 1) color = FINISH;
    else if(color == 2) color = ASTEROID;
    else if(color == 3) color = SHIP;
    
    int x = get_val();
    int y = get_val();
      
    
    if((uint8_t)(val << 3) == 1 << 3) {
      Serial.print("Got a pixel with dimensions: (");
      Serial.print(x);
      Serial.print(", ");
      Serial.print(y);
      Serial.println(")\n");
      matrix.drawPixel(x, y, color);
    } else if((uint8_t)(val << 3) == 2 << 3) {
      uint16_t type = (uint8_t)(val >> 5);
      if(type <= 3) {
        matrix.drawRect(x, y, 2, 2, color);
        Serial.print("Got a box with dimensions: (");
      } else if(type == 4) { //Up
        matrix.drawRect(x, y+1, 2, 1, ASTEROID);
        matrix.drawRect(x, y, 2, 1, SPIKE);
        Serial.print("Got an up spike with dimensions: (");
      } else if(type == 5) { //Right
        matrix.drawRect(x, y, 1, 2, ASTEROID);
        matrix.drawRect(x+1, y, 1, 2, SPIKE);
        Serial.print("Got a right spike with dimensions: (");
      } else if(type == 6) { //Down
        matrix.drawRect(x, y, 2, 1, ASTEROID);
        matrix.drawRect(x, y+1, 2, 1, SPIKE);
        Serial.print("Got a down spike with dimensions: (");
      } else if(type == 7) { //Left
        matrix.drawRect(x+1, y, 1, 2, ASTEROID);
        matrix.drawRect(x, y, 1, 2, SPIKE);
        Serial.print("Got a left spike with dimensions: (");
      }
      Serial.print(x);
      Serial.print(", ");
      Serial.print(y);
      Serial.println(")\n");
    } else if((uint8_t)(val << 3) == 6 << 3) {
      //matrix.drawRect(x, y, 
    } else if((uint8_t)(val << 3) == 5 << 3) { //Win!
      Serial.print("WINNER at: (");
      Serial.print(x);
      Serial.print(", ");
      Serial.print(y);
      Serial.println(")\n");
      drawWin(x, y);
    } else if((uint8_t)(val << 3) == 4 << 3) { //Loss
      Serial.print("LOSER FACE at: (");
      Serial.print(x);
      Serial.print(", ");
      Serial.print(y);
      Serial.println(")\n");
      drawDeath(x, y);
    }
  }

  delay(15);
}
