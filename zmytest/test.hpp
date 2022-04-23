
#ifndef MYTEST_HPP
#define MYTEST_HPP
#include <string>
#include "../matrix/matrix.hpp"

/* ************************************************************************** */

// ...

  void miotest();


  void SceltaB();
  void SceltaC();
  void SceltaD();
  void SceltaE();
  void SceltaF();
  void SceltaG();
  void SceltaH();
  void SceltaI();
  void SceltaJ();
  void SceltaK();
  void SceltaL();
  void SceltaM();
  void SceltaN();
  void subMenu();

  void PopolamentoCasualeVecInt();
  void PopolamentoCasualeCsrInt();
  void PopolamentoCasualeVecFloat();
  void PopolamentoCasualeCsrFloat();
  void PopolamentoCasualeVecString();
  void PopolamentoCasualeCsrString();

  std::string randomStringGenerator();


template<typename Data>
void stampaCella(const lasd::Matrix<Data>&, unsigned long i, unsigned long j);

template <typename Data>
void MapPrint(const Data& dat, void* _);

template<typename Data>
void AuxFoldExists(const Data&, const void*, void*);

void ProdottoInteri(const int&, const void*, void*);
void SommaFloat(const float&, const void*, void*);
void FoldConcatenazioneStringhe(const std::string&, const void*, void*);

void raddoppiaInteri(int&, void*_);
void cuboFloat(float&, void*_);
void concatenazioneStringhe(std::string&, void*);
/* ************************************************************************** */

#endif
