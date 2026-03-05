#include<stdio.h>
#include<time.h>

int main()
{
    int s,m,h,d,y;
    time_t now;
    long t;

    clrscr();

    now = time(NULL);//Passing NULL to only get a return value.
    t = (long)now;

    printf("Time in seconds since epoch: %ld seconds.",t);

    //Converting the time in seconds to years, days, hours, minutes and seconds.

    s = t % 60;//stores excess seconds in s.
    t = t / 60;//converts t to complete mins only.

    m = t % 60;//stores excess minutes in m.
    t = t / 60;//converts t to complete hours only.

    h = t % 24;//stores excess hours in h.
    t = t / 24;//converts t to complete days only.

    d = t % 365;//stores excess days in d.
    t = t / 365;//converts t to complete years only.

    y = t;//store the no. of years in y.

    sprintf(time_str,"%02d:%02d:%02d",h,m,s);

    printf("\nTime since epoch is %s",time_str);

    getch();
    return 0;
}
