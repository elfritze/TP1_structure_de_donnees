/**
 * \file Chemin.h
 * \brief Ce fichier contient l'interface d'un chemin.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 */

// Révision des commentaires avec balises Doxygen.
// Fichier mis à jour par : Éric Guillemette, Mathieu L'Écuyer

#ifndef CHEMIN_H_
#define CHEMIN_H_

#include <stdexcept>
#include <string>

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les définitions du TP1.
 */
namespace TP1
{

/**
 * \class Chemin
 * \brief Cette classe sert à définir le chemin du labyrinthe.
 *
 * Un chemin est implémenté dans une liste simplement chaînée de noms de pièces avec leurs
 * distances du début, c'est-à-dire le nombre de déplacements effectués depuis la case de départ.
 */
class Chemin
{
public:
   /**
    * \brief Constructeur par défaut.
    *
    * \post Une instance de la classe Chemin est initialisée.
    */
	Chemin();

   /**
    * \brief Destructeur.
    *
    * \post L'instance de Chemin est détruite.
    */
	virtual ~Chemin();

   /**
    * \brief Constructeur de copie.
    *
    * \post Une copie profonde d'un objet Chemin existant est initialisée.
    */
	Chemin(const Chemin&);

   /**
    * \brief Surcharge de l'opérateur d'assignation =
    *
    * \post Une copie de Chemin est retournée.
    */
	const Chemin& operator =(const Chemin& source);

	/**
    * \brief Ajoute à un chemin le nom d'une pièce avec sa distance du début du labyrinthe.
    *
    * \post Le nom d'une pièce et sa distance du début sont ajoutés au chemin dans un noeud typique.
    */
	void ajoutePiece(const std::string &nomPiece, int distanceDuDebut);

   /**
    * \brief Supprime une pièce d'un chemin à l'indice spécifié par numPiece.
    *
    * \pre L'indice de la pièce à supprimer commence par 1.
    * \pre L'indice de la pièce à supprimer doit être plus petit que le nombre de pièces.
    *
    * \post La pièce présente à l'indice numPiece est supprimée du chemin.
    *
    * \exception invalid_argument : Si l'indice est invalide.
    */
	void retirePiece(int numPiece);

   /**
    * \brief Cette méthode retourne le nom de la pièce au début d'un chemin.
    *
    * \post Le nom de la pièce est retourné.
    */
	const std::string & getNomPiece() const;

   /**
    * \brief Cette méthode retourne la distance du début, soit de la pièce au début d'un chemin.
    *
    * \post La distance du début est retournée.
    */
	int getDistanceDuDebut() const;

   /**
    * \brief Cette méthode retourne la taille d'un chemin.
    *
    * \post La taille d'un chemin est retournée.
    */
	int tailleChemin() const;

	/**
    * \brief Affiche le chemin, soit en affichant ligne par ligne chaque nom de pièce suivi
    *        de la distance du début.
    *
    * \post Le chemin est affiché.
    */
	void afficheChemin() const;

private:
   /**
    * \class NoeudChemin
    *
    * \brief Classe interne représentant un noeud typique.
    *
    * Cette classe représente un noeud typique pour implémenter une liste simplement chaînée.
    */
	class NoeudChemin
	{
   public:
      std::string nomPiece; /*!< Le nom d'une pièce du labyrinthe. */

      int distanceDuDebut; /*!< Le nombre de déplacements qu'il est nécessaire d'effectuer
                                depuis la pièce de départ pour se rendre à ce point dans le
                                chemin (à cette pièce). */

      NoeudChemin *suivant; /*!< Le point suivant du chemin (pièce suivante), ou 0 (NULL)
                                 s'il s'agit de la fin du chemin. */

      /**
       * \brief Constructeur de la classe NoeudChemin.
       *
       * \post Un noeud typique est initialisé.
       */
      explicit NoeudChemin(std::string nomPiece,int distanceDuDebut,NoeudChemin* next_ptr = 0) :
                           nomPiece(nomPiece),distanceDuDebut(distanceDuDebut),suivant(next_ptr) {}
	};

	NoeudChemin *debut; /*!< Un pointeur vers le premier noeud de la liste simplement chaînée.
	                         Un chemin vide est représenté directement par le pointeur 0 (NULL). */

	int cpt; /*!< Le nombre de noeud dans la liste. */


   // Méthodes privées

   /**
    * \brief Cette méthode privée sert à copier.
    *
    * \post Une copie profonde est créée.
    */
   void _copier(NoeudChemin *);

   /**
    * \brief Cette méthode privée sert à détruire un chemin.
    *
    * \post Le chemin est détruit.
    */
   void _detruire();

};

} // namespace TP1

#endif /* CHEMIN_H_ */
