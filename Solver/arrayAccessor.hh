#pragma once

#include "formula.hh"
#include "variable_v4.hh"

//extern std::vector<Variable> variables;

class ArrayAccessor {
private:

    ArrayEnsemble* _array; //pointer on array
    Variable* _itX; //pointer on iterator (Table des symboles) Un pointeur pour chaque dimension
    Variable* _itY;

public:
    
    //ArrayAccessor(){}
    ArrayAccessor(ArrayEnsemble* arr, Variable* itx, Variable* ity):_array(arr), _itX(itx), _itY(ity) {}
    //int value() const {return 0;}
    set<int>* value() const;
    int size() const;

    ~ArrayAccessor() {
        delete _array;
        delete _itX;
        delete _itY;
    }

};
