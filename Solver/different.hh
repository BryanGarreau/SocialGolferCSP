#pragma once

#include "formula.hh"
#include "constraint.hh"

class Different : public Constraint {
private:

    Formula* _right;
    Formula* _left;

public:

    Different(Formula* l, Formula* r): _right(r), _left(l) {}

    int filtre(){

        int u = _left->filtre(_right);
        if (u==2){return 2;}
        u = _right->filtre(_left);
         if (u==2){return 2;}
        return u;

    }
    int filtre(int j){return 0;}
    bool isValid() const;
    ~Different(){
        delete _right;
        delete _left;
    }

};
