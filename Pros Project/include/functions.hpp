#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include <vector>

void record (void*);
std::vector<std::vector<int>> read (std::vector<std::vector<int>> vect);

class Driver {

public:
  Driver driver();
  void drive ();
  void intakeAndscore (bool in);
  void intakeAnddescore (bool in);
  void descore (bool in);
  void outtakeAnddescore (bool in);

};

#endif
