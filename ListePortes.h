/**
 * \file ListePortes.h
 * \brief Ce fichier contient l'interface d'une liste de portes.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 */

// Révision des commentaires avec balises Doxygen.
// Fichier mis à jour par : Éric Guillemette, Mathieu L'Écuyer

#ifndef LISTEPORTES_H_
#define LISTEPORTES_H_

#include <stdexcept>
#include "Porte.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les définitions du TP1.
 */
namespace TP1
{

/**
 * \class ListePortes
 * \brief Cette classe sert à définir une liste de portes.
 *
 * La liste de portes est implémentée dans une liste doublement chaînée.
 * Elle est décrite par une porte et deux pointeurs, l'un vers le noeud
 * suivant de la liste et l'autre vers le noeud précédent.
 */
class ListePortes
{
public:
   /**
    * \brief Constructeur par défaut.
    *
    * \post Une instance de la classe ListePortes est initialisée.
    */
	ListePortes();

	/**
    * \brief Destructeur.
    *
    * \post L'instance de ListePortes est détruite.
    */
	virtual ~ListePortes();

	/**
    * \brief Constructeur de copie.
    *
    * \post Une copie profonde d'un objet ListePortes existant est initialisée.
    */
	ListePortes(const ListePortes&);

	/**
    * \brief Surcharge de l'opérateur d'assignation =
    *
    * \post Une copie de ListePortes est retournée.
    */
	const ListePortes& operator =(const ListePortes& source);

	/**
    * \brief Cette méthode doit ajouter la Porte p à la ListePortes.
    *
    * \pre p ne doit pas avoir la même couleur et la même destination
    *      qu'une porte déjà présente dans la liste de portes.
    *
    * \post L'objet p est ajouté à la liste de portes.
    *
    * \exception logic_error : Si tentative d'ajouter une porte déjà présente (doublon).
    */
	void ajoutePorte(Porte &p);

	/**
    * \brief Cette méthode retourne le nombre de portes présentes dans la ListePortes.
    *
    * \post La taille de la liste est retournée, soit le nombre de portes.
    */
	int tailleListePortes() const;

	/**
    * \brief Cette méthode supprime la porte à l'indice spécifié par porteASupprimer.
    *
    * \pre L'indice de la porte à supprimer doit être plus grand ou égal à 0.
    * \pre L'indice de la porte à supprimer doit être plus petit que le nombre de portes.
    *
    * \post La porte présente à l'indice porteASupprimer est supprimée de la liste de portes.
    *
    * \exception invalid_argument : Si l'indice est négatif ou plus grand ou égal au nombre
    *            de portes présentes dans la liste.
    */
	void supprimePorte(int porteASupprimer);

	/**
    * \brief Cette méthode vérifie si la liste de portes est vide.
    *
    * \post VRAI est retourné si la liste est vide, FAUX sinon.
    */
	bool estVideListePortes() const;

	/**
    * \brief Cette méthode retourne l'élément Porte dans la liste à une position donnée.
    *
    * \pre pos : La première position est en position 1.
    *
    * \post La porte à la position pos est retournée.
    *
    * \exception invalid_argument : Si la position donnée en paramètre est invalide.
    */
	Porte elementAt(int pos) const;

private:
	/**
    * \class NoeudListePortes
    *
    * \brief Classe interne représentant un noeud typique.
    *
    * Cette classe représente un noeud typique pour implémenter une liste doublement chaînée.
    */
	class NoeudListePortes
	{
		public:
			Porte porte; /*!< La porte contenue dans ce noeud de la liste. */
			NoeudListePortes *suivant; /*!< Un pointeur vers le noeud suivant de la liste.
			                                NULL s'il s'agit du dernier noeud. */
			NoeudListePortes *precedent; /*!< Un pointeur vers le noeud précédent de la liste.
                                           NULL s'il s'agit du premier noeud. */

			/**
          * \brief Constructeur de la classe NoeudListePortes.
          *
          * \post Un noeud typique est initialisé.
          */
			explicit NoeudListePortes(const Porte& porte, NoeudListePortes* next_ptr = 0,
			                          NoeudListePortes* prev_ptr = 0) :
			                          porte(porte), suivant(next_ptr), precedent(prev_ptr){}
	};

   NoeudListePortes *acces; /*!< Pointeur sur le début de la liste des portes. */
	NoeudListePortes *fin; /*!< Pointeur sur la fin de la liste des portes. */
	int nbPorte; /*!< Nombre de portes dans la liste des portes. */

	// Méthodes privées

	/**
    * \brief Cette méthode privée sert à copier une liste de portes.
    *
    * \post Une copie profonde d'une liste de portes est créée.
    */
	void _copier(NoeudListePortes *);

	/**
    * \brief Cette méthode privée sert à détruire une liste de portes.
    *
    * \post La liste de portes est détruite.
    */
	void _detruire();
};

} // namespace TP1

#endif /* LISTEPORTES_H_ */
