#pragma once

#include "arrayAccessor.hh"
#include "formula.hh"
#include <set>
#include <iostream>

class Card : public Formula {
private:

    ArrayAccessor* _array;

public:

    Card(ArrayAccessor* a):_array(a){};
    int value() const {
        //std::cout << "size : " << _array->size() << std::endl; 
        return _array->size();
    }
    ~Card(){
        delete _array;
    }
};
