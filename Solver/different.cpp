#include "different.hh"

bool Different::isValid() const {

    int l = _left->value();
    int r = _right->value();

    return l != r;

}
