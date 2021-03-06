#pragma once

#include <set>
#include <vector>
#include <iostream>
#include <string>
#include "ensemble.hh"

using namespace std;

//Classe qui va servir à englober les set.
/*class Ensemble{
private:

    set<int>* _s;
    string _nom;

public:

    Ensemble(set<int>* s, string n):_s(s), _nom(n){}

    set<int>* get(){return _s;}
    string getNom(){return _nom;}
    unsigned int size(){return _s->size();} 
    void setValue(set<int>* s) {_s = s;}
    bool isEmpty(){return _s->empty();}
};*/

class ArrayEnsemble{
private:

    vector<vector<Ensemble*>> _s;
    string _nom;
    int _x;
    int _y;

public:

    ArrayEnsemble(string n, int x, int y, set<int>* s): _nom(n), _x(x), _y(y) {
        for(int l = 0; l < x; l++){
            vector<Ensemble*> ligne;
            for(int c = 0; c < y; c++){
                ligne.push_back(new Ensemble(new set<int>(*s),"ARRAY_ENSEMBLE"));
            }
            _s.push_back(ligne);
        }
    }

    Ensemble* get(int x, int y){return _s[x][y];}
    void setValue(int x, int y, set<int>* s){_s[x][y]->setValue(s);}
    string getNom(){return _nom;}
    int getX(){return _x;}
    int getY(){return _y;}

    unsigned int sizeX(){return _s.size();}
    unsigned int sizeY(){return _s[0].size();}
};


class Variable{
private:

    int _val;
    string _nom;
    Ensemble* _domaine;

public:

    Variable(int i, string n, Ensemble* d):_val(i), _nom(n), _domaine(d) {}
    int getVal(){return _val;}
    void setVal(int a){_val = a;}
    string getNom() {return _nom;}
    Ensemble* getDomaine(){return _domaine;}

};
