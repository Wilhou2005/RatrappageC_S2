#include <stdio.h>
#include "seance.h"

void menu() {
    printf("1 ajouter\n");
    printf("2 supprimer\n");
    printf("3 afficher\n");
    printf("4 update\n");
    printf("5 tri duree\n");
    printf("6 tri calories\n");
    printf("0 quitter\n");
}

int main() {
    int choix;

    while (choix != 0){
        menu();
        scanf("%d", &choix);

        if (choix == 1)
            ajouterSeance();
        else if (choix == 2)
            supprimerSeance();
        else if (choix == 3)
            afficherSeances();
        else if (choix == 4)
            mettreajourSeances();
        else if (choix == 5)
            trierParDuree();
        else if (choix == 6)
            trierParCalories();

    }

    return 0;
}