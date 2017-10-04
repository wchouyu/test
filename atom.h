#ifndef ATOM_H
#define ATOM_H

#include <string>

using std::string;


//class Variable;
//class Number;
class Atom {
public:
  Atom (string s):_symbol(s),_value(s) {}

  //Atom (const Atom &a):_symbol(a._symbol){}
  /*bool operator ==(Atom a) {return match(a);}
  bool operator =(Variable &var){return match(var);}
  bool operator =(Number num){return match(num);}*/
	string value(){ return _value; }
	string symbol(){return _symbol;}
	int class_number(){return 0;}

  template <class T>
  bool match(T &atom)
  {
	  if (class_number()==0)
		  return atom.value() == _value;
	  else if (class_number()==1)
		  return false;
	  else
	  {
		  return atom.match(*this);
	  }
  }
  
  
private:
	string _symbol;
	string _value;
};

#endif
