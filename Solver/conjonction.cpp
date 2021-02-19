#include "conjonction.hh"

bool Conjonction::isValid() const {
    return _left->isValid() && _right->isValid();
}
