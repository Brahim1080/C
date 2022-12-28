#include <stdio.h>
#include <stdlib.h>

int main(){
    int nData, nPos, nNeg;
    int *inputs, *positives, *negatives;

    printf("Entrez le nombre de donnees (0 pour terminer): ");
    scanf("%d", &nData);
    
    while(nData>0){
        inputs = malloc(nData*sizeof(int));
        if (inputs == NULL) {
         perror("Out of memory\n");
         exit(EXIT_FAILURE);
        }

        //lire les inputs et compter le nbr de negatifs et positifs
        nNeg = nPos = 0;
        //ptr - inputs = nombre d element car ptr adresse actuelle et inputs adresse du premier elem du tab
        for(int* ptr= inputs; ptr - inputs < nData; ptr++ ){
            scanf("%d",ptr);
            if(*ptr>=0)
                nPos++;
            else 
                nNeg++;
            
        }

        //Allocation memoire
        positives = malloc(nPos*sizeof(int));
        if (positives == NULL) {
         perror("Out of memory\n");
         exit(EXIT_FAILURE);
        }
        negatives = malloc(nNeg*sizeof(int));
        if (negatives == NULL) {
         perror("Out of memory\n");
         exit(EXIT_FAILURE);
        }

        //Rempli les tableaux de positifs et de negatifs
        int* ptrP = positives;
        int* ptrN = negatives;
        for (int* ptr = inputs; ptr - inputs < nData; ptr++){
            if (*ptr>= 0)
            {
                *ptrP = *ptr;
                ptrP++;
            }else{
                *ptrN = *ptr;
                ptrN++;
            }
            
        }

        // Print les tableaux
         printf("Resultat : \n");
        for (int i=0; i<nPos; i++)
            printf("%d ", positives[i]);
        printf("\n");

        for (int i=0; i<nNeg; i++)
            printf("%d ", negatives[i]);
        printf("\n");
        

        // Free dynamic memory
        free(inputs);
        free(negatives);
        free(positives);

        printf("Entrez le nombre de donnees (0 pour terminer): ");
        scanf("%d", &nData);




    }
}