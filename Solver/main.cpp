#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "parser.hh"

//#include "variable_v4.hh"
#include "solveur.hh"
/*#include "forAll.hh"
#include "equal.hh"
#include "var.hh"
#include "card.hh"
#include "arrayAccessor.hh"
*/
using namespace std;



int main(int argc, char **argv)
{

	string fileName;
	if (argv[1] == nullptr)
	{
		cout << "Paramètre non renseigné" << endl;
		return 1;
	}
	else
	{
		fileName = argv[1];
	}

	if(read(fileName))
        std::cout << "Lecture bonne" << endl;

    //std::cout<<"FFFFF"<<_arraysDecision.at(0)->get(0,0)<<std::endl;
    std::vector<ArrayEnsemble*> t = _arraysDecision;
    //std::cout<<"FFFFF"<<t.at(0)->get(0,0)<<std::endl;
    Solveur solveur(t,_constraints);
    solveur.lauch();

/*
    Teste des constraints et de la modélisation de celles ci.
*/
/*
    int* taille_groupe = new int(3);
    std::set<int> * nb_semaine = new std::set<int>();
    std::set<int> * nb_groupe = new std::set<int>();

    //constraint forall(i in 1..nb_semaine)(forall(j in 1..nb_groupe)(card(ladder[i,j])==taille_groupe ));

    for(int i = 1; i <= *taille_groupe; i++){
        nb_semaine->insert(i);
        nb_groupe->insert(i);
    }

    Var* left = new Var(new int(3));
    Var* right = new Var(taille_groupe);

    Equal* contrainteInterne =  new Equal(left, right);

    int* it2 = new int(0);
    Variable<int*> itj("j",it2);
    ForAll* deuxiemeForall = new ForAll(it2, nb_groupe, contrainteInterne);

    int* it1 = new int(0);
    Variable<int*> iti("i",it1);
    ForAll* premierForall = new ForAll(it1, nb_semaine, deuxiemeForall);

    cout << "val left  : " << left->value() << std::endl;
    cout << "val right : " << right->value() << std::endl;
    cout << "res left == right : " << contrainteInterne->isValid() << endl;
    cout << "res Forall 2 : " << deuxiemeForall->isValid() << endl;
    cout << "res Forall 1 : " << premierForall->isValid() << endl;

    Card ca(nb_semaine);

    std::cout << "card : " << ca.value() << std::endl;

    int** arrayyy = new int*[3];
    arrayyy[1] = new int[3];

    Variable<int**>* v = new Variable<int**>("tableau", arrayyy);
    Variable<int>* x = new Variable<int>("x",1);
    Variable<int>* y = new Variable<int>("y",1);

    ArrayAccessor a(v,x,y);
    //ArrayAccessor a;
    std::cout << a.value() << std::endl;

    std::vector<Constraint*> constraints;//va contenir toutes les contraintes.
    std::vector<Variable<int*>*> iterator;//va contenir les variables associées au contraintes
    std::vector<Variable<std::set<int>**>*> arrays;//va contenir les variables associées au contraintes

    iterator.push_back(new Variable<int*>("i",new int(0)));
    iterator.push_back(new Variable<int*>("j",new int(0)));
    constraints.push_back(new ForAll(iterator[0]->getValue(), nb_groupe, 
                            new ForAll(iterator[1]->getValue(), nb_semaine,
                                new Equal(new Card(new std::set<int>()), new Var(taille_groupe)) )
                            )
                         );


    std::cout << constraints[0]->isValid() << std::endl;
*/
	return 0;
}
