# esp8266_1.3inchOLED_SPI_I2C
This repository describes a detailed approach (in the form of hardware and software) to interface a 1.3" OLED display with NodeMCU ESP8266 module in SPI and I2C modes. Following website is the motivation for the present work. <br/>
<p align = "center">[(https://github.com/rene-mt/esp8266-oled-sh1106)]<p/>

In this project I am going to present hardware software to interface 1.3"OLED with NodeMCU ESP8266 in both SPI and I2C modes. In an attempt to do this, software is developed to display different shapes and graphics on OLED. The front and back sides of OLED are shown below:
<p align ="center"> 
  <img src="https://github.com/DrKRR/esp8266_1.3inchOLED_SPI_I2C/blob/main/s-l300%20(1).jpg" width="250" height="250"> 
      <img src="https://github.com/DrKRR/esp8266_1.3inchOLED_SPI_I2C/blob/main/1.3-Inch-128%C3%9764-OLED-Display-BackView.jpg" width="250" height="250">
          <img src="https://github.com/DrKRR/esp8266_1.3inchOLED_SPI_I2C/blob/main/1.3inch_I2C.jpg" width="200" height="200"> 
            <p/> 
      <br/>
It is clear from the above figure that, the OLED has seven pins: GND, Vcc, CLK, MOSI, RES, DC, CS. In the I2C mode, the first four pins are used for I2C communication. Neverthless, other pins have to be either HI or LO. Thus, for I2C make RES=1, DC=CS=0. All seven pins are used in SPI mode. <b>Further, by visual inspection of the backplane, one can see that the board comes with a 4k7 resistor connected across the SPI bridge, and the R8 bridge in OPEN condition.</b> <b><i>For I2C, (i). the 4k7 resistor has to be removed from SPI bridge and soldered across the I2C bridge, (ii). the R8 resistor position (bridge) shorted as shown in the third figure above</i></b>                                                                 
<h3>
  Interfacing 1.3" OLED with NodeMCU ESP8266 in I2C Mode 
  </h3>
  <h7>
  <b>HARDWARE:></b>
             </h7></br>
The 1.3" 128x64 OLED uses SH1106 driver IC for handling the pixels. Commands used with SH1106 are different from that of the commands used with SSD1306. Also the constructors used in the software are different. The figure given below shows interfacing OLED with NodeMCU ESP8266 in I2C mode:
<p align="center">
<img src="https://github.com/DrKRR/esp8266_1.3inchOLED_SPI_I2C/blob/main/SH1106_I2C.jpg" width=300" height="350"> 
 <img src="https://github.com/DrKRR/esp8266_1.3inchOLED_SPI_I2C/blob/main/SH1106_I2C_1.jpg" width=300" height="350">                                   
  <img src="https://github.com/DrKRR/esp8266_1.3inchOLED_SPI_I2C/blob/main/SH1106_I2C_2.jpg" width=300" height="350">                                                                          <p/>
It is clear from the above first figure that the SCL pin of NodeMCU is connected to CLK of OLED and the SDA pin of NodeMCU to MOSI of the OLED.
                                                                                                                <i> Pull-up resistors (4k7 or 3k3) are used on both of these pins.</i>
After successful execution, the program is dumped on to NodeMCU, and the system is powered by power bank, which can be seen in the third figure above. The second figure shows the display of ASCII characters, and the third one shows the display of graphics on the 1.3" OLED in I2C mode, with SH1106 driver. </br>                                                                                                               
 <h7>
  <b>SOFTWARE:></b>
             </h7></br>
All programs are developed in Arduino <b>I</b>ntegrated <b>D</b>evelopment <b>E</b>nvironment (<b>IDE</b>). For the current work, <i>u8g2</i> library is installed in the program execution path. It's indeed a great library! Installation of u8g2 library is accomplished from the following website:
<p align = "center"> [(https://github.com/olikraus/u8g2)] <p/> 
Method of downloading and adding it to the Arduino path, choosing of the board etc., are not explained here, because the procedure is well explained in different blogs and websites. Here, I am considering examples for which algorithms and program listings are given.
When we consider I2C, its address is important. One among the following websites can be used to obtain the I2C address:
<p align = "center">[(https://github.com/gryzli133/ESP8266-I2C-Scanner-with-OLED-SH1106-Display/blob/master/I2C_Scanner.ino)]<p/> 
<p align = "center">[(https://www.instructables.com/ESP8266-I2C-PORT-and-Address-Scanner/)]<p/>
I have used the second website to obtain the I2C address of the 1.3" OLED used in the present work. The Arduino program is included <a href="https://github.com/DrKRR/esp8266_1.3inchOLED_SPI_I2C/blob/main/1.3inch_OLED_I2C_test.ino"> here </a>
The output on the Serial Monitor is available <a href="https://github.com/DrKRR/esp8266_1.3inchOLED_SPI_I2C/blob/main/I2C_Serial_Monitor_Output.docx"> here </a>
<i>The I2C address for my display is 0x3C.</i> But, for certain displays, it is mentioned that DC>>GND-->I2C addrees=0x3D. One should test and ascertain the I2C address before its use. The following pictures show the I2C address displayed on OLED and a graphic output using I2C interface.
<p align="center">
<img src="https://github.com/DrKRR/esp8266_1.3inchOLED_SPI_I2C/blob/main/1.3inch_I2CDisp.jpg" width="400" height="250"> 
 <img src="https://github.com/DrKRR/esp8266_1.3inchOLED_SPI_I2C/blob/main/U8g2_logo_I2C.jpg" width="400" height="250"                                                                                                                    </p> </br>
 <p> I will now turn my attention towards description on interfacing 1.3" OLED module (the same above module) in SPI mode
<h3>
  Interfacing 1.3" OLED module with NodeMCU ESP8266 in SPI Mode:
  </h3>
 <h7>
  <b>HARDWARE:></b>
             </h7></br>
The following circuit shows the interfacing OLED display with NodeMCU ESP8266 in SPI mode. 
</br>   <p align="center">
     <img src="https://github.com/DrKRR/esp8266_1.3inchOLED_SPI_I2C/blob/main/1.3_inch_OLED_SPI.jpg" width=350" height="400"> 
                 </p>
