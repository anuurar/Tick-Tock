/*TickTock version 1.0*/
/*An application that uses functions from the time and dos header files to create a general clock application featuring a utc clock, alarm clock, timer and stopwatch.*/
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>

int count_alarms=0;//Global count of number of alarms set.
long alarm_seconds[100];//Global array to store alarms in seconds only from 00:00:00.

void initialize();//Function to initiakize clock settings and alarms
void UTCclock();
void timer();
void stopwatch();
void setAlarm();
void checkAlarm();
int checkExit();//Loop control function that checks for esc key press
void ring();//Rings until a key is pressed.

int main()
{
	int key = 0;
	clrscr();

	initialize();//Initializing the clock settings and alarm timigs.

	while(key!= 27)
	{
		clrscr();

		//if(kbhit()) getch();//Buffer filter.
		//This filter was used to filter the  excess input from timer.

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
		else if(key == 27) {printf("\nExiting...");delay(500);}
		else {printf("\nInvalid Input!");delay(500);}
	}
	return 0;
}

void initialize()
{
	FILE *fp;

	fp = fopen("Alarms.dat","rb");

	if(fp)//If file exists.
	{
		fread(&count_alarms,sizeof(count_alarms),1,fp);
		fread(alarm_seconds,sizeof(alarm_seconds),count_alarms,fp);
	}
	else
	{
		printf("Aww!! There are no alarms set... Why not set some? :D");
		delay(2000);
		clrscr();
	}

	fclose(fp);
}

void UTCclock()
{
	time_t now;
	long t;
	int h,m,s;

	while(checkExit())
	{
		clrscr();
		checkAlarm();//Checks if any alarm nneds to be rung.

		now = time(NULL);//Pass null to just get the seconds

		t = (long)now;

		//Manually converting seconds passed from epoch to hours minutes and seconds which is automatically the time of the day.
		s = t % 60; //Storing excess seconds in s.
		t = t / 60; //Converting t to complete minutes only.

		m = t % 60; //Storing excess minutes in m.
		t = t / 60; //Converting t to complete hours only.

		h = t % 24; //Storing excess hours in h.

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
		checkAlarm();

		now = clock();//Storing current clock ticks.

		time_elapsed = (double)(now - start) / CLOCKS_PER_SEC;//Calculating time elspsed in seconds.

		time_left = wait_time - time_elapsed;

		printf("%.3lf",time_left);
		delay(50);

		if(time_left<=0.0) break;
	}

	//this filter was put just incase the above loop had any excess input.
	//if(kbhit()) getch();//Buffer filter.

	printf("Time's Up!!");
	ring();
}

void stopwatch()
{
	clrscr();

	while(checkExit())
	{
		clrscr();
		checkAlarm();

		printf("\nStopwatch");
		delay(50);
	}
}

void setAlarm()
{
	FILE *fp;
	int h,m;

	clrscr();

	fp = fopen("Alarms.dat","wb");

	clrscr();
	checkAlarm();

	printf("\nEnter the Alarm hour and minutes you want to set:");
	scanf("%d %d", &h, &m);

	alarm_seconds[count_alarms] = h*3600 + m*60;//Converting the alarm time to seconds only.
	count_alarms++;
	fwrite(&count_alarms,sizeof(count_alarms),1,fp);
	fwrite(alarm_seconds,sizeof(alarm_seconds),count_alarms,fp);

	fclose(fp);
}

void checkAlarm()
{
	long t,current_seconds;
    time_t now;
	int i;

    now = time(NULL);
    t =(long)now;

    current_seconds = t % 86400;//Gets the seconds passed today

	for(i=0;i<count_alarms;i++)
	{
	if(alarm_seconds[i] == current_seconds)
	{
		ring();
	}
	}
}

int checkExit()
{
	int key = 0;

	if(kbhit()) key = getch();

	if(key == 27)
		return 0;
	else
		return 1;
}

void ring()
{
	while(!kbhit())
	{
		sound(800);//Plays a beep of 800 Hzs.
		delay(200);
		nosound();//Stops the sound.
		delay(800);
	}

	//This buffer filter replaces all else filter.
	if(kbhit()) getch();//Buffer filter.

	sound(650);
	delay(300);
	nosound();
}