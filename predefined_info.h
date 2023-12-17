#ifndef PREDEFINED_INFO_H_INCLUDED
#define PREDEFINED_INFO_H_INCLUDED

// Structure pour représenter une cellule de la forêt
typedef struct {
    char type;     // Type de la cellule (par exemple, '+', '*', ' ', '#', 'x', '/', '-', '@')
    int estEnFeu;  // État de la cellule (0 si la cellule n'est pas en feu, 1 sinon)
    int degreBurn; // Degré de combustibilité (rapidité avec laquelle le type peut brûler)
} Cellule;

// Structure pour représenter la forêt
typedef struct {
    int longueur;
    int largeur;
    Cellule** grille; // Tableau 2D pour stocker les cellules de la forêt
} Foret;

// Prototypes de fonctions
Foret initialiserForet(int longueur, int largeur);
void afficherForet(Foret foret);
void remplissageAleatoire(Foret *foret);
void remplissageManuel(Foret *foret);

#endif // PREDEFINED_INFO_H_INCLUDED
