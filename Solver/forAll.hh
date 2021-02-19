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

    bool isValid() const;
};
