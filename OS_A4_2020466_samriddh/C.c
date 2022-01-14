
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
#define sys_reader 449
int main(){
    while(1){
        
        long abc=syscall(449,10000L);
        unsigned char * p = (unsigned char*)&abc;
        printf("Dequeued in char: %s\n", p);
        
        printf("Dequeued in long: %ld\n",abc);
        sleep(2);
    }


}