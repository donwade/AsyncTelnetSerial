#include "AsyncTelnetSerial.h"

AsyncTelnetSerial Test(&Serial);
void setup()
{
    WiFi.disconnect(true, true);
    delay(200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(MY_SSID, MY_SSID_PASSWORD);

    if (WiFi.waitForConnectResult() != WL_CONNECTED)
        return;

    WiFi.setAutoReconnect(true);
    Test.begin(115200, true, true ); // AsyncTelnetSerial::begin(unsigned long baudrate = 115200, bool LinkTelnetToSerial = true, bool enableMDNS = false);

    Serial.print("IP address: ");                                       
    Serial.println(WiFi.localIP()); // This prints the IP address

}


void loop()
{
    static int i = 0;
    Serial.printf("%d \n", i++);
    delay(1000);
}
