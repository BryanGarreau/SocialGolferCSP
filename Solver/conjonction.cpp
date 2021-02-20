#include "conjonction.hh"

#include <iostream>

bool Conjonction::isValid() const {
    //std::cout << "débug conjonction : " << _left->isValid() << " et " << _right->isValid() << std::endl;
    return _left->isValid() && _right->isValid();
}
