#pragma once

#include <set>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class ArrayEnsemble{
private:

    vector<vector<set<int>*>> _s;
    string _nom;
    int _x;
    int _y;

public:

    ArrayEnsemble(string n, int x, int y, set<int>* s): _nom(n), _x(x), _y(y) {
        for(int l = 0; l < x; l++){
            vector<set<int>*> ligne;
            for(int c = 0; c < y; c++){
                ligne.push_back(new set<int>(*s));
            }
            _s.push_back(ligne);
        }
    }

    set<int>* get(int x, int y){return _s[x][y];}
    string getNom(){return _nom;}
    int getX(){return _x;}
    int getY(){return _y;}
};


//Classe qui va servir à englober les set.
class Ensemble{
private:

    set<int>* _s;
    string _nom;

public:

    Ensemble(set<int>* s, string n):_s(s), _nom(n){}

    set<int>* get(){return _s;}
    string getNom(){return _nom;}
    bool isEmpty(){return _s->empty();}
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
    string getNom(){return _nom;}
    Ensemble* getDomaine(){return _domaine;}

};
