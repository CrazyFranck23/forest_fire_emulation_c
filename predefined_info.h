#ifndef PREDEFINED_INFO_H_INCLUDED
#define PREDEFINED_INFO_H_INCLUDED

// Structure pour repr�senter une cellule de la for�t
typedef struct {
    char type;     // Type de la cellule (par exemple, '+', '*', ' ', '#', 'x', '/', '-', '@')
    int estEnFeu;  // �tat de la cellule (0 si la cellule n'est pas en feu, 1 sinon)
    int degreBurn; // Degr� de combustibilit� (rapidit� avec laquelle le type peut br�ler)
} Cellule;

// Structure pour repr�senter la for�t
typedef struct {
    int longueur;
    int largeur;
    Cellule** grille; // Tableau 2D pour stocker les cellules de la for�t
} Foret;

// Prototypes de fonctions
Foret initialiserForet(int longueur, int largeur);
void afficherForet(Foret foret);
void remplissageAleatoire(Foret *foret);
void remplissageManuel(Foret *foret);

#endif // PREDEFINED_INFO_H_INCLUDED
