#include <stdlib.h>
#include <stdio.h>

int main(){

    int a = 1080;
    int b = 1000;
    printf("Les deux variable avant : \na = %d",a);
    printf("\nb = %d",b);
    printf("\nEntrez deux entiers\n");
    int aTemp;
    scanf("%d",&aTemp);
    a = aTemp;
    int bTemp;
    scanf("%d",&bTemp);
    b = bTemp;
    printf("les deux variables apres : \na = %d",a);
    printf("\nb = %d\n",b);
    exit(0);
}