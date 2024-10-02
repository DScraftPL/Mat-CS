#include "../headers/matryce.hpp"
#include <iostream>

using namespace std;

matryca::matryca(){}
matryca::matryca(unsigned int _n, float** _M) : w(_n), k(_n), elementy(_M){}
matryca::matryca(unsigned int _w, unsigned int _k, float ** _M) : w(_w), k(_k), elementy(_M){} 
matryca::~matryca(){
  delete elementy;
}

unsigned int matryca::wiersze(){
  return w;
}

unsigned int matryca::kolumny(){
  return k;
}

float matryca::element(int i, int j){
  return elementy[i][j];
}

matryca matryca::operator+(matryca _matryca){
  float** temp = new float*[k];
  for(int i=0; i<w; i++){
    temp[i] = new float[w];
    for(int j=0; j<k; j++){
      temp[i][j] = _matryca.element(i,j) + this->element(i,j);
    }
  }
  return matryca(this->w, this->k, temp);
} 

matryca matryca::operator-(matryca _matryca){
  float** temp = new float*[k];
  for(int i=0; i<w; i++){
    temp[i] = new float[w];
    for(int j=0; j<k; j++){
      temp[i][j] = _matryca.element(i,j) - this->element(i,j);
    }
  }
  return matryca(this->w, this->k, temp);
}

matryca matryca::operator*(matryca _matryca){
  float** temp = new float*[this->k];
  for(int i=0; i<k; i++){
    temp[i] = new float[_matryca.wiersze()];
    for(int j=0; j<_matryca.wiersze(); j++){
      float suma=0;
      int _j=0;
      for(int _i=0; _i<this->w; _i++){
        suma += this->element(_i, _j)* _matryca.element(_j, _i);
      }
      _j++;
      temp[i][j] = suma; 
    }
  }
  return matryca(_matryca.wiersze(), this->k, temp);
}
float matryca::wyznacznik(){
  if(w!=k){
    return 0;
  }
  if(w==2){
    return elementy[0][0]*elementy[1][1] - elementy[0][1]*elementy[1][0];
  }
  if(w==3){
    float Wx = elementy[0][0]*elementy[1][1]*elementy[2][2];
    float Wy = elementy[1][0]*elementy[2][1]*elementy[0][2];
    float Wz = elementy[2][0]*elementy[0][1]*elementy[1][2];
    float _Wx = elementy[2][0]*elementy[1][1]*elementy[0][2];
    float _Wy = elementy[1][0]*elementy[0][1]*elementy[2][2];
    float _Wz = elementy[0][0]*elementy[2][1]*elementy[1][2];
    return Wx+Wy+Wz-_Wx-_Wy-_Wz;
  } else {
    for(int i=0; i<w; i++){
    }
  }
  //  0  1  2  3
  //0 00 01 02 03   1 2 3 4 1
  //1 10 11 12 13 * 5 6 7 8 1
  //2 20 21 22 23   9 1 2 3 1 
  //3 30 31 32 33   1 2 3 4 1
  //            
}


