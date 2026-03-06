#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>

int main()
{
    int key=0;
    double time_elapsed = 0.0,wait_time;
    clock_t start,now;
    clrscr();

    printf("Enter no. of seconds to wait:");
    scanf("%lf",&wait_time);
    start = clock();//stores the initial clock ticks.
    while(time_elapsed < wait_time)
    {
	now = clock();//stores the current clock ticks in now.
	time_elapsed = (double)(now - start) / CLOCKS_PER_SEC;//Calculates the time elapsed in seconds.

	if(kbhit())
	{
	    clrscr();
	    printf("%.3lf seconds have elapsed.",time_elapsed);
	}
    }

    while(key!=27)//Until esc key is pressed.
    {
        if(kbhit())
        {
            key = getch();
        }
        sound(520);
        delay(1000);
        nosound();
    }

    return 0;
}