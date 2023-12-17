#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "predefined_info.h"

int main() {
    int choix;
    int longueur, largeur;

    // Initialisation du g�n�rateur de nombres al�atoires avec le temps actuel
    srand(time(NULL));

    // Demander � l'utilisateur les dimensions de la for�t
    printf("Veuillez entrer les dimensions souhaitees.\n");
    printf("Longueur de la foret (Nombre lignes) : ");
    scanf("%d", &longueur);
    printf("Largeur de la foret (Nombre colonnes) : ");
    scanf("%d", &largeur);


    // Initialiser la for�t avec les dimensions fournies
    Foret foret = initialiserForet(longueur, largeur);

    do {
        // Afficher le menu
        printf("\nMenu :\n");
        printf("1. Remplissage aleatoire de la foret\n");
        printf("2. Remplissage manuel de la foret\n");
        printf("3. Afficher la foret\n");
        printf("4. Quitter\n");

        // Demander � l'utilisateur de faire un choix
        printf("Faites votre choix (1-4) : ");
        scanf("%d", &choix);

        // Effectuer l'action en fonction du choix de l'utilisateur
        switch (choix) {
            case 1:
                remplissageAleatoire(&foret);
                break;
            case 2:
                remplissageManuel(&foret);
                break;
            case 3:
                afficherForet(foret);
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 1 et 4.\n");
        }
    } while (choix != 4);

    // Lib�rer la m�moire allou�e pour la for�t
    for (int i = 0; i < foret.longueur; i++) {
        free(foret.grille[i]);
    }
    free(foret.grille);

    return 0;
}
