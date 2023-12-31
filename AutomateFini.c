#include<stdio.h>
#include<stdlib.h>
#include "AutomateFini.h"
#include <stdbool.h>

/*
    Initialise un automate
    @param automate : automate a initialiser
    @param alphabet : alphabet de l'automate
    @param nombreEtats : nombre d'etats de l'automate
*/
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
/*
    Ajoute une transition a un automate
    @param automate : automate auquel on veut ajouter une transition
    @param depart : etat de depart de la transition
    @param fin : etat d'arrivee de la transition
    @param lettre : lettre de la transition
*/
void ajouterTransition (AutomateFini *automate, Etat depart, Etat fin, int lettre ){ // OK

    automate -> transition[depart.numeroEtat][fin.numeroEtat] = lettre ;

}
/*
    Supprime une transition a un automate
    @param automate : automate auquel on veut supprimer une transition
    @param depart : etat de depart de la transition
    @param fin : etat d'arrivee de la transition
*/
void supprimerTransition (AutomateFini *automate, Etat depart, Etat fin ){ // OK

    automate -> transition[depart.numeroEtat][fin.numeroEtat] = -1 ;
}
/*
    Affiche un automate
    @param automate : automate a afficher
*/
void afficherAutomate(AutomateFini *automate){ // Plus Tard

}
/*
    Supprime un automate
    @param automate : automate a supprimer
*/
void supprimerAutomate(AutomateFini *automate){ // OK

    free(automate);
}
/*
    Importe un automate
    @param emplacement : emplacement de l'automate a importer

*/
void importerAutomate (char emplacement){ // Plus Tard

}
/*
    Exporte un automate
    @param automate : automate a exporter
*/
void exporterAutomate (AutomateFini *automate){ // Plus Tard

}
/*
    Verifie si un mot est dans un automate
    @param automate : automate dans lequel on veut verifier le mot
    @param mot : mot a verifier

*/
bool verifierMotDansAutomate(AutomateFini *automate, char mot){ // Plus Tard

}
/*
    Verifie si un automate est complet
    @param automate : automate a verifier
*/
bool estComplet(AutomateFini *automate){ // Plus Tard

}
/*
    Verifie si un automate est deterministe
    @param automate : automate a verifier
*/
bool estDeterministe(AutomateFini *automate){ // Plus Tard

}
/*
    Rend un automate complet
    @param automate : automate a rendre complet
*/
void rendreComplet(AutomateFini *automate){ // Plus Tard

}
/*
    Rend un automate deterministe
    @param automate : automate a rendre deterministe

*/
void rendreDeterministe(AutomateFini *automate){ // Plus Tard

}