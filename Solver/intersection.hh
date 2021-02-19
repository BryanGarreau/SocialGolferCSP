#pragma once

#include "formula.hh"
#include <set>

class Intersection : public Formula {
private:

    std::set<int>* _left;
    std::set<int>* _right;

public:

    Intersection(std::set<int>* l, std::set<int>* r): _left(l), _right(r) {}
    int value() const;

};
