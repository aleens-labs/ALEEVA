#include <Arduino.h> 
#include "replay_attack.h"

extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;

extern Adafruit_NeoPixel pixels;

extern RCSwitch mySwitch;

#define RX_PIN 4         
#define TX_PIN 2        

#define BUTTON_PIN 27    

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

static const uint32_t subghz_frequency_list[] = {
    300000000, 303875000, 304250000, 310000000, 315000000, 318000000,
    390000000, 418000000, 433075000, 433420000, 433920000, 434420000,
    434775000, 438900000, 868350000, 868000000, 915000000, 925000000
};

int currentFrequencyIndex = 0; 
unsigned long receivedValue = 0; 
int receivedBitLength = 0;       
int receivedProtocol = 0;       

void rpattackSetup() {
    Serial.begin(115200);
    pinMode(BUTTON_PIN, INPUT_PULLUP); 

    u8g2.begin();
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    
    u8g2.setCursor(0, 10);
    u8g2.print("Received:");
    u8g2.setCursor(70, 10);
    u8g2.print("000000");
    u8g2.setCursor(0, 30);
    u8g2.printf("Bit: -");
    u8g2.setCursor(40, 30);
    u8g2.printf("Ptc: -");
    u8g2.setCursor(0, 50);
    u8g2.print("Freq:");  
    u8g2.setCursor(40, 50);
    u8g2.print("0");
    u8g2.print(" MHz");
    u8g2.sendBuffer();
    delay(1000);
    u8g2.clearBuffer();

    ELECHOUSE_cc1101.Init(); 
    ELECHOUSE_cc1101.SetRx(); 

    mySwitch.enableReceive(RX_PIN); 
    mySwitch.enableTransmit(TX_PIN);   
}

void rpattackLoop() {
    Serial.println("Loop started"); // Menunjukkan bahwa loop berjalan

    // Cek jika tombol ditekan
    if (digitalRead(BUTTON_PIN) == LOW) {
        delay(50); // Debounce delay
        if (digitalRead(BUTTON_PIN) == LOW) { // Cek tombol masih ditekan
            Serial.println("Button Pressed"); // Menunjukkan tombol ditekan
            
            // Ganti frekuensi ke yang berikutnya
            currentFrequencyIndex = (currentFrequencyIndex + 1) % (sizeof(subghz_frequency_list) / sizeof(subghz_frequency_list[0]));
            ELECHOUSE_cc1101.setMHZ(subghz_frequency_list[currentFrequencyIndex] / 1000000.0);
            
            Serial.print("Current Frequency: ");
            Serial.println(subghz_frequency_list[currentFrequencyIndex] / 1000000.0);
            
            // Tampilkan frekuensi baru di layar
            u8g2.clearBuffer();
            u8g2.setCursor(0, 10);
            u8g2.print("Freq:");
            u8g2.setCursor(40, 10);
            u8g2.print(subghz_frequency_list[currentFrequencyIndex] / 1000000.0);
            u8g2.print(" MHz");
            u8g2.sendBuffer();
            
            // Tunggu sampai tombol dilepas
            while (digitalRead(BUTTON_PIN) == LOW) {
                // Menunggu tombol dilepas
            }
            delay(50); // Debounce delay setelah tombol dilepas
        }
    }

    if (mySwitch.available()) {
        Serial.println("Received Value Available"); // Menunjukkan nilai tersedia
        
        receivedValue = mySwitch.getReceivedValue(); 
        receivedBitLength = mySwitch.getReceivedBitlength(); 
        unsigned int* rawSignal = mySwitch.getReceivedRawdata(); 
        receivedProtocol = mySwitch.getReceivedProtocol(); 

        if (receivedValue != 0) { 
            u8g2.clearBuffer();
            u8g2.setCursor(0, 10);
            u8g2.print("Received:");
            u8g2.setCursor(70, 10);
            u8g2.print(receivedValue);
            u8g2.setCursor(0, 30);
            u8g2.printf("Bit:%d ", receivedBitLength);
            u8g2.setCursor(40, 30);
            u8g2.printf("Ptc:%d ", receivedProtocol);    
            u8g2.sendBuffer();

            mySwitch.resetAvailable(); 
        }
    }

    if (digitalRead(BUTTON_PIN) == LOW && receivedValue != 0) { 
        Serial.println("Sending Value..."); // Menunjukkan bahwa proses pengiriman dimulai
        
        mySwitch.disableReceive(); 
        delay(100);
        mySwitch.enableTransmit(TX_PIN); 
        ELECHOUSE_cc1101.SetTx();

        u8g2.clearBuffer();
        u8g2.setCursor(0, 10);
        u8g2.print("Value:");
        u8g2.setCursor(40, 10);
        u8g2.print(receivedValue);
        u8g2.setCursor(0, 30);
        u8g2.print("Sending...");
        u8g2.sendBuffer();

        mySwitch.setProtocol(receivedProtocol);
        mySwitch.send(receivedValue, receivedBitLength); 

        delay(500);
        u8g2.clearBuffer();
        u8g2.setCursor(0, 10);
        u8g2.print("Value:");
        u8g2.setCursor(40, 10);
        u8g2.print(receivedValue);
        u8g2.setCursor(0, 30);
        u8g2.print("Done!");
        u8g2.sendBuffer();

        ELECHOUSE_cc1101.SetRx(); 
        mySwitch.disableTransmit(); 
        delay(100);
        mySwitch.enableReceive(RX_PIN); 
    }  
}
