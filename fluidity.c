#include<stdio.h>
#include<dos.h>

int main()
{
    int i;

    printf("Without delay");
    getch();
    for(i=0;i<100;i++)
    {
	clrscr();
	printf("%d",i);
    }

    printf("With delay");
    getch();

    for(i=0;i<100;i++)
    {
	clrscr();
	printf("%d",i);
	delay(50);//delays 50 millisecconds for flluid display of numbers.
    }

    getch();
    return 0;
}