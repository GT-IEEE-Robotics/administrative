#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#define TFT_CS     10
#define TFT_RST    0
#define TFT_DC     8

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

void setup(void) {
  Serial.begin(9600);
  Serial.print("Program starting...");
  
  tft.initR(INITR_BLACKTAB); // initialize a ST7735S chip, black tab
  tft.fillScreen(ST7735_BLACK);
  Serial.println("Initialized screen");

  // monitor time!
  initPrintTime();
  Serial.println("done");
}

void loop() {
  printTime();
  delay(1000);
}

void initPrintTime() {
  tft.setTextWrap(true);
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_WHITE);
  tft.setCursor(0, 0);
  tft.setTextSize(2);
  
  tft.println("Sketch has");
  tft.println("been runn-");
  tft.println("ing for:");
  tft.println();
  tft.println("hours");
  tft.println();
  tft.println("minutes");
  tft.println();
  tft.print("seconds");
  tft.setTextColor(ST7735_GREEN);
}

void printTime() {
  // if (millis() / 1000) 
  
  tft.setCursor(0, 50);
  tft.fillRect(0, 50, tft.width(), 14, ST7735_BLACK);
  tft.print((millis() / 1000) / 3600);

  tft.setCursor(0, 82);
  tft.fillRect(0, 82, tft.width(), 14, ST7735_BLACK);
  tft.print((millis() / 1000) / 60);
  
  tft.setCursor(0, 115);
  tft.fillRect(0, 115, tft.width(), 14, ST7735_BLACK);
  tft.print(millis() / 1000);
}

