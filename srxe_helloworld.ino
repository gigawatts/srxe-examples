#include <SmartResponseXE.h>

int TEXT_WIDTH = 384;
int TEXT_HEIGHT = 136;
int DRAW_WIDTH = 128;
int DRAW_HEIGHT = 136;

unsigned int counter = 0;
char buf[10];

void setup() {
  SRXEInit(0xe7, 0xd6, 0xa2); // initialize and clear display // CS, D/C, RESET

  // Next, you can draw some text or rectangles. The color can be 0-3 (0=off, 3=fully on)
  SRXEWriteString(60,2,"Hello World!", FONT_LARGE, 3, 0); // (int x, int y, char *szMsg, int iSize, int iFGColor, int iBGColor)
  SRXEWriteString(60,32,"Uptime:", FONT_LARGE, 3, 0); 
  
  // Draw a rectanle on each side of the screen
  SRXERectangle(0, 0, 17, 135, 0x1, 0x1); // (int x, int y, int cx, int cy, byte color, byte bFilled)
  SRXERectangle(110, 0, 17, 135, 0x1, 0x1);

  // Draw arrows pointing to the soft keys
  SRXEWriteString(0, 2,  "< A", FONT_LARGE, 3, 1);
  SRXEWriteString(0, 32, "< B", FONT_LARGE, 3, 1);
  SRXEWriteString(0, 62, "< C", FONT_LARGE, 3, 1);
  SRXEWriteString(0, 92, "< D", FONT_LARGE, 3, 1);
  SRXEWriteString(0, 122,"< E", FONT_LARGE, 3, 1);
  
  int charnum = 3;
  int rightColX = TEXT_WIDTH - (16 * charnum);
  SRXEWriteString(rightColX, 2,  "F >", FONT_LARGE, 3, 1);
  SRXEWriteString(rightColX, 32, "G >", FONT_LARGE, 3, 1);
  SRXEWriteString(rightColX, 62, "H >", FONT_LARGE, 3, 1);
  SRXEWriteString(rightColX, 92, "I >", FONT_LARGE, 3, 1);
  SRXEWriteString(rightColX, 122,"J >", FONT_LARGE, 3, 1);

  // Draw some rectangles with various fill and color
  SRXERectangle(25, 80, 15, 35, 0x3, 0x0);
  SRXERectangle(45, 80, 15, 35, 0x1, 0x1);
  SRXERectangle(70, 80, 15, 35, 0x2, 0x1);
  SRXERectangle(90, 80, 15, 35, 0x3, 0x1);

  // Draw a vertical and horizontal line
  SRXEVerticalLine(DRAW_WIDTH/2, DRAW_HEIGHT/2, DRAW_HEIGHT/2, 0x3); // int x, int y, int height, byte color // color options: 0x0 - 0x3
  SRXEHorizontalLine(17, DRAW_HEIGHT/2, 93, 0x3, 2); // (int x, int y, int length, byte color, int thickness)
}

void loop() {
  // convert counter integer to C string array
  memset (buf, 0, sizeof(buf));
  snprintf(buf, sizeof(buf)-1, "%u", counter);

  // clear the previous text and draw new text
  SRXEWriteString(171, 32, "      ", FONT_LARGE, 3, 0);
  SRXEWriteString(171, 32, buf, FONT_LARGE, 3, 0);
  delay(1000);
  counter++;
}
