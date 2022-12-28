#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
PRE : t : tableau de longueur sz
POST : t représente un tableau trié contenant les sz premiers nombres premiers.
*/

/*
PRE : n >= 2
RES : true si le nombre est un nombre premier , false si l'inverse 
*/
bool is_prime_number(int x);

void first_prime_numbers(int* t,int sz);

int main (){

    int sz = 25;
    
    int* tab = (int*) malloc((sz)*sizeof(int));



    first_prime_numbers(tab,sz);
    printf("Tableau des nombres premiers plus petit que %d: \n",sz);
    for(int i = 0; i < sz ; i++){
        printf("%d  ",tab[i] );
    }

    printf("\n");

    free(tab);


}


void first_prime_numbers(int* t,int sz){
   
    int cptNbPremier = 0;
    int n = 2;
    while(cptNbPremier<sz){

        if(is_prime_number(n)){
            t[cptNbPremier] = n;
            cptNbPremier++;
            
        }
        n++;
    }

}

bool is_prime_number(int x){
    for(int i = 2 ; i <= x/2 ; i++){

        if(x % i == 0) {
            return false ;
        } 
    }

    return true;
}
