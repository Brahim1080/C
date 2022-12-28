#include <stdio.h>
#include <stdlib.h>
#define NBMAX 50
int main(){

    int val;
    float notes [NBMAX];
    int cpt = 0;
    float somme;

    printf("Entrez les notes des etudiants, Ctrl-D pour terminer:\n");
    //Lecture des notes des etudiants   
    while((cpt<NBMAX) && (scanf("%d",&val) != EOF)){
        notes[cpt] = val;
        somme += val;
        cpt++;
    }

    //Calcul de la moyenne 
    float moyenne = somme/cpt;
    printf("Moyenne = %.2f\n",moyenne); //ok
    
    //Calcul des ecarts a la moyenne 

    float ecart;
    somme =0;

    for(int i = 0 ; i < cpt ; i++){
        ecart = notes[i]-moyenne;
        printf("Etudiant numero %d: %.2f\n", i+1 , ecart);
        //pour la variance moyenne des ecarts aux carre
        somme += ecart * ecart ;
    }

    //Calcul de la variance moyenne des ecarts aux carre
    float variance = somme/cpt;
    printf("Variance = %.2f\n", variance);


    exit(0);
}