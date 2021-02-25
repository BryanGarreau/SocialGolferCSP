#pragma once
#include <iostream>
#include "constraint.hh"

class Conjonction : public Constraint {
private:

    Constraint* _left;
    Constraint* _right;

public:

    Conjonction(Constraint* left, Constraint* right):_left(left), _right(right) {}
    bool isValid() const;
    int filtre(){
        //std::cout<<"conjonction"<<std::endl;
        int u = _left->filtre();
        if (u==2){return 2;}
        u = _right->filtre();
         if (u==2){return 2;}
        return u;
    }
    int filtre(int j){


        return 0;}
    ~Conjonction(){
        delete _left;
        delete _right;
    }
};
