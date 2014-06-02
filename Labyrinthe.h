/**
 * \file Labyrinthe.h
 * \brief Ce fichier contient l'interface d'un labyrinthe.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 * 
 */

#ifndef LABYRINTHE_H_
#define LABYRINTHE_H_

#include <stdexcept>
#include <iostream>
#include <fstream> // pour les fichiers
#include <sstream> // lecture/�criture dans un string, voir la m�thode chargeLabyrinthe() fournie
#include <string>

#include "Chemin.h"
#include "Porte.h"
#include "Piece.h"
#include "FilePieces.h"


namespace TP1
{

class Labyrinthe
{
public:
	//Constructeur par d�faut
	Labyrinthe();

	//Destructeur
	virtual ~Labyrinthe();

	//constructeur de copie
	Labyrinthe(const Labyrinthe&);

	//Surcharge de l'op�rateur =
	const Labyrinthe& operator =(const Labyrinthe& source);

	//M�thode fournie dans le fichier Labyrinthe.cpp, elle charge
	//un fichier contenant un labyrinthe d'une certaine couleur
	//
	//Voici comment un labyrinthe est mis en m�moire:
	//1- ChargerLabyrinthe() appelle ajoutePieceLabyrinthe()
	//2- ajoutePieceLabyrinthe() ajoute la pi�ce si elle n'existe pas d�j�.
	//3- Si la pi�ce existe d�j�, ajoutePieceLabyrinthe() n'ajoute pas de pi�ce et laisse le programme rouler
	//4- On sort de ajoutePieceLabyrinthe() et ChargerLabyrinthe() fait quelques op�rations pour ensuite appeler ajoutePassage()
	//5- ajoutePassage() ajoute les portes � la pi�ce qui � �t� pr�alablement cr��e ou qui existait d�j�
	//6- La pi�ce et les portes sont cr��es et on passe � une autre pi�ce
	void chargeLabyrinthe(Couleur couleur, std::ifstream &entree);

	//Cette fonction doit ajouter la pi�ce p � un labyrinthe. Dans le cas o�
	//une pi�ce du labyrinthe porte d�j� un m�me nom, la m�thode ne doit
	//rien faire (faire un simple return, sans g�n�rer d'exception).
	void ajoutePieceLabyrinthe(Piece &p);

	//Cette m�thode doit solutionner un labyrinthe pour le joueur sp�cifi� par joueur.
	//Elle doit donc trouver en combien d'�tapes au minimum le joueur sp�cifi� peut solutionner
	//le labyrinthe, en ne passant bien s�r que par les portes qui correspondent � sa couleur.
	//
	//Si un labyrinthe ne peut pas �tre solutionn� par le joueur, il faut retourner -1. Dans ce cas,
	//nous ne consid�rerons pas cela comme un appel anormal de la fonction.
	//Vous devez utiliser l'algorithme suivant pour solutionner le labyrinthe, en utilisant la classe FilePieces:
	// 1. Enfiler la pi�ce de d�part en lui associant une distance du d�part de z�ro.
	// 2. Faire
	//       1. D�filer une pi�ce
	//       2. Enfiler toutes les pi�ces qui sont accessibles � partir de cette pi�ce � l'aide d'une porte
	//          de la couleur du joueur, et qui n'ont pas �t� d�j� parcourues, en leur associant la distance
	//			du d�part de la pi�ce d�fil�e plus un.
	//
	//			Remarquez qu'il faut faire une v�rification double ici. Il faut d'abord chercher les portes dans la liste
	//			de portes de la pi�ce d�fil�e, puis il faut ensuite aussi chercher les portes dans les listes de portes de
	//			toutes les pi�ces pour voir s'il y en aurait qui m�nent � la pi�ce d�fil�e. Ceci est n�cessaire car les portes
	//			ne sont pas � sens unique, mais la m�thode qui charge un labyrinthe fournie ne les ajoute qu'une seule fois
	//			dans le mod�le d'implantation. Afin de savoir si une pi�ce a d�j� �t� parcourue ou non, employez le champ
	//			bool�en parcourue. N'enfilez que des pi�ces pour lesquelles ce champ a false comme valeur, puis au moment
	//			o� vous l'enfilez, appliquez-lui la valeur true. Aussi, n'oubliez pas, avant de commencer l'algorithme, de
	//			mettre ce champ � false pour toutes les pi�ces du labyrinthe.
	//
	//	Tant qu'il reste des pi�ces dans la file et que la pi�ce d'arriv�e n'a pas encore �t� atteinte (d�fil�e).
	int solutionner(Couleur joueur);

	//Cette m�thode devra appeler quatre fois la m�thode solutionner(), une fois par couleur, pour d�terminer
	//quel est le joueur qui peut solutionner le labyrinthe en le moins de d�placements. Si aucun joueur ne peut
	//solutionner un labyrinthe, retournez Aucun. Dans le cas o� deux joueurs ou plus peuvent arriver ex-equo,
	//accordez la priorit� au joueur rouge, puis au joueur vert, puis au bleu, puis au jaune. Par exemple,
	// si le joueur rouge peut solutionner le labyrinthe en 12 coups, le joueur vert en 8 coups, le joueur bleu en 9
	// coups, puis le jaune en 8 coups aussi, c'est le vert qui gagne.
	Couleur trouveGagnant();

	//Cette M�thode doit faire la m�me chose que la fonction solutionLabyrinthe, mais plut�t que de retourner
	//le nombre d'�tapes minimum pour que le joueur joueur se rende � la case finale, elle doit retourner
	//le chemin qu'il doit prendre pour ce faire. Si cela est impossible, elle retournera un chemin vide.
	//
	//Pour r�ussir � programmer cette fonction, vous devez prendre le m�me algorithme que celui propos� � la
	//m�thode solutionner(), mais vous devez trouver un moyen d'associer chaque pi�ce plac�e dans la file
	//avec une r�f�rence � la pi�ce par laquelle on a d� passer pour se rendre � celle-ci. Il faut que ces
	//associations, stock�es dans des structures de donn�es auxiliaires locales � la m�thode cheminLabyrinthe(),
	//persistent m�me lorsque les pi�ces sont d�fil�es.
	//
	//Lorsque la pi�ce d'arriv�e aura �t� atteinte, donc apr�s la boucle de l'algorithme, il s'agira de parcourir
	//vos associations en sens inverse pour retrouver, tour � tour, quelles
	//pi�ces ont d� �tre travers�es pour se rendre jusqu'� la fin du labyrinthe.
	Chemin cheminLabyrinthe(Couleur joueur);

private:
	//M�thode priv�e fournie dans le fichier Labyrinthe.cpp, elle ajoute un passage
	//dans un labyrinthe. Elle est appel�e par la m�thode chargeLabyrinthe()
	void ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2);

	//M�thode priv�e, elle sert pour charger un labyrinthe. Ajuste le pointeur depart d'un labyrinthe
	//pour qu'il contienne l'adresse de la pi�ce correspondant au nom sp�cifi� par nom. Lancer une
	//exception logic_error si aucune pi�ce du labyrinthe ne porte le nom nom.
	void placeDepart(std::string& nom);

	//M�me chose que pour la fonction placeDepart d�crite plus haut, mais pour le pointeur arrivee d'un labyrinthe.
	void placeArrivee(std::string& nom);

	class NoeudListePieces //noeud typique d'une liste cha�n�e circulaire
	{
		public:
			// La piece contenue dans un noeud d'une liste cha�n�e circulaire.
			Piece piece;

			// Le noeud suivant
			NoeudListePieces *suivant;

			//Constructeur de la classe Noeud
			explicit NoeudListePieces (const Piece& data_item, NoeudListePieces * next_ptr = 0) :
										piece(data_item), suivant(next_ptr) {}
	};

	//M�thode priv�e. Retourne l'adresse du noeud de la liste de pi�ces contenue dans le labyrinthe lab
	//qui correspond � la pi�ce portant le nom nom, la m�thode doit lancer une exception invalid_argument si le nom de
	//la pi�ce est vide. La m�thode doit lancer �galement une exception logic_error si la pi�ce est introuvable.
	//Remarquez qu'il faut retourner l'adresse du noeud de la liste doublement cha�n�e de pi�ces,
	//et non l'adresse de la pi�ce.
	NoeudListePieces *trouvePiece(std::string &nom) const;

	// Le dernier noeud de la liste cha�n�e circulaire. Ce noeuds ne contient
	// pas n�cessairement les pi�ces de d�part ou d'arriv�e.
	NoeudListePieces *dernier;

	// Adresses des pi�ces de d�part et d'arriv�e. Remarquez que ces adresses doivent
	// �tre celles des pi�ces et non des noeuds cha�n�e circulaire de la liste de pi�ces.
	Piece *depart, *arrivee;

	//M�thode de copie d'un labyrinthe
	void _copier( NoeudListePieces *);

	//D�truire le labyrinthe
	void  _detruire();

};

}

#endif /* LABYRINTHE_H_ */
