/**
 * \file Chemin.cpp
 * \brief Ce fichier contient une implantation des m�thodes de la classe Chemin
 * \author �tudiant 1, �tudiant 2
 * \version 0.1
 * \date juin 2014
 *
 */

#include "Chemin.h"
#include <iostream>
using namespace std;
namespace TP1
{

	//Constructeur par d�faut
	Chemin::Chemin() : debut(0){}

	//Destructeur
	Chemin:: ~Chemin()
	{
		_detruire();
	}

	//constructeur de copie
	Chemin::Chemin(const Chemin& source)
	{
		debut = source.debut;
		if (debut!=0)
		{
			_copier(source.debut);
		}
	}

	//Surcharge de l'op�rateur =
	const Chemin& Chemin::operator= (const Chemin& source)
	{
		if (debut!=0)
			_detruire();

		//On copie le d�but
		debut = source.debut;
		if(source.debut!=0)
			_copier(source.debut); //On appelle la m�thode copier pour copier le reste de la liste chain�e � partir du d�but.

		return (*this);
	}

	//Ajoute le nom d'une pi�ce avec sa distance au d�but, sp�cifi�s par nomPiece et distanceDuDebut,
	//� un chemin. Il n'y a pas de v�rification particuli�re de doublons � faire.
	void Chemin::ajoutePiece(const std::string &nomPiece, int distanceDuDebut)
	{
		NoeudChemin * nouveau = new NoeudChemin(nomPiece,distanceDuDebut);
		NoeudChemin * courant = debut;
		NoeudChemin * pred = 0;

		// On parcoure la liste jusqu'� la fin
		while(courant != 0)
		{
			pred = courant;
			courant = courant->suivant;
		}

		//Si la liste est vide on insere au d�but
		if(debut==0)
			debut = nouveau;
		else
			pred->suivant = nouveau; // Sinon on ajoute � la fin
	}

	//Supprime une pi�ce d'un chemin, dont l'indice dans la liste cha�n�e,commen�ant par 1,
	//est sp�cifi� par numPiece. La m�thode doit lancer une exception invalid_argument si l'indice est invalide.
	void Chemin::retirePiece(int numPiece)
	{
		//V�rification
		if(numPiece >= 1 && numPiece <= tailleChemin()){
			int i = 1;
			NoeudChemin * courant = debut;
			NoeudChemin * precedent = courant;

			//On loop n fois pour atteindre la piece d�sir�e
			while(i < numPiece)
			{
				precedent = courant;
				courant = courant->suivant;
				i++;
			}

			//Si le noeud d�sir� est le premier on r�assigne le d�but au suivant du d�but.
			if(debut==courant)
					debut=courant->suivant;
			else
				precedent->suivant=courant->suivant;// Sinon on associe le suivant du noeud pr�c�dant le noeud d�sir� au noeud suivant du noeud d�sir�

			//On se d�barasse du noeud d�sir�
			courant->suivant = 0;
			delete courant;
		}else
			throw std::invalid_argument("L'indice est invalide");
	}

	/**
	 * \brief obtenir le nom de la pi�ce du d�but d'un chemin
	 */
	const std::string & Chemin::getNomPiece() const
	{
		return debut->nomPiece;
	}

	/**
	 * \brief obtenir la distance du d�but de la pi�ce au d�but d'un chemin
	 */
	int Chemin::getDistanceDuDebut() const
	{
		return debut->distanceDuDebut;
	}

	//Retourne la taille d'un chemin.
	int Chemin::tailleChemin() const
	{
		int i = 0;
		for (NoeudChemin* temp = debut;temp != 0;temp = temp->suivant)
			i++;

		return i;
	}

	//Affiche le chemin c en affichant, ligne par ligne, chaque nom de case suivi d'une espace puis de la distance du d�but.
	//Par exemple :
	//  PremierePiece 0
	//  CaseACote 1
	//  AutreCase 2
	//  Blabla 3
	void Chemin::afficheChemin() const
	{
		for (NoeudChemin* temp = debut;temp != 0;temp = temp->suivant)
		{
			cout << temp->nomPiece << " " << temp->distanceDuDebut ;
		}
	}


	void Chemin:: _copier(NoeudChemin* sn)
	{
		try{

			// copier le premier noeud
			debut = new NoeudChemin(sn->nomPiece,sn->distanceDuDebut);

			NoeudChemin* nouveau = debut;
			for (NoeudChemin* temp = sn->suivant;temp != 0;temp = temp->suivant)
			{
				nouveau->suivant = new NoeudChemin(temp->nomPiece,temp->distanceDuDebut);
				nouveau = nouveau->suivant;
			}
		}
		catch(std::exception&)
		{
			_detruire();
			throw;
		}
	}

	void Chemin::_detruire()
	{
		NoeudChemin * courant = debut;
		NoeudChemin * temp = 0;
		while (courant!=0)
		{
			temp = courant->suivant;
			delete courant;
			courant = temp;
		}
		debut = 0;
		delete debut;
		
	}

}