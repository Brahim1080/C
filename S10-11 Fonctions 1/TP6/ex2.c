#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


/*
PRE : t : tableau de longueur sz
RES : true si le t contient un élément x, false sinon
*/
bool search (int* t, int sz, int x);

int main(){

    int* tab = (int*) malloc(5*sizeof(int));

    for(int i = 0 ; i < 5 ; i++){
        tab[i] = i ; 

    }
    // Return true
    bool contient = search(tab,5,2);

    printf("%d\n",contient);
    free(tab);


}

bool search (int* t, int sz, int x){

    for(int i = 0 ; i < sz ; i++){
        if(t[i] == x){
           return true;
        }
    }
    return false;
}