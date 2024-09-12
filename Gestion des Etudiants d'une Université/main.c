#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int jour ;
    int mois ;
    int annee ;
}Date;


typedef struct {
    int numero ;
    char nom[100];
    char prenom[100];
    char dateNaissance[100];
    int departement;
    float note;
}Etudiant;


void ajouterEtudiant(Etudiant E[] , int compteur);

void Affichage(Etudiant E[] , int debut ,int compteur);

int RechercheParNom(Etudiant E[] , int compteur);
int RechercheParDepart(Etudiant E[] , int compteur);
int RechercheParNumero(Etudiant E[] , int compteur);

float moyenneGeneraleDepart(Etudiant E[] , int compteur , int Departement);
float moyenneGeneraleUniversite(Etudiant E[] , int compteur);

char Confirmation();

void modifierNom(Etudiant E[] , char newNom[] , int indice);
void modifierPrenom(Etudiant E[] , char newPrenom[] , int indice);
void modifierDateNaissance(Etudiant E[] , char newDate[] , int indice);
void modifierDepartement(Etudiant E[] , int newDepartement , int indice);
void modifierNote(Etudiant E[] , float newNote , int indice);

void Supprimer(Etudiant E[] , int indice ,int compteur);

void TypeTri();

void Tri_Croissant(Etudiant E[] , int compteur , int choix);
void Tri_Decroissant(Etudiant E[] , int compteur , int choix);
void Tri_Statut(Etudiant E[], int compteur);
void TriNumero(Etudiant E[] , int compteur);

int nbrEtudiantParDepart(Etudiant E[], int compteur , int Departement);
int nbrEtudiantReussiParDepart(Etudiant E[] , int compteur , int Departement);
int superieurSeuil(Etudiant E[] , int compteur , float Seuil);




int main()
{
    Etudiant etudiant[100] = {
        {1, "Ali", "Ali", "12/03/2001", 1, 15},
        {2, "Badr", "Badr", "25/07/2000", 2, 14},
        {3, "Maryam", "Maryam", "01/01/1999", 3, 6},
        {4, "Omar", "Omar", "05/09/2002", 4, 18},
        {5, "Laila", "Laila", "18/06/2001", 1, 11},
        {6, "Mourad", "Mourad", "01/11/2001", 2, 14},
        {7, "Houssam", "Houssam", "16/10/2000", 3, 16},
        {8, "Sara", "Sara", "04/02/2002", 4, 9},
        {9, "Achraf", "Achraf", "23/06/2001", 1, 15},
        {10, "Imane", "Imane", "10/03/1999", 3, 11}
    };

    int menu = -1 ;//variable pour naviguer dans le menu principale
    int choix ;//variable pour navigher dans les sous-menus de modification , recherche et statistique
    int compteur = 10 ;//le nombre des étudiants ajoutée
    int nbrEtudiant;//le nombre des étudiants à ajouter
    int test ;//variable pour tester quelques fonction qui ont une valeur de retour
    int tri ;//choix du type de tri (Croissant , Decroissant)
    int count ;//utilisé dans la partie statistiques

    float seuil ;
    float moyenne_generale ;

    char confirm;//confirmer la modification et la suppression


    char newNom[100];
    char newPrenom[100] ;
    char newDateNaissance[10];
    int newDepartement ;
    float newNote ;



    printf("*************************************************************************\n");
    printf("*                 Programme de Gestion des Etudiants                 *\n");
    printf("*************************************************************************\n\n\n");


    while(menu!=0){
        printf("===================================================================\n");
        printf("                         MENU PRINCIPALE                         \n");
        printf("===================================================================\n");
        printf("  1 - Ajouter un ou plusieurs Etudiants . \n");
        printf("  2 - Affichage . \n");
        printf("  3 - Calculer la Moyenne Generale . \n");
        printf("  4 - Rechercher un Etudiant . \n");
        printf("  5 - Modifier un Etudiant . \n");
        printf("  6 - Supprimer un Etudiant .\n");
        printf("  7 - Trier la Liste des Etudiants .\n");
        printf("  8 - Statistiques .\n");
        printf("\n  0 - Arreter le Programme . \n");
        printf("===================================================================\n\n\n");

        printf("\nChoisir l'operation a Effectuer : ");
        scanf("%d", &menu);

        switch(menu){
            case 0 :
                break;
            case 1 :
                printf("\n\n---------------------------------------\n");
                printf("         MENU D'AJOUT                  \n");
                printf("---------------------------------------\n");
                printf("  1 - Ajouter un seul Etudiant.\n");
                printf("  2 - Ajouter plusieurs Etudiants.\n");
                printf("\n  0 - Retour au Menu Principale .\n");
                printf("---------------------------------------\n\n");

                do{
                    printf("Entrer votre Choix : ");
                    scanf("%d", &choix);
                }while(choix<0 || choix>2);

                if(choix==1){
                    printf("\nVeuillez Remplir les Infos de l'Etudiant : ");
                    ajouterEtudiant(etudiant , compteur);
                    compteur++;
                }else if(choix==2){
                    do{
                        printf("\nEntrer le nombre de Livres a Ajouter : ");
                        scanf("%d", &nbrEtudiant);
                    }while(nbrEtudiant<0 || nbrEtudiant>(100-compteur));
                    for(int i=0; i<nbrEtudiant; i++){
                        printf("\nEtudiant %d : ------------------", i+1);
                        ajouterEtudiant(etudiant , compteur);
                        compteur++;
                    }
                }else{
                    break;
                }
                printf("\n\n");

                break;
    //======================================================================================================================
            case 2 :
                printf("\n\nAFFICHAGE \n");
                TriNumero(etudiant , compteur);
                Affichage(etudiant , 0 , compteur);
                printf("\n\n");
                break;
    //======================================================================================================================
            case 3 :
                printf("\n\n----------------------------------------------------\n");
                printf("                  MOYENNE GENERALE                 \n");
                printf("----------------------------------------------------\n");
                printf("  1 - La Moyenne Generale de Chaque Departement .\n");
                printf("  2 - La Moyenne Generale de l'Universite Entiere .\n");
                printf("\n  0 - Retour au Menu Principale .\n");
                printf("----------------------------------------------------\n\n");

                do{
                    printf("Entrer votre Choix : ");
                    scanf("%d", &choix);
                }while(choix<0 || choix>2);

                if(choix==1){
                    printf("\nLa Moyenne Generale de Chaque Departement est : \n");
                    moyenne_generale = moyenneGeneraleDepart(etudiant , compteur , 1);
                    printf("- Informatique : %.2f .\n", moyenne_generale);
                    moyenne_generale = moyenneGeneraleDepart(etudiant, compteur, 2);
                    printf("- RH : %.2f .\n", moyenne_generale);
                    moyenne_generale = moyenneGeneraleDepart(etudiant, compteur, 3);
                    printf("- Electrique : %.2f .\n", moyenne_generale);
                    moyenne_generale = moyenneGeneraleDepart(etudiant, compteur, 4);
                    printf("- Finance : %.2f .\n", moyenne_generale);
                }else if (choix==2){
                    moyenne_generale=moyenneGeneraleUniversite(etudiant , compteur);
                    printf("\nLa Moyenne Generale de l'Universite est : %.2f\n", moyenne_generale);
                }
                break;
    //======================================================================================================================
            case 4 :
                printf("\n\n---------------------------------------\n");
                printf("         MENU DE RECHERCHE                 \n");
                printf("---------------------------------------\n");
                printf("  1 - Rechercher par Nom.\n");
                printf("  2 - Rechercher par Departement.\n");
                printf("\n  0 - Retour au Menu Principale .\n");
                printf("---------------------------------------\n\n");

                do{
                    printf("Entrer votre Choix : ");
                    scanf("%d", &choix);
                }while(choix<0 || choix>2);

                if(choix==1){
                    test = RechercheParNom(etudiant , compteur);
                    if(test==-1)
                        printf("\nLe Nom recherche ne correspond a aucun Etudiant de la Liste !\n\n");
                    else
                        Affichage(etudiant , test , test+1);
                }else if(choix==2){
                    test = RechercheParDepart(etudiant , compteur);
                    if(test==0)
                        printf("\nLe Departement recherche ne contient aucun Etudiant de la Liste !\n\n");

                }else{
                    break;
                }

                printf("\n\n");
                break;
    //======================================================================================================================
            case 5 :
                    printf("\n\n---------------------------------------\n");
                    printf("          MENU DE MODIFICATION                  \n");
                    printf("--------------------------------------------\n");
                    printf("  1 - Modifier le Nom .\n");
                    printf("  2 - Modifier le Prenom .\n");
                    printf("  3 - Modifier la Date de Naissance .\n");
                    printf("  4 - Modifier le Departement .\n");
                    printf("  5 - Modifier la Note Generale.\n");
                    printf("  6 - Modifier Tous Les Champs .\n");
                    printf("\n  0 - Retour au Menu Principale .\n");
                    printf("--------------------------------------------\n\n");

                    do{
                        printf("Entrer votre Choix : ");
                        scanf("%d", &choix);
                    }while(choix<0 || choix>6);


                    switch(choix){
                //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        case 1 :
                            test = RechercheParNumero(etudiant , compteur);
                            if(test==-1)
                                printf("\nLe Numero recherche ne correspond a aucun Etudiant de la Liste !\n\n");
                            else{
                                printf("\nEntrer le Nouveau Nom : ");
                                scanf("%s", newNom);
                                confirm = Confirmation();
                                if(confirm=='N'){
                                    printf("\nOperation Annule !\n");
                                    break;
                                }
                                else{
                                    modifierNom(etudiant , newNom , test);
                                    Affichage(etudiant , test , test+1);
                                }
                            }
                            printf("\n\n");
                            break ;
                    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        case 2 :
                            test = RechercheParNumero(etudiant , compteur);
                            if(test==-1)
                                printf("\nLe Numero recherche ne correspond a aucun Etudiant de la Liste !\n");
                            else{
                                printf("\nEntrer le Nouveau Prenom : ");
                                scanf("%s", newPrenom);
                                confirm = Confirmation();
                                if(confirm=='N'){
                                    printf("\nOperation Annule !\n");
                                    break;
                                }
                                else{
                                    modifierPrenom(etudiant , newPrenom , test);
                                    Affichage(etudiant , test , test+1);
                                }
                            }
                            printf("\n\n");
                            break;
                    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        case 3 :
                            test = RechercheParNumero(etudiant , compteur);
                            if(test==-1)
                                printf("\nLe Numero recherche ne correspond a aucun Etudiant de la Liste !\n\n");
                            else{
                                printf("\nEntrer le Nouvelle Date de Naissance (Ex: jour/mois/Annee) : ");
                                scanf("%s", newDateNaissance);
                                confirm = Confirmation();
                                if(confirm=='N'){
                                    printf("\nOperation Annule !\n");
                                    break;
                                }
                                else{
                                    modifierDateNaissance(etudiant , newDateNaissance , test);
                                    Affichage(etudiant , test , test+1);
                                }
                            }
                            printf("\n\n");
                            break;
                    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        case 4 :
                            test = RechercheParNumero(etudiant , compteur);
                            if(test==-1)
                                printf("\nLe Numero recherche ne correspond a aucun Etudiant de la Liste !\n\n");
                            else{
                                printf("- Departement : \n");
                                printf("\t1- Informatique.\n\t2- RH.\n\t3- Electrique.\n\t4- Finance.\n");
                                do{
                                    printf("Entrer le Numero qui correspond au Nouveau Departement : ");
                                    scanf("%d", &newDepartement);
                                }while(newDepartement!=1 && newDepartement!=2 && newDepartement!=3 && newDepartement!=4);
                                confirm = Confirmation();
                                if(confirm=='N'){
                                    printf("\nOperation Annule !\n");
                                    break;
                                }
                                else{
                                    modifierDepartement(etudiant , newDepartement , test);
                                    Affichage(etudiant , test , test+1);
                                }
                            }
                            printf("\n\n");
                            break;
                    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        case 5 :
                            test = RechercheParNumero(etudiant , compteur);
                            if(test==-1)
                                printf("\nLe Numero recherche ne correspond a aucun Etudiant de la Liste !\n\n");
                            else{
                                do{
                                    printf("\nEntrer la Nouvelle Note Generale : ");
                                    scanf("%f", &newNote);
                                }while(newNote<0 || newNote>20);
                                confirm = Confirmation();
                                if(confirm=='N'){
                                    printf("\nOperation Annule !\n");
                                    break;
                                }
                                else{
                                    modifierNote(etudiant , newNote , test);
                                    Affichage(etudiant , test , test+1);
                                }
                            }
                            printf("\n\n");
                            break;
                    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        case 6 :
                            test = RechercheParNumero(etudiant , compteur);
                            if(test==-1)
                                printf("\nLe Numero recherche ne correspond a aucun Etudiant de la Liste !\n\n");
                            else{
                                printf("\nEntrer le Nouveau Nom : ");
                                scanf("%s", newNom);
                                printf("\nEntrer le Nouveau Prenom : ");
                                scanf("%s", newPrenom);
                                printf("\nEntrer le Nouvelle Date de Naissance (Ex: jour/mois/Annee) : ");
                                scanf("%s", newDateNaissance);
                                printf("- Departement : \n");
                                printf("\t1- Informatique.\n\t2- RH.\n\t3- Electrique.\n\t4- Finance.\n");
                                do{
                                    printf("Entrer le Numero qui correspond au Nouveau Departement : ");
                                    scanf("%d", &newDepartement);
                                }while(newDepartement<1 || newDepartement>4);
                                do{
                                    printf("\nEntrer la Nouvelle Note Generale : ");
                                    scanf("%f", &newNote);
                                }while(newNote<0 || newNote>20);

                                confirm = Confirmation();
                                if(confirm=='N'){
                                    printf("\nOperation Annule !\n");
                                    break;
                                }
                                else{
                                    modifierNom(etudiant , newNom , test);
                                    modifierPrenom(etudiant , newPrenom , test);
                                    modifierDateNaissance(etudiant , newDateNaissance , test);
                                    modifierDepartement(etudiant , newDepartement , test);
                                    modifierNote(etudiant , newNote , test);

                                    Affichage(etudiant , test , test+1);
                                }
                            }
                            printf("\n\n");
                            break;
                    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        case 0 :
                            break;
                        default :
                            break;
                    }

                break;
    //======================================================================================================================
            case 6 :
                test = RechercheParNumero(etudiant , compteur);
                if(test==-1)
                    printf("\nLe Numero recherche ne correspond a aucun Etudiant de la Liste !\n\n");
                else{
                    confirm = Confirmation();
                    if(confirm=='N'){
                        printf("\nOperation Annule !\n");
                        break;
                    }else
                        Supprimer(etudiant , test , compteur);
                        compteur--;
                }
                printf("\n\n");
                break;
    //========================================================================================================================
            case 7 :
                Modify :
                printf("\n\n---------------------------------------\n");
                printf("          MENU DE MODIFICATION                  \n");
                printf("--------------------------------------------\n");
                printf("  1 - Tri par Nom .\n");
                printf("  2 - Tri par Note Generale .\n");
                printf("  3 - Tri par Statut de Reussite .\n");
                printf("\n  0 - Retour au Menu Principale .\n");
                printf("--------------------------------------------\n\n");

                do{
                    printf("Entrer votre Choix : ");
                    scanf("%d", &choix);
                }while(choix<0 || choix>3);

                switch(choix){
                //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        case 1 :
                            TypeTri();
                            do{
                                printf("Entrer votre Choix : ");
                                scanf("%d", &tri);
                            }while(tri!=1 && tri!=2 && tri!=0);

                            if(tri==1){
                                Tri_Croissant(etudiant , compteur , choix);
                                //Tri_Croissant_Nom(etudiant , compteur );
                                Affichage(etudiant , 0 , compteur);
                            }else if(tri==2){
                                Tri_Decroissant(etudiant , compteur , choix);
                                //Tri_Decroissant_Nom(etudiant , compteur);
                                Affichage(etudiant , 0 , compteur);
                            }else
                                goto Modify;

                            break ;
                    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        case 2 :
                            TypeTri();
                            do{
                                printf("Entrer votre Choix : ");
                                scanf("%d", &tri);
                            }while(tri!=1 && tri!=2 && tri!=0);

                            if(tri==1){
                                Tri_Croissant(etudiant , compteur , choix);
                                Affichage(etudiant , 0 , compteur);
                            }else if(tri==2){
                                Tri_Decroissant(etudiant , compteur , choix);
                                Affichage(etudiant , 0 , compteur);
                            }else
                                goto Modify;
                            break ;
                    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        case 3 :
                            Tri_Statut(etudiant , compteur);
                            break ;
                    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        case 0 :
                            break ;
                        default :
                            break ;
                }


                break;
    //==================================================================================================================
            case 8 :
                printf("\n\n-----------------------------------------------------------------------\n");
                printf("                         MENU DE STATISTIQUES                  \n");
                printf("----------------------------------------------------------------------\n");
                printf("  1 - Nombre Totales des Etudiants .\n");
                printf("  2 - Nombre d'Etudiants dans Chaque Departement .\n");
                printf("  3 - Etudiants ayant une Moyenne Superieure a un Seuil Donne .\n");
                printf("  4 - 3 Etudiants avec la Meilleure Note .\n");
                printf("  5 - Nombre d'Etudiants ayant reussi dans chaque Departement.\n");
                printf("\n  0 - Retour au Menu Principale .\n");
                printf("----------------------------------------------------------------------\n\n");

                do{
                    printf("Entrer votre Choix : ");
                    scanf("%d", &choix);
                }while(choix<0 || choix>5);

                switch(choix){
                //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    case 1 :
                        printf("\nLe Nombre Totales des Etudiants est : %d Etudiants.\n\n", compteur);
                        break;
                //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    case 2 :
                        printf("\nLe Nombre des Etudiants par Chaque Departement est : \n");
                        count=nbrEtudiantParDepart(etudiant, compteur, 1);
                        printf("- Informatique : %d Etudiants.\n", count);
                        count=nbrEtudiantParDepart(etudiant, compteur, 2);
                        printf("- RH : %d Etudiants.\n", count);
                        count=nbrEtudiantParDepart(etudiant, compteur, 3);
                        printf("- Electrique : %d Etudiants.\n", count);
                        count=nbrEtudiantParDepart(etudiant, compteur, 4);
                        printf("- Finance : %d Etudiants.\n", count);
                        break;
                //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    case 3 :
                        do{
                            printf("\nEntrer le Seuil : ");
                            scanf("%f", &seuil);
                        }while(seuil<0 || seuil>20);
                        test = superieurSeuil(etudiant , compteur , seuil);
                        if(test==0)
                            printf("\nAucun Etudiant a obtenu une note superieure a %.2f !\n", seuil);
                        break;
                //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    case 4 :
                        Tri_Decroissant(etudiant , compteur , 2);
                        Affichage(etudiant , 0 , 3);
                        break;
                //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    case 5 :
                        printf("\nLe Nombre des Etudiants Reussi dans Chaque Departement est : \n");
                        count = nbrEtudiantReussiParDepart(etudiant, compteur, 1);
                        printf("- Informatique : %d Etudiants.\n", count);
                        count = nbrEtudiantReussiParDepart(etudiant, compteur, 2);
                        printf("- RH : %d Etudiants.\n", count);
                        count = nbrEtudiantReussiParDepart(etudiant, compteur, 3);
                        printf("- Electrique : %d Etudiants.\n", count);
                        count = nbrEtudiantReussiParDepart(etudiant, compteur, 4);
                        printf("- Finance : %d Etudiants.\n", count);

                        printf("\n\n");
                        break;
                //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    case 0 :
                        break;
                    default :
                        break;

                }

                break;
            default :
                break;
        }
    }

    return 0;
}


//FONCTION D'AJOUT DES ETUDIANT ========================================================
void ajouterEtudiant(Etudiant E[] , int compteur){
    debut:
    printf("\n- Numero : ");
    scanf("%d", &E[compteur].numero);
    for(int i=0 ; i<compteur ;i++){
        if(E[compteur].numero == E[i].numero){
            printf("Le Numero Entre deja existe ! Veuillez entrer un Numero Unique.\n");
            goto debut ;
            break;
        }
    }
    printf("- Nom : ");
    scanf("%s", E[compteur].nom);
    printf("- Prenom : ");
    scanf("%s", E[compteur].prenom);
    printf("- Date (ex: jour/mois/annee) : ");
    scanf("%s", E[compteur].dateNaissance);
    printf("- Departement : \n");
    printf("\t1- Informatique.\n\t2- RH.\n\t3- Electrique.\n\t4- Finance.\n");

    do{
        printf("Entrer le numero correspond au Departement : ");
        scanf("%d", &E[compteur].departement);
    }while(E[compteur].departement!=1 && E[compteur].departement!=2 && E[compteur].departement!=3 && E[compteur].departement!=4);

    do{
        printf("- Note Generale : ");
        scanf("%f", &E[compteur].note);
    }while(E[compteur].note<0 || E[compteur].note>20);

    printf("\nEtudiant Ajoute avec Succes !\n");
}


//FONCTION D'AFFICHAGE DES ETUDIANT ========================================================
void Affichage(Etudiant E[] , int debut ,int compteur){
    for(int i=debut ; i<compteur ; i++){
        printf("\nEtudiant %d : -------------------------\n", i+1);
        printf("- Numero : %d .\n", E[i].numero);
        printf("- Nom : %s .\n", E[i].nom);
        printf("- Prenom : %s .\n", E[i].prenom);
        printf("- Date de Naissance : %s .\n", E[i].dateNaissance);
        if(E[i].departement==1)
            printf("- Departement : Informatique .\n");
        else if(E[i].departement==2)
            printf("- Departement : RH .\n");
        else if(E[i].departement==3)
            printf("- Departement : Electrique .\n");
        else
            printf("- Departement : Finance .\n");

        printf("- Note Generale : %.2f .\n", E[i].note);
    }
}


//FONCTION DE RECHERCHE PAR NOM DE L'ETUDIANT ========================================================
int RechercheParNom(Etudiant E[] , int compteur){
    int exist ;
    char nom[100];
    printf("\nEntrer le Nom de l'Etudiant a Chercher : ");
    scanf("%s", nom);
    for(int i=0 ; i<compteur ; i++){
        if(strcmp(nom , E[i].nom)==0){
            exist = i ;
            break ;
        }else
            exist = -1;
    }
    return exist ;
}


//FONCTION DE RECHERCHE PAR DEPARTEMENT DE L'ETUDIANT ========================================================
int RechercheParDepart(Etudiant E[] , int compteur){
    int exist = 0;
    int depart;
    printf("- Departement : \n");
    printf("\t1- Informatique.\n\t2- RH.\n\t3- Electrique.\n\t4- Finance.\n");
    do{
        printf("Entrer le Departement a Chercher : ");
        scanf("%d", &depart);
    }while(depart!=1 && depart!=2 && depart!=3 && depart!=4);

    for(int i=0 ; i<compteur ; i++){
        if(E[i].departement == depart){
            Affichage(E , i , i+1);
            exist=1;
        }
    }
    return exist ;
}

//FONCTION DE RECHERCHE PAR NUMERO DE L'ETUDIANT========================================================
int RechercheParNumero(Etudiant E[] , int compteur){
    int id;
    printf("\nEntrer le Numero de l'Etudiant a Chercher : ");
    scanf("%d", &id);
    for(int i=0 ; i<compteur ; i++){
        if(E[i].numero == id)
            return i ;
    }
    return -1 ;
}



//FONCTION DE CONFIRMATION DE MODIFICATION ET DE SUPPRESSION ========================================================
char Confirmation(){
    char confirmer ;
    do{
        printf("\nVoulez-vous vraiment effectuer cette operation (O/N): ");
        getchar();
        scanf("%c", &confirmer);
    }while(confirmer!='N' && confirmer!='O');
    return confirmer;
}


//FONCTION DE MODIFICATION DE LA NOTE GENERALE========================================================
void modifierNote(Etudiant E[] , float newNote , int indice){
    E[indice].note = newNote;
    printf("\nNote Generale Modifie Avec Succes !");
}

//FONCTION DE MODIFICATION DU DEPARTEMENT ========================================================
void modifierDepartement(Etudiant E[] , int newDepartement , int indice){
    E[indice].departement = newDepartement;
    printf("\nDepartement Modifie Avec Succes !");
}

//FONCTION DE MODIFICATION DE LA DATE DE NAISSANCE ========================================================
void modifierDateNaissance(Etudiant E[] , char newDate[] , int indice){
    strcpy(E[indice].dateNaissance , newDate);
    printf("\nDate de Naissance Modifie Avec Succes !");
}

//FONCTION DE MODIFICATION DU PRENOM ========================================================
void modifierPrenom(Etudiant E[] , char newPrenom[] , int indice){
    strcpy(E[indice].prenom , newPrenom);
    printf("\nPrenom Modifie Avec Succes !");
}

//FONCTION DE MODIFICATION DU NOM ========================================================
void modifierNom(Etudiant E[] , char newNom[] , int indice){
    strcpy(E[indice].nom , newNom);
    printf("\nNom Modifie Avec Succes !");
}


//FONCTION DE SUPPRESSION D'UN ETUDIANT ============================================================
void Supprimer(Etudiant E[] , int indice , int compteur){
    for(int i=indice ; i<compteur ; i++){
        E[i] = E[i+1] ;
    }
    printf("\nEtudiant Supprime avec Succes !\n\n");
}


//FONCTION POUR MENU DE TYPE DE TRI (CROISSANT OU DECROISSANT) ============================================
void TypeTri(){
    printf("\n\n---------------------------------------\n");
    printf("         TYPE DE TRI                  \n");
    printf("---------------------------------------\n");
    printf("  1 - Tri Croissant.\n");
    printf("  2 - Tri Decroissant.\n");
    printf("\n  0 - Retour au Menu Precedent .\n");
    printf("---------------------------------------\n\n");
}


//FONCTION DE TRI CROISSANT ===========================================================================
void Tri_Croissant(Etudiant E[] , int compteur , int choix){
    Etudiant temp;
    if(choix==1){
        for(int i=0; i<compteur-1 ; i++){
            for(int j=0; j<compteur-1-i ; j++){
                if(strcmp(E[j].nom , E[j+1].nom)>0){
                    temp = E[j];
                    E[j] = E[j+1] ;
                    E[j+1] = temp ;
                }
            }
        }
        printf("\nTri Croissant par Nom Effectue avec Succes 2 !\n\n");
    }else if(choix==2){
        for(int i=0; i<compteur-1 ; i++){
            for(int j=0; j<compteur-1-i ; j++){
                if(E[j].note > E[j+1].note){
                    temp = E[j];
                    E[j] = E[j+1] ;
                    E[j+1] = temp ;
                }
            }
        }
        printf("\nTri Croissant par Note Effectue avec Succes 1 !\n\n");
    }
}



//FONCTION DE TRI DECROISSANT ===========================================================================
void Tri_Decroissant(Etudiant E[] , int compteur , int choix){
    Etudiant temp;
    if(choix==1){
        for(int i=0; i<compteur-1 ; i++){
            for(int j=0; j<compteur-1-i ; j++){
                if(strcmp(E[j].nom , E[j+1].nom)<0){
                    temp = E[j];
                    E[j] = E[j+1] ;
                    E[j+1] = temp ;
                }
            }
        }
        printf("\nTri Decroissant par Nom Effectue avec Succes !\n\n");
    }else if(choix==2){
        for(int i=0; i<compteur-1 ; i++){
            for(int j=0; j<compteur-1-i ; j++){
                if(E[j].note < E[j+1].note){
                    temp = E[j];
                    E[j] = E[j+1] ;
                    E[j+1] = temp ;
                }
            }
        }
        printf("\nTri Deroissant par Note Effectue avec Succes !\n\n");
    }
}


//FONCTION DE TRI PAR STATUT =======================================================================
void Tri_Statut(Etudiant E[], int compteur){
    printf("\nLes Etudiants Reussis sont : \n");
    for(int i=0 ; i<compteur; i++){
        if(E[i].note>=10){
            Affichage(E , i , i+1);
        }
    }
    printf("\n\nLes Etudiants Non Reussis sont : \n");
    for(int i=0 ; i<compteur; i++){
        if(E[i].note < 10){
            Affichage(E , i , i+1);
        }
    }
}


//FONCTION D'AFFICHAGE DE NOMBRE DES ETUDIANTS DANS CHAQUE DEPARTEMENT ============================================
int nbrEtudiantParDepart(Etudiant E[] , int compteur , int Departement){
    int count = 0;
    for(int i=0 ; i<compteur ; i++){
        if(E[i].departement==Departement)
            count++;
    }
    return count ;
}


//FONCTION D'AFFICHAGE DE NOMBRE DES ETUDIANTS REUSSI DANS CHAQUE DEPARTEMENT ============================================
int nbrEtudiantReussiParDepart(Etudiant E[] , int compteur , int Departement){
    int count = 0;
    for(int i=0 ; i<compteur ; i++){
        if(E[i].departement==Departement && E[i].note>=10)
            count++;
    }
    return count ;
}


//FONCTION D'AFFICHAGE DES ETUDIANTS AYANT UNE NOTE SUPERIEUR A UN SEUIL DONNE ============================================
int superieurSeuil(Etudiant E[] , int compteur , float Seuil){
    int count = 0 ;
    for(int i=0 ; i<compteur ; i++){
        if(E[i].note>Seuil){
            Affichage(E , i , i+1);
            count++;
        }
    }
    return count ;
}


//FONCTION DE CALCUL DE MOYENNE GENERALE DE CHAQUE DEPARTEMENT==========================================================
float moyenneGeneraleDepart(Etudiant E[] , int compteur , int Departement){
    float somme = 0 ;
    int count = 0 ;
    float moyenne ;
    for(int i=0 ; i<compteur ; i++){
        if(E[i].departement==Departement){
            somme += E[i].note;
            count++;
        }
    }
    if(count==0){
        printf("Le Departement ne Contient aucun Etudiant !");
        moyenne = 0 ;
    }else
        moyenne = somme/count;
    return moyenne;
}


//FONCTION DE CALCUL DE MOYENNE GENERALE DE L'UNIVERSITE==========================================================
float moyenneGeneraleUniversite(Etudiant E[] , int compteur){
    float somme = 0 ;
    float moyenne ;
    for(int i=0 ; i<compteur ; i++){
            somme += E[i].note;
    }
    if(compteur==0){
        printf("L'Universite ne Contient aucun Etudiant !");
        moyenne = 0 ;
    }else
        moyenne = somme/compteur;
    return moyenne;
}


//FONCTION DE TRI PAR NUMERO UNIQUE DE L'ETUDIANT ========================================================================
void TriNumero(Etudiant E[] , int compteur){
    Etudiant temp ;
    for(int i=0; i<compteur-1 ; i++){
        for(int j=0; j<compteur-1-i ; j++){
            if(E[j].numero > E[j+1].numero){
                temp = E[j];
                E[j] = E[j+1] ;
                E[j+1] = temp ;
            }
        }
    }
}
