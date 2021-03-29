
//#include <ESP8266WiFi.h>
//#include <ESPAsyncE131.h>
#include <E131.h>
const char ssid[] = "Maszt5G";         /* Replace with your SSID */
const char passphrase[] = "Genowefa42";   /* Replace with your WPA2 passphrase */

E131 e131;

void setup() {
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    /*pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(16, OUTPUT);
    pinMode(13, OUTPUT);*/
    
    Serial.begin(115200);
    delay(10);

    /* Choose one to begin listening for E1.31 data */
   // e131.begin(ssid, passphrase);               /* via Unicast on the default port */
    e131.beginMulticast(ssid, passphrase, 1); /* via Multicast for Universe 1 */
}

void loop() {

    /* Parse a packet */
    uint16_t num_channels = e131.parsePacket();
    
    /* Process channel data if we have it */
    if (num_channels) {
               Serial.printf("Universe %u / %u Channels | Packet#: %u / Errors: %u / CH1: %u\n",
                e131.universe,              // The Universe for this packet
                num_channels,               // Number of channels in this packet
                e131.stats.num_packets,     // Packet counter
                e131.stats.packet_errors,   // Packet error counter
                e131.data[0]);              // Dimmer data for Channel 1 
                 int one1 =map(e131.data[0],0,255,0,1024);
                 int one2 =map(e131.data[1],0,255,0,1024);
                 int one3 =map(e131.data[2],0,255,0,1024);
                 /*int one4 =map(e131.data[3],0,255,0,1024);
                 int one5 =map(e131.data[4],0,255,0,1024);
                 int one6 =map(e131.data[5],0,255,0,1024);
                 int one7 =map(e131.data[6],0,255,0,1024);
                 int one8 =map(e131.data[7],0,255,0,1024);*/
               analogWrite(2, one1);       
               analogWrite(4, one2);
               analogWrite(5, one3);            // Dimmer data for Channel 1
               /*analogWrite(13, one4);
               analogWrite(12, one5);            // Dimmer data for Channel 1
               analogWrite(14, one6);
               analogWrite(16, one7);            // Dimmer data for Channel 1
               analogWrite(9, one8);*/
               
    }else{
     // digitalWrite(13, LOW);
      }
}
