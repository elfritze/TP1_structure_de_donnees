/**
 * \file Chemin.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Chemin
 * \author Étudiant 1, étudiant 2
 * \version 0.1
 * \date juin 2014
 *
 */

#include "Chemin.h"
#include <iostream>
using namespace std;
namespace TP1
{

	//Constructeur par défaut
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

	//Surcharge de l'opérateur =
	const Chemin& Chemin::operator= (const Chemin& source)
	{
		if (debut!=0)
			_detruire();

		//On copie le début
		debut = source.debut;
		if(source.debut!=0)
			_copier(source.debut); //On appelle la méthode copier pour copier le reste de la liste chainée à partir du début.

		return (*this);
	}

	//Ajoute le nom d'une pièce avec sa distance au début, spécifiés par nomPiece et distanceDuDebut,
	//à un chemin. Il n'y a pas de vérification particulière de doublons à faire.
	void Chemin::ajoutePiece(const std::string &nomPiece, int distanceDuDebut)
	{
		NoeudChemin * nouveau = new NoeudChemin(nomPiece,distanceDuDebut);
		NoeudChemin * courant = debut;
		NoeudChemin * pred = 0;

		// On parcoure la liste jusqu'à la fin
		while(courant != 0)
		{
			pred = courant;
			courant = courant->suivant;
		}

		//Si la liste est vide on insere au début
		if(debut==0)
			debut = nouveau;
		else
			pred->suivant = nouveau; // Sinon on ajoute à la fin
	}

	//Supprime une pièce d'un chemin, dont l'indice dans la liste chaînée,commençant par 1,
	//est spécifié par numPiece. La méthode doit lancer une exception invalid_argument si l'indice est invalide.
	void Chemin::retirePiece(int numPiece)
	{
		//Vérification
		if(numPiece >= 1 && numPiece <= tailleChemin()){
			int i = 1;
			NoeudChemin * courant = debut;
			NoeudChemin * precedent = courant;

			//On loop n fois pour atteindre la piece désirée
			while(i < numPiece)
			{
				precedent = courant;
				courant = courant->suivant;
				i++;
			}

			//Si le noeud désiré est le premier on réassigne le début au suivant du début.
			if(debut==courant)
					debut=courant->suivant;
			else
				precedent->suivant=courant->suivant;// Sinon on associe le suivant du noeud précédant le noeud désiré au noeud suivant du noeud désiré

			//On se débarasse du noeud désiré
			courant->suivant = 0;
			delete courant;
		}else
			throw std::invalid_argument("L'indice est invalide");
	}

	/**
	 * \brief obtenir le nom de la pièce du début d'un chemin
	 */
	const std::string & Chemin::getNomPiece() const
	{
		return debut->nomPiece;
	}

	/**
	 * \brief obtenir la distance du début de la pièce au début d'un chemin
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

	//Affiche le chemin c en affichant, ligne par ligne, chaque nom de case suivi d'une espace puis de la distance du début.
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