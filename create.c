#include <stdio.h>
#include <fcntl.h>
#include <signal.h>

int main()
{
    int fd1, fd2;
    fd1= creat("tex1.txt",0777);
    fd2= creat("text2.txt", 0777);
    while(1)
    {}
}