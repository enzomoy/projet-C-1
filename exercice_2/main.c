/*
 * Auteur : E.Moy
 *
 * Date : 10/11/2022
 *
 * Description : Construire un programme C permettant de supprimer (dans l'ordre) les chiffres d'un nombre n dans
un nombre m.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {

    // Menu
    char menuChoice;

    //Calcul
    int n;
    int m;
    int mSave;
    int result;
    char lenght = 0;
    char affirm;
    char i = 0;


    do {

        // Menu principal
        do {
            printf("\n-----------------------------");
            printf("\n1 - Selection des valeurs");
            printf("\n2 - Faire le calcul");
            printf("\n3 - Afficher le resultat");
            printf("\n4 - Quittez le programme");
            printf("\n-----------------------------");
            printf("\nQue souhaitez-vous faire ?  ");
            scanf("%d", &menuChoice);
        } while (menuChoice > 4 || menuChoice < 1);


        // Sélection des valeurs
        if (menuChoice == 1) {

            printf("\nEntrez la valeur de n (entiere) :");
            scanf("%d", &n);
            printf("\nEntrez la valeur de m (entiere) :");
            scanf("%d", &m);
        }

        // Faire le calcul
        if (menuChoice == 2) {


            // Récupération de la longueur de m
            mSave = m;
            result = 0;

            if (m == 0) lenght = 1;

            while (m != 0) {
                lenght++;
                m /= 10;
            }


            while (n != 0){

                affirm = (mSave == n % (int)pow(10, lenght)) ? 1 : 0; // Vérifie si m = aux derniers chiffres de n

                if (affirm == 0) {
                    result += (n % 10) * pow(10, i);// Affiche le dernier chiffre de n actuel
                    i++;
                }

                if (affirm == 1) {
                    n /= pow(10, lenght - 1);
                }
                n /= 10;

            }

        }

        // Afficher le résultat
        if (menuChoice == 3) {
            printf("\n---------------");
            printf("\nLe resultat est : %d", result);
            printf("\n---------------");
        }

    } while (menuChoice != 4);


    return EXIT_SUCCESS;
}