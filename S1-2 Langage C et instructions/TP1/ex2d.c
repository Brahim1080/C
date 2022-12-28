#include <stdlib.h>
#include <stdio.h>

int main(){

    char caractere = 'A';
    do{
    printf("Caractere = '%c'    code dec = %d    code hexa = %x  \n", caractere , caractere , caractere);
        caractere++;
    }while(caractere <= 'Z');


    
    for(char i = '1'; i<= '9' ; i++){
        printf("Caractere = '%c'    code dec = %d    code hexa = %x  \n", i,i,i);
    }
    exit(0);
}