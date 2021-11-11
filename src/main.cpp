#include <iostream>

#include <vector>
#include <string>


#include "../include/primitive.h"

using namespace std;

int main(int argc, char *argv[]) {
  Zero z; // 0
  cout << z.run() << endl;

  Number n(9); // 9
  cout << n.run() << endl;

  Sucessor s(45); // 46
  cout << s.run() << endl;

  Predecessor p(0); // 0
  cout << p.run() << endl;

  Add a(5, 2); // 7
  cout << a.run() << endl;

  Mult m(6, 9); // 54
  cout << m.run() << endl;

  Pow pow(5, 4); // 625
  cout << pow.run() << endl;

  cout << "\nBye!" << endl; 
}

