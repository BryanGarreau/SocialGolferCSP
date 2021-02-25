#pragma once

#include "formula.hh"
#include "variable_v4.hh"

class Constante : public Formula {
private:

    int _val;

public:
    
    Constante(int v): _val(v) {}
    int value() const {return _val;}
    int filtre(Formula* e){return 0;}

};
