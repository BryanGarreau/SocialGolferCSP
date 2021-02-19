#pragma once

#include <set>

class Ensemble {
private:

    std::set<int> _set;

public:

    Ensemble(){}
    Ensemble(std::set<int> s): _set(s){}
    
    std::set<int>::iterator upperBound(){return _set.upperBound();}
    std::set<int>::iterator lowerBound(){return _set.lowerBound();}
    
};
