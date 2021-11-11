#include "../include/Primitive.h"

Primitive::Primitive(int first) {
  _first = first;
}

Primitive::Primitive(int first, int second) {
  _first = first;
  _second = second;
}

Primitive::~Primitive() {}

Number::Number(int first) : Primitive(first) {}

Sucessor::Sucessor(int first) : Primitive(first) {}

Predecessor::Predecessor(int first) : Primitive(first) {}

Add::Add(int first, int second) : Primitive(first, second) {}

Mult::Mult(int first, int second) : Primitive(first, second) {}

Pow::Pow(int first, int second) : Primitive(first, second) {}