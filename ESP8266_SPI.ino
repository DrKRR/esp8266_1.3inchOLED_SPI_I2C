#include <Arduino.h>
#include <U8g2lib.h>
#include<SPI.h>

U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ D8, /* dc=*/D2, /* reset=*/ D1);

void setup(void) {
  u8g2.begin();
  Serial.begin(74880);
  u8g2.clearBuffer();
}

void loop(void){
    u8g2.firstPage();
  do{
          u8g2.setCursor(0,10);
          u8g2.setFont(u8g2_font_t0_11b_tf);
          u8g2.print("NodeMCU ESP9266!");
          u8g2.setCursor(63,36);
          u8g2.print("SPI Mode");
              }while ( u8g2.nextPage() );
       delay(1000);     
        }
