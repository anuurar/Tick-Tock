#include<stdio.h>
#include<time.h>

int main()
{
    time_t now;
    long t;
    now = time(NULL);//Passing NULL to only get a return value.
    t = (long)now;
    printf("%ld",t);

    return 0;
}
