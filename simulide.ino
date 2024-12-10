#include <Adafruit_NeoPixel.h>

#define PIN 2 // input pin Neopixel is attached to

#define NUMPIXELS 300 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // timing delay in milliseconds

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

int headRedColor = 255; // Head LED color
int headGreenColor = 0;
int headBlueColor = 0;

int arrayInput[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int ledStartIndex[] = {
    280,
    279,
    240,
    239,
    200,
    199,
    160,
    159,
    120,
    119,
    80,
    79,
    40,
    39,
    0};

void setup()
{
  pixels.begin();
}

void ledRun(int index)
{
  int ledIndex = ledStartIndex[index];
  for (int j = 0; j < 20; j++)
  {
    if (index % 2 == 0)
    {
      if (j == 0)
      {
        turnOnLED(ledIndex + j, headRedColor, headGreenColor, headBlueColor);
      }
      else
      {
        turnOnLED(ledIndex + j, redColor, greenColor, blueColor);
      }
    }
    else
    {
      if (j == 0)
      {
        turnOnLED(ledIndex - j, headRedColor, headGreenColor, headBlueColor);
      }
      else
      {
        turnOnLED(ledIndex - j, redColor, greenColor, blueColor);
      }
    }
  }
}

void turnOnLED(int ledIndex, int r, int g, int b)
{
  pixels.setPixelColor(ledIndex, pixels.Color(r, g, b));
  pixels.show();
}

void setColor()
{
  redColor = random(0, 255);
  greenColor = random(0, 255);
  blueColor = random(0, 255);
}

void loop()
{
  setColor();
  while (1)
  {
    // for (int i = 0; i < 15; i++)
    // {
    //   delay(500);
    // }
    ledRun(14);
  }
}