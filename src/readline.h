#pragma once 
#define START_BUF_SIZE 1024
#include <stdlib.h>
#include <stdio.h>

char *readline(void){
    int buffsize = START_BUF_SIZE;
    int pos = 0;
    
    char *line = (char *)malloc(buffsize);
    int c;

    if(!line){
        fprintf(stderr, "allocate error\n");
        exit(EXIT_FAILURE);
    }

    while(1){
        c = getchar();

        if(c == 'EOF' || c == '\n'){
            line[pos] = '\0';
            return line;
        }
        else{
            line[pos] = c;
        }
        pos++;  

        if(pos >= buffsize){
            buffsize *= 2;
            line = (char *)realloc(line, buffsize);
            if (!line){
                fprintf(stderr, "reallocate error");
                exit(EXIT_FAILURE);
            }
        }
    }
}