#include <stdio.h>
#include <stdlib.h>
#include "qsort.c"

int main(){

    char c;
    char *filename = "data.txt";
    FILE *fp;
    FILE *fp_2;
    FILE *fp_3;
    int count = 0;

    fp = fopen(filename,"r");

    if (fp == NULL){
        printf("ERROR: could not open file");
        return 1;
    }

    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;

    //printf("This file has %d lines\n", count);

    fclose(fp);

    fp_2 = fopen(filename,"r");
    char* row;
    ssize_t len =0;
    ssize_t read;
    int buffer[count];

    int i=0,j=0;
    while (((read = getline(&row, &len, fp_2)) != -1)&& (i<count)) {
            buffer[i]=atoi(row);
            i++;
    }

    fclose(fp_2);

    quicksort(buffer,0,count-1);
    for(j = 0;j<count;j++){
        printf("%d\n",buffer[j]);
    }

    fp_3 = fopen("data_sorted.txt","w");

    for(int i = 0; i < count ; i++){

        fprintf(fp,"%d\n",buffer[i]);

    }
    fclose(fp_3);
    return 0;
}