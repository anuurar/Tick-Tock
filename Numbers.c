#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>

void printnum(int number);

int main()
{
    int n;
    int GD=DETECT,GM;
    initgraph(&GD,&GM,"C:/TURBOC3/BGI");//Give the path to graphics driver... This is the default path for TURBOC.

    settextstyle(3,HORIZ_DIR/*VERT_DIR*/,9);//Sets the style, direction and size of the text in graphics mode.
    setcolor(1);//Sets the color of output in graphics mode ranging form 0 to 15 and then repeats in the same sequence for further numbers.

    //printf("%d*%d",getmaxx(),getmaxy());
    //A manual check revealed my screen to be 640*447 pixels despite getmax returning 639*479 for maximum pixel values. So x=[0,639] and y = [0,446].

    printf("Enter a number:");
    scanf("%d",&n);

    printnum(n);

    getch();

    return 0;
}

void printnum(int n)
{
	char number[50];

	sprintf(number,"%d",n);//Converts numbers to string
	//Printing the number.
    cleardevice();
	outtextxy(300,100,number);//Prints the text in graohics mode in specified x and y co-ords
}