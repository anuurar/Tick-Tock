/*TickTock version 1.0*/
/*An application that uses functions from the time and dos header files to create a general clock application featuring a utc clock, alarm clock, timer and stopwatch.*/
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>

void UTCclock();
void timer();
void stopwatch();
void setAlarm();
int checkExit();//Loop control function that checks for esc key press

int main()
{
	int key = 0;
	while(key!=27)
	{
		clrscr();

		if(kbhit()) getch();//Buffer filter.
		//Right now this filter is used to filter the  excess input from timer.

		printf("What do you want to do?");
		printf("\n Press 1 for clock");
		printf("\n Press 2 for timer");
		printf("\n Press 3 for stopwatch");
		printf("\n Press 4 to set alarm clock");

		key = getch();

		if(key == 49) UTCclock();
		else if(key == 50) timer();
		else if(key == 51) stopwatch();
		else if(key == 52) setAlarm();
		else if(key == 27) printf("\nExiting...");
		else printf("\nInvalid Input!");

		delay(500);
	}
	return 0;
}

void UTCclock()
{
	time_t now;
	long t;
	int h,m,s;

	while(checkExit())
	{
		clrscr();

		now = time(NULL);//Pass null to just get the seconds

		t = (long)now;

		//Manually converting seconds passed from epoch to hours minutes and seconds which is automatically the time of the day.
		s = t % 60; //Storing excess seconds in s.
		t = t / 60; //Converting t to complete minutes only.

		m = t % 60; //Storing excess minutes in m.
		t = t / 60; //Converting t to complete hours only.

		h = h % 24; //Storing excess hours in h.

		printf("%02d:%02d:%02d",h,m,s);
		delay(50);
    }
}

void timer()
{
	clock_t start,now;
	double time_elapsed = 0.0,wait_time,time_left;

	clrscr();
	printf("Enter no. of secods to wait:");
	scanf("%lf",&wait_time);

	start = clock();//Storing the initial clock ticks.

	while(checkExit())
	{
		clrscr();
		now = clock();//Storing current clock ticks.

		time_elapsed = (double)(now - start) / CLOCKS_PER_SEC;//calculating time elspsed in seconds.

		time_left = wait_time - time_elapsed;

		printf("%.3lf",time_left);
		delay(50);

		if(time_left<=0.0) {printf("yo");break;}
	}

	//this filter was put just incase the above loop had any excess input.
	//if(kbhit()) getch();//Buffer filter.

	while(!kbhit())
	{
		sound(800);//plays a beep of 800 Hzs.
		delay(200);
		nosound();//Stops the sound.
		delay(800);
	}
}

void stopwatch()
{
	printf("\nStopwatch");
}

void setAlarm()
{
	printf("\nAlarm Clock");
}

int checkExit()
{
	int key = 0;

	if(kbhit())
		key = getch();

	if(key == 27)
		return 0;
	else
		return 1;
}