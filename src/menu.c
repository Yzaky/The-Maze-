#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "menu.h"
void menuInit(Menu *m)
{
	m->nb_lignes = 0;
}

void menuAjouterLigne(Menu *m, char txt[64], MenuFonction fonct)
{
    assert( m->nb_lignes<32 );
	strcpy(  m->lignes[ m->nb_lignes ].texte, txt);
	m->lignes[ m->nb_lignes ].fonction_commande = fonct;
	m->nb_lignes++;
}

void menuLibere(Menu *m)
{
	m->nb_lignes = 0;
}

void menuAff(const Menu *m)
{
	int i;
	printf("\nWelcome to the Maze !! \n");
	for(i=0;i<m->nb_lignes;++i)
		printf("%d : %s\n", i, m->lignes[i].texte);
	printf("Votre choix?\n");
	fflush(stdout);
}

int menuQuestion(const Menu *m)
{
	int cm;
	char dum[32];
	int ok=0;
	do
	{
		if (scanf("%d",&cm)!=1) scanf("%s",dum);
		if ((cm<0) || (cm>=m->nb_lignes))
			printf("Erreur choix menu\n");
		else ok=1;
		fflush(stdout);
	} while(ok==0);
	printf("\n"); fflush(stdout);
	return cm;
}

void menuLoop(Menu *m)
{
	int cm;
	while(1)
	{
		menuAff(m);
		cm = menuQuestion(m);
		m->lignes[ cm ].fonction_commande();
	}
}
