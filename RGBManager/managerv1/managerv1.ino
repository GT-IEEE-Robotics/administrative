#include <TFT.h>
#include <SPI.h>

#define TFT_CS 10
#define TFT_RST 0
#define TFT_DC 8

TFT tft = TFT(TFT_CS, TFT_DC, TFT_RST);

// global selection variable
int select = 0;

// preview color
// TODO preview color global varaible

void setup() {
  Serial.begin(9600);
  Serial.print("Program starting...");

  tft.initR(INITR_BLACKTAB); // initialize a ST7735S chip, black tab
  tft.fillScreen(ST7735_BLACK);
  tft.setRotation(3);
  Serial.println("Initialized screen");

  initMenu();
}

void loop() {
  checkJoystick(); // TODO make interrupt driven
  menu();
}

void initMenu() {
  // title
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(50, 0);
  tft.setTextColor(ST7735_RED);
  tft.print("R");
  tft.setTextColor(ST7735_GREEN);
  tft.print("G");
  tft.setTextColor(ST7735_BLUE);
  tft.print("B");
  tft.setTextColor(ST7735_WHITE);
  tft.print(" Manager");
  tft.stroke(255, 255, 255);
  tft.line(0, 10, 160, 10);
  
  // options
  tft.setCursor(10, 22);
  tft.print("Option 1");
  tft.setCursor(10, 37);
  tft.print("Option 2");
  tft.setCursor(10, 52);
  tft.print("Option 3");
  tft.setCursor(10, 67);
  tft.print("Option 4");
  tft.setCursor(10, 82);
  tft.print("Option 5");
  tft.setCursor(10, 97);
  tft.print("Option 6");

  // preview
  tft.rect(70, 24, 80, 80);

  // credits
  tft.setCursor(0, 120);
  tft.print("v1.0");
  tft.setCursor(115, 120);
  tft.print("tlee753");  
  tft.line(0, 117, 160, 117);
}

void menu() { // TODO make changes interrupt driven and maintain otherwise
  // clear all circles
  tft.stroke(0, 0, 0);
  tft.circle(5, 25, 1);
  tft.circle(5, 40, 1);
  tft.circle(5, 55, 1);
  tft.circle(5, 70, 1);
  tft.circle(5, 85, 1);
  tft.circle(5, 100, 1);
  
  // menu cursor
  tft.stroke(255, 255, 255);
  switch(select) {
    case 0:
      tft.circle(5, 25, 1);
      break;
    case 1:
      tft.circle(5, 40, 1);
      break;
    case 2:
      tft.circle(5, 55, 1);
      break;
    case 3:
      tft.circle(5, 70, 1);
      break;
    case 4:
      tft.circle(5, 85, 1);
      break;
    case 5:
      tft.circle(5, 100, 1);
      break;
  }
}

void checkJoystick()
{
  int joystickState = analogRead(3);
  
  if(joystickState < 50) { // left
    select--;
    delay(100);
  } else if(joystickState < 150) { // down
    select++;
    delay(1000);
  } else if (joystickState < 250) { // press
    select++;
    delay(1000);
  } else if (joystickState < 500) { // right
    select++;
    delay(1000);
  } else if(joystickState < 650) { // up
    select--;
    delay(1000);
  }
  
  if (select < 0) {
    select = 5;
  }
  select = select % 6;
}

