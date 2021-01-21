#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void my_handler(int signo){
        printf("Signal caught is %d", signo);

    }

int main()
{
    (void) signal (SIGINT, my_handler);

    while(1)
    {
        printf("hello babua..!");
    }

}
