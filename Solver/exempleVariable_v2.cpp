#include <iostream>
#include <vector>
#include "variable_v2.cpp"
using namespace std;

int main(int argc, char **argv)
{

	vector<BaseVariable> v;

	set<int> v2_values;
	for(int i=0; i<10; i++)
		v2_values.insert(i);

	int **p;
	p = new int*[3];
	for (int i = 0; i < 3; ++i) {
	  p[i] = new int[3];
	}

	Variable<int> v1("v1", 4);
	Variable<set<int>> v2("v2", v2_values);
	Variable<int **> v3("v3", p);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	std::cout << v1.getValue() << '\n';

	int **p2 = v3.getValue();
	set<int> s = v2.getValue();
	for(int i : s){
		std::cout << i << '\n';
	}

	return 0;
}
