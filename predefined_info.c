#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "predefined_info.h"

// Fonction pour initialiser une for�t avec des dimensions donn�es
Foret initialiserForet(int longueur, int largeur) {
    Foret foret;
    foret.longueur = longueur;
    foret.largeur = largeur;

    // Allouer de la m�moire pour la grille de la for�t
    foret.grille = (Cellule**)malloc(longueur * sizeof(Cellule*));
    for (int i = 0; i < longueur; i++) {
        foret.grille[i] = (Cellule*)malloc(largeur * sizeof(Cellule));
    }

    // Initialiser chaque cellule de la for�t (par exemple, avec un type par d�faut)
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < largeur; j++) {
            foret.grille[i][j].type = '+'; // '+' repr�sente le sol par d�faut
        }
    }

    return foret;
}

// Fonction pour afficher la for�t
void afficherForet(Foret foret) {
    printf("\nLa foret :\n");
    for (int i = 0; i < foret.longueur; i++) {
        for (int j = 0; j < foret.largeur; j++) {
            printf("%c ", foret.grille[i][j].type);
        }
        printf("\n");
    }
}

// Fonction pour remplir la for�t de mani�re al�atoire
void remplissageAleatoire(Foret *foret) {
    for (int i = 0; i < foret->longueur; i++) {
        for (int j = 0; j < foret->largeur; j++) {
            // Remplir chaque cellule avec des valeurs al�atoires
            int randomType = rand() % 8; // G�n�rer un nombre entre 0 et 7 inclus (pour les 8 types)
            switch (randomType) {
                case 0:
                    foret->grille[i][j].type = '+'; // sol
                    foret->grille[i][j].estEnFeu = 0;
                    foret->grille[i][j].degreBurn = 0;
                    break;
                case 1:
                    foret->grille[i][j].type = '*'; // arbre
                    foret->grille[i][j].estEnFeu = 0;
                    foret->grille[i][j].degreBurn = 4;
                    break;
                case 2:
                    foret->grille[i][j].type = ' '; // feuille
                    foret->grille[i][j].estEnFeu = 0;
                    foret->grille[i][j].degreBurn = 2;
                    break;
                case 3:
                    foret->grille[i][j].type = '#'; // roche
                    foret->grille[i][j].estEnFeu = 0;
                    foret->grille[i][j].degreBurn = 5;
                    break;
                case 4:
                    foret->grille[i][j].type = 'x'; // herbe
                    foret->grille[i][j].estEnFeu = 0;
                    foret->grille[i][j].degreBurn = 3;
                    break;
                case 5:
                    foret->grille[i][j].type = '/'; // eau
                    foret->grille[i][j].estEnFeu = 0;
                    foret->grille[i][j].degreBurn = 0;
                    break;
                case 6:
                    foret->grille[i][j].type = '-'; // cendres
                    foret->grille[i][j].estEnFeu = 0;
                    foret->grille[i][j].degreBurn = 1;
                    break;
                case 7:
                    foret->grille[i][j].type = '@'; // cendres �teintes
                    foret->grille[i][j].estEnFeu = 0;
                    foret->grille[i][j].degreBurn = 0;
                    break;
                default:
                    break;
            }
        }
    }
}

// Fonction pour remplir la for�t manuellement
/*
void remplissageManuel(Foret *foret) {
    for (int i = 0; i < foret->longueur; i++) {
        for (int j = 0; j < foret->largeur; j++) {
            // Demander � l'utilisateur de fournir le type de chaque cellule
            printf("Entrez le type de la cellule [%d][%d] : ", i, j);
            scanf(" %c", &foret->grille[i][j].type); // Utilisation de l'espace avant %c pour consommer le retour � la ligne pr�c�dent
        }
    }
} */
// Fonction pour remplir la for�t manuellement
void remplissageManuel(Foret *foret) {
    char typesValides[] = {'+', '*', ' ', '#', 'x', '/', '-', '@'};
    int typeValide = 0;

    for (int i = 0; i < foret->longueur; i++) {
        for (int j = 0; j < foret->largeur; j++) {
            do {
                // Demander � l'utilisateur de fournir le type de chaque cellule
                printf("Entrez le type de la cellule [%d][%d] : ", i, j);
                scanf(" %c", &foret->grille[i][j].type);

                // V�rifier si la saisie est un type valide
                typeValide = 0;
                for (int k = 0; k < sizeof(typesValides) / sizeof(typesValides[0]); k++) {
                    if (foret->grille[i][j].type == typesValides[k]) {
                        typeValide = 1;
                        break;
                    }
                }

                // Si la saisie n'est pas valide, signaler l'erreur
                if (!typeValide) {
                    printf("Erreur : Type de cellule invalide. Veuillez saisir un type parmi les suivants : ");
                    for (int k = 0; k < sizeof(typesValides) / sizeof(typesValides[0]); k++) {
                        printf("%c ", typesValides[k]);
                    }
                    printf("\n");
                }
            } while (!typeValide);
        }
    }
}
