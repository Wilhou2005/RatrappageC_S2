typedef struct {
    char nom[50];
    char type[20];
    int duree;
    int intensite;
    int calories;
} Seance;

void ajouterSeance();
void supprimerSeance();
void afficherSeances();
void mettreajourSeances();
void trierParDuree();
void trierParCalories();