#pragma once
#include <iostream>
#include <string>
#include <set>
#include <cstdarg>
#include <iterator>

using namespace std;

struct Variable{
  string _varName;
  int _intValue;
  set<int> _setValue;
  int ** _arrayValue;

  Variable(string varName, int value):_varName(varName), _intValue(value){}
  Variable(string varName, int** value):_varName(varName), _arrayValue(value), _intValue(-1){}
  Variable(string varName, set<int> value):_varName(varName), _setValue(value), _intValue(-1){}

  string getName(){
    return _varName;
  }

  int getIntValue(){
    return _intValue;
  }

  int** getArrayValue(){
    return _arrayValue;
  }

  set<int> getSetValue(){
    return _setValue;
  }

  friend ostream& operator<<(ostream &out, Variable &v) {
    out << v.getName() << " = ";

    if(v.getIntValue() != -1){
      out << v.getIntValue();
    }

    if(!v.getSetValue().empty()){
      out << "[";
      for(int i : v.getSetValue()){
        out << i << (i!=v.getSetValue().size() ? "," : "");
      }
      out << "]";
    }

    //sortie tableau a faire

    out << "\n";
    return out;
  }

};
