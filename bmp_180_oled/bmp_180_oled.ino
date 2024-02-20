#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


Adafruit_BMP085 bmp;
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1);
  
void setup() {
  Serial.begin(115200);
  if (!bmp.begin()) {
  Serial.println("BMP180 Not Found. CHECK CIRCUIT!");
  while (1) {}
  }
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
  Serial.println(F("SSD1306 allocation failed"));
  for(;;);
}
  delay(2000);
display.clearDisplay();
display.setTextColor(WHITE);
}
  
void loop() {
    Serial.print("sicaklik = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print("basinc = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    Serial.println();

  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("sicaklik: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(bmp.readTemperature());
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");
  
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("basinc: ");
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(bmp.readPressure());
  display.print(" Pa");
  
  display.display();
  delay(1000);
  display.clearDisplay();
}
