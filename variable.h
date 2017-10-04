#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
//#include "atom.h"
//#include "number.h"
using std::string;

//class Number;
//class Atom;

class Variable{
public:
  Variable(string s):_symbol(s){}
  
  string value(){ return _value; }
  string symbol(){return _symbol;}
  int class_number(){return 2;}

  template <class T>
  bool match( T  &atom)
  {
	bool ret = _assignable;
    if(_assignable){
      _value = atom.value() ;
      _assignable = false;
    }
	else {
		if (_value==atom.symbol())
			ret=true;
	}
    return ret;
  }
  //bool match(Number number);
  //bool match(Variable variable);
  
private:
	string _symbol;
	string _value;
	bool _assignable = true;
};

#endif
