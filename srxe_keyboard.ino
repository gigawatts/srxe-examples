#include <SmartResponseXE.h>

int TEXT_WIDTH = 384;
int TEXT_HEIGHT = 136;
int DRAW_WIDTH = 128;
int DRAW_HEIGHT = 136;

char Hbuf[10];
char Abuf[10];
char Ibuf[10];

void setup() {
  Serial.begin(9600);
  SRXEInit(0xe7, 0xd6, 0xa2); // initialize display // CS, D/C, RESET
  SRXEWriteString(0, 2, "Key pressed", FONT_LARGE, 3, 0);
  SRXEWriteString(0, 32, "ASCII:  ", FONT_LARGE, 3, 0);
  SRXEWriteString(0, 62, "Integer:", FONT_LARGE, 3, 0);
  SRXEWriteString(0, 92, "Hex:  0x", FONT_LARGE, 3, 0);
}

void loop() {
  byte key;
  if(key = SRXEGetKey()){
    Serial.print("Key pressed: ");
    Serial.println(key);

    memset (Hbuf, 0, sizeof(Hbuf));
    snprintf(Hbuf, sizeof(Hbuf)-1, "%x", key);
    
    memset (Abuf, 0, sizeof(Abuf));
    snprintf(Abuf, sizeof(Abuf)-1, "%c", key);

    memset (Ibuf, 0, sizeof(Ibuf));
    snprintf(Ibuf, sizeof(Ibuf)-1, "%i", key);

    int x = 129;
    SRXEWriteString(x, 32, "        ", FONT_LARGE, 3, 0);
    SRXEWriteString(x, 32, Abuf, FONT_LARGE, 3, 0);
    SRXEWriteString(x, 62, "        ", FONT_LARGE, 3, 0);
    SRXEWriteString(x, 62, Ibuf, FONT_LARGE, 3, 0);
    SRXEWriteString(x, 92, "        ", FONT_LARGE, 3, 0);
    SRXEWriteString(x, 92, Hbuf, FONT_LARGE, 3, 0);
  }
}
