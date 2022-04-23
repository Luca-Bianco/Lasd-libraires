
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst: virtual public Queue<Data>,
                virtual protected List<Data>{ // Must extend Queue<Data> and List<Data>

private:

  // ...

protected:

  // using List<Data>::???;
  using List<Data>::size;
  using List<Data>::testa;
  using List<Data>::tail;

  // ...

public:

  // Default constructor
  // QueueLst() specifier;
  QueueLst();

  /* ************************************************************************ */

  // Specific constructor
  // QueueLst(argument) specifiers; // A queue obtained from a LinearContainer

  QueueLst(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // QueueLst(argument);

  QueueLst(const QueueLst&);

  // Move constructor
  // QueueLst(argument);

  QueueLst(QueueLst&&) noexcept;

  /* ************************************************************************ */

  QueueLst(const unsigned long);

  // Destructor
  // ~QueueLst() specifier;

  virtual ~QueueLst();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  QueueLst& operator=(const QueueLst&);

  // Move assignment
  // type operator=(argument);
  QueueLst& operator=(QueueLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const QueueLst&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const QueueLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  void Enqueue(const Data&) override;
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)
  void Enqueue(Data&&) override;
  // type Head() specifiers; // Override Queue member (must throw std::length_error when empty)
  Data& Head() override;
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  void Dequeue()override;
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue()override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member
  void Clear() override;


};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
