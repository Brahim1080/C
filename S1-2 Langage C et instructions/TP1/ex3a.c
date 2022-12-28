#include <stdlib.h>
#include <stdio.h>

int main(){
    int INT_MAX = 2147483647;
    double n;
    printf("Entrez un nombre pour afficher sa factorielle ");
    scanf("%lf",&n);

    double factorielle = 1.0;
    for(double i = 2.0; i <= n; i ++){
        factorielle = factorielle * i;
        printf("\ni = %.0lf et fact = %0.lf",i,factorielle);
    }
    // utiliser le int fait    

    printf("\nla factorielle %.0lf est %.0lf\n", n , factorielle);

}