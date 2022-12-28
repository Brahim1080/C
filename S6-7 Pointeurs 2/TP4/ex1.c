#include <stdio.h>
#include <stdlib.h>

int main(){

    char **cases;
    int hauteur,largeur;
    
    printf("Hauteur : ? ");
    scanf("%d",&hauteur);
    printf("largeur : ? ");
    scanf("%d",&largeur);
    printf("\n");

    // Allocation de la matrice
    cases = (char**)malloc(hauteur* sizeof(char*));

    // Allocation du tableau de position
    int* remplissageCol = (int *)malloc(largeur*sizeof(int));

    if(cases == NULL || remplissageCol == NULL) {
        perror("Probleme memoire!\n");
        exit(1);
        
    }

    for(int i= 0 ; i < largeur; i++){
        //Allocation pour chaque ligne 
        cases[i] =  (char*) malloc(largeur* sizeof(char));
        if (cases[i] == NULL){
            perror("Probleme memoire!\n");
            exit(1);
        }

    }

    // Initialisation de la matrice
    for(int i = 0 ; i < hauteur ; i ++){
        for(int j = 0 ; j < largeur ; j ++){
            cases[i][j] = '.' ; 
        }
    }
    // ?
    for (int j = 0; j < largeur; j++)
        remplissageCol[j] = hauteur-1;


    // Jeu
    char pionJoueur = 'X';
    char pionJouePas = 'O';
    int colJoueur;

    do{
        // Permutation des joueurs
        char temp = pionJoueur;
        pionJoueur = pionJouePas;
        pionJouePas = temp;

         // print de la matrice 
        for(int i = 0 ; i < hauteur ; i ++){
            for(int j = 0 ; j < largeur ; j ++)
                printf("%2c ",cases[i][j]); 
            printf("\n");
        }

        // Lecture de la colonne a jouer
        printf("\nColonne joueur %c ? ", pionJoueur);
        scanf("%d", &colJoueur);

        // Cas de la colonne pleine
        if (colJoueur>0 && colJoueur<=largeur && remplissageCol[colJoueur-1] < 0){
            printf("Colonne pleine! Tu passes ton tour!\n");
            continue;
        }

         // Cas de placement d'un pion
        if (colJoueur>0 && colJoueur<=largeur){
            // remplasse le . par X ou O
            //place dans la matrice a i qui vaut ce que se trouve dans le table de remplissage et j ce que l'user a choisi
            cases[remplissageCol[colJoueur-1]][colJoueur-1] = pionJoueur; 
            remplissageCol[colJoueur-1]--; //le remplissage de la colonne est decrementer
        }
        //Cas de rajout de colonne si la col choisit et superieur aux col existantes
        else if(colJoueur> largeur){
            for(int i = 0; i < hauteur; i++){
                
               cases[i] = (char*) realloc(cases[i],colJoueur*sizeof(char));
               if (cases[i] == NULL){
                    perror("Probleme memoire!\n");
                    exit(1);
                }
                // Ajout des . dans les nouvelles colonnes
                for (int j = largeur; j < colJoueur; j++){
                    cases[i][j] = '.';
                }
            }
            // Aggrandissement du tableau de position 
            remplissageCol = (int*) realloc(remplissageCol, colJoueur*sizeof(int));
            if (remplissageCol == NULL){
                perror("Probleme memoire!\n");
                exit(1);
            }
            // Remplissage des du tab de pos
            for (int j = largeur; j < colJoueur; j++){
                remplissageCol[j] = hauteur-1;
            }
            largeur = colJoueur;
                 
        }
        //suppression de col
        else if (colJoueur < 0 && -colJoueur < largeur){
            //mise a jour du nb de colonne
            largeur = -colJoueur;

            for(int i= 0 ; i < hauteur; i++){
                cases[i] = (char*) realloc(cases[i],largeur*sizeof(char));
                if (cases[i] == NULL){
                    perror("Probleme memoire!\n");
                    exit(1);
                }
            }

            //diminution du table des pos
            remplissageCol =  (int*) realloc(remplissageCol, largeur*sizeof(int));
            if (remplissageCol == NULL){
                perror("Probleme memoire!\n");
                exit(1);
            }



        }else //colJoueur = 0
            largeur=colJoueur;

        
    }while(largeur != 0);
    
    printf("\nFin de partie!\n");

    
    // Liberation de la memoire 
    for (int i = 0; i < hauteur; i++)
        free(cases[i]);
    free(cases);
    free(remplissageCol);

   


}