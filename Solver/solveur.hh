#pragma once
#include <iostream>
#include <set>
#include <vector>
#include "constraint.hh"
#include "ensemble.hh"
#include "formula.hh"
//#include "parser.hh"
#include "intersection.hh"
#include "equal.hh"
#include "constante.hh"
#include "card.hh"

class Solveur{

public:
    Solveur(std::vector<ArrayEnsemble*> &e,std::vector<Constraint*> &c):_ensemble(e),_constrainte(c){}
    bool lauch();
    bool propagation(std::vector<Ensemble*> &ensemble,std::vector<std::vector<Ensemble>> &solution,int profondeur,u32 endroit);
    bool verification_contrainte(std::vector<Ensemble*> &ensemble);
    bool look_ahead(std::vector<Ensemble*> &ensemble,std::vector<std::vector<Ensemble>> &solution,int pronfondeur,u32 endroit);
    bool create_branch(Ensemble* &e,std::vector<Ensemble*> &ensemble,std::vector<std::vector<Ensemble>> &solution,u32 k,bool t,int profondeur,u32 endroit);
private:
    bool arc_consistance();
    std::vector<ArrayEnsemble*> _ensemble;
    std::vector<Constraint*> _constrainte;
    //unsigned int endroit;
    u32 _maximum;
    u32 sum;

    std::vector<std::vector<Ensemble*>> _pile;
public:
    ~Solveur(){for(u32 i=0;i<_ensemble.size();i++){delete _ensemble.at(i);}
              //for(u32 i=0;i<_constrainte.size() ;i++){delete _constrainte.at(i);
                 // for(u32 i=0;i<_ensemble.size();i++){delete _ensemble.at(i);
              }


};

bool intersect_bound(std::vector<std::set<int>> &varia);
