#ifndef NUMBER_H
#define NUMBER_H

#include <string>
//#include "atom.h"
#include <sstream>
using namespace std;

//class Atom;
//class Variable;

class Number{
public:
	//Number (){}
	Number (int s){
		std::stringstream ss;
		ss << s;
		_symbol=ss.str();
		_value=ss.str();
	}
	//Number (const Number &num):_value(num._value),_symbol(num._symbol){}

	string value(){ return _value; }
	string symbol(){return _symbol;}
	int class_number(){return 1;}
	//bool match(Number num);

	template <class T>
	bool match(T &atom)
	{
		if (class_number()==0)
			return false;
		else if (class_number()==1)
			return atom.value()==_value;
		else
			return atom.match(*this);
	}
	//bool match(Variable &var);

private:
	
	string _symbol;
	string _value;
	
};
#endif