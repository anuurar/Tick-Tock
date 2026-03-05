#include<stdio.h>
#include<conio.h>

void main()
{
    int key;
    clrscr();
    while(key!=27)//ASCII of Esc key.
    {
	clrscr();
	if(kbhit())
	{
	key = getch();
	printf("The ASCII value of the key pressed is: %d\n", key);
	getch();
	}
	printf("NO KEY IS PRESSED.");
    }
}