
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec: virtual public BinaryTree<Data> { // Must extend BinaryTree<Data>

private:

  // ...

protected:

  // using BinaryTree<Data>::???;
  using BinaryTree<Data>::size;

  // ...

  struct NodeVec: virtual public BinaryTree<Data>::Node { // Must extend Node

  private:

    // ...

  protected:

    // ...

  public:

    // friend class BinaryTreeVec<Data>;
    using BinaryTree<Data>::Node::val;
    unsigned long index;
    const Vector<struct BinaryTreeVec<Data>::NodeVec*>* Array;

    virtual ~NodeVec()=default;

    Data& Element() noexcept override;
    const Data& Element() const noexcept override;

    NodeVec(const Data&, unsigned long, const Vector<NodeVec*>*);


    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;

    typename BinaryTreeVec<Data>::NodeVec& LeftChild() const override; //throw std::out_of_range
    typename BinaryTreeVec<Data>::NodeVec& RightChild() const override; //throw std::out_of_range


    typename BinaryTreeVec<Data>::NodeVec& operator=(const NodeVec&);
    typename BinaryTreeVec<Data>::NodeVec& operator=(NodeVec&&) noexcept;

  };


public:

  Vector<NodeVec*> Elements;
  // NodeVec* Elements = nullptr;

friend class BinaryTreeVec<Data>::NodeVec;
  // Default constructor
  // BinaryTreeVec() specifiers;
  BinaryTreeVec()=default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a LinearContainer
  BinaryTreeVec(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(BinaryTreeVec&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeVec() specifiers;
  virtual ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec<Data>& operator=(const BinaryTreeVec&);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec<Data>& operator=(BinaryTreeVec&&)  noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BinaryTreeVec&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const BinaryTreeVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
  typename BinaryTree<Data>::Node& Root() const override;

  using typename MappableContainer<Data>::MapFunctor;
  void MapBreadth(const MapFunctor, void*) override;

  using typename FoldableContainer<Data>::FoldFunctor;
  void FoldBreadth(const FoldFunctor, const void*, void*) const override;
  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member
  void Clear() override;

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
