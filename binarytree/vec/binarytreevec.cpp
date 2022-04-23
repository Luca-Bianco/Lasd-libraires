#include<iostream>
namespace lasd {

/* ************************************************************************** */

// ...

template<typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept{
  return val;
}

template<typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept{
  return val;
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{
  if(((2*index)+1) < Array->Size()){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& dato, unsigned long i, const Vector<NodeVec*>* vec){
    val=dato;
    index=i;
    Array=vec;
}


template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& nodo){
  val=nodo.val;
  index=nodo.index;
  Array=nodo.Array;
  return *this;
}

template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& nodo) noexcept{
  std::swap(val,nodo.val);
  std::swap(index,nodo.index);
  std::swap(Array,nodo.Array);
  return *this;
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{
  if(((2*index)+2) < Array->Size()){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const{
  if(HasLeftChild()==true){
    // return *Array->operator[]((2*index)+1);
    return *((*Array)[(2*index)+1]);
  }else{
    throw std::out_of_range("this node hasn't got a LeftChild");
  }
}

template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const{
  if(HasRightChild() == true){
    // return *Array->operator[]((2*index)+2);
    return *((*Array)[(2*index)+2]);
  }else{
    throw std::out_of_range("this node hasn't got a RightChild");
  }
}

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& con){
  size=con.Size();
  Elements.Resize(con.Size());

  unsigned long i;

  for(i=0;i<con.Size();i++){
    Elements[i] = new BinaryTreeVec<Data>::NodeVec(con[i], i, &Elements);
  }
}

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec& bt){
  size=bt.size;
  Elements.Resize(size);
  for(unsigned long index=0; index<size; index++){
    Elements[index]=new NodeVec(bt.Elements[index]->Element(), index, &Elements);
  }
}

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec&& bt) noexcept{
  std::swap(size, bt.size);
  std::swap(Elements, bt.Elements);
  for(unsigned long index=0; index<size; index++){
    Elements[index]->Array=&Elements;
  }
}

template<typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){
  for(unsigned long i; i<Elements.Size(); i++){
    delete Elements[i];
  }
   Elements.Clear();
   size=0;
}

template<typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec& bt){
  BinaryTreeVec<Data>* tmp = new BinaryTreeVec<Data> (bt);
  std::swap(*this, *tmp);
  for(unsigned long index=0; index<size; index++){
    Elements[index]->Array=&Elements;
  }
  delete tmp;
  return *this;
}

template<typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec&& bt) noexcept{
  std::swap(size, bt.size);
  std::swap(Elements, bt.Elements);
  for(unsigned long index=0; index<size; index++){
    Elements[index]->Array=&Elements;
  }
  return *this;
}

template<typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec& bt) const noexcept{
  if(size==bt.size){
    for(unsigned int i = 0; i < size; i++){
      if(*Elements[i] != *bt.Elements[i]){
        return false;
      }
    }
    return true;
  }
  else{
    return false;
  }
}

template<typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec& bt) const noexcept{
  return !(BinaryTreeVec<Data>::operator==(bt));
}

template<typename Data>
typename BinaryTree<Data>::Node& BinaryTreeVec<Data>::Root() const{
  if(size!=0){
    return *Elements[0];
  }
  throw std::length_error("vuoto");
}

template<typename Data>
void BinaryTreeVec<Data>::Clear(){
  for(unsigned long i; i<Elements.Size(); i++){
    delete Elements[i];
  }
   Elements.Clear();
   size=0;
}

template<typename Data>
void BinaryTreeVec<Data>::MapBreadth(const MapFunctor fun, void* par){
  unsigned long index;
  if(Elements.Size()!=0){
  for(index=0;index<size;index++){
    fun(Elements[index]->val, par);
  }
}
}

template<typename Data>
void BinaryTreeVec<Data>::FoldBreadth(const FoldFunctor fun, const void* par, void* acc)const{
  unsigned long index;
if(Elements.Size()!=0){
  for(index=0;index<size;index++){
    fun(Elements[index]->val, par, acc);
  }
}
}




/* ************************************************************************** */

}
