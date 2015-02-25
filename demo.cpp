#include "stdafx.h"

#include <Windows.h>

#include "ROCCAT_Talk.h"
#include <iostream>

int redcolor;
int greencolor;
int bluecolor;

HDC hdcScreen = GetDC(0);

int main(){
	CROCCAT_Talk roccat;

	if (roccat.init_ryos_talk()){
		while (true){
			if (GetAsyncKeyState(VK_ESCAPE))
			{
				break;
			}
			COLORREF vari = GetPixel(hdcScreen, 124, 1052);

			redcolor = GetRValue(vari);
			greencolor = GetGValue(vari);
			bluecolor = GetBValue(vari);

			if (redcolor > 100 && greencolor < 50 && bluecolor < 50){
				roccat.turn_on_all_LEDS();
				redcolor = 255;
				greencolor = 0;
				bluecolor = 0;
			}
			else
			{
				roccat.turn_off_all_LEDS();
				redcolor = 0;
				greencolor = 0;
				bluecolor = 0;
			}

			roccat.Set_LED_RGB(0x01, 0x01, 0x01, ("0x%x\n", redcolor), ("0x%x\n", greencolor), ("0x%x\n", bluecolor));
		}
		roccat.RestoreLEDRGB();
	}
}