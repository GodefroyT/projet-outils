/**
* \file main.c
* \brief projet de Black Jack
* \author GUEDOUAR Wajdi
* \author THIEULART Godefroy
* \author OKROU PODA
* \version 1.1
* \date 20 Octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"

#define LIBRE			0 	/**< constante indiquant que la carte i du tableau cartes[i] est libre */
#define BANQUE			1 	/**< constante indiquant que la carte i du tableau cartes[i] est en posséssion de la banque */
#define JOUEUR			2 	/**< constante indiquant que la carte i du tableau cartes[i] est en posséssion du joueur */
#define BANQUE_CACHEE	3 	/**< constante indiquant que la carte i du tableau cartes[i] est en posséssion de la banque et est de type carte caché */
#define DEB_COEURS		0 	/**< constante indiquant la valeur à partir de laquelle la carte est de type coeur */
#define	FIN_COEURS		12 	/**< constante indiquant la valeur jusqu'ou la carte est de type coeur */
#define	DEB_CARREAUX	13 	/**< constante indiquant la valeur à partir de laquelle la carte est de type carreau */
#define FIN_CARREAUX	25 	/**< constante indiquant la valeur jusqu'ou la carte est de type carreau */
#define	DEB_PIQUES		26 	/**< constante indiquant la valeur à partir de laquelle la carte est de type pique */
#define FIN_PIQUES		38 	/**< constante indiquant la valeur jusqu'ou la carte est de type pique */
#define	DEB_TREFLES		39 	/**< constante indiquant la valeur à partir de laquelle la carte est de type trèfle */
#define	FIN_TREFLES		51 	/**< constante indiquant la valeur jusqu'ou la carte est de type trèfle */

short cartes[52]; 			/**< tableau contenant les 52 cartes du jeu */
short nb_as_joueur; 		/**< variable globale contenant le nombre d'as du joueur */
short nb_as_banque; 		/**< variable globale contenant le nombre d'as de la banque */


/**
*\fn int main
*\brief la fonction principale permettant de jouer une partie de black jack contre l'ordinateur
*\return int renvoie EXIT_SUCCESS pour mettre fin au programme
*/
int main(){
	int cpt=0;
	int choix;
	short carte=0;
	short score_joueur=0;
	short score_banque=0;
	
	for(cpt=0 ; cpt<52 ; cpt++){
		cartes[cpt]=0;
	}
		for(cpt=0 ; cpt<2 ; cpt++){
			carte=tirer_carte(JOUEUR);
			donner_valeur_carte(JOUEUR, carte);
			score_joueur=evaluer_score(JOUEUR, carte, &score_joueur);
		}
		printf("joueur : \n");
		afficher_mains(JOUEUR);
		printf("score joueur : %d \n", score_joueur);
		
	
		for(cpt=0 ; cpt<2 ; cpt++){
			carte=tirer_carte(BANQUE);
			donner_valeur_carte(BANQUE, carte);
			score_banque=evaluer_score(BANQUE, carte, &score_banque);
		}
		printf("banque : \n");
		afficher_mains(BANQUE);
		printf("score banque : %d \n", score_banque);
		
	while(score_joueur<21&&score_banque<21){
		
		printf("souhaitez vous tirer une carte ? (1=oui ; 0=non)");
		scanf("%i", &choix);
		while(choix<0||choix>1){
			printf("\n1 pour oui et 0 pour non \n souhaitez vous tirer une carte ?");
			scanf("%i", &choix);
		}
		if(choix==1){
			carte=tirer_carte(JOUEUR);
			donner_valeur_carte(JOUEUR, carte);
			score_joueur=evaluer_score(JOUEUR, carte, &score_joueur);
		}
		while(score_banque<17||(choix==0 && score_banque>score_joueur)){
			carte=tirer_carte(BANQUE);
			donner_valeur_carte(BANQUE, carte);
			score_banque=evaluer_score(BANQUE, carte, &score_banque);
		}
		
		printf("joueur : \n");
		afficher_mains(JOUEUR);
		printf("score joueur : %d \n", score_joueur);
		
		printf("banque : \n");
		afficher_mains(BANQUE);
		printf("score banque : %d \n", score_banque);
	}

	if(score_banque<score_joueur&&score_banque<21&&score_joueur<21){
		printf("\nle joueur 1 a gagné !\n");
		afficher_mains(JOUEUR);
	}
	else if(score_banque>score_joueur&&score_banque<21&&score_joueur<21){
		printf("\nl'ordinateur a gagné !\n");
		afficher_mains(BANQUE);
	}
	else if(score_banque>21&&score_joueur<=21){
		printf("\nle joueur 1 a gagné !\n");
		afficher_mains(JOUEUR);
	}
	else if(score_joueur>21&&score_banque<=21){
		printf("\nl'ordinateur a gagné !\n");
		afficher_mains(BANQUE);
	}
		
	

	return EXIT_SUCCESS;
}
