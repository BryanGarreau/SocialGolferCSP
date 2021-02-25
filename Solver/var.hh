#pragma once

#include "formula.hh"
#include "variable_v4.hh"
#include <iostream>


class Var : public Formula {
private:

    Variable* _val;

public:
    
    Var(Variable* v): _val(v) {}

    int value() const {
        //std::cout << " debug var : " << _val << std::endl;
        return _val->getVal();
    }
    int filtre(Formula* e){return 0;}
    std::string getName() {return _val->getNom();}
    ~Var(){
        delete _val;
    }
};
