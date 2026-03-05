#include<stdio.h>
#include<conio.h>
#include<time.h>

int main()
{
    int key;
    double time_elapsed = 0.0;
    clock_t start,now;

    printf("Enter to start/stop stopwatch:");
    start = clock();//stores the initial clock ticks.
    while(key!=13)//13 is the ASCII code for Enter key.
    {
        now = clock();//stores the current clock ticks in now. 
        time_elapsed = (double)(now - start) / CLOCKS_PER_SEC;//Calculates the time elapsed in seconds.

        clrscr();
        printf("%.3lf seconds have elapsed.",time_elapsed);

        if(kbhit())
            key=getch();
    }

    return 0;
}