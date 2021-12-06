# esp8266_1.3inchOLED_SPI_I2C
This repository describes a detailed approach (in the form of hardware and software) to interface a 1.3" OLED display with NodeMCU ESP8266 module in SPI and I2C modes. Following website is the motivation for the present work. <br>
<p align = "center">[(https://github.com/rene-mt/esp8266-oled-sh1106)]</p>

In this project I am going to present hardware software to interface 1.3"OLED with NodeMCU ESP8266 in both SPI and I2C modes. In an attempt to do this, software is developed to display different shapes and graphics on OLED. The front and back sides of OLED are shown below:
<p align ="center"> 
  <img src="https://github.com/DrKRR/esp8266_1.3inchOLED_SPI_I2C/blob/main/s-l300%20(1).jpg" width = "250" height = "200/><p align="center">
  <img src="https://github.com/DrKRR/esp8266_1.3inchOLED_SPI_I2C/blob/main/1.3-Inch-128%C3%9764-OLED-Display-Module-with-SPI-Serial-Interface-7-Pin-back_1.jpg".jpg" width = "250" height = "200"/>
 </p><br/>
It is clear from the above figure that, the OLED has seven pins: GND, Vcc, CLK, MOSI, RES, DC, CS. In the I2C mode, the first four pins are used 
for I2C communication with RES=1, DC=CS=0. All seven pins are used in SPI mode.
