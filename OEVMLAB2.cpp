#include "conio.h"
#include "iostream.h"
#include "stdio.h"
#include "dos.h"
#include "stdlib.h"
#include "time.h"

union type
{
    unsigned long long II;
    long double d;
};
void printLongDouble(long double x)
{
    type m;
    m.d = x;
    for (int i = 16 * sizeof(m.II) - 1; i > -1; i--)
    {
	cprintf("%d", m.II >> i & 1);
    }
    cprintf("\n\r");
}

void scroll(int direction, int lines, char I_row, char I_col, char r_row, char r_col)
{
    union REGS r;
    if (direction)
    {
	r.h.al = lines;
	r.h.ah = direction;
    }
    else
    {
	r.h.al = lines;
	r.h.ah = 6;
    }
    r.h.ch = I_row;
    r.h.cl = I_col;
    r.h.dh = r_row;
    r.h.dl = r_col;
    int86(0x11, &r, &r);
}

void GetPrintColor(unsigned char colors)
{
    unsigned char bg = colors >> 4;
    unsigned char text = colors & 15;
    switch (bg)
    {
    case 0:
	cprintf("Background: Black\n");
	break;
    case 1:
	cprintf("Background: Blue\n");
	break;
    case 2:
	cprintf("Background: Green\n");
	break;
    case 3:
	cprintf("Background: Cyanic\n");
	break;
    case 4:
	cprintf("Background: Red\n");
	break;
    case 5:
	cprintf("Background: Purple\n");
	break;
    case 6:
	cprintf("Background: Brown\n");
	break;
    case 7:
	cprintf("Background: Light-gray\n");
	break;
    case 8:
	cprintf("Background: Dark-gray\n");
	break;
    case 9:
	cprintf("Background: Light-blue\n");
	break;
    case 10:
	cprintf("Background: Light-green\n");
	break;
    case 11:
	cprintf("Background: Light-cyanic\n");
	break;
    case 12:
	cprintf("Background: Light-red\n");
	break;
    case 13:
	cprintf("Background: Light-purple\n");
	break;
    case 14:
	cprintf("Background: Yellow\n");
	break;
    case 15:
	cprintf("Background: White\n");
	break;
    }

    switch (text)
    {
    case 0:
	cprintf("\rTextcolor: Black\r");
	break;
    case 1:
	cprintf("\rTextcolor: Blue\r");
	break;
    case 2:
	cprintf("\rTextcolor: Green\r");
        break;
    case 3:
        cprintf("\rTextcolor: Cyanic\r");
        break;
    case 4:
        cprintf("\rTextcolor: Red\r");
        break;
    case 5:
        cprintf("\rTextcolor: Purple\r");
        break;
    case 6:
        cprintf("\rTextcolor: Brown\r");
        break;
    case 7:
        cprintf("\rTextcolor: Light-gray\r");
        break;
    case 8:
        cprintf("\rTextcolor: Dark-gray\r");
        break;
    case 9:
        cprintf("\rTextcolor: Light-blue\r");
        break;
    case 10:
        cprintf("\rTextcolor: Light-green\r");
        break;
    case 11:
        cprintf("\rTextcolor: Light-cyanic\r");
        break;
    case 12:
        cprintf("\rTextcolor: Light-red\r");
        break;
    case 13:
        cprintf("\rTextcolor: Light-purple\r");
        break;
    case 14:
        cprintf("\rTextcolor: Yellow\r");
        break;
    case 15:
        cprintf("\rTextcolor: White\r");
        break;
    }

}

int main()
{
    clrscr();
    char t;
    long double inputLongDouble;
    scroll(1, 0, 0, 0, 25, 80);
    window(25, 5, 55, 15);
    textattr(0);
    scroll(1, 0, 9, 19, 19, 59);
    cprintf("\n\n\n\n\n\n\n\n\r");
    do
    {
        unsigned char i = 0;
        do
        {
            textattr(i);
            inputLongDouble = ((0.956358714) * (rand() % 12501));
            printLongDouble(inputLongDouble);
            GetPrintColor(i);
            i++;
            delay(300);
            scroll(1, 1, 9, 19, 19, 59);
        } while (i < 127);
        cprintf("What's next? (y - work again / n - exit): ");
        do
        {
            cscanf("%c", &t);
        } while (t != 'y' && t != 'n');
    } while (t == 'y');

    cprintf("\n\r --- DONE! ---- \n\r");
    getch();
    return 0;
}


