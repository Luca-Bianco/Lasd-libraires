
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk: virtual public BinaryTree<Data> { // Must extend BinaryTree<Data>

private:

  // ...

protected:

  // using BinaryTree<Data>::???;
  using BinaryTree<Data>::size;

  // ...

  struct NodeLnk: virtual public BinaryTree<Data>::Node { // Must extend Node

  private:

    // ...

  protected:

    // ...


  public:

    struct NodeLnk* figlioSinistro = nullptr;
    struct NodeLnk* figlioDestro = nullptr;
    using BinaryTree<Data>::Node::val;

    NodeLnk() = default;
    NodeLnk(const Data&);
    NodeLnk(Data&&) noexcept;

    virtual ~NodeLnk();
    // Data& Element() noexcept override;

    Data& Element() noexcept override;
    const Data& Element() const noexcept override;


    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;

    typename BinaryTree<Data>::Node& LeftChild() const override; // throw std::out_of_range
    typename BinaryTree<Data>::Node& RightChild() const override; //throw std::out_of_range
    // typename BinaryTree<Data>::Node& prova() const override; //throw std::out_of_range


    typename BinaryTreeLnk<Data>::NodeLnk& operator=(const NodeLnk&);
    typename BinaryTreeLnk<Data>::NodeLnk& operator=(NodeLnk&&) noexcept;


  };

  struct NodeLnk* root = nullptr;

  void auxBinaryTreeLnk(NodeLnk*, unsigned long, const LinearContainer<Data>&);
  void auxBinaryTreeLnkCopyConstructor(NodeLnk*, struct BinaryTree<Data>::Node&);
  // void auxBinaryTreeLnkMoveConstructor(NodeLnk*, struct BinaryTree<Data>::Node*);
  // void auxBinaryTreeLnkClear(NodeLnk&);


public:

  // Default constructor
  // BinaryTreeLnk() specifiers;
  BinaryTreeLnk()=default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a LinearContainer
  BinaryTreeLnk(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeLnk(argument) specifiers;
  BinaryTreeLnk(const BinaryTreeLnk&);

  // Move constructor
  // BinaryTreeLnk(argument) specifiers;
  BinaryTreeLnk(BinaryTreeLnk&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeLnk() specifiers;
  virtual~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeLnk& operator=(const BinaryTreeLnk&);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
  typename BinaryTree<Data>::Node& Root() const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member
  void Clear() override;

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
