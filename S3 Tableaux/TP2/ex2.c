#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>   
// utiliser l'option "-lm" pour lier la la librairie 
// mathematique au programme

#define LIMIT 100
int main()
{
    int nombre;
    bool valid = false;

    /// Lecture d'un nombre entier positif nbre, strictement inferieur a 100
    while (!valid) {
        printf("Enter a positive integer value inferior to %d: ", LIMIT);
        if (scanf("%d",&nombre) != 1) {
            fprintf(stderr, "Error: invalid data\n");
        }
        else if (nombre < 0 || nombre > LIMIT) {
            fprintf(stderr, "Error: invalid integer value\n");
        } else {
            valid = true;
        }
    }

    //Calcul des nombres premiers inferieur a nombre
    bool table[LIMIT] = {false};  // initialisation de tous les elements a false

    for(int i= 2 ; i <= sqrt(nombre); i++ ){
        if(!table[i]){
            for(int j = i + i ; j <= nombre ; j += i)
                table[j] = true;
        }
    }
    printf("Nombres premiers inferieurs a %d: \n",nombre);
    for (int i=2; i<=nombre; i++){
        if (!table[i]){
            printf("%4d", i);
        }
    }


}