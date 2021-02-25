#include "equal.hh"
#include <iostream>

bool Equal::isValid() const{

    int l = _left->value();//on récupère la valeur de la formule de gauche
    int r = _right->value();//on récupère la valeur de la formule de droite

    //std::cout << "Debug equal : " << _left << " " << _right << std::endl;
    //std::cout << "debug equal : " << l << " " << r << std::endl;
    return l == r;
}

int Equal::filtre(){

int result = 0;
    if(_right->value() >= 0){
    result = _left->filtre(_right);


if (result == 2){
    return 2;
}
    }
//std::cout<<"value "<<_right->value()<<std::endl;
//std::cout<<"left "<<_left->value()<<std::endl;
//result = _right->filtre(_left);
   /* if(_right->value()>=100  ){

        if(  8<_left->value() ){
            return 0;
        }
        else {
            return 2;
        }
    }*/


return 0;
}
