/**
 * \file Chemin.h
 * \brief Ce fichier contient l'interface d'un chemin.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 * 
 */

#ifndef CHEMIN_H_
#define CHEMIN_H_

#include <stdexcept>
#include <string>


namespace TP1
{

class Chemin
{
public:
	//Constructeur par d�faut
	Chemin();

	//Destructeur
	virtual ~Chemin();

	//constructeur de copie
	Chemin(const Chemin&);

	//Surcharge de l'op�rateur =
	const Chemin& operator =(const Chemin& source);

	//Ajoute le nom d'une pi�ce avec sa distance au d�but, sp�cifi�s par nomPiece et distanceDuDebut,
	//� un chemin. Il n'y a pas de v�rification particuli�re de doublons � faire.
	void ajoutePiece(const std::string &nomPiece, int distanceDuDebut);

	//Supprime une pi�ce d'un chemin, dont l'indice dans la liste cha�n�e,commen�ant par 1,
	//est sp�cifi� par numPiece. La m�thode doit lancer une exception invalid_argument si l'indice est invalide.
	void retirePiece(int numPiece);

	/**
	 * \brief obtenir le nom de la pi�ce du d�but d'un chemin
	 */
	const std::string & getNomPiece() const;

	/**
	 * \brief obtenir la distance du d�but de la pi�ce au d�but d'un chemin
	 */
	int getDistanceDuDebut() const;

	//Retourne la taille d'un chemin.
	int tailleChemin() const;

	//Affiche le chemin c en affichant, ligne par ligne, chaque nom de case suivi d'une espace puis de la distance du d�but.
	//Par exemple :
	//  PremierePiece 0
	//  CaseACote 1
	//  AutreCase 2
	//  Blabla 3
	void afficheChemin() const;

private:
	class NoeudChemin //noeud typique d'une liste simplement cha�n�e
	{
		public:
			// Le nom d'une pi�ce du labyrinthe.
			std::string nomPiece;

			// Le nombre de d�placements qu'il est n�cessaire d'effectuer depuis la pi�ce de d�part pour se rendre
			// � ce point dans le chemin (� cette pi�ce).
			int distanceDuDebut;

			// Le point suivant du chemin (pi�ce suivante), ou 0 (NULL) s'il s'agit de la fin du chemin.
			NoeudChemin *suivant;

			//Notez bien. Vous pouvez ajouter � cette classe un constructeur qui prend en argument un string et un int
			//pour initialiser nomPiece et distanceDebut respectivement
	};

	// Un chemin est d�fini comme un pointeur vers le premier noeud de la liste simplement cha�n�e.
	// Un chemin vide est repr�sent� directement par le pointeur 0 (NULL).
	NoeudChemin *debut;
};

}

#endif /* CHEMIN_H_ */
