#include "iostream.h"
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "dos.h"
#include "graphics.h"
#include "string.h"

void Draw_Graphic(int N, int X1, int X2, int Y1, int Y2, double x0, double xm, double dx, float& Fmax)
{
	double x;
	float F;
	int i;
	for (x = x0; x <= xm; x += dx)
	{
		F = (float)(pow((cos(x)), 2.0) + sqrt(x));
		if (Fmax < F)
			Fmax = F;
	}
	for (i = 0, x = x0; i < N; i++, x += dx)
	{
		F = (float)(pow((cos(x)), 2.0) + sqrt(x));
		putpixel(X1 + i + 47, Y2 - (int)((float)(Y2 - Y1) / (9.0 / F)), GREEN);
	}
}

int main()
{
	clrscr();
	int driver = DETECT, mode;
	initgraph(&driver, &mode, "c:\\turboc3\\bgi");
	int Xmax = getmaxx(), Ymax = getmaxy();
	int X1 = 40, X2 = Xmax - 40, Y1 = 50, Y2 = Ymax - 70, N = X2 - X1 - 47 - 26;
	float F, Fmax = 0.;
	double x0 = 3.14 / 2, xm = 5 * 3.14, dx = (xm - x0) / (N);
	setlinestyle(0, 1, 3);
	setcolor(BLUE);
	rectangle(18, 18, Xmax - 18, Ymax - 18);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(20, 20, BLUE);
	Draw_Graphic(N, X1, X2, Y1, Y2, x0, xm, dx, Fmax);
	setcolor(WHITE);
	setlinestyle(0, 1, 1);
	line(X1, Y2, X1, Y1);
	line(X1, Y2, X2, Y2);
	setcolor(YELLOW);
	outtextxy(X1 + 8, Y1 - 7, "F(x)");
	outtextxy(X2 + 8, Y2 - 4, "X");
	setcolor(WHITE);
	outtextxy(X1 - 10, Y2 + 5, "0");

	int i;
	for (i = 1; i < 19; ++i)
		line(X1 - 5, Y2 - i * 20, X1 + 5, Y2 - i * 20);
	for (i = 1; i < 29; ++i)
		line(X1 + 20 * i, Y2 + 5, X1 + 20 * i, Y2 - 5);

	char xi[14][2];
	for (i = 4; i < 57; i += 4)
	{
		sprintf(xi[i / 4 - 1], "%d", i);
		outtextxy(X1 + 18 * i / 2 + i - 3, Y2 + 7, xi[i / 4 - 1]);
	}

	char yi[14][2];
	for (i = 2; i < 19; i += 2)
	{
		sprintf(yi[i / 2 - 1], "%d", i / 2);
		outtextxy(X1 - 20, Y2 - 20 * i - i / 4, yi[i / 2 - 1]);
	}

	char cFmax[10], str[24];
	sprintf(cFmax, "%f", Fmax);
	strcpy(str, "Fmax = ");
	strcat(str, cFmax);
	setcolor(YELLOW);
	outtextxy(30, Ymax - 35, "F = cos(x)^2 + sqrt(x)");
	outtextxy(300, Ymax - 35, str);
	getch();
	closegraph();
	return 0;
}