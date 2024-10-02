#ifndef MATRYCE
#define MATRYCE

class matryca{
private:
  unsigned int w;
  unsigned int k;
  float **elementy;
public: 
  //konstruktory
  matryca();
  matryca(unsigned int _n, float** _M );
  matryca(unsigned int _w, unsigned int _k, float** _M);
  ~matryca();
  //gettery
  unsigned int wiersze();
  unsigned int kolumny();
  float element(int i, int j);
  //operacje arytmetyczne
  matryca operator+(matryca _matryca);
  matryca operator-(matryca _matryca);
  matryca operator*(matryca _matryca);
  //operacje przypisania
  void operator=(matryca _matryca);
  void operator+=(matryca _matryca);
  void operator-=(matryca _matryca);
  void operator*=(matryca _matryca);
  //wyznaczniki
  float wyznacznik();
  //rzad
  int rzad();
};

#endif // !MATRYCE
