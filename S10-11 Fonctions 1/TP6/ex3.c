#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


/*
PRE : n >= 2
POST : *sz est égal à la taille physique du tableau renvoyé par cette fonction
RES : un tableau trié contenant tous les nombres premiers strictement plus petits
que n si aucune erreur n’est survenue et NULL si une erreur est survenue.
*/
int* prime_numbers (int n, int* sz);

/*
PRE : n >= 2
RES : true si le nombre est un nombre premier , false si l'inverse 
*/
bool is_prime_number(int x);


int main(){

    int sz = 0;

    int* tab = prime_numbers(100,&sz);

    //int estNbrPrem = is_prime_number(11);

    printf("Tableau des nombres premiers plus petit que 100: \n");
    for(int i = 0; i < sz ; i++){
        printf("%d  ",tab[i] );
    }

    printf("\n");
   
   

    free(tab);
   

}

int* prime_numbers(int n , int* sz){


    //Pour changer la taille sz à chaque nombre premier qu'on trouve
    for(int i = 2 ; i <= n ; i++){

        printf("%d\n",i);
        if(is_prime_number(i) == true){
            *sz= *sz+1;
        }
    }
    //printf("nb de nbr premier avant 100 : %d\n",*sz);
    int* tab = (int*) malloc((*sz)*sizeof(int));

    int cptNbPremier = 0;
    for(int i = 2; i< n;i++){
      
        if(is_prime_number(i) == true){
            tab[cptNbPremier] = i;
            cptNbPremier++;
        }

    }
    return tab;
}

bool is_prime_number(int x){
    for(int i = 2 ; i <= x/2 ; i++){

        if(x % i == 0) {
            return false ;
        } 
    }

    return true;
}