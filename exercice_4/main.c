/*
Auteur: Yang Lucien, Moy Enzo, Smahat Hamza
Date: 21/11/2022
Objectif: l'objectif de cette exercice et de trouver les puissances pour calculer un nombre exemple 135 = 1^1 + 3^2 + 5^3 ou 2537 = 2^1+3^2+5^3+7^4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {

    char menuChoice;

    do {

        int binaryNumber = 0;
        int binaryCounter = 0;
        char byte = 0;
        int firstOne = 0;
        int allZero = 0;
        int allOne = 0;
        int lastZero = 0;
        int lastOne = 0;
        int addedZero = 0;
        char verifZero = 0;
        char verifOne = 0;
        char i = 0;
        char j = 1;
        char verifStartOne = 0;

        do {
        printf("\n-----------------------------");
        printf("\n1 - Selection des valeurs");
        printf("\n2 - Afficher le resultat");
        printf("\n3 - Quittez le programme");
        printf("\n-----------------------------");
        printf("\nQue souhaitez-vous faire ?  ");
        scanf("%d", &menuChoice);
    } while (menuChoice > 4 || menuChoice < 1);



        int decimalNumber;
        short workWithWhichNumber;


        if (menuChoice == 1) {
            // Choix utilisateur du nombre décimal
            do {
                printf("Choisir un nombre entier : ");
                scanf("%d", &decimalNumber);
            } while (decimalNumber < 0 || decimalNumber > 4294967296);

            do {
                printf("\n1 - Comptez le nombre de 0");
                printf("\n2 - Comptez le nombre de 1");
                printf("\nQue souhaitez vous faire ?");
                scanf("%hd", &workWithWhichNumber);
            } while (workWithWhichNumber < 1 || workWithWhichNumber > 2);
        }

        if (menuChoice == 2) {

            // Recherche de l'octet correspondant au nombre binaire
            if (decimalNumber <= 4294967296 && decimalNumber > 16777216) byte = 4;
            if (decimalNumber <= 16777216 && decimalNumber > 65536) byte = 3;
            if (decimalNumber <= 65536 && decimalNumber > 256) byte = 2;
            if (decimalNumber <= 256) byte = 1;

            while (decimalNumber != 0) {

                if (decimalNumber % 2 == 0) {

                    // Compte les zero de la fin tant que y'a pas eu de 1
                    if (verifZero == 0 && workWithWhichNumber == 1) lastZero++;

                    allZero++; // Incrémente le total
                    verifOne = 1; // Bloque les futurs lastOne
                }

                if (decimalNumber % 2 == 1) {
                    // Compte les 1 de la fin tant que y'a pas eu de 0
                    if (verifOne == 0 && workWithWhichNumber == 2) lastOne++;

                    allOne++; // Incrémente le total
                    verifZero = 1; // Bloque les futurs lastZero
                }


                binaryCounter++;
                binaryNumber += (decimalNumber % 2) * (int)pow(10, i);

                decimalNumber /= 2;
                i++;
            }

            // Comble l'octet sur lequel on travaille par des zéros.
            if (binaryCounter != byte * 8) {
                addedZero = (byte * 8 - binaryCounter);
                allZero += addedZero;
            }

            // Récupérer les 1 avant le premier bit à 0.
            while (verifStartOne == 0) {
                if ((int) binaryNumber / (int) pow(10, ((byte * 8) - j)) % 2 == 1) firstOne++;
                else verifStartOne = 1;
                j++;
            }

            if (workWithWhichNumber == 1) { // L'utilisateur souhaite voir les 0).
                printf("\n----------------------");
                printf("\nEn partant de la gauche, le nombre de 0 avant le premier 1 est : %d", addedZero);
                printf("\nEn partant de la gauche, le nombre de 0 avant le dernier 1 est : %d", allZero - lastZero);
                printf("\n----------------------");
                printf("\nEn partant de la droite, le nombre de 0 avant le premier 1 est : %d", lastZero);
                printf("\nEn partant de la droite, le nombre de 0 avant le dernier 1 est : %d", allZero - addedZero);
                printf("\n----------------------");
            }

            if (workWithWhichNumber == 2) { // L'utilisateur souhaite voir les 1).
                printf("\n----------------------");
                printf("\nEn partant de la gauche, le nombre de 1 avant le premier 0 est : %d", firstOne);
                printf("\nEn partant de la gauche, le nombre de 1 avant le dernier 0 est : %d", allOne - lastOne);
                printf("\n----------------------");
                printf("\nEn partant de la droite, le nombre de 1 avant le premier 0 est : %d", lastOne);
                printf("\nEn partant de la droite, le nombre de 1 avant le dernier 0 est : %d", allOne - firstOne);
                printf("\n----------------------");
            }
        }


    } while (menuChoice != 3);


    return EXIT_SUCCESS;
}

