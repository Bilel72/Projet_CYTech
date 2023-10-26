#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {        // Type Etat
    int numeroEtat;
    bool estFinal;      // Si Etat Finale
} Etat;

typedef struct {        // Type Automate
    char *alphabet;     // Alphabet
    int etatInitial;    // Etat Initial
    int nombreEtats;
    Etat *etats;        // Tableau des Etats
    int **transition;   // Matrice des transitions
} AutomateFini;

void initialiserAutomate(AutomateFini *automate, char *alphabet, int nombreEtats) { // OK

    automate -> alphabet = alphabet ;   //init alphabet
    automate -> nombreEtats = nombreEtats ; //init nombre Etat
    automate ->etatInitial = 0; // par default etat initial est a la position 0
    automate -> etats = malloc(nombreEtats*sizeof(Etat));   // init des Etat par default

    for (int i = 0; i < nombreEtats; i++) {
        automate->etats[i].numeroEtat = i;  // numéro par default
        automate->etats[i].estFinal = false;    // par default non final
    }

    automate -> transition = malloc(nombreEtats*sizeof(int *)); // init de la matrice des transition

    for (int i = 0; i < nombreEtats; i++) {
        automate -> transition[i] = malloc(nombreEtats*sizeof(int));
        for (int j = 0; j < nombreEtats; j++){
            automate ->transition[i][j] = -1 ;  // par default pas de transition donc -1
        }
    }
}

void ajouterEtat (AutomateFini *automate, bool estInitial, bool estFinal) { // OK

    int nombreEtats = 1 + automate -> nombreEtats ; // augmente le nombre d'etat de 1

    Etat nouvelleEtat;

    nouvelleEtat.estFinal = estFinal;   // init le nouvelle etat avec les parametres
    nouvelleEtat.numeroEtat = nombreEtats;

    Etat *nouveauxEtats = malloc(nombreEtats*sizeof(Etat)); // alloue la memoire pour le nouveau tableau
    for (int i = 0; i < nombreEtats - 1; i++){
        nouveauxEtats[i] = automate -> etats[i]; // copie les ancients etats dans le nouveau tableau
    }

    nouveauxEtats[nombreEtats] = nouvelleEtat; // ajoute le nouvelle etat dans le tableau
    free(automate -> etats);    // libere la memoire de l'ancien tableau
    automate -> etats = nouveauxEtats ;

    if (estInitial){
        automate -> etatInitial = nombreEtats -1 ; // change etat initial si demandé
    }

}

void modifierEtat (AutomateFini *automate, int numeroEtat, bool estInitial, bool estFinal) { // OK

    automate -> etats[numeroEtat].estFinal = estFinal ;
    if (estInitial){
        automate -> etatInitial = numeroEtat ; // change etat initial si demandé
    }

}

void supprimerEtat (AutomateFini *automate, int numeroEtat ){ // Relou

}

void ajouterTransition (AutomateFini *automate, Etat depart, Etat fin, int lettre ){ // OK

    automate -> transition[depart.numeroEtat][fin.numeroEtat] = lettre ;

}

void supprimerTransition (AutomateFini *automate, Etat depart, Etat fin ){ // OK

    automate -> transition[depart.numeroEtat][fin.numeroEtat] = -1 ;
}

void afficherAutomate(AutomateFini *automate){ // Plus Tard

}

void supprimerAutomate(AutomateFini *automate){ // OK

    free(automate);
}

void importerAutomate (char emplacement){ // Plus Tard

}

void exporterAutomate (AutomateFini *automate){ // Plus Tard

}

bool verifierMotDansAutomate(AutomateFini *automate, char mot){ // Plus Tard

}

bool estComplet(AutomateFini *automate){ // Plus Tard

}

bool estDeterministe(AutomateFini *automate){ // Plus Tard

}

void rendreComplet(AutomateFini *automate){ // Plus Tard

}

void rendreDeterministe(AutomateFini *automate){ // Plus Tard

}

int main() {
    /*
    int choix;

    while (true)
    {
        printf("---------------------------------------------\n");
        printf("Voici le menu de notre projet\n");
        printf("Si vous voulez :\n");
        printf("    Creez un automate alors tapez 1 \n");
        printf("    Modifiez un automate alors tapez 2 \n");
        printf("    Importez un automate alors tapez 3 \n");
        printf("    Exportez un automate alors tapez 4 \n");
        printf("    Supprimez un automate alors tapez 5 \n");
        printf("---------------------------------------------\n");

        scanf("%d", &choix);

        switch (choix)
        {
            case 1:

            case 2:

            case 3:

            case 4:

            case 5:

            default:
                printf("Choix non valide. Veuillez reessayer.\n");
        }
    }
    */
    // Exemple automate 1

    AutomateFini *automate ;
    char alphabet[2] ;
    alphabet[0] = "a" ;
    alphabet[1] = "b" ;
    int nombreEtat = 2 ;

    initialiserAutomate (automate ,alphabet, nombreEtat);
    modifierEtat(automate,0,true,false);
    modifierEtat(automate,1,false,true);
    ajouterTransition(automate,automate -> etats[0],automate -> etats[1],1);
    ajouterTransition(automate,automate -> etats[0],automate -> etats[0],0);

    return 0;
}
