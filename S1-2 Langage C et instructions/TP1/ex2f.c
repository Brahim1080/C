#include <stdlib.h>
#include <stdio.h>

int main(){

    int a =0;
    int b =0;
    
    int min;
    int max;
    
    while(a<= 0 || b <= 0 ){
        printf("Entrez deux entier simuler une division euclidienne \n");
        scanf("%d",&a);
        scanf("%d",&b);
        if(a > b){
        min = b;
        max = a;
        
        }else{
        min = a;
        max = b;
        }
        if( a <= 0 || b <= 0)
            printf("Vous ne pouvez pas mettre de 0 ");
        

    }
    
    printf("max = %d  min = %d\n",max,min);
    

    int quotient = 0;
    int fini = 0;
    int reste = 0;
    int maxConst = max;
    while(fini != 1){
        
        if(max < min){
            reste = max;
            fini = 1 ;
        }else{
            if(min == max){
                fini = 1;
            }
            max -= min;
            quotient++;
        }
        
    }
    printf("%d / %d = %d   reste = %d\n",maxConst,min,quotient,reste);

}