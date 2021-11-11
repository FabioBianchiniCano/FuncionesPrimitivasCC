#pragma once
#include <iostream>

#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Primitive {
  protected: 
    int _first, _second;
  public:
    Primitive(){};
    Primitive(int);
    Primitive(int, int);
    virtual ~Primitive() = 0;
    virtual int run() = 0;
};

class Zero : public Primitive {
  public: 
    int run() {
      return 0;
    }
};

class Number : public Primitive {
  public: 
    Number(int);
    int run() {
      return _first;
    }
};

class Sucessor : public Primitive {
  public: 
    Sucessor(int);
    int run() {
      return Number(_first + 1).run();
    }
};

class Predecessor : public Primitive {
  public: 
    Predecessor(int);
    int run() {
      if (_first == 0) return Zero().run();
      return Number(_first - 1).run();
    }
};

// La suma se define como:
// Sucesor(x + Predecesor(y))
class Add : public Primitive {
  public: 
    Add(int, int);
    int run() {
      if (_second == 0) return Number(_first).run();
      Add recursiveAdd(_first, Predecessor(_second).run());
      return Sucessor(recursiveAdd.run()).run();
    }
};

// La multiplicación se define como:
// add(x * Predecesor(y))
class Mult : public Primitive {
  public: 
    Mult(int, int);
    int run() {
      if (_second == 0) return Zero().run();
      Mult recursiveMult(_first, Predecessor(_second).run());
      return Add(_first, recursiveMult.run()).run();    
    }
};

// La potencia se define como:
// mult(x ^ Predecesor(y))
class Pow : public Primitive {
  public: 
    Pow(int, int);
    int run() {
      if (_second == 0) return Number(1).run();
      Pow recursivePow(_first, Predecessor(_second).run());
      return Mult(_first, recursivePow.run()).run();
    }
};

