#include <stdio.h>
#include <Windows.h>
#include <math.h>
#define PI 3.14159265358979323846

void gotoXY(int x, int y) {
	printf("\033[%d;%dH", y, x);
}

int main() {
	printf("(Bomb)----+");
	int posX = 11, posY = 1;
	double angle = 0.0;
	int length = 4;
	while (length > 0)
	{
		angle += 90.0;
		int dx = (int)(cos(angle * PI / 180.0));
		int dy = (int)(sin(angle * PI / 180.0));
		int count = 0;
		while (count < length)
		{
			posX += dx;
			posY += dy;
			gotoXY(posX, posY);
			if (count != length - 1)
			{
				printf("|");
			}
			else {
				printf("+");
			}
			count++;
		}
		angle += 90.0;
		dx = (int)(cos(angle * PI / 180.0));
		dy = (int)(sin(angle * PI / 180.0));
		count = 0;
		while (count < length)
		{
			posX += dx;
			posY += dy;
			gotoXY(posX, posY);
			if (count != length - 1)
			{
				printf("-");
			}
			else {
				printf("+");
			}
			count++;
		}

		length--;
	}
	gotoXY(posX, posY);
	printf("*");

	angle -= 180.0;

	while (length < 4)
	{
		int dx = (int)(cos(angle * PI / 180.0));
		int dy = (int)(sin(angle * PI / 180.0));
		int count = 0;
		while (count < length + 1)
		{
			Sleep(300);
			gotoXY(posX, posY);
			printf(" ");
			posX += dx;
			posY += dy;
			gotoXY(posX, posY);
			printf("*");
			count++;
		}
		angle -= 90.0;
		dx = (int)(cos(angle * PI / 180.0));
		dy = (int)(sin(angle * PI / 180.0));
		count = 0;
		while (count < length + 1)
		{
			Sleep(300);
			gotoXY(posX, posY);
			printf(" ");
			posX += dx;
			posY += dy;
			gotoXY(posX, posY);
			printf("*");
			count++;
		}
		angle -= 90.0;
		if (length > 2)
		{
			dx = (int)(cos(angle * PI / 180.0));
			dy = (int)(sin(angle * PI / 180.0));
			count = 0;
			while (count < length + 1)
			{
				Sleep(300);
				gotoXY(posX, posY);
				printf(" ");
				posX += dx;
				posY += dy;
				gotoXY(posX, posY);
				printf("*");
				count++;
			}

		}
		length++;
	}
	Sleep(300);
	gotoXY(posX, posY);
	printf(" ");

	gotoXY(1, 4);
	printf("^^^^^^^^^^^\n");
	printf("  !BOOM!\n");
	printf("^^^^^^^^^^^\n");
	return 0;
}