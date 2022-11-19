#include <stdio.h>

int main(int argc,char ** argv){

    int nb_space,i,y,space_between;
    printf("quel est la grandeur de votre arc :");
    scanf("%d",&nb_space);
    nb_space+=9;

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
                for (int i = 0; i < 4; ++i) {
                    printf(" ");
                }
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
                                for (int x = 0; x < nb_space - 17; ++x) {
                                    for (int i = 0; i < nb_space - y; ++i) {
                                        printf(" ");
                                    }
                                    printf("****");
                                    for (int i = 0; i < space_between; ++i) {
                                        printf(" ");
                                    }
                                    printf("****\n");
                                    if (x + 1 < nb_space) {
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
    return 0;
}
