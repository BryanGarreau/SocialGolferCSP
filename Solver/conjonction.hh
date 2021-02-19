#pragma once

#include "constraint.hh"

class Conjonction : public Constraint {
private:

    std::vector<Constraint*> _atoms;

public:

    void addAtom(Constraint* a){_atoms.push_back(a);}
    bool isValid() const;
};
