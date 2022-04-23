
#ifndef MATRIX_HPP
#define MATRIX_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Matrix: virtual public MappableContainer<Data>,
              virtual public FoldableContainer<Data>{ // Must extend MappableContainer<Data> and FoldableContainer<Data>

private:

  // ...

protected:

  // ...
  unsigned long numRighe = 0;
  unsigned long numColonne = 0;

public:

  // Destructor
  // ~Matrix() specifiers
  virtual ~Matrix() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  Matrix& operator=(const Matrix&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  Matrix& operator=(Matrix&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator==(const Matrix&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator!=(const Matrix&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type RowNumber() specifiers; // (concrete function should not throw exceptions)
  unsigned long RowNumber() const noexcept;
  // type ColumnNumber() specifiers; // (concrete function should not throw exceptions)
  unsigned long ColumnNumber() const noexcept;

  // type RowResize() specifiers;
  virtual void RowResize(const unsigned long) = 0;
  // type ColumnResize() specifiers;
  virtual void ColumnResize(const unsigned long) = 0;

  // type ExistsCell() specifiers; // (concrete function should not throw exceptions)
  virtual bool ExistsCell(unsigned long, unsigned long) const noexcept = 0;

  // type operator()() specifiers; // Mutable access to the element (concrete function should throw exceptions only when out of range)
  virtual Data& operator()(const unsigned long, const unsigned long) = 0;
  // type operator()() specifiers; // Immutable access to the element (concrete function should throw exceptions when not present)
  virtual const Data& operator()(const unsigned long, const unsigned long) const = 0;

};

/* ************************************************************************** */

}

#include "matrix.cpp"

#endif
