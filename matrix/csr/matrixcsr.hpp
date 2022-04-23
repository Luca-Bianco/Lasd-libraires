
#ifndef MATRIXCSR_HPP
#define MATRIXCSR_HPP

/* ************************************************************************** */

#include "../matrix.hpp"

#include "../../list/list.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MatrixCSR: virtual public Matrix<Data>,
                 virtual protected List<std::pair<Data, unsigned long>>{ // Must extend Matrix<Data>

private:

  // ...

protected:

  // using Matrix<Data>::???;
  using Matrix<Data>::numRighe;
  using Matrix<Data>::numColonne;
  using List<std::pair<Data, unsigned long>>::testa;
  using List<std::pair<Data, unsigned long>>::tail;
  using List<std::pair<Data, unsigned long>>::size;
  using typename List<std::pair<Data, unsigned long>>::Node;


  // ...

  void DeleteNodes(Node*);
  lasd::Vector<Node**> rowVec = Vector<Node**>(1);

public:

  // Default constructor
  // MatrixCSR() specifiers;
  MatrixCSR();

  /* ************************************************************************ */


  // Specific constructors
  // MatrixCSR(argument) specifiers; // A matrix of some specified dimension
  MatrixCSR(unsigned long, unsigned long);

  /* ************************************************************************ */

  // Copy constructor
  // MatrixCSR(argument) specifiers;
  MatrixCSR(const MatrixCSR&);

  // Move constructor
  // MatrixCSR(argument) specifiers;
  MatrixCSR(MatrixCSR&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~MatrixCSR() specifiers;
  virtual ~MatrixCSR() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  MatrixCSR& operator=(const MatrixCSR&);

  // Move assignment
  // type operator=(argument) specifiers;
  MatrixCSR& operator=(MatrixCSR&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const MatrixCSR&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const MatrixCSR&) const noexcept;

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

#include "matrixcsr.cpp"

#endif
