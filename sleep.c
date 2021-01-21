#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int signum) //signal handler
{
    printf("\n\nwaking up from sleep..caught signal... %d \n\n", signum);
    exit(1);
}

void sleepSimulator()
{
    struct sigaction action;
    action.sa_handler = sighandler; //setting/installing the signal handler
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_RESTART;

    if (sigaction(SIGINT, &action, NULL) == -1) //sigaction call to catch and handle interrupt
        perror("error in sigaction");
}

int main(int argc, char const *argv[])
{
    printf("\nstarting sleep simulator\n");
    sleepSimulator(5);
    while (1)
    {
        pause(); //taking an indefinite pause untill the interrupt is caught
    }

    return 0;
}
