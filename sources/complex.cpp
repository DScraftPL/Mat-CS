#include "../headers/complex.hpp"
#include <cmath>

using namespace std;

//konstruktory
complexNumber::complexNumber(){
  x = 0;
  y = 0;
}
complexNumber::complexNumber(float _x, float _y): x(_x), y(_y){}

//gettery
float complexNumber::Re(){
  return x;
}
float complexNumber::Im(){
  return y;
}

//specyficzne wartości
complexNumber complexNumber::Sprezenie(){
  return complexNumber(x, -1*y);
}
float complexNumber::Modul(){
  return std::sqrt(x*x+y*y);
}

//operatory podstawowe
complexNumber complexNumber::operator+(complexNumber temp){
  return complexNumber(x+temp.Re(), y+temp.Im());
}
complexNumber complexNumber::operator+(float _x){
  return complexNumber(x+_x, y);
}
complexNumber complexNumber::operator-(complexNumber temp){
  return complexNumber(x-temp.Re(), y-temp.Im());
}
complexNumber complexNumber::operator-(float _x){
  return complexNumber(x-_x, y);
}
complexNumber complexNumber::operator*(complexNumber temp){
  return complexNumber(x*temp.Re() - y*temp.Im(), temp.Re()*y + x*temp.Im());
}
complexNumber complexNumber::operator*(float _x){
  return complexNumber(x*_x, y*_x);
}
complexNumber complexNumber::operator/(complexNumber temp){
  return complexNumber(x/(temp.Re()*temp.Re()+temp.Im()*temp.Im()),y/(temp.Re()*temp.Re()+temp.Im()*temp.Im()));
}
complexNumber complexNumber::operator/(float _x){
  return complexNumber(x/_x, y/_x);
}

//operatory przypisania
void complexNumber::operator+=(complexNumber temp){
  x += temp.Re();
  y += temp.Im();
}
void complexNumber::operator+=(float _x){
  x += _x;
}
void complexNumber::operator-=(complexNumber temp){
  x -= temp.Re();
  y -= temp.Im();
}
void complexNumber::operator-=(float _x){
  x -= _x;
}
void complexNumber::operator*=(complexNumber temp){
  x = x * temp.Re() - temp.Im() * y;
  y = temp.Re() * y + x * temp.Im();
  // (x+iy)(a+ib) = xa + aiy + xib - yb  
}
void complexNumber::operator*=(float _x){
  x*=_x;
  y*=_x;
}
void complexNumber::operator=(complexNumber temp){
  x = temp.Re();
  y = temp.Im();
}

//operatory strumieniowe
istream& operator>>(istream& strumien, complexNumber &temp){
  float _x, _y;
  strumien >> _x >> _y;
  complexNumber _temp(_x,_y);
  temp = _temp;
  return strumien;
}
ostream& operator<<(ostream& strumien, complexNumber temp){ 
  strumien << temp.Re() << " + " << temp.Im() << "i";
  return strumien;
}

//wyswietlanie 
void complexNumber::showTryg(){
  float fi = atan(Im()/Re());
  cout << Modul() << "(cos(" << fi << ") + sin(" << fi << ")\n";  
}

//potegowanie wzorem
complexNumber complexNumber::Pow(int n){
  float fi = atan(Im()/Re());
  float mod = pow(Modul(), n);
  float _x = cos(n*fi);
  float _y = sin(n*fi);
  return complexNumber(_x*mod, _y*mod);
}
