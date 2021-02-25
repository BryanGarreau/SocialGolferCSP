#pragma once

#include "variable_v4.hh"
#include "constraint.hh"
#include <set>

class ForAll : public Constraint{

private:

    Variable* _iterator;//symbole sur lequel on va itérer
    Ensemble* _s;//valeurs de l'itérateur
    Constraint* _c;

public:

    ForAll(Variable* i, Ensemble* s, Constraint* c): _iterator(i), _s(s), _c(c) {}
    int filtre(){
        int res=0;
        int balancoire = 0;
        for(auto i : (*_s->get())){//pour chaque élément de l'ensemble
            //std::cout << "debug forall : "<< _iterator->getNom() << " value : "  << i << std::endl;
            _iterator->setVal(i);
            res =  _c->filtre();
            if(res == 1){
                balancoire = 1;
            }
            if(res == 2){
                return 2;
            }
        }

        return balancoire;
    }

    bool isValid() const;
    ~ForAll(){
        delete _iterator;
        delete _s;
        delete _c;
    }
    int filtre(int j){

        return 0;
    }
};
