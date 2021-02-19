#pragma once

#include "constraint.hh"

class Conjonction : public Constraint {
private:

    Constraint* _left;
    Constraint* _right;

public:

    Conjonction(Constraint* left, Constraint* right):_left(left), _right(right) {}
    bool isValid() const;
};
