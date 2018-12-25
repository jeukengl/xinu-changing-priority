/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

void process2(void){
    while(1){
        printf("\nProcess %d is running.",getpid());
        sleepms(5);
    }
}
void process3(void){
    while(1){
        printf("\nProcess %d is running.",getpid());
        sleepms(5);
    }
    
}
void process4(void){
    /*starving process */
    while(1){
        printf("\nPROCESS %d IS RUNNING.",getpid());
        printf("\nPRIORITY %d.",getprio(4));
    }
    
    
}
int main(void){
    resume(create(process2,4096,40,"process 2",0));
    resume(create(process3,4096,35,"process 3",0));
    resume(create(process4,4096,25,"process 4",0));
}
