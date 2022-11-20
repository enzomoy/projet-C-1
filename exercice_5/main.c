#include <stdio.h>

/* AUTEUR: Lucien Yang
 * DATE DEBUT:17/11/2022
 * DATE FIN:??/11/2022
 * OBJECTIF:faire un system de reduction automatique
 * pour l'entreprise ouibus
 */


int main(int argc, char ** argv){

    int card,old,range;
    float sold,tempres;
    int loop;
    int count19=0;
    int count4=0;
    int count18=0;
    int count183=0;
    int count12=0;
    int countG=0;
    int answer,solo;
    fflush(stdin);

//------------------voyage seule------------------

    do {
        printf("voyage tu seul");
        printf("\nsi ui repondre 1 sinon repondre 0");
        printf("\nreponce :");
        scanf("%d", &solo);
    }while (solo<0 || solo>1);

//------------------voyage en famille/ a plusieur------------------

    if (solo==1){
        //------------------menu------------------
        do {

            do {
                printf("\n||--------------------------------------------||\n");
                printf("que faire ");
                printf("\n1 - inscription enfant");
                printf("\n2 - distance du trajet");
                printf("\n3 - voir le prix avec redtion");
                printf("\n4 - voir le prix avec reduction");
                printf("\n0 - quitter la boucle");
                printf("\nreponce :");
                scanf("%d",&loop);
                printf("\n||--------------------------------------------||\n");
            } while (loop<0 || loop>4);

//------------------enregistrement des enfant------------------

            if (loop==1){
                do {

                    printf("avez vous un/des enfant(s)");
                    printf("\n(ps: repondre 1 si il y a un/des enfant(s) \nsinon repondre autre chose que 1");
                    printf("\nreponce :");
                    scanf(" %d",&answer);

                    if (answer==1){
                        printf("quel age a votre enfant");
                        scanf("%d",&old);
                        if (old<5){
                            count4=count4+1;
                        }
                        if (old<13 && old>4){
                            count12=count12+1;
                        }
                        if (old<19){
                            count18=count18+1;
                        }
                        if (count18>=3){
                            count183=1;
                        }
                        if (old>18){
                            printf("votre enfant ne benefici de aucune reduction");
                            count19=count19+1;
                        }

                    }
                    printf("\n||--------------------------------------------||\n");
                }while(answer==1);
                printf("vous avez actuellement enregister \n%d enfant de moins de 5ans\n%d enfant de moins de 13 ans(enfant de -5ans  compris) \n%d enfant de moins de 19ans(enfant de -5 et -13 ans compris) \nvous avez aussi enregistre %d personne de plus de 18 ans",count4,count12,count18,count19);
                if(count183==1){
                    printf("\nvue que vous avez au moins 3 enfant de moins de 18 ans \nvous pouvez beneficier de la carte famille nombreuse");
                }
            }
//------------------distance du trajet------------------

            if (loop==2){
                printf("que distance parcourer vous");
                printf("\n(3e/km)");
                printf("\nreponce :");
                scanf("%d",&range);
            }
//------------------prix sans reduction------------------

            if (loop==3){
                printf("le prix du voyage sans la promotion est de");
                printf("\nprix : %d * 3",range );
                sold=range*3;
                printf("\nprix sans sold du billet : %lf",sold);
                countG=count18+count19;
                printf("\nvous avez un total de %d billet",countG+1);
                tempres=(countG+1)*sold;
                printf("\ncela vous revien a : %f",tempres);
            }
//------------------prix sans reduction------------------

            if (loop==4){
                sold=range*3;

                if (count18==0 && count4==0 && count183==0){
                    printf("\ntu ne possede d'aucune reduction");
                    printf("\nprix : %d * 3",range);
                    sold=range*3;
                    printf("\nprix : %lf",sold);
                }
                if (count18>0 || count4>0 || count183>0){
                    count18=count18-count12;
                    count12=count12-count4;
                    printf("\nvous povez beneficier de certain bonus dont :");
                    printf("\nle prix toltal avec les reduction :");
                    printf("\nvous avez %d place gratuite",count4);
                    printf("\nvous avez %d place a demi prix",count12);
                    if (count183!=1){
                        printf("\nvous pouvez l'avantage carte famille");
                        printf("\nrappel : la carte famille coute 100e et vous permet d'avoir les place -18 a -50");
                        printf("\nactuellement vous avez %d place qui benefici de l'avantage",count18);
                        printf("\nvoulez vous la carte");
                        do {
                            printf("\nreponde(1-oui 0-non): ");
                            scanf("%d",&card);
                        }while (card<0 && card>1);
                        printf("\nle prix :");
                        if (card==1){
                            printf("\n(%d * 0) + (((%d * %lf) / 2) / 2) + (%d * %lf) / 2)",count4,count12,sold,count18,sold);
                            printf("\nle prix est de :");
                            printf("\n%lf",(((count12*sold)/2)/2)+((count18*sold)/2)+100);
                        }

                    }
                    if (count183==1){
                        printf("\nvous pouvez l'avantage carte famille nombreuse");
                        printf("\nrappel : la carte famille coute 125e et vous permet d'avoir sur toute les place -30");
                        printf("\nvoulez vous la carte");
                        do {
                            printf("\nreponde(1-oui 0-non): ");
                            scanf("%d",&card);
                        }while (card<0 || card>1);
                        if (card==1){
                            printf("\n((%d * 0) + ((%d * %lf)/2) + (%d * %lf))*0.3)",count4,count12,sold,count18,sold);
                            printf("\nle prix est de :");
                            printf("\n%lf",((((count12*sold)/2)+(count18*sold)*0.3)+125));
                        }

                    }
                }
            }


//------------------quitter la boucle------------------

            if (loop==0) {
                printf("au revoir");
                break;
            }

        }while(loop>=0 && loop<=4);

    }

//------------------voyage en solo------------------

    if (solo==0){
        //------------------menu------------------
        do {

            do {
                printf("\n||--------------------------------------------||\n");
                printf("que faire ");
                printf("\n1 - distance du trajet");
                printf("\n2 - voir le prix");
                printf("\n0 - quitter la boucle");
                printf("\nreponce :");
                scanf("%d",&loop);
                printf("\n||--------------------------------------------||\n");
            } while (loop<0 || loop>4);


//------------------distance du trajet------------------

            if (loop==1){
                printf("que distance parcourer vous");
                printf("\n(3e/km)");
                printf("\nreponce :");
                scanf("%d",&range);
            }
//------------------prix sans reduction------------------

            if (loop==2){
                printf("le prix du voyage est de");
                printf("\nprix : %d * 3",range );
                sold=range*3;
                printf("\nprix du billet : %lf",sold);
            }

//------------------quitter la boucle------------------

            if (loop==0) {
                printf("au revoir");
                break;
            }

        }while(loop>=0 && loop<=4);

    }

    return 0;
}
