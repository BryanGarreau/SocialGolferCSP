#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <cstdarg>
#include <iterator>
#include "calculatrice.hh"
#include "variable_v4.hh"

#include "forAll.hh"
#include "card.hh"
#include "equal.hh"
#include "different.hh"
#include "var.hh"
#include "disjonction.hh"
#include "conjonction.hh"
#include "intersection.hh"


extern vector<Variable*> _variables;
extern vector<Ensemble*> _ensembles;
extern vector<ArrayEnsemble*> _arrays;

extern vector<Variable*> _variablesDecision;
extern vector<Ensemble*> _ensemblesDecision;
extern vector<ArrayEnsemble*> _arraysDecision;

extern vector<Variable*> _iterators;

extern vector<Constraint*> _constraints;

 bool read(string fileName);
