#include <conio.h>
#include"graphics.h"

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\tc\\bgi");
	circle(300, 300, 50);
	closegraph();
	getch();
}