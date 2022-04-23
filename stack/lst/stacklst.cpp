#include<iostream>
namespace lasd {

/* ************************************************************************** */

template<typename Data>
StackLst<Data>::StackLst():List<Data>::List(){

}

template<typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>& con):List<Data>::List(con){

}

template<typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& stklst): List<Data>::List(stklst){

}

template<typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& st) noexcept : List<Data>::List(std::move(st)){

}

template<typename Data>
StackLst<Data>::~StackLst(){

}

template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& copstk){
  lasd::List<Data>::operator=(copstk);
  return *this;
}

template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& movestk) noexcept{
  lasd::List<Data>::operator=(std::move(movestk));
  return *this;
}

template<typename Data>
bool StackLst<Data>::operator==(const StackLst& stk) const noexcept{
  return lasd::List<Data>::operator==(stk);
}

template<typename Data>
bool StackLst<Data>::operator!=(const StackLst& stk) const noexcept{
  return lasd::List<Data>::operator!=(stk);
}

template<typename Data>
void StackLst<Data>::Push(const Data& val){
  lasd::List<Data>::InsertAtFront(val);
}

template<typename Data>
void StackLst<Data>::Push(Data&& val){
  lasd::List<Data>::InsertAtFront(val);
}

template<typename Data>
Data& StackLst<Data>::Top(){
  if(size!=0){
    return lasd::List<Data>::Front();
  }else{
    throw std::length_error("Accesso ad uno stack vuoto");
  }
}

template<typename Data>
void StackLst<Data>::Pop(){
  if(size!=0){
    return lasd::List<Data>::RemoveFromFront();
  }else{
    throw std::length_error("Accesso ad uno stack vuoto");
  }
}

template<typename Data>
Data StackLst<Data>::TopNPop(){
  if(size!=0){
    return lasd::List<Data>::FrontNRemove();
  }else{
    throw std::length_error("Accesso ad uno stack vuoto");
  }
}

template<typename Data>
void StackLst<Data>::Clear(){
  if(size!=0){
    lasd::List<Data>::Clear();
  }
}



/* ************************************************************************** */

}
