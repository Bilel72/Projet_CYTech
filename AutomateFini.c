#include<stdio.h>
#include<stdlib.h>
#include "AutomateFini.h"
#include <stdbool.h>


void initialiserAutomate(AutomateFini *automate, char *alphabet, int nombreEtats) { // OK

    automate -> alphabet = alphabet ;   //init alphabet
    automate -> nombreEtats = nombreEtats ; //init nombre Etat
    automate ->etatInitial = 0; // par default etat initial est a la position 0
    automate -> etats = malloc(nombreEtats*sizeof(Etat));   // init des Etat par default

    for (int i = 0; i < nombreEtats; i++) {
        automate->etats[i].numeroEtat = i;  // numero par default
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