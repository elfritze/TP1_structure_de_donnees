/**
 * \file Chemin.h
 * \brief Ce fichier contient l'interface d'un chemin.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 */

// R�vision des commentaires avec balises Doxygen.
// Fichier mis � jour par : �ric Guillemette, Mathieu L'�cuyer

#ifndef CHEMIN_H_
#define CHEMIN_H_

#include <stdexcept>
#include <string>

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les d�finitions du TP1.
 */
namespace TP1
{

/**
 * \class Chemin
 * \brief Cette classe sert � d�finir le chemin du labyrinthe.
 *
 * Un chemin est impl�ment� dans une liste simplement cha�n�e de noms de pi�ces avec leurs
 * distances du d�but, c'est-�-dire le nombre de d�placements effectu�s depuis la case de d�part.
 */
class Chemin
{
public:
   /**
    * \brief Constructeur par d�faut.
    *
    * \post Une instance de la classe Chemin est initialis�e.
    */
	Chemin();

   /**
    * \brief Destructeur.
    *
    * \post L'instance de Chemin est d�truite.
    */
	virtual ~Chemin();

   /**
    * \brief Constructeur de copie.
    *
    * \post Une copie profonde d'un objet Chemin existant est initialis�e.
    */
	Chemin(const Chemin&);

   /**
    * \brief Surcharge de l'op�rateur d'assignation =
    *
    * \post Une copie de Chemin est retourn�e.
    */
	const Chemin& operator =(const Chemin& source);

	/**
    * \brief Ajoute � un chemin le nom d'une pi�ce avec sa distance du d�but du labyrinthe.
    *
    * \post Le nom d'une pi�ce et sa distance du d�but sont ajout�s au chemin dans un noeud typique.
    */
	void ajoutePiece(const std::string &nomPiece, int distanceDuDebut);

   /**
    * \brief Supprime une pi�ce d'un chemin � l'indice sp�cifi� par numPiece.
    *
    * \pre L'indice de la pi�ce � supprimer commence par 1.
    * \pre L'indice de la pi�ce � supprimer doit �tre plus petit que le nombre de pi�ces.
    *
    * \post La pi�ce pr�sente � l'indice numPiece est supprim�e du chemin.
    *
    * \exception invalid_argument : Si l'indice est invalide.
    */
	void retirePiece(int numPiece);

   /**
    * \brief Cette m�thode retourne le nom de la pi�ce au d�but d'un chemin.
    *
    * \post Le nom de la pi�ce est retourn�.
    */
	const std::string & getNomPiece() const;

   /**
    * \brief Cette m�thode retourne la distance du d�but, soit de la pi�ce au d�but d'un chemin.
    *
    * \post La distance du d�but est retourn�e.
    */
	int getDistanceDuDebut() const;

   /**
    * \brief Cette m�thode retourne la taille d'un chemin.
    *
    * \post La taille d'un chemin est retourn�e.
    */
	int tailleChemin() const;

	/**
    * \brief Affiche le chemin, soit en affichant ligne par ligne chaque nom de pi�ce suivi
    *        de la distance du d�but.
    *
    * \post Le chemin est affich�.
    */
	void afficheChemin() const;

private:
   /**
    * \class NoeudChemin
    *
    * \brief Classe interne repr�sentant un noeud typique.
    *
    * Cette classe repr�sente un noeud typique pour impl�menter une liste simplement cha�n�e.
    */
	class NoeudChemin
	{
   public:
      std::string nomPiece; /*!< Le nom d'une pi�ce du labyrinthe. */

      int distanceDuDebut; /*!< Le nombre de d�placements qu'il est n�cessaire d'effectuer
                                depuis la pi�ce de d�part pour se rendre � ce point dans le
                                chemin (� cette pi�ce). */

      NoeudChemin *suivant; /*!< Le point suivant du chemin (pi�ce suivante), ou 0 (NULL)
                                 s'il s'agit de la fin du chemin. */

      /**
       * \brief Constructeur de la classe NoeudChemin.
       *
       * \post Un noeud typique est initialis�.
       */
      explicit NoeudChemin(std::string nomPiece,int distanceDuDebut,NoeudChemin* next_ptr = 0) :
                           nomPiece(nomPiece),distanceDuDebut(distanceDuDebut),suivant(next_ptr) {}
	};

	NoeudChemin *debut; /*!< Un pointeur vers le premier noeud de la liste simplement cha�n�e.
	                         Un chemin vide est repr�sent� directement par le pointeur 0 (NULL). */

	int cpt; /*!< Le nombre de noeud dans la liste. */


   // M�thodes priv�es

   /**
    * \brief Cette m�thode priv�e sert � copier.
    *
    * \post Une copie profonde est cr��e.
    */
   void _copier(NoeudChemin *);

   /**
    * \brief Cette m�thode priv�e sert � d�truire un chemin.
    *
    * \post Le chemin est d�truit.
    */
   void _detruire();

};

} // namespace TP1

#endif /* CHEMIN_H_ */
