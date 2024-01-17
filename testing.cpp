#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void record () {
  FILE *file = fopen ("C:/Users/Alex_/Desktop/15s.dat", "w");
  for (int i = 0 ; i < 15000; i ++){
    string a = to_string(-127 + ( std::rand() % (127 +127 + 1 ) )) + " " +
    to_string(-127 + ( std::rand() % (127 + 127 + 1 ) )) + " " +
    to_string(-127 + ( std::rand() % (127 +127 + 1 ) )) + " " +
    to_string(-127 + ( std::rand() % (127 +127 + 1 ) )) + " " +
    to_string(-127 + ( std::rand() % (127 +127 + 1 ) )) + " " +
    to_string(-127 + ( std::rand() % (127 +127 + 1 ) )) + " " +
    to_string(-127 + ( std::rand() % (127 +127 + 1 ) )) + " " +
    to_string(-127 + ( std::rand() % (127 +127 + 1 ) )) + " "+ "\n";
    fputs(a.c_str(), file);
  }
  fclose (file);
}

int main() {
  record ();
  vector<vector<int>> vect( 15000 , vector<int> (8, 0));
  fstream f;
	f.open("C:/Users/Alex_/Desktop/15s.dat", ios::in);
	ifstream ("C:/Users/Alex_/Desktop/15s.dat");
	if (f.is_open()){
		for (int i= 0; i < 15000; i++){
			int x;
			int count = 0;
			while(count < vect[i].size()&&f>>x){
				vect [i][count++] = x;
			}
		}
	}
  for (int i = 0; i < 15000; i ++){
    for (int j = 0; j < 8 ; j++){
      cout << vect [i][j] << " ";
    }
  }
  cout<<endl;
  return 0;
}
