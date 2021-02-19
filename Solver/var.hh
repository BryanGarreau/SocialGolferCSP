#pragma once

#include "formula.hh"
#include "variable_v4.hh"

class Var : public Formula {
private:

    Variable* _val;

public:
    
    Var(Variable* v): _val(v) {}

    int value() const {return _val->getVal();}
};
