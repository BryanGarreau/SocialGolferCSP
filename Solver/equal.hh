#pragma once

#include "constraint.hh"
#include "formula.hh"

class Equal : public Constraint{

private:

    Formula* _left;//symbole sur lequel on va itérer
    Formula* _right;

public:

    Equal(Formula* l, Formula* r):_left(l), _right(r) {}

    void setLeft(Formula* l){_left = l;}
    void setRight(Formula* r){_right = r;}
    bool isValid() const;
    int filtre();
    int filtre(int j){return 0;}

    ~Equal(){
        delete _left;
        delete _right;
    }

};
