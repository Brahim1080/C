#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>

#define NB_CHAR 254  // longueur max d'un string lu sur stdin c'est suivi de \n et \0
#define TAILLE_ID 5  // taille de l'identifiant du coffre
#define NB_COFFRES 25 // taille initiale du coffre
int main(){
    // Allocation de la table de coffres
    int taillePhys = NB_COFFRES;
    int tailleLog = 0;
    char** coffres = (char**) malloc(taillePhys * sizeof(char*));
    if (coffres == NULL) {perror("erreur d'alloc"); exit(1);}

    //+2 car ça prend en compte le retour a la ligne \n et la fin de string \0
    char ligne [NB_CHAR+2]; 
    printf("**Application de coffres**\n\n");
    while(fgets(ligne, NB_CHAR+2 ,stdin)!= NULL){
        if(ligne[0]=='\n') break; //Arreter de lire
        
        // si ligne = test alors strlen = 5 car la fin de test a un \n , 
        // alors on doit changer le \n en '\0' pour la fin du string
        // apres ça strlen sera egale à 4
        ligne[strlen(ligne)-1] = '\0'; // suppression de '\n'
        
        bool contient= false;
        int i = 0;
        for(i =0; i < tailleLog; i++){
            //Verfie si le coffre existe deja verifie seulement les 5 premiers caracteres 
            if( !strncmp( coffres[i] ,ligne , TAILLE_ID)){
                contient = true;
                break;
            }

        }


        if(contient){// Si la table contient le coffre 
            // doit faire un realloc 
            // Concaténation du nouveau contenu dans le coffre
            printf("Contient dans le coffre !!\n");

            size_t tailleChaine = strlen(coffres[i]) + strlen(ligne+TAILLE_ID) + 1;
            if ((coffres[i] = (char*) realloc(coffres[i], tailleChaine * sizeof(char))) == NULL) 
                {perror("erreur d'alloc"); exit(1);}

            strcat(coffres[i], ligne + TAILLE_ID); // + Taille id pour copier l adresse du string 
        }else{//Si il n'y a pas deja de coffre avec cet id 
            
            // Cas de table pleine
            if (tailleLog == taillePhys) {
                taillePhys *= 2; // doublement de la taille physique
                if ((coffres = (char**) realloc(coffres, taillePhys * sizeof(char*))) == NULL) 
                    {perror("erreur d'alloc"); exit(1);}
            }
            // Copie du nouveau coffre dans la table //+1 pour le retour à la ligne
            if ((coffres[tailleLog] = (char*) malloc((strlen(ligne)+1) * sizeof(char))) == NULL) 
                {perror("erreur d'alloc"); exit(1);}

            strcpy(coffres[tailleLog],ligne);
            tailleLog++;
            

        }


    }
    




    // Affichage des coffres
    printf("\nCOFFRES-FORTS:\n\n");
    for (int i = 0 ; i < tailleLog; i++) {
        printf("%s\n", coffres[i]);
    }

    // Libération de la mémoire dynamique
    for (int i = 0 ; i < tailleLog; i++)
        free(coffres[i]);
    free(coffres);

    exit(EXIT_SUCCESS);



}