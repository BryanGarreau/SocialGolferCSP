#include "disjonction.hh"

bool Disjonction::isValid() const {

    for(auto i :_atoms){
        if(i->isValid()){
            return true;
        }
    }
    return false;
}
