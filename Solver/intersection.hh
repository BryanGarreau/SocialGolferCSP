#pragma once

#include "formula.hh"
#include "arrayAccessor.hh"
#include <set>

class Intersection : public Formula {
private:

    ArrayAccessor* _left;
    ArrayAccessor* _right;

public:

    Intersection(ArrayAccessor* l, ArrayAccessor* r): _left(l), _right(r) {}
    int value() const;
    ~Intersection(){
        delete _left;
        delete _right;
    }
};
