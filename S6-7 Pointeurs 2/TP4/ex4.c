#include <stdio.h>
#include <stdlib.h>

int main(){

    int **image;
    int hauteur, largeur;
    printf("Hauteur : ? ");
    scanf("%d",&hauteur);
    printf("largeur : ? ");
    scanf("%d",&largeur);
    printf("\n");

    image = (int**) malloc(hauteur*sizeof(int*));

    
    if(image == NULL) {
        perror("Probleme memoire!\n");
        exit(1);
        
    }
    for(int i= 0 ; i < largeur; i++){
        //Allocation pour chaque ligne 
        image[i] =  (int*) malloc(largeur* sizeof(int));
        if (image[i] == NULL){
            perror("Probleme memoire!\n");
            exit(1);
        }

    }

    //initialisation de la matrice
     for(int i = 0 ; i < hauteur ; i ++){
        for(int j = 0 ; j < largeur ; j ++){
            //image[i][j] =  rand() % 256; op1

            image[i][j] =  j+1 % 256; 
        }
    }

    //print de l'image
    /*for(int i = 0 ; i < hauteur ; i ++){
            for(int j = 0 ; j < largeur ; j ++)
                printf("%d  ",image[i][j]); 
            printf("\n");
    }*/
    //op3
    for(int **ptr = image ; ptr - image < hauteur ; ptr ++){

            for(int* ptrLigne = *ptr ; ptrLigne - *ptr < largeur ; ptrLigne ++)
                printf("%d  ", *ptrLigne); 
            printf("\n");
    }
    // Liberation de la memoire 
    for (int i = 0; i < hauteur; i++)
        free(image[i]);
    free(image);




}