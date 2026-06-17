#include <stdio.h>
#include <string.h>
#include "seance.h"

Seance seances[100];
int nbSeances = 0;

void ajouterSeance()
{
    if (nbSeances >= 100)
    {
        printf("plein\n");
        return;
    }

    Seance s;

    printf("nom : ");
    scanf("%s", s.nom);

    printf("type (course velo musculation) : ");
    scanf("%s", s.type);

    printf("duree : ");
    scanf("%d", &s.duree);

    printf("intensite : ");
    scanf("%d", &s.intensite);

    printf("calories : ");
    scanf("%d", &s.calories);

    seances[nbSeances] = s;
    nbSeances++;

    printf("ajoute\n");
}

void supprimerSeance()
{
    char nom[50];
    int i;
    int j;
    int trouve = 0;

    printf("nom a supprimer : ");
    scanf("%s", nom);

    for (i = 0; i < nbSeances; i++)
    {
        if (strcmp(seances[i].nom, nom) == 0)
        {
            for (j = i; j < nbSeances - 1; j++)
            {
                seances[j] = seances[j + 1];
            }

            nbSeances--;
            trouve = 1;
            break;
        }
    }

    if (trouve == 0)
    {
        printf("pas trouve\n");
    }
}

void afficherSeances()
{
    int i;

    if (nbSeances == 0)
    {
        printf("vide\n");
        return;
    }

    for (i = 0; i < nbSeances; i++)
    {
        printf("\nseance %d\n", i + 1);
        printf("nom : %s\n", seances[i].nom);
        printf("type : %s\n", seances[i].type);
        printf("duree : %d\n", seances[i].duree);
        printf("intensite : %d\n", seances[i].intensite);
        printf("calories : %d\n", seances[i].calories);
    }
}

void mettreajourSeances()
{
    int i;

    for (i = 0; i < nbSeances; i++)
    {
        if (strcmp(seances[i].type, "course") == 0)
        {
            seances[i].calories = seances[i].calories + 50;
        }
        else if (strcmp(seances[i].type, "musculation") == 0)
        {
            seances[i].intensite = seances[i].intensite + 1;
        }
        else if (strcmp(seances[i].type, "velo") == 0)
        {
            seances[i].calories = seances[i].calories + 30;
            seances[i].intensite = seances[i].intensite + 1;
        }
    }

    printf("miseajour\n");
}

void trierParDuree()
{
    int i;
    int j;
    Seance temp;

    for (i = 0; i < nbSeances - 1; i++)
    {
        for (j = i + 1; j < nbSeances; j++)
        {
            if (seances[i].duree > seances[j].duree)
            {
                temp = seances[i];
                seances[i] = seances[j];
                seances[j] = temp;
            }
        }
    }

    printf("tri duree ok\n");
}

void trierParCalories()
{
    int i;
    int j;
    Seance temp;

    for (i = 0; i < nbSeances - 1; i++)
    {
        for (j = i + 1; j < nbSeances; j++)
        {
            if (seances[i].calories > seances[j].calories)
            {
                temp = seances[i];
                seances[i] = seances[j];
                seances[j] = temp;
            }
        }
    }

    printf("tri calories ok\n");
}