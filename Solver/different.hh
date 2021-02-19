#pragma once

#include "formula.hh"
#include "constraint.hh"

class Different : public Constraint {
private:

    Formula* _right;
    Formula* _left;

public:

    Different(Formula* l, Formula* r): _right(r), _left(l) {}
    bool isValid() const;

};
