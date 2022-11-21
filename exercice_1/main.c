/*AUTEUR:Yang Lucien
 *DATE DEBUT:13/11/2022
 * DATE FIN:20/11/2022
 * OBJECTIF: construction une arche
 *en langage c avec de *
 */

#include <stdio.h>

int main(int argc,char ** argv){

    int i,y,space_between,answer;
    int nb_space=0;

    do {

        do {
            printf("--- Menu ---");
            printf("\n1 - Configurer la taille de l'arche");
            printf("\n2 - Afficher l'arche");
            printf("\n0 - Quitter le programme");
            printf("\n>> ");
            scanf(" %d",&answer);
        }while(answer<0 && answer>2);

//------------------ nb de tour ------------------

        if (answer==1){
            printf("Combien de ligne :");
            scanf("%d",&nb_space);
            nb_space+=9;
        }

//------------------ affiche l'arche ------------------

        if (answer==2){

//------------------ debut de l'arche ------------------

            if (nb_space>9) {
                for (int i = 0; i < nb_space; ++i) {
                    printf(" ");
                }
                printf("************\n");

//------------------ l'arche de taille 2 ------------------

                if (nb_space>10) {
                    for (int i = 0; i < nb_space - 3; ++i) {
                        printf(" ");
                    }
                    printf("******************\n");

//------------------ l'arche de taille 3 ------------------

                    if (nb_space>11) {
                        for (int i = 0; i < nb_space - 5; ++i) {
                            printf(" ");
                        }
                        printf("*********");
                        printf("    ");
                        printf("*********\n");

//------------------ l'arche de taille 4 ------------------

                        if (nb_space>12) {
                            for (int i = 0; i < nb_space - 7; ++i) {
                                printf(" ");
                            }
                            printf("******");
                            for (int i = 0; i < 14; ++i) {
                                printf(" ");
                            }
                            printf("******\n");

//------------------ l'arche de taille 5 et 6 ------------------

                            if (nb_space>13) {
                                y = 8;
                                space_between = 18;
                                for (int x = 0; x < 2; ++x) {
                                    if (nb_space == 14) {
                                        x++;
                                    }
                                    for (int i = 0; i < nb_space - y; ++i) {
                                        printf(" ");
                                    }
                                    printf("*****");
                                    for (int i = 0; i < space_between; ++i) {
                                        printf(" ");
                                    }
                                    printf("*****\n");
                                    y++;
                                    space_between = space_between + 2;
                                }

//------------------ l'arche de taille 7 ------------------

                                if (nb_space>15) {
                                    for (int i = 0; i < nb_space - 10; ++i) {
                                        printf(" ");
                                    }
                                    printf("****");
                                    for (int i = 0; i < 24; ++i) {
                                        printf(" ");
                                    }
                                    printf("****\n");

//------------------ l'arche de taille 8,9,...,n ------------------

                                    space_between=26;
                                    y=11;
                                    if (nb_space>16){
                                        for (int x = 0; x <= nb_space - 17; ++x) {
                                            for (int i = 0; i < nb_space - y; ++i) {
                                                printf(" ");
                                            }
                                            printf("****");
                                            for (int i = 0; i < space_between; ++i) {
                                                printf(" ");
                                            }
                                            printf("****\n");
                                            if (x + 1 < nb_space - 17) {
                                                for (int x = 0; x < nb_space - y; ++x) {
                                                    printf(" ");
                                                }
                                                printf("****");
                                                for (int i = 0; i < space_between; ++i) {
                                                    printf(" ");
                                                }
                                                printf("****\n");
                                                space_between += 2;
                                                y++;
                                                x++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

        }

        if (answer==0){

            printf("Au-revoir");
            break;

        }

    }while(answer>-1 && answer<3);

    return 0;
}
