/*
Auteur: Yang Lucien, Moy Enzo, Smahat Hamza
Date: 19/11/2022
Objectif: l'objectif de cette exercice et de trouver les puissances pour calculer un nombre exemple 135 = 1^1 + 3^2 + 5^3 ou 2537 = 2^1+3^2+5^3+7^4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {

    char menuChoice;
    int number1;
    int sum = 0;
    int digit = 0;
    int power = 1;
    int lenght = 0;
    int nbsortie = 0;
    int num1 = 0, num2 = 0;
    int finalNumber1;
    int j, i;


    do {
        do {
            printf("\n-----------------------------");
            printf("\n1 - Selection des valeurs (Partie 1)");
            printf("\n2 - Faire le calcul (Partie 1)");
            printf("\n3 - Afficher le resultat (Partie 1)");
            printf("\n4 - Selection des valeurs (Partie 2)");
            printf("\n5 - Afficher le resultat (Partie 2)");
            printf("\n6 - Quittez le programme");
            printf("\n-----------------------------");
            printf("\nQue souhaitez-vous faire ?  ");
            scanf("%d", &menuChoice);
        } while (menuChoice > 6 || menuChoice < 1);


        // PARTIE 1


        // Selection des valeurs
        if (menuChoice == 1) {
            printf("Entrez un nombre : \n>>> ");
            scanf("%d", &number1);
        }


        // Calculs

        if (menuChoice == 2) {

            sum = 0;
            digit = 0;
            power = 1;
            lenght = 0;
            nbsortie = 0;
            num1 = 0, num2 = 0;

            int temp_nb1 = number1;

            while (temp_nb1) {
                temp_nb1 /= 10;
                lenght++;
            }

            for (num1 = 0; num1 < lenght; num1++) { // permet de créer le nombre de boucle grâce à la variable num1

                int max = 1;

                for (num2 = 0; num2 < lenght - num1; num2++) { // permet d'obtenir le chiffre max
                    if ((number1 % (max * 10)) / max < (number1 % (int) pow(10, num2 + 1)) / (int) pow(10, num2)) {
                        max = pow(10, num2); // permet d'attribuer un nouveau plus grand chiffre par rapport à l'ancien
                    }
                }

                nbsortie += (number1 % (max * 10) / max) *
                            pow(10, num1);//permet d'ajouter le plus grand chiffre à gauche du nombre par odre croissant
                number1 = number1 % max + (number1 / (max * 10)) * max; //permet de supprimer le chiffre le plus grand
            }
            number1 = nbsortie;
        }

        // Affichage du résultat
        if (menuChoice == 3) {
            finalNumber1 = number1;
            for (i = 0; i < lenght; i++) {
                digit = number1 % 10;

                printf("\n%d^%d = %d", digit, lenght - i, (int) pow(digit, lenght - i));
                sum += pow(digit, lenght - i);
                number1 /= 10;
                power++;
            }

            printf("\nTotal = %d", sum);

            if (finalNumber1 == sum) printf("\nLa propriete est valide pour le nombre %d", finalNumber1);
            else printf("\nCette propriete n'est pas valide pour le nombre %d", finalNumber1);
        }

        // PARTIE 2

        int a, b;

        if (menuChoice == 4) {
            printf("Choisisez la borne inferieure : ");
            scanf("%d", &a);
            printf("Choisisez la borne superieur : ");
            scanf("%d", &b);
        }

        if (menuChoice == 5) {
            for (; a <= b; a++) {

                j = a;
                sum = 0;
                digit = 0;
                power = 1;
                lenght = 0;
                nbsortie = 0;
                num1 = 0, num2 = 0;

                int temp_j = j;

                while (temp_j) {
                    temp_j /= 10;
                    lenght++;
                }

                for (num1 = 0; num1 < lenght; num1++) { // permet de créer le nombre de boucle grâce à la variable num1

                    int max = 1;

                    for (num2 = 0; num2 < lenght - num1; num2++) { // permet d'obtenir le chiffre max
                        if ((j % (max * 10)) / max < (j % (int) pow(10, num2 + 1)) / (int) pow(10, num2)) {
                            max = pow(10,num2); // permet d'attribuer un nouveau plus grand chiffre par rapport à l'ancien
                        }
                    }

                    nbsortie += (j % (max * 10) / max) * pow(10,num1);//permet d'ajouter le plus grand chiffre à gauche du nombre par odre croissant
                    j = j % max + (j / (max * 10)) * max; //permet de supprimer le chiffre le plus grand
                }
                j = nbsortie;

                finalNumber1 = j;
                for (i = 0; i < lenght; i++) {
                    digit = j % 10;
                    sum += pow(digit, lenght - i);
                    j /= 10;
                    power++;
                }

                if (finalNumber1 == sum) printf("\nLe nombre %d valide la propriete", a);
            }

        }


    } while (menuChoice != 6);

    return EXIT_SUCCESS;
}
