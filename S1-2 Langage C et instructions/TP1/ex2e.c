#include <stdlib.h>
#include <stdio.h>

int main(){
    
    int entier;

    printf("Entrez un nombre entier pour afficher tout ses diviseurs :\n");
    scanf("%d",&entier);
    
    for(int i = 1; i <= entier ;i++){
        
        if(entier % i == 0){
            printf("\n%d",i);
        }
    }
    exit(0);
}