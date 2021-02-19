#include "conjonction.hh"

bool Conjonction::isValid() const {

    for(auto i :_atoms){
        if(not i->isValid()){
            return false;
        }
    }
    return true;
}
