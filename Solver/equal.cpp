#include "equal.hh"
#include <iostream>

bool Equal::isValid() const{

    int l = _left->value();//on récupère la valeur de la formule de gauche
    int r = _right->value();//on récupère la valeur de la formule de droite

    //std::cout << "debug : " << l << " " << r << std::endl;
    return l == r;
}
