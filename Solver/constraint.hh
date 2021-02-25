#pragma once

#include <vector>

class Constraint{
private:

public:
    //Constraint(Constraint* c){_CNF.push_back(c);}
    virtual bool isValid() const = 0;
     virtual int filtre() =0;
    virtual int filtre(int j) =0;
    //void addConstraint(Constraint* c){_CNF.push_back(c);}
    virtual ~Constraint(){}

};


