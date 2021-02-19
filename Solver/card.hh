#pragma once

#include "arrayAccessor.hh"
#include "formula.hh"
#include <set>

class Card : public Formula {
private:

    ArrayAccessor* _array;

public:

    Card(ArrayAccessor* a):_array(a){};
    int value() const {return _array->size();}

};
