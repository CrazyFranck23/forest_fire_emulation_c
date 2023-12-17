#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "predefined_info.h"

// Fonction pour initialiser une forêt avec des dimensions données
Foret initialiserForet(int longueur, int largeur) {
    Foret foret;
    foret.longueur = longueur;
    foret.largeur = largeur;

    // Allouer de la mémoire pour la grille de la forêt
    foret.grille = (Cellule**)malloc(longueur * sizeof(Cellule*));
    for (int i = 0; i < longueur; i++) {
        foret.grille[i] = (Cellule*)malloc(largeur * sizeof(Cellule));
    }

    // Initialiser chaque cellule de la forêt (par exemple, avec un type par défaut)
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < largeur; j++) {
            foret.grille[i][j].type = '+'; // '+' représente le sol par défaut
        }
    }

    return foret;
}

// Fonction pour afficher la forêt
void afficherForet(Foret foret) {
    printf("\nLa foret :\n");
    for (int i = 0; i < foret.longueur; i++) {
        for (int j = 0; j < foret.largeur; j++) {
            printf("%c ", foret.grille[i][j].type);
        }
        printf("\n");
    }
}

// Fonction pour remplir la forêt de manière aléatoire
void remplissageAleatoire(Foret *foret) {
    for (int i = 0; i < foret->longueur; i++) {
        for (int j = 0; j < foret->largeur; j++) {
            // Remplir chaque cellule avec des valeurs aléatoires
            int randomType = rand() % 8; // Générer un nombre entre 0 et 7 inclus (pour les 8 types)
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
                    foret->grille[i][j].type = '@'; // cendres éteintes
                    foret->grille[i][j].estEnFeu = 0;
                    foret->grille[i][j].degreBurn = 0;
                    break;
                default:
                    break;
            }
        }
    }
}

// Fonction pour remplir la forêt manuellement
/*
void remplissageManuel(Foret *foret) {
    for (int i = 0; i < foret->longueur; i++) {
        for (int j = 0; j < foret->largeur; j++) {
            // Demander à l'utilisateur de fournir le type de chaque cellule
            printf("Entrez le type de la cellule [%d][%d] : ", i, j);
            scanf(" %c", &foret->grille[i][j].type); // Utilisation de l'espace avant %c pour consommer le retour à la ligne précédent
        }
    }
} */
// Fonction pour remplir la forêt manuellement
void remplissageManuel(Foret *foret) {
    char typesValides[] = {'+', '*', ' ', '#', 'x', '/', '-', '@'};
    int typeValide = 0;

    for (int i = 0; i < foret->longueur; i++) {
        for (int j = 0; j < foret->largeur; j++) {
            do {
                // Demander à l'utilisateur de fournir le type de chaque cellule
                printf("Entrez le type de la cellule [%d][%d] : ", i, j);
                scanf(" %c", &foret->grille[i][j].type);

                // Vérifier si la saisie est un type valide
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
