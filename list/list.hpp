
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List: virtual public LinearContainer<Data>,
            virtual public MappableContainer<Data>,
            virtual public FoldableContainer<Data>{ // Must extend LinearContainer<Data>, MappableContainer<Data>, and FoldableContainer<Data>

private:

  // ...

protected:

  using LinearContainer<Data>::size; //prende la size di LinearContainer

  struct Node
  {

    // Data
    // ...
    //template <typename Data>
    Data val;
    struct Node* nextNode = nullptr;

    /* ********************************************************************** */

    // Specific constructors
    // ...
    Node() = default;
    //template <typename Data>
    Node(const Data&);


    /* ********************************************************************** */

    // Copy constructor
    // ...
  //  Node(const lasd::List<Data>::Node&);
    Node(const lasd::List<Data>::Node&);
    // Move constructor
    // ...
    Node(lasd::List<Data>::Node&&) noexcept;
    /* ********************************************************************** */

    // Destructor
    // ...
    virtual ~Node()=default;

    /* ********************************************************************** */

    // Comparison operators
    // ...
    bool operator==(const Node&)const noexcept;
    bool operator!=(const Node&)const noexcept;
    /* ********************************************************************** */

    // Specific member functions

    // ...
//    void changePointer(const Node&) noexcept;
  };

  struct Node* testa = nullptr;
  struct Node* tail = nullptr;
  // ...

public:

  // Default constructor
  // List() specifiers;
  List();

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a LinearContainer
  List(const LinearContainer<Data>&);
  /* ************************************************************************ */
  List(const unsigned long);
  // Copy constructor
  // List(argument) specifiers;
  List(const List&);
  // Move constructor
  // List(argument) specifiers;
  List(List&&)noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~List() specifiers;

  virtual ~List();

/* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  List& operator=(const List&);
  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  List& operator=(List&&)noexcept;

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */
  bool operator==(const List&) const noexcept;
  bool operator!=(const List&) const noexcept;
  // Specific member functions

  // type InsertAtFront(argument) specifier; // Copy of the value
//  template <typename Data>
  void InsertAtFront(const Data&);
  // type InsertAtFront(argument) specifier; // Move of the value
  //template <typename Data>
  void InsertAtFront(Data&&);
  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
//  template <typename Data>
  void RemoveFromFront();
  // type FrontNRemove() specifier; // (must throw std::length_error when empty)
//  template <typename Data>
  Data FrontNRemove();
  // type InsertAtBack(argument) specifier; // Copy of the value
  //template <typename Data>
  void InsertAtBack(const Data&);

  // type InsertAtBack(argument) specifier; // Move of the value
//  template <typename Data>
  void InsertAtBack(Data&&);

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member
  void Clear() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type Front() specifiers; // Override LinearContainer member (must throw std::length_error when empty)
  // type Back() specifiers; // Override LinearContainer member (must throw std::length_error when empty)
  Data& Front() const override;
  Data& Back() const override;
  // type operator[](argument) specifiers; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************ */
  Data& operator[](const unsigned long) const override;
  // Specific member functions (inherited from MappableContainer)

   using typename MappableContainer<Data>::MapFunctor;

  // type MapPreOrder(arguments) specifiers; // Override MappableContainer member
  // type MapPostOrder(arguments) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  void MapPreOrder(const MapFunctor, void*)override;
  void MapPostOrder(const MapFunctor, void*)override;

  // Specific member functions (inherited from FoldableContainer)
void Tail();
   using typename FoldableContainer<Data>::FoldFunctor;

  // type FoldPreOrder(arguments) specifiers; // Override FoldableContainer member
  // type FoldPostOrder(arguments) specifiers; // Override FoldableContainer member
  void FoldPreOrder(const FoldFunctor, const void*, void*) const override;
  void FoldPostOrder(const FoldFunctor, const void*, void*) const override;
  void stampaLista();
protected:

  // Node costruisciLista(unsigned long);
  List<Data>::Node* costruisciLista(unsigned long);
  void auxCopy(Node*, const Node*);
  bool uguaglianzaListe(const Node*, const Node*) const;
 //struct Node* auxRecuperaUltimoNodo() const;
 List<Data>::Node* auxRecuperaUltimoNodo() const;
  Data& auxAccessToNumber(unsigned long, Node*) const;

  // Auxiliary member functions (for MappableContainer)

  // type MapPreOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type MapPostOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  void auxMapPreOrder(const MapFunctor, void*, Node*);
  void auxFoldPreOrder(const FoldFunctor, const void*, void*, Node*) const;
  void auxFoldPreOrderWithSize(const FoldFunctor, const void*, void*, Node*, const unsigned long) const;
  void stampaLista(Node*);


  /* ************************************************************************ */

  // Auxiliary member functions (for FoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type FoldPostOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
