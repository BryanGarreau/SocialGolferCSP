#include "different.hh"
#include <iostream>

bool Different::isValid() const {

    int l = _left->value();
    int r = _right->value();

    //std::cout << "debug diffrent : " << l << " " << r << std::endl;
    return l != r;
}
