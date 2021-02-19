#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <cstdarg>
#include <iterator>
#include "calculatrice.cpp"
#include "variable_v4.hh"

#include "constraint.hh"
#include "forAll.hh"
#include "card.hh"
#include "equal.hh"
#include "different.hh"
#include "var.hh"
#include "disjonction.hh"
#include "conjonction.hh"
#include "intersection.hh"

using namespace std;

vector<Variable*> _variables;
vector<Ensemble*> _ensembles;
vector<ArrayEnsemble*> _arrays;

vector<Variable*> _variablesDecision;
vector<Ensemble*> _ensemblesDecision;
vector<ArrayEnsemble*> _arraysDecision;

vector<Constraint*> _constraints;

Constraint* buildConstraint(vector<string> & s);


vector<Variable*> _iterators;


Variable* getVar(vector<Variable*> variables, string varName){
    for(Variable* v : variables)
        if(v->getNom() == varName)
            return v;
}

Ensemble* getEnsemble(vector<Ensemble*> ensembles, string varName){
    for(Ensemble* e : ensembles)
        if(e->getNom() == varName)
            return e;
}

ArrayEnsemble* getArray(vector<ArrayEnsemble*> arrays, string varName){
    for(ArrayEnsemble* a : arrays)
        if(a->getNom() == varName)
            return a;
}

bool isIn(std::vector<Variable*> variables, string varName){
  for(Variable* v : variables)
    if(v->getNom() == varName)
      return true;
  return false;
}

bool isNumber(string s){
    for(unsigned int i = 0; i < s.size(); i++)
        if( s[i] < 48 || s[i] > 57)
         return false;
    return true;
}

vector<string> parse(string s){

    vector<string> stringParsed;
    string tmp = "";

    for(unsigned int i = 0; i < s.size(); i++){
        string caractere = s.substr(i,1);
        
        if(caractere == ";"){
            stringParsed.push_back(tmp);
            break;
        }
        if(caractere == " " || caractere == ","){
            if(tmp != ""){
                stringParsed.push_back(tmp);
                tmp = "";
            }
        } else {
            tmp += caractere;
        }
    }

    return stringParsed;
}

static bool buildVariable(vector<string> s){

    string type = s[0];
    bool isDecision = false;
    string varName = s[1];//nom de la variable

    if(varName == "dec"){
        isDecision = true;
        s.erase(s.begin()+1);//on supprime le dec pour faire simplifier le traitement.
        varName = s[1]; 
    }

    if(type == "var"){ //type variable (int)
      
        int valeur;
        if(s[3] == "operation"){

            int v1, v2;
            //on va chercher les valeurs des opérandes si ce sont des variables
            if(not isNumber(s[5])){v1 = getVar(_variables,s[5])->getVal();} else {v1 = stoi(s[5]);}
            if(not isNumber(s[7])){v2 = getVar(_variables,s[7])->getVal();} else {v2 = stoi(s[7]);}

            //calculate va faire l'opération pour nous.
            valeur = calculate(v1,v2,s[6][0]);//le [0] est un peu sale mais ça permet d'être suûr d'avoir un caractère

        } else if (isNumber(s[3])) {
            valeur = stoi(s[3]);
        } else {
            valeur = getVar(_variables,s[3])->getVal();
        }
        
        //cout << "Nouvelle variable : " << varName << " " << valeur << endl;

        set<int> * tmpSet = new set<int>();
        tmpSet->insert(valeur);//cette variable ne peut prendre qu'une valeur
        Variable* tmp = new Variable(valeur, varName, new Ensemble(tmpSet, "constant"));      
        
        //ajout de la nouvelle variable dans le vecteur
        if(isDecision)
            _variablesDecision.push_back(tmp);
        else
            _variables.push_back(tmp);

    } else if(type == "set"){ //cas d'affectation avec une autre variable

        string varName = s[1];
        string valeurLimite = s[3];
        int limite = 0; // on va considérer que les ensemble forcément de 1 à limite;

        if(isNumber(valeurLimite)){
            limite = stoi(valeurLimite);
        } else { //si ce n'est pas un nombre c'est une variable
            limite = getVar(_variables,valeurLimite)->getVal();
        }

        set<int>* tmp = new set<int>();

        for(int i = 1; i <= limite; i++){tmp->insert(i);}

        if(isDecision)
            _ensemblesDecision.push_back(new Ensemble(tmp, varName));
        else
           _ensembles.push_back(new Ensemble(tmp, varName));

    } else if(type == "array"){
        //un array sera un set en 2D
        int dimension1;
        int dimension2;

        string dim = s[3];
        if(isNumber(dim)){dimension1 = stoi(dim);} else {dimension1 = getVar(_variables,dim)->getVal();}
        dim = s[4];
        if(isNumber(dim)){dimension2 = stoi(dim);} else {dimension2 = getVar(_variables,dim)->getVal();}

        set<int>* tmp;
        if(isNumber(s[6])){
            tmp = new set<int>();
            for(int i = stoi(s[6]); i > 0; i--)
                tmp->insert(i);
        } else 
            tmp = getEnsemble(_ensembles, s[6])->get();
        //cout << "array detecté : " << varName << " dimension : " << dimension1 << " " << dimension2 << endl;

        if(isDecision)
            _arraysDecision.push_back(new ArrayEnsemble(varName,dimension1,dimension2,tmp));
        else
            _arrays.push_back(new ArrayEnsemble(varName,dimension1,dimension2,tmp));

    }
  return true;
}

Intersection* buildIntersection(vector<string> & s){

    s.erase(s.begin());//on supprime (
    
    ArrayEnsemble* ens1 = getArray(_arraysDecision,s[0]);

    s.erase(s.begin());//on supprime le nom du tableau
    s.erase(s.begin());//on supprime la première parenthèse
    //on chope les itérateurs
    Variable* it11 = getVar(_iterators, s[0]);
    s.erase(s.begin());//on supprime le premier itérateur
    Variable* it12 = getVar(_iterators, s[0]);
    s.erase(s.begin());//on supprime le deuxieme itérateur

    s.erase(s.begin());//on supprime )

    ArrayEnsemble* ens2 = getArray(_arraysDecision,s[0]);

    s.erase(s.begin());//on supprime le nom du tableau
    s.erase(s.begin());//on supprime la première parenthèse
    //on chope les itérateurs
    Variable* it21 = getVar(_iterators, s[0]);
    s.erase(s.begin());//on supprime le premier itérateur
    Variable* it22 = getVar(_iterators, s[0]);
    s.erase(s.begin());//on supprime le deuxieme itérateur

    s.erase(s.begin());//on supprime )
    s.erase(s.begin());//on supprime )

    return new Intersection(new ArrayAccessor(ens1,it11,it12), new ArrayAccessor(ens2,it21,it22));
}

Card* buildCard(vector<string> & s){

    s.erase(s.begin());//on supprime (
    
    ArrayEnsemble* ens = getArray(_arraysDecision,s[0]);

    s.erase(s.begin());//on supprime le nom du tableau
    s.erase(s.begin());//on supprime la première parenthèse
    //on chope les itérateurs
    Variable* it1 = getVar(_iterators, s[0]);
    s.erase(s.begin());//on supprime le premier itérateur
    Variable* it2 = getVar(_iterators, s[0]);
    s.erase(s.begin());//on supprime le deuxieme itérateur    

    //ladder ( i,j )

    Card* tmp = new Card(new ArrayAccessor(ens,it1,it2));

    s.erase(s.begin());//on supprime ) // il y en a bien deux à supprimer c'est pas une erreur
    s.erase(s.begin());//on supprime )
    return tmp;
}

Formula* buildFormula(vector<string> & s){

    string type = s[0];
    s.erase(s.begin());

    if(type == "Card"){
        return buildCard(s);
    } else if (type == "Intersection"){
        return buildIntersection(s);
    } else {
        //Si la variable existe déjà, on construit un Var et on la renvoie
        //cout << "Nom var : " << type << endl;
        Var* tmp = new Var(getVar(_variables,type));
        return tmp;
    }
}

ForAll* buildFor(vector<string> & s){

    //on traite l'itérateur
    s.erase(s.begin());//suppression du (

    //on créer l'itérateur i
    string itName(s[0]);
    string ensembleName(s[1]);//ensemble de définition de l'itérateur

    Ensemble* ensDef;

    if(isIn(_variables,ensembleName)){
        set<int>* s = new set<int>();
        int limite = getVar(_variables,ensembleName)->getVal();
        for(int i = 1; i <= limite; i++){
            s->insert(i);            
        }
        ensDef = new Ensemble(s,ensembleName);
    } else {
        ensDef = getEnsemble(_ensembles,ensembleName); // ensemble de definition de l'iterateur
    }

    
    Variable* it = new Variable(0,itName,ensDef); // création de l'itérateur
    _iterators.push_back(it);

    s.erase(s.begin());//suppression du nom de l'itérateur
    s.erase(s.begin());//suppression du son ensemble de définition
    s.erase(s.begin());//suppression du )
    s.erase(s.begin());//suppression du (
    
    //on traite la contrainte d'après.

    Constraint* c = buildConstraint(s);
    //suppression de l'itérateur.
    _iterators.pop_back();
    
    s.erase(s.begin());//on supprime )

    return new ForAll(it,ensDef,c);
}

Equal* buildEqual(vector<string> & s){

    if(s[0] == "("){s.erase(s.begin());}

    Formula* f1 = buildFormula(s);
    Formula* f2 = buildFormula(s);

    s.erase(s.begin());//on supprime )

    return new Equal(f1,f2);
}

Different* buildDifferent(vector<string> & s){
    
    if(s[0] == "("){s.erase(s.begin());}

    Formula* f1 = buildFormula(s);
    Formula* f2 = buildFormula(s);

    s.erase(s.begin());//on supprime )

    return new Different(f1,f2);
}

Conjonction* buildConjonction(vector<string> & s){

    s.erase(s.begin());//on supprime ( 

    Constraint* l = buildConstraint(s);//construit la contrainte de gauche

    if(s[0] == ","){s.erase(s.begin());}

    Constraint* r = buildConstraint(s);//construit la contrainte de droite

    s.erase(s.begin());//on supprime )

    return new Conjonction(l,r);
}

Disjonction* buildDisjonction(vector<string> & s){

    s.erase(s.begin());//on supprime (

    Constraint* l = buildConstraint(s);//construit la contrainte de gauche

    if(s[0] == ","){s.erase(s.begin());}

    Constraint* r = buildConstraint(s);//construit la contrainte de droite

    s.erase(s.begin());//on supprime )

    return new Disjonction(l,r);
}

Constraint* buildConstraint(vector<string> &  s){
    
    string type = s[0];

    s.erase(s.begin());//on supprime le token du nom du type de contrainte

    //cout << "Type : " << type << endl;

    if(type == "Forall"){
        return buildFor(s);
    } else if(type == "Equal") {
        return buildEqual(s);
    } else if(type == "Different") {
        return buildDifferent(s);
    } else if(type == "Disjonction") {
        return buildDisjonction(s);
    } else if(type == "Conjonction") {
        return buildConjonction(s);
    }

    return nullptr;
}

void traiterLigne(vector<string> s){

    if(s[0] == "constraint"){
        s.erase(s.begin());//Le mot clef contraint ne nous sert à rien
        _constraints.push_back(buildConstraint(s));
    } else {
        buildVariable(s);
    }

}

static bool read(string fileName)
{

    cout << "Lecture du fichier... " << endl << endl;
    ifstream fichier(fileName, ios::in);
    if (!fichier.good())
    {
        cout << "le fichier renseigné en paramètre n'existe pas" << endl;
        throw runtime_error("Could not open file");
        return false;
    }
    string ligne;
    while (getline(fichier, ligne))
    {
        traiterLigne(parse(ligne));
    }

    fichier.close();

    cout << "Liste des variables trouvées :"<<endl<<endl;
    for(Variable* v : _variables){
      std::cout << "\t" << v->getNom() << " = " << v->getVal() << '\n';
    }
   

    cout << endl << "Liste des ensembles récupérés :" << endl << endl;
    for(Ensemble* e : _ensembles){

       cout << "\t" << e->getNom() << endl;
    }

    cout << endl << "Liste des array de décisions : " << endl << endl;
    for(ArrayEnsemble* a : _arraysDecision){
        cout << "\t" << a->getNom() << " dimension : (" << a->getX() << "," << a->getY() << ")" << endl;
    }

    cout << endl << "Nb contraintes trouvé : " << _constraints.size() << endl << endl;

    cout << "DEBUG " << _constraints[0]->isValid() << endl;
    cout << "DEBUG " << _constraints[1]->isValid() << endl;
    cout << "DEBUG disjonction 1 : " << _constraints[2]->isValid() << endl;
/*    cout << "DEBUG disjonction 1 : " << _constraints[3]->isValid() << endl;
    cout << "DEBUG disjonction 0 : " << _constraints[4]->isValid() << endl;
    cout << "DEBUG disjonction 1 : " << _constraints[5]->isValid() << endl;
    cout << endl;
    cout << "DEBUG conjonction 0 : " << _constraints[6]->isValid() << endl;
    cout << "DEBUG conjonction 0 : " << _constraints[7]->isValid() << endl;
    cout << "DEBUG conjonction 0 : " << _constraints[8]->isValid() << endl;
    cout << "DEBUG conjonction 1 : " << _constraints[9]->isValid() << endl;
    cout << endl;
    cout << "DEBUG intersection : " << _constraints[10]->isValid() << endl;
*/
    return true;
}
