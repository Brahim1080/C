#include <stdlib.h>
#include <stdio.h>

/* 3.a Permuter */
void permuter(int* a, int* b);

/* 3.b  Permuter des chaines de caracteres */
void permuterChaine(char ** char1 , char ** char2);

/* 3.c permuter deux table d'entier */
void permuterTableEntier(int** t1, int** t2);

int main (){
    int a = 2;
    int b = 5;

    printf("**Permutation d'entier**\n");
    printf("Avant permutation :\t a = %d \t b = %d\n",a,b);
    permuter(&a,&b);
    printf("Apres permutation :\t a = %d \t b = %d\n\n",a,b);

    printf("**Permutation de chaines de caracteres**\n");
    char* char1;
    char* char2;
    char1 = "Hello";
    char2 = "Test";
    printf("Avant permutation :\t char1 = %s \t char2 = %s\n",char1,char2);
    permuterChaine(&char1,&char2);
    printf("Apres permutation :\t char1 = %s \t char2 = %s\n\n",char1,char2);


    printf("**Permutation deS tableau d'entier**\n");
    int* tab1;
    int* tab2;
    int tailleTab = 4 ;
    if((tab1 =(int*) malloc(tailleTab*sizeof(int)))== NULL){
        exit(1);
    }

    if((tab2 =(int*) malloc(tailleTab*sizeof(int)))== NULL){
        exit(1);
    }
    int nb = 3;
    for(int* p = tab1 ; p - tab1 < tailleTab ; p++){
        *p = nb;
        nb *= 4;
    }
    nb = 6;
    for(int* p = tab2 ; p - tab2 < tailleTab; p++){
        *p = nb;
        nb *= 7;
    }
    printf("Avant permutation :\n");
    printf("Affichage du tableau 1 : ");
    for(int i= 0 ; i<tailleTab ; i++)
        printf("%d ",tab1[i]);

    
    printf("\n");
    printf("\nAffichage du tableau 2 : ");
    for(int i= 0 ; i<tailleTab ; i++)
        printf("%d ",tab2[i]);
    printf("\n\n");

    permuterTableEntier(&tab1,&tab2);

    printf("Apres permutation :\n");
    printf("Affichage du tableau 1 : ");
    for(int i= 0 ; i<tailleTab ; i++)
        printf("%d ",tab1[i]); 
    printf("\n");
    printf("\nAffichage du tableau 2 : ");
    for(int i= 0 ; i<tailleTab ; i++)
        printf("%d ",tab2[i]);

    printf("\n");
    
    free(tab1);
    free(tab2);


}

void permuter(int* a, int* b){
    
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permuterChaine(char ** char1 , char ** char2){

    char* temp = *char1;
    *char1 = *char2;
    *char2 = temp;

}

void permuterTableEntier(int** t1, int** t2){
    int * temp = *t1;
    *t1 = *t2;
    *t2 = temp;
}