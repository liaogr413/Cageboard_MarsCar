int  Distance;
int  Dtime;
float ultrasonic_distance_9_10() 
{
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  delayMicroseconds(5);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);
  unsigned long sonic_duration = pulseIn(10, HIGH);
  float distance_cm = (sonic_duration / 2.0) / 29.1;
  return distance_cm;
}

float  Dist;
#include <moto_NeoPixel.h>
moto_NeoPixel strip13= moto_NeoPixel(2,13, NEO_GRB + NEO_KHZ800);
void colorled13(int number,String c)
{
	long rgb_number = strtol(&c[1], NULL, 16);
   int r = rgb_number >> 16;
   int g = rgb_number >> 8 & 0xFF;
   int b = rgb_number & 0xFF;
   if(number <= 0) number = 0;
      else  number--;
   strip13.setPixelColor(number,strip13.Color(r,g,b));
   strip13.show();
}

/**
 * 描述此函式...
 */
void forward() 
{
  digitalWrite(7,LOW);
  analogWrite(5,120);
  digitalWrite(4,HIGH);
  analogWrite(6,115);
}

/**
 * 描述此函式...
 */
void stop2() 
{
  analogWrite(5,0);
  analogWrite(6,0);
}

void setup()
{
  pinMode(12, INPUT);
    if (digitalRead(12) == 1) 
	{
	}
  pinMode( 9 , OUTPUT);
  pinMode( 10 , INPUT);
  strip13.begin();
  strip13.show();
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
}


void loop()
{
    delay(100);
    Dist = ultrasonic_distance_9_10( );
    if (Dist < 10) 
	{
      delay(20);
      stop2();
      for (int count = 0; count < 20; count++) 
	  {
        colorled13(1,"#cc33cc");
        colorled13(2,"#cc33cc");
        delay(100);
        colorled13(1,"#000000");
        colorled13(2,"#000000");
        delay(100);
      }
    } 
	else if (Dist < 30) 
	{
      forward();
      colorled13(1,"#ff0000");
      colorled13(2,"#ff0000");
    } 
	else if (Dist < 50) 
	{
      forward();
      colorled13(1,"#ffff00");
      colorled13(2,"#ffff00");
    } 
	else if (Dist < 100) 
	{
      forward();
      colorled13(1,"#33cc00");
      colorled13(2,"#33cc00");
    } 
	else 
	{
      forward();
      colorled13(1,"#33ccff");
      colorled13(2,"#33ccff");
    }

}
