#include <stdio.h>
#include <unistd.h>


int main(){
    /*fork a child proccess*/
    fork();

    /*fork another child proccess*/
    fork();

    /*and fork another*/
    fork();

    printf("Process ID: %d\n", getpid());

    return 0;
}