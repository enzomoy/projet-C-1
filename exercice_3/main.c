/*
Auteur: Hamza SMAHAT
Date: 19/11/2022
Objectif: l'objectif de cette exercice et de trouver les puissances pour calculer un nombre exemple 135 = 1^1 + 3^2 + 5^3 ou 2537 = 2^1+3^2+5^3+7^4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int number1, digit; // on initialise les variables number 1 et digit
    double somme = 0;
    int power = 1;
    int lenght = 0;
    int nbsortie = 0;

    printf("Entrez nombre : \n>>> ");
    scanf("%d", &number1);

    int temp_nb1 = number1;

    while(temp_nb1){
        temp_nb1 /= 10;
        lenght++;
    }

    for(int num1 = 0; num1 < lenght; num1++){ // permet de créer le nombre de boucle grâce à la variable num1
        int max = 1;
        for (int num2 = 0 ; num2 < lenght - num1; num2++) { // permet d'obtenir le chiffre max
            if ((number1 % (max * 10)) / max < (number1 % (int)pow(10,num2 + 1)) / (int)pow(10,num2)){
                max = pow(10,num2); // permet d'attribuer un nouveau plus grand chiffre par rapport à l'ancien
            }
        }

        nbsortie += (number1 % (max * 10) / max) * pow(10,num1);//permet d'ajouter le plus grand chiffre à gauche du nombre par odre croissant
        number1 = number1 % max + (number1 / (max * 10)) * max; //permet de supprimer le chiffre le plus grand
    }
    number1 = nbsortie;

    for(int i = 0; i < lenght; i++){
        digit = number1 % 10;

        printf("\n%d^%d = %f\n", digit, lenght - i, pow((double)digit , (double)power ));
        somme += pow( (double)digit , (double)lenght - i );
        number1 /= 10;
        power++;
    }

    /*condition pour mettre ordre croissant */


    printf("Total = %.0lf", somme);
    return 0;
}
