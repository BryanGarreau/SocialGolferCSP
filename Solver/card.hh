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
        //return _array->size();
        return _array->value()->get_lower_bound().size();
    }


    int filtre(Formula* e){
        //std::cout<<"jen ai marre"<<std::endl;
        int j = static_cast<int>(_array->value()->get_lower_bound().size());
        if (j>e->value()){
            j = 2;
        }
        else {
            j = 0;
        }
        return j;}

    ~Card(){
        delete _array;
    }
};
