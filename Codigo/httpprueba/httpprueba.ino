#include <EtherCard.h>

#define HTTP_HEADER_OFFSET 0
static byte mymac[] = {0x12,0x34,0x56,0x78,0x90,0xAB};
const char website[] PROGMEM = "http://localhost:9002/api/tasks";

byte Ethernet::buffer[700];
static uint32_t timer = 0;

static void response_callback (byte status, word off, word len) {
  Serial.print((const char*) Ethernet::buffer + off + HTTP_HEADER_OFFSET);
} 

void setup () {
  Serial.begin(57600);

  if (!ether.begin(sizeof Ethernet::buffer, mymac, 10))
  {
    Serial.println("Failed to access Ethernet controller");
    while(1);
  }
  else
    Serial.println("Ethernet controller initialized");
  Serial.println();

  if (!ether.dhcpSetup())
  {
    Serial.println("Failed to get configuration from DHCP");
    while(1);
  }
  else
    Serial.println("DHCP configuration done");

  if (!ether.dnsLookup(website))
  {
    Serial.println("DNS failed");
    while(1);
  }
  else 
    Serial.println("DNS resolution done"); 

  ether.printIp("SRV IP:\t", ether.hisip);
  Serial.println();
}

void loop() {
  ether.packetLoop(ether.packetReceive());

  if (millis() > timer) {
    timer = millis() + 5000;
    ether.browseUrl("/", "yourpage.php", website, response_callback);
  }
}
