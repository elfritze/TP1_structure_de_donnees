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
	//Constructeur par défaut
	Chemin();

	//Destructeur
	virtual ~Chemin();

	//constructeur de copie
	Chemin(const Chemin&);

	//Surcharge de l'opérateur =
	const Chemin& operator =(const Chemin& source);

	//Ajoute le nom d'une pièce avec sa distance au début, spécifiés par nomPiece et distanceDuDebut,
	//à un chemin. Il n'y a pas de vérification particulière de doublons à faire.
	void ajoutePiece(const std::string &nomPiece, int distanceDuDebut);

	//Supprime une pièce d'un chemin, dont l'indice dans la liste chaînée,commençant par 1,
	//est spécifié par numPiece. La méthode doit lancer une exception invalid_argument si l'indice est invalide.
	void retirePiece(int numPiece);

	/**
	 * \brief obtenir le nom de la pièce du début d'un chemin
	 */
	const std::string & getNomPiece() const;

	/**
	 * \brief obtenir la distance du début de la pièce au début d'un chemin
	 */
	int getDistanceDuDebut() const;

	//Retourne la taille d'un chemin.
	int tailleChemin() const;

	//Affiche le chemin c en affichant, ligne par ligne, chaque nom de case suivi d'une espace puis de la distance du début.
	//Par exemple :
	//  PremierePiece 0
	//  CaseACote 1
	//  AutreCase 2
	//  Blabla 3
	void afficheChemin() const;

private:
	class NoeudChemin //noeud typique d'une liste simplement chaînée
	{
		public:
			// Le nom d'une pièce du labyrinthe.
			std::string nomPiece;

			// Le nombre de déplacements qu'il est nécessaire d'effectuer depuis la pièce de départ pour se rendre
			// à ce point dans le chemin (à cette pièce).
			int distanceDuDebut;

			// Le point suivant du chemin (pièce suivante), ou 0 (NULL) s'il s'agit de la fin du chemin.
			NoeudChemin *suivant;

			//Notez bien. Vous pouvez ajouter à cette classe un constructeur qui prend en argument un string et un int
			//pour initialiser nomPiece et distanceDebut respectivement
	};

	// Un chemin est défini comme un pointeur vers le premier noeud de la liste simplement chaînée.
	// Un chemin vide est représenté directement par le pointeur 0 (NULL).
	NoeudChemin *debut;
};

}

#endif /* CHEMIN_H_ */
