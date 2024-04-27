#include <SPI.h>
#include <mcp2515.h>
#define pin 10

int rndNumber;
struct can_frame WE;

MCP2515 mcp2515(pin);

void setup()
{
  SPI.begin();
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
}

void loop()
{
  rndNumber = random(1, 100);
  WE.can_id = 0x12;
  WE.can_dlc = 8;
  WE.data[0] = rndNumber;
  WE.data[1] = 0x12;
  WE.data[2] = 0x34;
  WE.data[3] = 0x56;
  WE.data[4] = 0x78;
  WE.data[5] = 0x65;
  WE.data[6] = 0x43;
  WE.data[7] = 0x21;
  mcp2515.sendMessage(&WE);
  delay(2000);
}
