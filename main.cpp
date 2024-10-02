#include <iostream>
#include "headers/complex.hpp"
#include "headers/matryce.hpp"

using namespace std;

int main (int argc, char *argv[]) {
  float **temp = new float*[10];
  float **temp2 = new float*[10];
  for(int i=0; i<10; i++){
    temp[i] = new float[10];
    temp2[i] = new float[10];
    for(int j=0; j<10; j++){
      temp[i][j] = i+j;
      temp2[i][j] = i-j;
    }
  }
  matryca pepe(3,temp);
  matryca pepe2(3,temp2);
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cout << pepe.element(i,j) << " ";
    }
    cout << endl;
 }
  cout << pepe.wyznacznik() << " ";
  cout << "``````````````````````````````````````````\n";
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cout << pepe2.element(i,j) << " ";
    }
    cout << endl;
  }
  matryca pepe3 = pepe*pepe2;
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cout << pepe3.element(i,j) << " ";
    }
    cout << endl;
  }

  return 0;
}
