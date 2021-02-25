#pragma once
#include "iostream"
#include "constraint.hh"

class Disjonction : public Constraint {
private:

    Constraint* _left;
    Constraint* _right;

public:

    Disjonction(Constraint* left, Constraint* right):_left(left), _right(right) {}
    bool isValid() const;
    int filtre(){
        //std::cout<<"disjonction"<<std::endl;
        int u = _left->filtre();
        if (u==2){return 2;}
        u = _right->filtre();
         if (u==2){return 2;}
        return u;
    }
    int filtre(int j){

        return 0;
    }

    ~Disjonction(){
        delete _left;
        delete _right;
    }
};
