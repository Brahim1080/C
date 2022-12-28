#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(int argc , char *argv[]){
    int nbMot = argc -1;
    
    printf("Nombre de parametres : %d\n",nbMot);
    char ** tabMots =(char **) malloc(nbMot * sizeof(char*));
    if (tabMots == NULL) exit(1);


    for(int i = 0 ; i < nbMot; i++){
        
        int tailleMot = strlen(argv[i+1])+1;
        tabMots[i]= (char *) malloc (tailleMot*sizeof(char));
        if (tabMots[i]== NULL) exit(1);

        strcpy(tabMots[i], argv[i+1]);

        for(int j = 0 ; j < tailleMot; i++)
            tabMots[i][j] = toupper((unsigned char)tabMots[i][j]);
          
    }

    for(int i = 0 ; i < argc -1; i++){
        
        printf("%s ",tabMots[i]);


    }

    printf("\n");

    


    
    for(int i = 0 ; i < argc -1; i++)
        free(tabMots[i]);
    free(tabMots);
    
}