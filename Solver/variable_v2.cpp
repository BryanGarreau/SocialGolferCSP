#pragma once
#include <iostream>
#include <string>
#include <set>
#include <cstdarg>
#include <iterator>

using namespace std;

struct BaseVariable{
  string _varName;
  string getName(){return _varName;}
  void setName(string name){_varName = name;}
// virtual void print() const;
};

/*
template<class T>
struct SuperType{
  T _value;

  T getValue(){
    return _value;
  }
  friend ostream& operator<<(ostream &out,const SuperType &v) {
    return out;
  }
};

struct IntValue : public SuperType{
  int _value;
  IntValue(int value):_value(value){}

  friend ostream& operator<<(ostream &out,const IntValue &v) {
    out << "Int " <<(int)v._value;
    return out;
  }
};

struct SetValue : public SuperType{
  set<int> _values;
  SetValue(int start, int end){
    for(int i = start; i<=end; i++){
      _values.insert(i);
    }
  }

  friend ostream& operator<<(ostream &out,const SetValue &v) {
    out << "[";
    for (auto elem : v._values)
    {
      out << elem << ", ";
    }
    out << "]";
    return out;
  }
};

struct Array1D : public SuperType{
  size_t _size;
  int * _values;
  // iterator iterator;
  Array1D(size_t size, int * values):_size(size){
    _values = new int[size];
    // iterator = begin(values);
  }

  friend ostream& operator<<(ostream &out,const Array1D &v) {
    out << "tableau 1D pas implémenté";
    return out;
  }
};

struct Array2D : public SuperType{
  size_t _size1;
  size_t _size2;
  int ** _values;
  Array2D(size_t size1, size_t size2)
  :_size1(size1), _size2(size2){
    // values = new int[size1][size2];
  }

  friend ostream& operator<<(ostream &out,const Array2D &v) {
    out << "{ ";
    for(int i=0; i<v._size1; i++){
      out << "{ ";
      for(int j=0; j<v._size2; j++){
        out << v._values[i][j] << " ";
      }
      out << "} ";
    }
    out << "} ";
    return out;
  }
};
*/

// template<typename T>
// void print(Variable<T> &var){
//   std::cout << "/* message */" << '\n';
// }

template<typename T>
struct Variable : public virtual BaseVariable{
  T _value;

  Variable(string varName, int value):_value(value){setName(varName);}
  Variable(string varName, int** value):_value(value){setName(varName);}
  Variable(string varName, set<int> value):_value(value){setName(varName);}

  T getValue(){
    return _value;
  }

  /*
  void print<int**>() override{
    std::cout << "array" << '\n';
  }
  void print<set<int>>() override{
    std::cout << "set" << '\n';
  }

  */
/*
  friend ostream& operator<<(ostream &out,const Variable &v) {
    out << v._varName << " : ";
    switch (v._varType) {
      case 1:
      {
        auto value = static_cast<const IntValue&>(*v._value);
        out << value << "\n";
        break;
      }
      case 2:
      {
        auto value = static_cast<const SetValue&>(*v._value);
        out << value << "\n";
        break;
      }
      case 3:
      {
        auto value = static_cast<const Array2D&>(*v._value);
        out << value << "\n";
        break;
      }
    }
    return out;
  }

  */
};
