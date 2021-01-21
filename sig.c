//to compil, run below command
// gcc -o sig sig.c 
#include<stdio.h>
#include<signal.h>
#include<assert.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

static clock_t start;
char lines[10][100]={};
//memset(lines, '0', (sizeof lines[0][0])*10*100); 
int timer = 0;

void handle_alarm(int sig){
    timer+=10;
    printf("tick %d\n",timer);    
    alarm(10);
}

void sigint_handler(int sig){
    clock_t end = clock();
    double totaltime = (double)(end-start)/ CLOCKS_PER_SEC;
    printf("total time spent by program is : %lf \n", totaltime);
    
}

void sigterm_handler(int sig){
    clock_t end = clock();
    double totaltime = (double)(end-start)/ CLOCKS_PER_SEC;
    printf("total time spent by program is : %lf \n", totaltime);
    exit(0);
}

void sigtstp_handler(int sig){
    printf("Last 10 lines of the input \n");
    for(int i=0; i<10; i++){
        printf("%s",lines[i]);
    }
    exit(0);

}


void main(){
    char input[100];
    start = clock();     
    signal(SIGINT,sigint_handler);
    signal(SIGALRM,handle_alarm);
    signal(SIGTERM, sigterm_handler);
    signal(SIGTSTP, sigtstp_handler);
    printf("tick %d \n", timer);
    alarm(10);
    while(1){
        for(int i=0;i<10;i++){
        fgets(input,sizeof(input), stdin);
        printf("%s \n",input);
        strcpy(lines[i], input);
        }
        memset(lines,0,sizeof(lines)); ;
    }

}