#include <iostream>
#include <cmath>
#ifndef COMPLEX
#define COMPLEX

class complexNumber {
private:
  float x;
  float y;
public:
  //konstruktory
  complexNumber();
  complexNumber(float _x, float _y);
  //gettery
  float Re();
  float Im();
  //wlasnosci liczb zespolonych
  complexNumber Sprezenie();
  float Modul();
  //przeciezenia operatorow arytmetycznych
  complexNumber operator+(complexNumber temp);
  complexNumber operator+(float _x);
  complexNumber operator-(complexNumber temp);
  complexNumber operator-(float _x);
  complexNumber operator*(complexNumber temp);
  complexNumber operator*(float _x);
  complexNumber operator/(complexNumber temp);
  complexNumber operator/(float _x);
  //przeciazenia operatorow przypisania
  void operator=(complexNumber temp);
  void operator=(float _x);
  void operator+=(complexNumber temp);
  void operator+=(float _x);
  void operator-=(complexNumber temp);
  void operator-=(float _x);
  void operator*=(complexNumber temp);
  void operator*=(float _x);
  //wypis postaci |z|(cos + isin )
  void showTryg();
  //wypis postaci |z|e^pi
  complexNumber Pow(int n);
};

//przeciezenia operatorow strumienia (wypisania)
std::istream& operator>>(std::istream & strumien, complexNumber & temp);
std::ostream& operator<<(std::ostream & strumien, complexNumber  temp);

#endif // !COMPLEX

