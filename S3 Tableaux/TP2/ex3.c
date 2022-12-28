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
    int cpt = 0;

    for(int i = 0 ; i< nombreLigne; i++){
        for(int j = 0 ; j < nombreColonne ; j++){
            matrice1[i][j] = 'A' + cpt;
            cpt = (cpt + 1) % 26; //Apres Z retourne a A
        }
    }

    // Affichage de la matrice
    printf("\n");
    printf("Affichage ligne par ligne \n");
    for (int i=0; i<nombreLigne; i++) {
        for (int j=0; j<nombreColonne; j++)
            printf("%c  ", matrice1[i][j]);
        printf("\n");
    }
    printf("\n");

    // Generation de la matrice colonne par colonne 
    char matrice2 [MAXDIM][MAXDIM];
    cpt = 0;
    for(int i = 0 ; i< nombreColonne; i++){
        for(int j = 0 ; j < nombreLigne ; j++){
            matrice2[j][i] = 'A' + cpt;
            cpt = (cpt + 1) % 26; //Apres Z retourne a A
        }
    }

    // Affichage de la matrice
    printf("\n");
    printf("Affichage colonne par colonne \n");
    for (int i=0; i<nombreLigne; i++) {
        for (int j=0; j<nombreColonne; j++)
            printf("%c  ", matrice2[i][j]);
        printf("\n");
    }
    printf("\n");

    // Affichage des valeurs indentiques 
    for(int i = 0; i < nombreLigne ; i++){
        for(int j= 0; j < nombreColonne ; j++){
            
            if(matrice1[i][j] == matrice2[i][j]){
                
                printf("%c en ligne %d et colonne %d\n", matrice2[i][j], i, j);
            }
                
        }
    }

    printf("\n");

    exit(0);
    
}