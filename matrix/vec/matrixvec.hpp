
#ifndef MATRIXVEC_HPP
#define MATRIXVEC_HPP

/* ************************************************************************** */

#include "../matrix.hpp"

#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MatrixVec: virtual public Matrix<Data>/*,
                 virtual public Vector<Data>*/{ // Must extend Matrix<Data>

private:

  // ...

protected:

  // using Matrix<Data>::???;
  using Matrix<Data>::numRighe;
  using Matrix<Data>::numColonne;
  // using Vector<Data>::Elements;
  // ...
  Vector<Data> vec;

public:

  // Default constructor
  // MatrixVec() specifiers;
  MatrixVec();

  /* ************************************************************************ */

  // Specific constructors
  // MatrixVec(argument) specifiers; // A matrix of some specified dimension
  MatrixVec(const unsigned long, const unsigned long);

  /* ************************************************************************ */

  // Copy constructor
  // MatrixVec(argument) specifiers;
  MatrixVec(const MatrixVec&);

  // Move constructor
  // MatrixVec(argument) specifiers;
  MatrixVec(MatrixVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~MatrixVec() specifiers;
  virtual ~MatrixVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  MatrixVec& operator=(const MatrixVec&);

  // Move assignment
  // type operator=(argument) specifiers;
  MatrixVec& operator=(MatrixVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const MatrixVec&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const MatrixVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Matrix)

  // type RowResize() specifiers; // Override Matrix member
  void RowResize(const unsigned long) override;
  // type ColumnResize() specifiers; // Override Matrix member
  void ColumnResize(const unsigned long) override;

  // type ExistsCell() specifiers; // Override Matrix member (should not throw exceptions)
  bool ExistsCell(unsigned long, unsigned long) const noexcept override;

  // type operator()() specifiers; // Override Matrix member (mutable access to the element; throw out_of_range when out of range)
  Data& operator()(const unsigned long, const unsigned long) override;
  // type operator()() specifiers; // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)
  const Data& operator()(const unsigned long, const unsigned long) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member
  void Clear() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)
  using typename MappableContainer<Data>::MapFunctor;
  // type MapPreOrder(arguments) specifiers; // Override MappableContainer member
  void MapPreOrder(const MapFunctor, void*) override;
  // using nomedellafunzione;
  // type MapPostOrder(arguments) specifiers; // Override MappableContainer member
  void MapPostOrder(const MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)
  using typename FoldableContainer<Data>::FoldFunctor;
  // type FoldPreOrder(arguments) specifiers; // Override FoldableContainer member
  void FoldPreOrder(const FoldFunctor, const void*, void*) const override;
  // type FoldPostOrder(arguments) specifiers; // Override FoldableContainer member
  void FoldPostOrder(const FoldFunctor, const void*, void*) const override;

};

/* ************************************************************************** */

}

#include "matrixvec.cpp"

#endif
