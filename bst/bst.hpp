
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../vector/vector.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"


/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST: virtual public BinaryTreeLnk<Data>{ // Must extend BinaryTreeLnk<Data>

private:

  // ...
  void MergeSort(Vector<Data>&);
  void MergeSort(Vector<Data>&, unsigned long, unsigned long);
  void Merge(Vector<Data>&, unsigned long, unsigned long, unsigned long);
  void Copy(Vector<Data>&, unsigned long, unsigned long, Vector<Data>&, unsigned long);
  void CostruisciBST(Vector<Data>&, unsigned long, unsigned long, typename BinaryTreeLnk<Data>::NodeLnk*);

protected:

  // using BinaryTreeLnk<Data>::???;
  using BinaryTreeLnk<Data>::size;
  using BinaryTreeLnk<Data>::root;
  using BinaryTreeLnk<Data>::NodeLnk;

  // ...

public:

  // Default constructor
  // BST() specifiers;
  BST()=default;


  /* ************************************************************************ */

  // Specific constructors
  // BST(argument) specifiers; // A bst obtained from a LinearContainer
  BST(const LinearContainer<Data>&); // A bst obtained from a LinearContainer


  /* ************************************************************************ */

  // Copy constructor
  // BST(argument) specifiers;
  BST(const BST&);


  // Move constructor
  // BST(argument) specifiers;
  BST(BST&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BST() specifiers;
  virtual ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BST<Data>& operator=(const BST&);

  // Move assignment
  // type operator=(argument) specifiers;
  BST<Data>& operator=(BST&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BST&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const BST&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type Insert(argument) specifiers; // Copy of the value
  void Insert(const Data&)noexcept;
  // type Insert(argument) specifiers; // Move of the value
  void Insert(Data&&)noexcept;
  // type Remove(argument) specifiers;
  void Remove(const Data&)noexcept;

  // type Min(argument) specifiers; // (concrete function must throw std::length_error when empty)
  const Data& Min()const;
  // type MinNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  Data MinNRemove();
  // type RemoveMin(argument) specifiers; // (concrete function must throw std::length_error when empty)
  void RemoveMin();

  // type Max(argument) specifiers; // (concrete function must throw std::length_error when empty)
  const Data& Max()const;
  // type MaxNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  Data MaxNRemove();
  // type RemoveMax(argument) specifiers; // (concrete function must throw std::length_error when empty)
  void RemoveMax();

  // type Predecessor(argument) specifiers; // (concrete function must throw std::length_error when empty)
  const Data& Predecessor(const Data&) const;
  // type PredecessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  Data PredecessorNRemove(const Data&);
  // type RemovePredecessor(argument) specifiers; // (concrete function must throw std::length_error when empty)
  void RemovePredecessor(const Data&);

  // type Successor(argument) specifiers; // (concrete function must throw std::length_error when empty)
  const Data& Successor(const Data&) const;
  // type SuccessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  Data SuccessorNRemove(const Data&);
  // type RemoveSuccessor(argument) specifiers; // (concrete function must throw std::length_error when empty)
  void RemoveSuccessor(const Data&);

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  bool Exists(const Data&) const noexcept override;

protected:

  // Auxiliary member functions

  // type DataNDelete(argument) specifiers;
  Data DataNDelete(typename BinaryTreeLnk<Data>::NodeLnk*);

  // type Detach(argument) specifiers;
  typename BinaryTreeLnk<Data>::NodeLnk* Detach(typename BinaryTreeLnk<Data>::NodeLnk*&) noexcept;

  // type DetachMin(argument) specifiers;
  typename BinaryTreeLnk<Data>::NodeLnk* DetachMin(typename BinaryTreeLnk<Data>::NodeLnk*&) noexcept;
  // type DetachMax(argument) specifiers;
  typename BinaryTreeLnk<Data>::NodeLnk* DetachMax(typename BinaryTreeLnk<Data>::NodeLnk*&) noexcept;

  // type SkipOnLeft(argument) specifiers;
  typename BinaryTreeLnk<Data>::NodeLnk* SkipOnLeft(typename BinaryTreeLnk<Data>::NodeLnk*&) noexcept;
  // type SkipOnRight(argument) specifiers;
  typename BinaryTreeLnk<Data>::NodeLnk* SkipOnRight(typename BinaryTreeLnk<Data>::NodeLnk*&) noexcept;

  // type FindPointerToMin(argument) specifiers;
  typename BinaryTreeLnk<Data>::NodeLnk*& FindPointerToMin(typename BinaryTreeLnk<Data>::NodeLnk*&) noexcept;
  typename BinaryTreeLnk<Data>::NodeLnk* const& FindPointerToMin(typename BinaryTreeLnk<Data>::NodeLnk* const&) const noexcept;

  // type FindPointerToMax(argument) specifiers;
  typename BinaryTreeLnk<Data>::NodeLnk*& FindPointerToMax(typename BinaryTreeLnk<Data>::NodeLnk*&) noexcept;
  typename BinaryTreeLnk<Data>::NodeLnk* const& FindPointerToMax(typename BinaryTreeLnk<Data>::NodeLnk* const&) const noexcept;


  // type FindPointerTo(argument) specifiers;
  typename BinaryTreeLnk<Data>::NodeLnk*& FindPointerTo(typename BinaryTreeLnk<Data>::NodeLnk*&, const Data&) noexcept;
  typename BinaryTreeLnk<Data>::NodeLnk* const& FindPointerTo(typename BinaryTreeLnk<Data>::NodeLnk* const&, const Data&) const noexcept;

  // type FindPointerToPredecessor(argument) specifiers;
  typename BinaryTreeLnk<Data>::NodeLnk*& FindPointerToPredecessor(typename BinaryTreeLnk<Data>::NodeLnk*&, const Data&) noexcept;
  typename BinaryTreeLnk<Data>::NodeLnk* const& FindPointerToPredecessor(typename BinaryTreeLnk<Data>::NodeLnk* const&, const Data&) const noexcept;

  // type FindPointerToSuccessor(argument) specifiers;
  typename BinaryTreeLnk<Data>::NodeLnk*& FindPointerToSuccessor(typename BinaryTreeLnk<Data>::NodeLnk*&, const Data&) noexcept;
  typename BinaryTreeLnk<Data>::NodeLnk* const& FindPointerToSuccessor(typename BinaryTreeLnk<Data>::NodeLnk* const&, const Data&) const noexcept;

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
