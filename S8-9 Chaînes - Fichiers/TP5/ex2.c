#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <strings.h>

#define MAX_LONG 27  // longueur maximale d'un mot
int main(int argc , char *argv[]){

    int nbArgument = argc -1;
    printf("Nb argument %d\n",nbArgument);

    for(int i = 1 ; i <= nbArgument ; i++){
        printf("%d : %s\n",i,argv[i]);
    }
    printf("\n");
    printf("\nIntroduire des mots d'au plus %i lettres a rechercher :\n",MAX_LONG);

    char ligne[MAX_LONG+2];
    bool present = false;
    int nbAbsent = 0;

    while (fgets(ligne, MAX_LONG+2, stdin) != NULL){
        if(ligne[0]=='\n') break;
        int taille = strlen(ligne)-1;

        // Variante 1 : mot trop long Si le dernier caractere n'est pas un saut de ligne ('\n')
        if(ligne[taille]!='\n'){
           
            printf("Erreur: le mot entré est trop long.\n");
            
            //Vide le stdin 
            while(fgets(ligne,MAX_LONG+ 2,stdin)&& ligne[strlen(ligne)-1] != '\n');
            printf("\n\nCACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n\n");
            // continue permet de reprendre l'execution au debut de la premiere boucle
            continue;
        }


        // Change le saut de ligne '\n' en '\0' pour pouvoir lire la taille 
        ligne[taille]= '\0';
        printf("  '%s'  longueur = %d\n",ligne, (int)strlen(ligne));

        // remet present à false pour les prochaines lectures au clavier 
        present = false;
        // Verifie si le mot se trouve dans argv 
        for(int i = 1; i <= nbArgument ; i++){
            // False si les deux chaines sont egales 
            // Variante 2 : strcase pour etre insensible à la casse 
            if(!strcasecmp(argv[i],ligne)){
                present = true;
                break;
            }
                
        }

        if(present){
            printf("%s est present\n", ligne);
        }else{
            printf("%s est absent\n", ligne);
            nbAbsent++;
        }
    }

    // Resultat 
    printf("\nNombre de mot entré qui ne sont pas dans argv : %d\n",nbAbsent);

}


