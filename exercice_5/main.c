#include <stdio.h>

/* AUTEUR: Lucien Yang
 * DATE DEBUT:17/11/2022
 * DATE FIN:??/11/2022
 * OBJECTIF:faire un systeme de reduction automatique
 * pour l'entreprise ouibus
 */


int main(int argc, char ** argv){

    int card,old;
    double range;
    double sold,tempres;
    int loop;
    int count19 = 0;
    int count4 = 0;
    int count18 = 0;
    int count183 = 0;
    int count12 = 0;
    int countG = 0;
    int answer,solo;

//------------------voyage seul------------------

    do {
        printf("Voyagez-vous seul ?");
        printf("\n1 - Non");
        printf("\n0 - Oui");
        printf("\n>> ");
        scanf("%d", &solo);
    }while (solo<0 || solo>1);

//------------------voyage en famille/ a plusieur------------------

    if (solo==1){
        //------------------menu------------------
        do {

            do {
                printf("\n-----------------------------------\n");
                printf("Que souhaitez-vous faire ?");
                printf("\n1 - Inscription enfant");
                printf("\n2 - Distance du trajet");
                printf("\n3 - Voir le prix sans reduction");
                printf("\n4 - Voir le prix avec reduction");
                printf("\n0 - Quitter la boucle");
                printf("\n>> ");
                scanf("%d",&loop);
                printf("\n----------------------------------\n");
            } while (loop<0 || loop>4);

//------------------enregistrement des enfant------------------

            if (loop==1){
                do {

                    printf("\nAvez vous un/des enfant(s)");
                    printf("\n1 - Vous avez 1 ou plusieurs enfants");
                    printf("\nAutre - Vous n'avez pas d'enfant");
                    printf("\n>>");
                    scanf(" %d",&answer);

                    if (answer==1){
                        printf("\nQuel age a votre enfant ?");
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
                            printf("\nVotre enfant ne beneficie de aucune reduction...");
                            count19=count19+1;
                        }

                    }
                    printf("\n----------------------------------)");
                }while(answer==1);
                printf("\nVous avez actuellement enregister \n%d enfant de moins de 5 ans,\n%d enfant de moins de 13 ans (enfant de -5ans compris) et \n%d enfant de moins de 19 ans (enfant de -5 et -13 ans compris). \nVous avez aussi enregistrer %d personne de plus de 18 ans",count4,count12,count18,count19);
                if(count183==1){
                    printf("\nVu que vous avez au moins 3 enfant de moins de 18 ans, \nvous pouvez beneficier de la carte famille nombreuse");
                }
            }
//------------------distance du trajet------------------

            if (loop==2){
                printf("\nQuelle distance parcourez-vous");
                printf("\n(3e/km)");
                printf("\n>> ");
                scanf("%lf",&range);
            }
//------------------prix sans reduction------------------

            if (loop==3){
                printf("\nLe prix du voyage sans la promotion est de");
                printf("\nPrix : %.2lf * 3",range);
                sold=range*3;
                printf("\nPrix du billet sans solde : %.2lf",sold);
                countG=count18+count19+1;
                printf("\nVous avez un total de %d billet",countG);
                tempres=(countG)*sold;
                printf("\nCela vous revient a : %lf",tempres);
            }
//------------------prix sans reduction------------------

            if (loop==4){
                sold=range*3;

                if (count18==0 && count4==0 && count183==0){
                    printf("\nTu ne possedes aucune reduction");
                    printf("\nPrix : %.2lf * 3",range);
                    sold=range*3;
                    printf("\nPrix : %.2lf",sold);
                }
                if (count18>0 || count4>0 || count183>0){
                    count18=count18-count12;
                    count12=count12-count4;
                    printf("\nVous pouvez beneficier de certain bonus dont :");
                    printf("\nLe prix total avec les reductions :");
                    printf("\nVous avez %d place gratuite",count4);
                    printf("\nVous avez %d place a demi prix",count12);
                    if (count183!=1){
                        printf("\nVous pouvez l'avantage carte famille");
                        printf("\nRappel : la carte famille coute 100e et vous permet d'avoir les place -18 a -50");
                        printf("\nActuellement vous avez %d place qui benefici de l'avantage",count18);
                        printf("\nVoulez-vous la carte ?");
                        do {
                            printf("\n1 - Oui");
                            printf("\n0 - Non");
                            printf("\n>> ");
                            scanf("%d",&card);
                        }while (card<0 && card>1);
                        printf("\nLe prix :");
                        if (card==1){
                            printf("\n(%d * 0) + (((%d * %.2lf) / 2) / 2) + (%d * %.2lf) / 2)",count4,count12,sold,count18,sold);
                            printf("\nLe prix est de :");
                            printf("\n%.2lf",(((count12*sold)/2)/2)+((count18*sold)/2)+100);
                        } else{
                            printf("\nVu que vous ne prener pas la carte, vous avez juste les reductions pour");
                            printf("\nLes enfants de -5ans (si vous en avez) et les enfants de -13 ans (si vous en avez)");
                            printf("\nCela vous fera donc un total de :");
                            printf("\n%lf",((count12*sold)/2)+(count18*sold)+(sold * count19));
                        }


                    }
                    if (count183==1){
                        printf("\nVous pouvez avoir la carte famille nombreuse");
                        printf("\nRappel : la carte famille coute 125e et vous permet d'avoir  toute les place à -30e");
                        printf("\nVoulez-vous la carte ?");
                        do {
                            printf("\n1 - Oui");
                            printf("\n0 - Non");
                            printf("\n>> ");
                            scanf("%d",&card);
                        }while (card<0 || card>1);
                        if (card==1){
                            printf("\n((%d * 0) + ((%d * %.2lf)/2) + (%d * %.2lf))*0.3)",count4,count12,sold,count18,sold);
                            printf("\nLe prix est de :");
                            printf("\n%.2lf",((((count12*sold)/2)+(count18*sold)*0.3)+125));
                        } else{
                            printf("\nvu que vous prener pas la carte vous avez juste les reductions pour");
                            printf("\nles enfant de -5ans (si vous en avez) et les enfant de -13 ans");
                            printf("\ncela vous fera donc un total de :");
                            printf("\n%lf",((count12*sold)/2)+(count18*sold)+(sold * count19));
                        }

                    }
                }
            }


//------------------quitter la boucle------------------

            if (loop==0) {
                printf("\nAu-revoir");
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
                printf("Que souhaitez-vous faire ?");
                printf("\n1 - Distance du trajet");
                printf("\n2 - Voir le prix");
                printf("\n0 - Quitter la boucle");
                printf("\n>> ");
                scanf("%d",&loop);
                printf("\n||--------------------------------------------||\n");
            } while (loop<0 || loop>4);


//------------------distance du trajet------------------

            if (loop==1){
                printf("Quel distance parcourez-vous");
                printf("\n(3e/km)");
                printf("\n>> ");
                scanf("%lf",&range);
            }
//------------------prix sans reduction------------------

            if (loop==2){
                printf("Le prix du voyage est de");
                printf("\nPrix : %lf * 3",range );
                sold=range*3;
                printf("\nPrix du billet : %.2lf",sold);
            }

//------------------quitter la boucle------------------

            if (loop==0) {
                printf("Au-revoir");
                break;
            }

        }while(loop>=0 && loop<=4);

    }

    return 0;
}
