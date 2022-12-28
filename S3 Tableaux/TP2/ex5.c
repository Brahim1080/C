#include <stdio.h>
#include <stdlib.h>

#define MAXDIM 9

int main(){
    // Lecture des dimensions de la matrice
    printf("Entrez le nombre de lignes de la matrice:\n");
    int nombreLigne;
    scanf("%d",&nombreLigne);
    printf("Entrez le nombre de colonnes de la matrice:\n");
    int nombreColonne;    
    scanf("%d",&nombreColonne);

    // Generation de la matrice ligne par ligne
    char matrice1[MAXDIM][MAXDIM];
    
    for(int i = 0 ; i< nombreLigne; i++){
        for(int j = 0 ; j < nombreColonne ; j++){
            char caractere = 'A' + (int)(rand()/(RAND_MAX+1.0)*('Z'-'A'+1));
            
            matrice1[i][j] = caractere;
        }
    }

    // Affichage de la matrice
    printf("\n");
    printf("Affichage de la matrice generee aux hasard \n");
    for (int i=0; i<nombreLigne; i++) {
        for (int j=0; j<nombreColonne; j++)
            printf("%c  ", matrice1[i][j]);
        printf("\n");
    }
    printf("\n");

    // Calcul du nombre d'occurence pour chaque ligne 
    int count[MAXDIM][26] = {0};
    for (int i=0; i<nombreLigne; i++) {
        for (int j=0; j<nombreColonne; j++)
            count[i][matrice1[i][j]- 'A']++; // - A reference au tableau ascii 
       
    }
    
   // Affichage du nombre d'occurences par ligne
    printf("         ");
    for (char c='A'; c<='Z'; c++)
        printf(" %c",c);
    printf("\n\n");

    for (int i=0; i<nombreLigne; i++) {
        printf("Ligne %d: ",i+1);
        for (int j=0; j<26; j++)
            printf(" %d", count[i][j]);
        printf("\n");
       
    }
    
     printf("\n");

    exit(0);
    
}