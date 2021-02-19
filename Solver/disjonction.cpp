#include "disjonction.hh"

#include <iostream>

bool Disjonction::isValid() const {
    return _left->isValid() || _right->isValid();
}
