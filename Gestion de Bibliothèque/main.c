#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char titre[100];
    char auteur[100];
    float prix ;
    int quantite ;
}Livre ;



void Ajout(Livre L[], int compteur);
void Affichage(Livre L[], int compteur);
int Recherche(Livre L[] , int compteur);
int RechercheAuteur(Livre L[] , int compteur);
void modifierAuteur(Livre L[] , int indice, char newAuteur[]);
void modifierPrix(Livre L[] , int indice, float newPrix);
void modifierQuantite(Livre L[] , int indice , int newQuantite);
char Confirm();
void Supprimer(Livre L[] , int indice , int compteur);
void triCroissant(Livre L[] , int compteur);
void triDecroissant(Livre L[] , int compteur);
int quantiteTotale(Livre L[] , int compteur);





int main()
{
    Livre livre[100];

    //Variables pour la Modification
    char newAuteur[100] ;
    float newPrix ;
    int newQuantite ;

    //Variable pour confirmer la modification ou la suppression
    char confimation ;

    //Variables pour entrer le nombre de Livres a Ajouter
    int nbrLivre = 0 ;

    //Variables pour les Statistiques
    int nbrTitre ;
    int totalQuantite;
    float moyennePrix ;
    float totalPrix = 0;
    float pourcentage ;

    //Navigation de Menu Principale
    int menu = -1 ;

    //Navigation des Sous-menus
    int choix ;

    //Compteur des livres ajoutés
    int compteur = 0 ;

    //Variables où on stocke la valeur de retour de fonction de recherche
    int test ;

    printf("*************************************************************************\n");
    printf("*                 Programme de Gestion de Bibliotheque                  *\n");
    printf("*************************************************************************\n\n\n");


    while(menu!=0){
        printf("===================================================================\n");
        printf("                         MENU PRINCIPALE                         \n");
        printf("===================================================================\n");
        printf("  1 - Ajouter un (des) Livres . \n");
        printf("  2 - Modifier un Livre. \n");
        printf("  3 - Supprimer un Livre.\n");
        printf("  4 - Rechercher un Livre. \n");
        printf("  5 - Trier la Liste des Livres.\n");
        printf("  6 - Statistiques .\n");
        printf("\n  0 - Arreter le Programme . \n");
        printf("===================================================================\n\n\n");


        printf("\nChoisir l'operation a Effectuer : ");
        scanf("%d", &menu);

        switch(menu){
            case 1 :
                printf("\n\n---------------------------------------\n");
                printf("         MENU D'AJOUT                  \n");
                printf("---------------------------------------\n");
                printf("  1 - Ajouter un seul livre.\n");
                printf("  2 - Ajouter plusieurs livres.\n");
                printf("---------------------------------------\n\n");

                do{
                printf("Entrer votre Choix : ");
                scanf("%d", &choix);
                }while(choix!=1 && choix!=2);

                if(choix==1){
                    printf("\nVeuillez Remplir les Infos du Livre : ");
                    Ajout(livre , compteur);
                    compteur++;
                    printf("\n\nAFFICHAGE -------------------------------------------\n");
                    Affichage(livre , compteur);
                    printf("\n\n");

                }else{
                    printf("\nEntrer le nombre de Livres a Ajouter : ");
                    scanf("%d", &nbrLivre);
                    for(int i=0; i<nbrLivre; i++){
                        printf("\nLivre %d : ==============", i+1);
                        Ajout(livre , compteur);
                        compteur++;
                    }
                    printf("\n\nAFFICHAGE -------------------------------------------\n");
                    Affichage(livre , compteur);
                }

                break;
    //=============================================================================================================
            case 2 :
                Affichage(livre , compteur);
                test = Recherche(livre , compteur);
                if(test==-1){
                    printf("\nLe titre a rechercher ne correspond a aucun livre de la liste !\n\n");
                }else{
                    printf("\n\n---------------------------------------\n");
                    printf("          MENU DE MODIFICATION                  \n");
                    printf("---------------------------------------\n");
                    printf("  1 - Modifier le Titre .\n");
                    printf("  2 - Modifier le Prix .\n");
                    printf("  3 - Modifier la Quantite .\n");
                    printf("  4 - Modifier Tous les Champs .\n");
                    printf("---------------------------------------\n\n");

                    do{
                        printf("Entrer votre Choix : ");
                        scanf("%d", &choix);
                    }while(choix!=1 && choix!=2 && choix!=3 && choix!=4);

                    switch(choix){
                        case 1 :
                            printf("\nEntrer Le nouveau Auteur : ");
                            scanf("%s", newAuteur);
                            confimation = Confirm();
                            if(confimation=='N'){
                                break;
                            }else{
                                modifierAuteur(livre , test , newAuteur);
                                printf("\n\nAFFICHAGE -------------------------------------------\n");
                                Affichage(livre , compteur);
                            }
                            break ;
                    //======================================================================================
                        case 2 :
                            printf("\nEntrer Le nouveau Prix : ");
                            scanf("%f", &newPrix);
                            confimation = Confirm();
                            if(confimation=='N'){
                                break;
                            }else{
                                modifierPrix(livre , test , newPrix);
                                printf("\n\nAFFICHAGE -------------------------------------------\n");
                                Affichage(livre , compteur);
                            }
                            break ;
                    //======================================================================================
                        case 3 :
                            printf("\nEntrer La nouvelle Quantite : ");
                            scanf("%d", &newQuantite);
                            confimation = Confirm();
                            if(confimation=='N'){
                                break;
                            }else{
                                modifierQuantite(livre , test , newQuantite);
                                printf("\n\nAFFICHAGE -------------------------------------------\n");
                                Affichage(livre , compteur);
                            }
                            break ;
                    //======================================================================================
                        case 4 :
                            printf("\nEntrer Le nouveau Auteur : ");
                            scanf("%s", newAuteur);
                            printf("\nEntrer Le nouveau Prix : ");
                            scanf("%f", &newPrix);
                            printf("\nEntrer La nouvelle Quantite : ");
                            scanf("%d", &newQuantite);

                            confimation = Confirm();

                            if(confimation=='N'){
                                break;
                            }else{
                                modifierAuteur(livre , test , newAuteur);
                                modifierPrix(livre , test , newPrix);
                                modifierQuantite(livre , test , newQuantite);
                                printf("\n\nAFFICHAGE -------------------------------------------\n");
                                Affichage(livre , compteur);
                            }
                            break ;
                        default :
                            break ;
                    }
                }

                break;

    //=============================================================================================================
            case 3 :
                Affichage(livre , compteur);
                test = Recherche(livre , compteur);
                if(test==-1){
                    printf("\nLe titre a rechercher ne correspond a aucun livre de la liste !\n\n");
                }else{
                    do{
                        printf("\nVoulez-vous vraiment supprimer le titre entre (O/N)? : ");
                        getchar();
                        scanf("%c", &confimation);
                    }while(confimation!='N' && confimation!='O');
                    if(confimation=='N'){
                        printf("\n\nAFFICHAGE -------------------------------------------\n");
                        Affichage(livre , compteur);
                        break;
                    }
                    else{
                        Supprimer(livre , test , compteur);
                        compteur-- ;
                        printf("\n\nAFFICHAGE -------------------------------------------\n");
                        Affichage(livre , compteur);
                    }
                }
                break;
    //=============================================================================================================
            case 4 :
                Affichage(livre , compteur);
                test = Recherche(livre , compteur);
                if(test==-1){
                    printf("\nLe titre a rechercher ne correspond a aucun livre de la liste !\n\n");
                }else {
                    printf("\nLe Livre qui correspond au Titre recherche est : \n");
                    printf("Livre %d : \n", test+1);
                    printf("- Titre : %s .\n", livre[test].titre);
                    printf("- Auteur : %s .\n", livre[test].auteur);
                    printf("- Prix : %.2f .\n", livre[test].prix);
                    printf("- Quantite : %d .\n", livre[test].quantite);
                }
                break;
    //=============================================================================================================
            case 5 :
                printf("\n\n---------------------------------------\n");
                printf("            MENU DE TRI                  \n");
                printf("---------------------------------------\n");
                printf("  1 - Tri Croissant .\n");
                printf("  2 - Tri Decroissant .\n");
                printf("---------------------------------------\n\n");

                do{
                printf("Entrer votre Choix : ");
                scanf("%d", &choix);
                }while(choix!=1 && choix!=2);


                if(choix==1)
                    triCroissant(livre , compteur);
                else
                    triDecroissant(livre , compteur);

                Affichage(livre , compteur);
                printf("\n\n");

                break;
    //=============================================================================================================
            case 6 :
                printf("\n\n-------------------------------------------------------------------------------------\n");
                printf("                              MENU DES STATISTIQUES                        \n");
                printf("-------------------------------------------------------------------------------------\n");
                printf("  1 - Le Nombre Totale de Quantite des Livres en Stock .\n");
                printf("  2 - Les Titres dont le Prix est Superieure a la Moyenne des Prix .\n");
                printf("  3 - Le Nombre de Titres elabore par un Auteur Donne.\n");
                printf("  4 - Le Pourcentage de la Quantite d'un Livre donne par Rapport au Stock Totale .\n");
                printf("-------------------------------------------------------------------------------------\n\n");

                do{
                printf("Entrer votre Choix : ");
                scanf("%d", &choix);
                }while(choix!=1 && choix!=2 && choix!=3 && choix!=4);

                switch(choix){
                    case 1 :
                        totalQuantite = quantiteTotale(livre , compteur);
                        printf("\nLa Quantite Totale des Livres en Stock est : %d .\n\n", totalQuantite);
                        break;
                //==============================================================================================================================
                    case 2 :
                        for(int i=0 ; i<compteur ; i++){
                            totalPrix+=livre[i].prix ;
                        }
                        moyennePrix = (float) (totalPrix/compteur) ;
                        for(int i=0 ; i<compteur ; i++){
                            if(livre[i].prix>moyennePrix){
                                printf("Livre %d : \n", i+1);
                                printf("- Titre : %s .\n", livre[i].titre);
                                printf("- Auteur : %s .\n", livre[i].auteur);
                                printf("- Prix : %.2f .\n", livre[i].prix);
                                printf("- Quantite : %d .\n", livre[i].quantite);
                            }
                        }
                        break;
                //===============================================================================================================================
                    case 3 :
                        test = RechercheAuteur(livre , compteur) ;
                        if(test==-1){
                            printf("\nL'auteur a rechercher ne correspond a aucun livre de la liste !\n\n");
                        }else{
                            nbrTitre = 0 ;
                            for(int i=0 ; i<compteur ; i++){
                                if(strcmp(livre[test].titre , livre[i].titre)==0){
                                    nbrTitre++;
                                }
                            }
                            printf("\nLe nombre de Livres de meme auteur entre est : %d .\n\n", nbrTitre);
                        }
                        break;
                //================================================================================================================================
                    case 4 :
                        totalQuantite = quantiteTotale(livre , compteur);
                        test = Recherche(livre , compteur);
                        if(test==-1){
                            printf("\nLe titre a rechercher ne correspond a aucun livre de la liste !\n\n");
                        }else{
                            pourcentage = (float)(livre[test].quantite * 100)/totalQuantite ;
                            printf("\nLe pourcentage de la quantite de livre choisi par rapport au stock est : %.2f% % .\n\n", pourcentage);
                        }
                        break;
                //================================================================================================================================
                    default :
                        break;
                }
                break;
    //=============================================================================================================
            case 0 :
                break;
    //=============================================================================================================
            default :
                printf("\n\nChoix Indisponible !\n\n");
                break;
        }
    }


    return 0;
}



//FONCTION AJOUTER UN OU DES LIVRES=============================================================
void Ajout(Livre L[], int compteur){
    printf("\n- Titre : ");
    scanf("%s", &L[compteur].titre);
    printf("- Auteur : ");
    scanf("%s", &L[compteur].auteur);
    printf("- Prix : ");
    scanf("%f", &L[compteur].prix);
    printf("- Quantite : ");
    scanf("%d", &L[compteur].quantite);

    printf("\nLivre Ajoute avec Succes !\n");
}


//FONCTION AFFICHER LA LISTE DES LIVRES=====================================================
void Affichage(Livre L[], int compteur){
    for(int i=0 ; i<compteur ; i++){
        printf("\nLivre %d :\n", i+1);
        printf("- Titre : %s .\n", L[i].titre);
        printf("- Auteur : %s .\n", L[i].auteur);
        printf("- Prix : %.2f .\n", L[i].prix);
        printf("- Quantite : %d .\n", L[i].quantite);
    }
}


//FONCTION DE RECHERCHER UN LIVRE PAR TITRE==========================================
int Recherche(Livre L[] , int compteur){
    int exist ;
    char recherche[100];
    printf("\nEntrer le Titre de Livre a Chercher : ");
    scanf("%s", recherche);
    for(int i=0 ; i<compteur ; i++){
        if(strcmp(recherche , L[i].titre)==0){
            exist = i ;
            break ;
        }else
            exist = -1;
    }
    return exist ;
}


//FONCTION RECHERCHER UN LIVRE PAR AUTEUR(STATISTIQUES)==================================================================
int RechercheAuteur(Livre L[] , int compteur){
    int exist ;
    char recherche[100];
    printf("\nEntrer l'Auteur de Livre a Chercher : ");
    scanf("%s", recherche);
    for(int i=0 ; i<compteur ; i++){
        if(strcmp(recherche , L[i].auteur)==0){
            exist = i ;
            break ;
        }else
            exist = -1;
    }
    return exist ;
}



//FONCTION MODIFIER L'AUTEUR D'UN LIVRE==========================================================
void modifierAuteur(Livre L[] , int indice, char newAuteur[]){
    strcpy(L[indice].auteur , newAuteur);
    printf("\nAuteur Modifie avec Succes !\n");
}


//FONCTION MODIFIER LE PRIX D'UN LIVRE==============================================================
void modifierPrix(Livre L[] , int indice, float newPrix){
    L[indice].prix = newPrix ;
    printf("\nPrix Modifie avec Succes !\n");
}


//FONCTION MODIFIER LA QUANTITE D'UN LIVRE========================================================
void modifierQuantite(Livre L[] , int indice , int newQuantite){
    L[indice].quantite = newQuantite ;
    printf("\nQuantite Modifie avec Succes !\n");
}


//FONCTION DE CONFIRMATION DE MODIFICATION ET DE SUPPRESSION============================================================
char Confirm(){
    char confirmation ;
    do{
        printf("\nVoulez-vous vraiment modifier le titre entre (O/N)? : ");
        getchar();
        scanf("%c", &confirmation);
    }while(confirmation!='N' && confirmation!='O');
    return confirmation ;
}




//FONCTION DE SUPPRESSION D'UN LIVRE=====================================================
void Supprimer(Livre L[] , int indice , int compteur){
    for(int i=indice ; i<compteur ; i++){
        L[i] = L[i+1] ;
    }
    printf("\nLivre Supprime avec Succes !\n\n");
}



//FONCTION DE TRI CROISSANT DES TITRES DES LIVRES==========================================================
void triCroissant(Livre L[] , int compteur){
    Livre temp;
    for(int i=0; i<compteur-1 ; i++){
        for(int j=0; j<compteur-1-i ; j++){
            if(strcmp(L[j].titre , L[j+1].titre)>0){
                temp = L[j];
                L[j] = L[j+1] ;
                L[j+1] = temp ;
            }
        }
    }
    printf("\nTri Croissant Effectue avec Succes !\n\n");
}



//FONCTION DE TRI DECROISSANT DES TITRES DES LIVRES===============================================
void triDecroissant(Livre L[] , int compteur){
    Livre temp;
    for(int i=0; i<compteur-1 ; i++){
        for(int j=0; j<compteur-1-i ; j++){
            if(strcmp(L[j].titre , L[j+1].titre)<0){
                temp = L[j];
                L[j] = L[j+1] ;
                L[j+1] = temp ;
            }
        }
    }
    printf("\nTri Decroissant Effectue avec Succes !\n\n");
}



//FONCTION DE CALCUL DE QUANTITE TOTALE DES LIVRES (STATISTIQUES)==================================================
int quantiteTotale(Livre L[] , int compteur){
    int totalQuant;
    for(int i=0 ; i<compteur ; i++){
        totalQuant+=L[i].quantite;
    }
    return totalQuant ;
}

