/**
 * \file ListePortes.h
 * \brief Ce fichier contient l'interface d'une liste de portes.
 * \author Admin
 * \version 0.1
 * \date mai 2014
 */

// R�vision des commentaires avec balises Doxygen.
// Fichier mis � jour par : �ric Guillemette, Mathieu L'�cuyer

#ifndef LISTEPORTES_H_
#define LISTEPORTES_H_

#include <stdexcept>
#include "Porte.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les d�finitions du TP1.
 */
namespace TP1
{

/**
 * \class ListePortes
 * \brief Cette classe sert � d�finir une liste de portes.
 *
 * La liste de portes est impl�ment�e dans une liste doublement cha�n�e.
 * Elle est d�crite par une porte et deux pointeurs, l'un vers le noeud
 * suivant de la liste et l'autre vers le noeud pr�c�dent.
 */
class ListePortes
{
public:
   /**
    * \brief Constructeur par d�faut.
    *
    * \post Une instance de la classe ListePortes est initialis�e.
    */
	ListePortes();

	/**
    * \brief Destructeur.
    *
    * \post L'instance de ListePortes est d�truite.
    */
	virtual ~ListePortes();

	/**
    * \brief Constructeur de copie.
    *
    * \post Une copie profonde d'un objet ListePortes existant est initialis�e.
    */
	ListePortes(const ListePortes&);

	/**
    * \brief Surcharge de l'op�rateur d'assignation =
    *
    * \post Une copie de ListePortes est retourn�e.
    */
	const ListePortes& operator =(const ListePortes& source);

	/**
    * \brief Cette m�thode doit ajouter la Porte p � la ListePortes.
    *
    * \pre p ne doit pas avoir la m�me couleur et la m�me destination
    *      qu'une porte d�j� pr�sente dans la liste de portes.
    *
    * \post L'objet p est ajout� � la liste de portes.
    *
    * \exception logic_error : Si tentative d'ajouter une porte d�j� pr�sente (doublon).
    */
	void ajoutePorte(Porte &p);

	/**
    * \brief Cette m�thode retourne le nombre de portes pr�sentes dans la ListePortes.
    *
    * \post La taille de la liste est retourn�e, soit le nombre de portes.
    */
	int tailleListePortes() const;

	/**
    * \brief Cette m�thode supprime la porte � l'indice sp�cifi� par porteASupprimer.
    *
    * \pre L'indice de la porte � supprimer doit �tre plus grand ou �gal � 0.
    * \pre L'indice de la porte � supprimer doit �tre plus petit que le nombre de portes.
    *
    * \post La porte pr�sente � l'indice porteASupprimer est supprim�e de la liste de portes.
    *
    * \exception invalid_argument : Si l'indice est n�gatif ou plus grand ou �gal au nombre
    *            de portes pr�sentes dans la liste.
    */
	void supprimePorte(int porteASupprimer);

	/**
    * \brief Cette m�thode v�rifie si la liste de portes est vide.
    *
    * \post VRAI est retourn� si la liste est vide, FAUX sinon.
    */
	bool estVideListePortes() const;

	/**
    * \brief Cette m�thode retourne l'�l�ment Porte dans la liste � une position donn�e.
    *
    * \pre pos : La premi�re position est en position 1.
    *
    * \post La porte � la position pos est retourn�e.
    *
    * \exception invalid_argument : Si la position donn�e en param�tre est invalide.
    */
	Porte elementAt(int pos) const;

private:
	/**
    * \class NoeudListePortes
    *
    * \brief Classe interne repr�sentant un noeud typique.
    *
    * Cette classe repr�sente un noeud typique pour impl�menter une liste doublement cha�n�e.
    */
	class NoeudListePortes
	{
		public:
			Porte porte; /*!< La porte contenue dans ce noeud de la liste. */
			NoeudListePortes *suivant; /*!< Un pointeur vers le noeud suivant de la liste.
			                                NULL s'il s'agit du dernier noeud. */
			NoeudListePortes *precedent; /*!< Un pointeur vers le noeud pr�c�dent de la liste.
                                           NULL s'il s'agit du premier noeud. */

			/**
          * \brief Constructeur de la classe NoeudListePortes.
          *
          * \post Un noeud typique est initialis�.
          */
			explicit NoeudListePortes(const Porte& porte, NoeudListePortes* next_ptr = 0,
			                          NoeudListePortes* prev_ptr = 0) :
			                          porte(porte), suivant(next_ptr), precedent(prev_ptr){}
	};

   NoeudListePortes *acces; /*!< Pointeur sur le d�but de la liste des portes. */
	NoeudListePortes *fin; /*!< Pointeur sur la fin de la liste des portes. */
	int nbPorte; /*!< Nombre de portes dans la liste des portes. */

	// M�thodes priv�es

	/**
    * \brief Cette m�thode priv�e sert � copier une liste de portes.
    *
    * \post Une copie profonde d'une liste de portes est cr��e.
    */
	void _copier(NoeudListePortes *);

	/**
    * \brief Cette m�thode priv�e sert � d�truire une liste de portes.
    *
    * \post La liste de portes est d�truite.
    */
	void _detruire();
};

} // namespace TP1

#endif /* LISTEPORTES_H_ */
