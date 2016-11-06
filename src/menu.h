#ifndef _MENU_H
#define _MENU_H


typedef void (*MenuFonction)();
/** @brief defining the menu line structure for the text mode
*/
typedef struct
{   /** an array of 64 cases which takes the choice sentence */
	char texte[64];
	/** the function we call depending on the switch case's choice */
	MenuFonction fonction_commande;
} MenuLigne;

/** @brief defining the menu  structure for the text mode
*/

typedef struct
{   /** a structure of menu lines */
	MenuLigne lignes[32];
	/** an integer that refers to the number of the lines the menu can take*/
	int nb_lignes;
} Menu;
/** @brief this procedure initialize the Menu
    @param m which is a pointer on the structure Menu
    */
void menuInit(Menu *m);
/** @brief this procedure is used to add a new line in the menu
    @param m is a pointer on the structure Menu
    @param MenuFonction is the fonction we will call if it's choice is selected
    */
void menuAjouterLigne(Menu *m, char txt[64], MenuFonction fonct);
/** @brief this procedure takes control of the menu loop
    @param m is a pointer on the structure Menu
    */
void menuLoop(Menu *m);
/** @brief this procedure frees the space allocated for the menu in the memory
    @param m is a pointer on the structure Menu
    */
void menuLibere(Menu *m);

#endif
