#pragma once

#include <vector>

class Constraint{
private:

   // std::vector<Constraint*> _CNF;

public:

    Constraint(){}
    //Constraint(Constraint* c){_CNF.push_back(c);}

    virtual bool isValid() const = 0;
    //void addConstraint(Constraint* c){_CNF.push_back(c);}

};


