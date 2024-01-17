# include "main.h"
# include <iostream>
# include <fstream>
# include <cstdlib>

// FILE*file = fopen("usd/vex/skills/15s.dat", "w");
void record (void*param){
    for (int i = 0; i < 15000; i++){
    string a = to_string(FR.get_voltage()) + " " +
    to_string(FL.get_voltage()) + " " +
    to_string(BR.get_voltage()) + " " +
    to_string(BL.get_voltage()) + " " +
    to_string(intakeR.get_voltage()) + " " +
    to_string(intakeL.get_voltage()) + " " +
    to_string(rollerH.get_voltage()) + " " +
    to_string(rollerL.get_voltage()) + " "+ "/n";
    fputs(a.c_str(), file);
    pros::delay(1);
  }
  fclose (file);
}

vector <vector<int>> read (vector<vector<int>> vect) {
  fstream f;
  f.open("usd/vex/skills/15s.dat", ios::in);
  ifstream ("usd/vex/skills/15s.dat");
  if (f.is_open()){
    for (int i= 0; i < 15000; i++){
      int x;
      int count = 0;
      while(count < vect[i].size()&&f>>x){
        vect [i][count++] = x;
      }
    }
  }
  return vect;
}
