
#define _GNU_SOURCE
#include<stdio.h>
#include<linux/kernel.h>
#include<sys/syscall.h>
#include<unistd.h>
#include<errno.h>
#include <sys/types.h>
#include <inttypes.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/stat.h>
#define sys_writer 450
int main(){
    int RandomV = open("/dev/urandom", O_RDONLY);
    if (RandomV < 0)
    {
        perror("");
    }
    char buffer[8];
    long final = *(long *) &buffer[0];
    // long buffer[8];
    while(1){
        int a=read(RandomV, buffer, sizeof(buffer));
        if(a < 0){
            exit(1);
        }
        long final = *(long *) &buffer[0];
        syscall(450,final);
        sleep(2);
        unsigned char * p = (unsigned char*)&final;
        printf("Enqueued in char: %s\n", p);
        printf("Enqueued in long: %ld\n",final);

        
    }
}