#include <stdlib.h>
#include <stdio.h>

/*
RES : le maximum entre x et y
*/
int max(int x , int y);

int main(){
    int x ;
    int y ; 

    printf("Entrez deux nombres \n");
    scanf("%d",&x);
    scanf("%d",&y);

    int nbmax = max(x,y);

    printf("Le max est %d\n",nbmax);


}


int max(int x , int y){
    if(x>y) return x;
    else return y;
}