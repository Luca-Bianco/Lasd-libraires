
// #include "..."

namespace lasd {

/* ************************************************************************** */
// ...
template<typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept{
  return (val==node.val);
}

template<typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept{
  return (val!=node.val);
}

template<typename Data>
bool BinaryTree<Data>::Node::IsLeaf() const noexcept{
  if(HasLeftChild() == false && HasRightChild() == false){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& bt) const noexcept{
  if(size == bt.size){
    if(size==0){
      return true;
    }else{
    if(&Root()!=nullptr && &bt.Root()!= nullptr){
      return AuxEqualTree(Root(),bt.Root());
    }else if(&Root() == nullptr && &bt.Root()==nullptr){
              return true;
              }
            }
          }
  return false;
  }

template<typename Data>
bool BinaryTree<Data>::AuxEqualTree(const Node& primoNodo, const Node& secondoNodo) const noexcept{
  bool ret=false;
  if(primoNodo.val == secondoNodo.val){
    if(primoNodo.IsLeaf()==true && secondoNodo.IsLeaf()==true){
      return true;
    }else{
      if(primoNodo.HasLeftChild() && secondoNodo.HasLeftChild()){
        ret=AuxEqualTree(primoNodo.LeftChild(), secondoNodo.LeftChild());
        if(ret==false){
          return ret;
        }
      }else{
        if(primoNodo.HasLeftChild()==false && secondoNodo.HasLeftChild()==false){
        ret = true;
      }else{
        return false;
      }
      }
      if(primoNodo.HasRightChild() && secondoNodo.HasRightChild()){
        ret=AuxEqualTree(primoNodo.RightChild(), secondoNodo.RightChild());
        if(ret==false){
          return ret;
        }
      }else{
        if(primoNodo.HasRightChild()==false && secondoNodo.HasRightChild()==false){
        ret = true;
      }else{
        return false;
      }
      }
    }
  }
  return ret;
}

template<typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree& binarytree) const noexcept{
  return !(lasd::BinaryTree<Data>::operator==(binarytree));
}

template<typename Data>
void BinaryTree<Data>::MapPreOrder(const MapFunctor fun, void* par){
  if(size!=0){
    MapPreOrder(Root(), fun, par);
  }
}

template<typename Data>
void BinaryTree<Data>::MapPreOrder(Node& nodo, const MapFunctor fun, void* par){
    fun(nodo.val, par);
    if(nodo.HasLeftChild()==true){
      MapPreOrder(nodo.LeftChild(), fun, par);
    }
    if(nodo.HasRightChild()==true){
      MapPreOrder(nodo.RightChild(), fun, par);
    }
}


template<typename Data>
void BinaryTree<Data>::MapPostOrder(const MapFunctor fun, void* par){
  if(size!=0){
      MapPostOrder(Root(), fun, par);
    }
  }

template<typename Data>
void BinaryTree<Data>::MapPostOrder(Node& nodo, const MapFunctor fun, void* par){
  if(nodo.HasLeftChild() == true){
    MapPostOrder(nodo.LeftChild(), fun, par);
  }
  if(nodo.HasRightChild() == true){
    MapPostOrder(nodo.RightChild(), fun, par);
  }
  fun(nodo.val, par);
}

template<typename Data>
void BinaryTree<Data>::MapInOrder(const MapFunctor fun, void* par){
  if(size!=0){
    MapInOrder(Root(), fun, par);
  }
}

template<typename Data>
void BinaryTree<Data>::MapInOrder(Node& nodo, const MapFunctor fun, void* par){
  if(nodo.HasLeftChild()==true){
    MapInOrder(nodo.LeftChild(), fun, par);
  }

  fun(nodo.val, par);

  if(nodo.HasRightChild()==true){
    MapInOrder(nodo.RightChild(), fun, par);
  }
}

template<typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const{
  if(size!=0){
    FoldPreOrder(Root(), fun, par, acc);
  }
}

template<typename Data>
void BinaryTree<Data>::FoldPreOrder(const Node& nodo, const FoldFunctor fun, const void* par, void* acc) const{
  fun(nodo.val, par, acc);

  if(nodo.HasLeftChild() == true){
    FoldPreOrder(nodo.LeftChild(), fun, par, acc);
  }
  if(nodo.HasRightChild() == true){
    FoldPreOrder(nodo.RightChild(), fun, par, acc);
  }
}

template<typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const{
  if(size!=0){
    FoldPostOrder(Root(), fun, par, acc);
  }
}

template<typename Data>
void BinaryTree<Data>::FoldPostOrder(const Node& nodo, const FoldFunctor fun, const void* par, void* acc) const{
  if(nodo.HasLeftChild() == true){
    FoldPostOrder(nodo.LeftChild(), fun, par, acc);
  }
  if(nodo.HasRightChild() == true){
    FoldPostOrder(nodo.RightChild(), fun, par, acc);
  }
  fun(nodo.val, par, acc);
}

template<typename Data>
void BinaryTree<Data>::FoldInOrder(const FoldFunctor fun, const void* par, void* acc) const{
  if(size!=0){
    FoldInOrder(Root(), fun, par, acc);
  }
}

template<typename Data>
void BinaryTree<Data>::FoldInOrder(const Node& nodo, const FoldFunctor fun, const void* par, void* acc) const{
  if(nodo.HasLeftChild() == true){
    FoldInOrder(nodo.LeftChild(), fun, par, acc);
  }

  fun(nodo.val, par, acc);

  if(nodo.HasRightChild() ==true){
    FoldInOrder(nodo.RightChild(), fun, par, acc);
  }
}

template<typename Data>
void BinaryTree<Data>::MapBreadth(const MapFunctor fun, void* par){
  if(size!=0){
    MapBreadth(&Root(), fun, par);
  }
}

template<typename Data>
void BinaryTree<Data>::MapBreadth(Node* nodo, const MapFunctor fun, void* par){
  QueueLst<Node*> queMapBreadth;
  bool check = false;
  fun(nodo->Element(), par);
  do{
    if(nodo->HasLeftChild() == true){
      fun(nodo->LeftChild().Element(), par);
      queMapBreadth.Enqueue(&nodo->LeftChild());
    }
    if(nodo->HasRightChild() == true){
      fun(nodo->RightChild().Element(), par);
      queMapBreadth.Enqueue(&nodo->RightChild());
    }
    if(queMapBreadth.Size()!=0){
      nodo=queMapBreadth.HeadNDequeue();
    }else{
      check = true;
    }
  }while(/*queMapBreadth.Size()!=0*/ check==false);
}

template<typename Data>
void BinaryTree<Data>::FoldBreadth(const FoldFunctor fun, const void* par, void* acc) const{
  if(size!=0){
    FoldBreadth(&Root(), fun, par, acc);
  }
}

template<typename Data>
void BinaryTree<Data>::FoldBreadth(const Node* nodo, const FoldFunctor fun, const void* par, void* acc) const{
QueueLst<Node*> queFoldBreadth;
bool check=false;
fun(nodo->Element(), par, acc);
do{
  if(nodo->HasLeftChild()){
    fun(nodo->LeftChild().Element(), par, acc);
    queFoldBreadth.Enqueue(&nodo->LeftChild());
  }
  if(nodo->HasRightChild()){
    fun(nodo->RightChild().Element(), par, acc);
    queFoldBreadth.Enqueue(&nodo->RightChild());
  }
  if(queFoldBreadth.Size()!=0){
    nodo=queFoldBreadth.HeadNDequeue();
  }else{
    check=true;
  }
}while(/*queFoldBreadth.Size()!=0 && nodo!=nullptr*/ check==false);


}

//BTPreOrderIterator

template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& bt){
  curr=&(bt.Root());
}

template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator& iterator){
  curr=iterator.curr;
  stk=iterator.stk;
}

template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& iterator) noexcept{
  std::swap(curr, iterator.curr);
  std::swap(stk, iterator.stk);
}

template<typename Data>
BTPreOrderIterator<Data>::~BTPreOrderIterator(){
  curr=nullptr;
  stk.Clear();
}

template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& iterator){
  curr=iterator.curr;
  stk=iterator.stk;
  return *this;
}

template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator&& iterator) noexcept{
  std::swap(curr, iterator.curr);
  std::swap(stk, iterator.stk);
  return *this;
}

template<typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator& iterator) const noexcept{
  if((curr==iterator.curr) && (stk==iterator.stk)){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator& iterator) const noexcept{
  return !(BTPreOrderIterator<Data>::operator==(iterator));
}

template<typename Data>
Data& BTPreOrderIterator<Data>::operator*() const{
  if(Terminated() == false){
    return curr->val;
  }else{
    throw std::out_of_range("iteratore terminato");
  }
}

template<typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept{
  if((curr==nullptr) && (stk.Empty() == true)){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
void BTPreOrderIterator<Data>::operator++(){

if(Terminated() == false){

  if(curr->HasLeftChild() == true){
    if(curr->HasRightChild() == true){
      stk.Push(&curr->RightChild());
    }
    curr=&curr->LeftChild();
  }else{
    if(curr->HasRightChild() == true){
      curr=&curr->RightChild();
    }else{
      if(stk.Empty() == true){
        curr=nullptr;
      }else{
        curr=stk.TopNPop();
      }
    }
  }
}else{
  throw std::out_of_range("struttura terminata");
}
}

//BTPostOrderIterator

template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& bt){
  curr=LeftMostLeaf(&bt.Root());
}

template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& iterator){
  curr=iterator.curr;
  stk=iterator.stk;
}

template<typename Data>
typename BinaryTree<Data>::Node* BTPostOrderIterator<Data>::LeftMostLeaf(struct BinaryTree<Data>::Node* nodo){
  if(nodo->HasLeftChild() == true){
    stk.Push(nodo);
    return LeftMostLeaf(&nodo->LeftChild());
  }else if(nodo->HasRightChild() == true){
    stk.Push(nodo);
    return LeftMostLeaf(&nodo->RightChild());
  }else{
    return nodo;
  }
}

template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& iterator) noexcept{
  std::swap(curr, iterator.curr);
  std::swap(stk, iterator.stk);
}

template<typename Data>
BTPostOrderIterator<Data>::~BTPostOrderIterator(){
  curr=nullptr;
  stk.Clear();
}

template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& iterator){
  curr=iterator.curr;
  stk=iterator.stk;
  return *this;
}

template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator&& iterator) noexcept{
  std::swap(curr, iterator.curr);
  std::swap(stk, iterator.stk);
  return *this;
}

template<typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator& iterator) const noexcept{
  if((curr==iterator.curr) && (stk == iterator.stk)){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator& iterator) const noexcept{
  return !(BTPreOrderIterator<Data>::operator==(iterator));
}

template<typename Data>
Data& BTPostOrderIterator<Data>::operator*() const{
  if(Terminated() == false){
    return curr->val;
  }else{
    throw std::out_of_range("iteratore terminato");
  }
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept{
  if((curr==nullptr) && (stk.Empty() == true)){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
void BTPostOrderIterator<Data>::operator++(){
  if(Terminated()==false){
    if(stk.Empty() == false){
      if(stk.Top()->HasLeftChild() && curr == &(stk.Top())->LeftChild()){
        if(stk.Top()->HasRightChild() == true){
          curr=LeftMostLeaf(&(stk.Top())->RightChild());
        }else{
          curr=stk.TopNPop();
        }
      }else{
        curr=stk.TopNPop();
      }
    }else{
      curr=nullptr;
    }
  }else{
    throw std::out_of_range("iteratore terminato");
  }
}

//BTInOrderIterator

template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& bt){
  curr=LeftMostNode(&bt.Root());
}

template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& iterator){
  curr=iterator.curr;
  stk=iterator.stk;
}

template<typename Data>
typename BinaryTree<Data>::Node* BTInOrderIterator<Data>::LeftMostNode(struct BinaryTree<Data>::Node* nodo){
  if(nodo->HasLeftChild() == true){
    stk.Push(nodo);
    return LeftMostNode(&nodo->LeftChild());
  }else{
    return nodo;
  }
}

template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator&& iterator) noexcept{
  std::swap(curr, iterator.curr);
  std::swap(stk, iterator.stk);
}

template<typename Data>
BTInOrderIterator<Data>::~BTInOrderIterator(){
  curr = nullptr;
  stk.Clear();
}

template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& iterator){
  curr=iterator.curr;
  stk=iterator.stk;
  return *this;
}

template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator&& iterator) noexcept{
  std::swap(curr, iterator.curr);
  std::swap(stk, iterator.stk);
  return *this;
}

template<typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator& iterator) const noexcept{
  if((curr==iterator.curr) && (stk==iterator.stk)){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator& iterator) const noexcept{
  return !(BTInOrderIterator<Data>::operator==(iterator));
}

template<typename Data>
Data& BTInOrderIterator<Data>::operator*() const{
  return curr->val;
}

template<typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept{
  if((curr==nullptr) && (stk.Empty() == true)){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
void BTInOrderIterator<Data>::operator++(){
  if(Terminated()==false){
    if(curr->HasRightChild()==true){
      curr=LeftMostNode(&curr->RightChild());
    }else if(stk.Empty()==false){
      curr=stk.TopNPop();
    }else{
      curr=nullptr;
    }
  }else{
     throw std::out_of_range("iteratore terminato");
  }
}

//BTBreadthIterator
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& bt){
  curr=&bt.Root();
}

template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator& iterator){
  curr=iterator.curr;
  que=iterator.que;
}

template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator&& iterator) noexcept{
  std::swap(curr, iterator.curr);
  std::swap(que, iterator.que);
}

template<typename Data>
BTBreadthIterator<Data>::~BTBreadthIterator(){
  curr=nullptr;
  que.Clear();
}

template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator& iterator){
  curr=iterator.curr;
  que=iterator.que;
  return *this;
}

template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator&& iterator)noexcept{
  std::swap(curr, iterator.curr);
  std::swap(que, iterator.que);
  return *this;
}

template<typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator& iterator) const noexcept{
  if((curr==iterator.curr) && (que==iterator.que)){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator& iterator) const noexcept{
  return !(BTBreadthIterator<Data>::operator==(iterator));
}

template<typename Data>
Data& BTBreadthIterator<Data>::operator*() const{
  return curr->val;
}

template<typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept{
  if((curr==nullptr) && (que.Empty()==true)){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
void BTBreadthIterator<Data>::operator++(){
  if(Terminated()==false){
    if(curr->HasLeftChild() == true){
      que.Enqueue(&curr->LeftChild());
    }
    if(curr->HasRightChild() == true){
      que.Enqueue(&curr->RightChild());
    }
    if(que.Empty()==false){
      curr=que.HeadNDequeue();
    }else{
      curr=nullptr;
    }
  }else{
    throw std::out_of_range("Iteratore terminato");
  }
}

/* ************************************************************************** */

}
