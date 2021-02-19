#pragma once

#include "constraint.hh"

class Disjonction : public Constraint {
private:

    Constraint* _left;
    Constraint* _right;

public:

    Disjonction(Constraint* left, Constraint* right):_left(left), _right(right) {}
    bool isValid() const;
};
