#include "calculatrice.hh"
#include <iostream>

using namespace std;

int add(int a, int b){
  return a+b;
}

int multiply(int a, int b){
  return a*b;
}

int calculate(int a, int b, char c){
  switch (c) {
    case '*':
      return multiply(a,b);
    case '+':
      return add(a,b);
  }
  return 0;
}
