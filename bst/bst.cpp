
namespace lasd {

/* ************************************************************************** */

// ...

template<typename Data>
BST<Data>::BST(const LinearContainer<Data>& con){
  // size=con.Size();
  // if(con.Size()>0){
  // lasd::Vector<Data> vec(con);
  // MergeSort(vec, 0, vec.Size()-1);
  // // unsigned long mediano = (vec.Size()-1)/2;
  // root = new typename BinaryTreeLnk<Data>::NodeLnk::NodeLnk();
  // CostruisciBST(vec, 0, vec.Size(), root);
  // }
  unsigned long index;

  for(index=0; index<con.Size(); index++){
    Insert(con[index]);
  }
}

template<typename Data>
void BST<Data>::CostruisciBST(Vector<Data>& vec, unsigned long p, unsigned long r, typename BinaryTreeLnk<Data>::NodeLnk* nodo){
  if(p<r){
    unsigned long q=(p+r)/2;
    nodo->val=vec[q];
    if(p<q){
    nodo->figlioSinistro=new typename BinaryTreeLnk<Data>::NodeLnk::NodeLnk();
    CostruisciBST(vec, p, q, nodo->figlioSinistro);
    }
    if((q+1)<r){
    nodo->figlioDestro=new typename BinaryTreeLnk<Data>::NodeLnk::NodeLnk();
    CostruisciBST(vec, q+1, r, nodo->figlioDestro);
    }
  }
}

//private for sort
template<typename Data>
void BST<Data>::MergeSort(Vector<Data>& vec, unsigned long p, unsigned long r){
	if(p<r){
		int q=(p+r)/2;
		MergeSort(vec, p, q);
		MergeSort(vec, q+1, r);
		Merge(vec, p, q, r);
	}
}

template<typename Data>
void BST<Data>::Merge(Vector<Data>& vec, unsigned long p, unsigned long q, unsigned long r){
	unsigned long z=p;
	unsigned long i=p;
	unsigned long j=q+1;
	Vector<Data> b(vec.Size());

	while(i<=q && j<=r){
		if(vec[i] <= vec[j]){
			b[z]=vec[i];
			i++;
		}else{
			b[z]=vec[j];
			j++;
		}
	z++;
	}
	Copy(vec,i,q,b,z);
	Copy(vec,j,r,b,z);
	Copy(b,p,r,vec,p);
}

template<typename Data>
void BST<Data>::Copy(Vector<Data>& a1, unsigned long k, unsigned long max, Vector<Data>& a2, unsigned long z){
	while(k<=max){
		a2[z] = a1[k];
		k++;
		z++;
	}
}
// end private fot sort

template<typename Data>
BST<Data>::BST(const BST<Data>& tree): BinaryTreeLnk<Data>::BinaryTreeLnk(tree){

}

template<typename Data>
BST<Data>::BST(BST<Data>&& bst) noexcept: BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(bst)){

}

template<typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& tree){
  BinaryTreeLnk<Data>::operator=(tree);
  return *this;
}

template<typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& tree)noexcept{
  BinaryTreeLnk<Data>::operator=(std::move(tree));
  return *this;
}

template<typename Data>
bool BST<Data>::operator==(const BST<Data>& tree) const noexcept{
if(size==tree.Size()){
  if(size==0){
    return true;
  }else{
    lasd::BTInOrderIterator<Data> itr1(*this);
    lasd::BTInOrderIterator<Data> itr2(tree);
    while(itr1.Terminated()==false){
      if(*itr1 != *itr2){
        return false;
      }
      ++itr1;
      ++itr2;
    }
    return true;
  }
}else{
  return false;
  }
}

template<typename Data>
bool BST<Data>::operator!=(const BST<Data>& tree) const noexcept{
  return !(BST<Data>::operator==(tree));
}

template<typename Data>
void BST<Data>::Insert(const Data& dat)noexcept{
  typename BinaryTreeLnk<Data>::NodeLnk** pointer = &FindPointerTo(root, dat);
  if(*pointer==nullptr){
    *pointer = new typename BinaryTreeLnk<Data>::NodeLnk::NodeLnk(dat);
    size++;
  }
}

template<typename Data>
void BST<Data>::Insert(Data&& dat)noexcept{
  typename BinaryTreeLnk<Data>::NodeLnk** pointer = &FindPointerTo(root, dat);
  if(*pointer==nullptr){
    *pointer = new typename BinaryTreeLnk<Data>::NodeLnk::NodeLnk(std::move(dat));
    size++;
  }
}

template<typename Data>
void BST<Data>::Remove(const Data& dat)noexcept{
  typename BinaryTreeLnk<Data>::NodeLnk** pointer = &FindPointerTo(root,dat);
  delete Detach(*pointer);
}

template<typename Data>
const Data& BST<Data>::Min() const{
  if(root!=nullptr){
    typename BinaryTreeLnk<Data>::NodeLnk* pointerToMin = FindPointerToMin(root);
    return pointerToMin->val;
  }else{
    throw std::length_error("albero vuoto");
  }
}

template<typename Data>
Data BST<Data>::MinNRemove(){
  if(root!=nullptr){
    return DataNDelete(DetachMin(root));
  }else{
    throw std::length_error("albero vuoto");
  }
}

template<typename Data>
void BST<Data>::RemoveMin(){
  if(root!=nullptr){
    delete DetachMin(root);
  }else{
    throw std::length_error("albero vuoto");
  }
}

template<typename Data>
const Data& BST<Data>::Max() const{
  if(root != nullptr){
    typename BinaryTreeLnk<Data>::NodeLnk* pointerToMax = FindPointerToMax(root);
    return pointerToMax->val;
  }else{
    throw std::length_error("albero vuoto");
  }
}

template<typename Data>
Data BST<Data>::MaxNRemove(){
  if(root!=nullptr){
    return DataNDelete(DetachMax(root));
  }else{
    throw std::length_error("albero vuoto");
  }
}

template<typename Data>
void BST<Data>::RemoveMax(){
  if(root!=nullptr){
    delete DetachMax(root);
  }else{
    throw std::length_error("albero vuoto");
  }
}

template<typename Data>
bool BST<Data>::Exists(const Data& dat) const noexcept{
  if(FindPointerTo(root,dat) == nullptr){
    return false;
  }else{
    return true;
  }
}

template<typename Data>
const Data& BST<Data>::Predecessor(const Data& dat) const{
  typename BinaryTreeLnk<Data>::NodeLnk* const* tmp = &FindPointerToPredecessor(root, dat);
  if((*tmp) != nullptr){
    return (*tmp)->val;
  }else{
    throw std::length_error("Predecessor does not exist");
  }
}

template<typename Data>
Data BST<Data>::PredecessorNRemove(const Data& dat){
  typename BinaryTreeLnk<Data>::NodeLnk** tmp = &FindPointerToPredecessor(root, dat);
  if((*tmp)!=nullptr){
    return DataNDelete(Detach(*tmp));
  }else{
    throw std::length_error("Predecessor does not exist");
  }
}

template<typename Data>
void BST<Data>::RemovePredecessor(const Data& dat){
  typename BinaryTreeLnk<Data>::NodeLnk** tmp = &FindPointerToPredecessor(root, dat);
  if((*tmp)!=nullptr){
    delete Detach(*tmp);
  }else{
    throw std::length_error("Predecessor does not exist");
  }
}

template<typename Data>
const Data& BST<Data>::Successor(const Data& dat) const{
  typename BinaryTreeLnk<Data>::NodeLnk* const* tmp = &FindPointerToSuccessor(root, dat);
  if((*tmp)!=nullptr){
    return (*tmp)->val;
  }else{
    throw std::length_error("Successor does not exist");
  }
}

template<typename Data>
Data BST<Data>::SuccessorNRemove(const Data& dat){
  typename BinaryTreeLnk<Data>::NodeLnk** tmp = &FindPointerToSuccessor(root, dat);
  if((*tmp)!=nullptr){
    return DataNDelete(Detach(*tmp));
  }else{
    throw std::length_error("Successor does not exist");
  }
}

template<typename Data>
void BST<Data>::RemoveSuccessor(const Data& dat){
  typename BinaryTreeLnk<Data>::NodeLnk** tmp = &FindPointerToSuccessor(root, dat);
  if((*tmp)!=nullptr){
    delete Detach(*tmp);
  }else{
    throw std::length_error("Successor does not exist");
  }
}



//protected
template<typename Data>
Data BST<Data>::DataNDelete(typename BinaryTreeLnk<Data>::NodeLnk* node){
  Data ret = node->val;
  delete node;
  return ret;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::Detach(typename BinaryTreeLnk<Data>::NodeLnk*& pointer) noexcept{
  if(pointer!=nullptr){
    if(pointer->figlioSinistro==nullptr){
      return SkipOnRight(pointer);
    }else if(pointer->figlioDestro==nullptr){
      return SkipOnLeft(pointer);
    }else{
      typename BinaryTreeLnk<Data>::NodeLnk* min = DetachMin(pointer->figlioDestro);
      std::swap(min->val, pointer->val);
      return min;
    }
  }
  return nullptr;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::DetachMin(typename BinaryTreeLnk<Data>::NodeLnk*& pointer) noexcept{
  typename BinaryTreeLnk<Data>::NodeLnk** min = &FindPointerToMin(pointer);
  return SkipOnRight(*min);
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::DetachMax(typename BinaryTreeLnk<Data>::NodeLnk*& pointer) noexcept{
  typename BinaryTreeLnk<Data>::NodeLnk** max = &FindPointerToMax(pointer);
  return SkipOnLeft(*max);
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::SkipOnLeft(typename BinaryTreeLnk<Data>::NodeLnk*& node) noexcept{
  typename BinaryTreeLnk<Data>::NodeLnk* tmp = nullptr;
if(node!=nullptr){
  size--;
  tmp=node->figlioSinistro;
  node->figlioSinistro = nullptr;
  // oppure std::swap(tmp, node->figlioSinistro);
  std::swap(tmp, node);

  }
  return tmp;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::SkipOnRight(typename BinaryTreeLnk<Data>::NodeLnk*& node) noexcept{
  typename BinaryTreeLnk<Data>::NodeLnk* tmp = nullptr;
  if(node!=nullptr){
    size--;
    tmp=node->figlioDestro;
    node->figlioDestro = nullptr;
    // oppure std::swap(tmp, node->figlioDestro);
    std::swap(tmp, node);
  }
  return tmp;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*& BST<Data>::FindPointerToMin(typename BinaryTreeLnk<Data>::NodeLnk*& node) noexcept{
  return const_cast<typename BinaryTreeLnk<Data>::NodeLnk*&>(static_cast<const BST<Data> *> (this)->FindPointerToMin(node));
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(typename BinaryTreeLnk<Data>::NodeLnk* const& node) const noexcept{
  typename BinaryTreeLnk<Data>::NodeLnk* const* pointer = &node;
  typename BinaryTreeLnk<Data>::NodeLnk* curr = node;
  if(curr!=nullptr){
    while(curr->HasLeftChild()){
      pointer = &curr->figlioSinistro;
      curr=curr->figlioSinistro;
    }
  }
  return *pointer;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*& BST<Data>::FindPointerToMax(typename BinaryTreeLnk<Data>::NodeLnk*& node) noexcept{
  return const_cast<typename BinaryTreeLnk<Data>::NodeLnk*&>(static_cast<const BST<Data> *> (this)->FindPointerToMax(node));
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(typename BinaryTreeLnk<Data>::NodeLnk* const& node) const noexcept{
  typename BinaryTreeLnk<Data>::NodeLnk* const* pointer = &node;
  typename BinaryTreeLnk<Data>::NodeLnk* curr = node;
  if(curr!=nullptr){
    while(curr->HasRightChild()){
      pointer=&curr->figlioDestro;
      curr=curr->figlioDestro;
    }
  }
  return *pointer;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*& BST<Data>::FindPointerTo(typename BinaryTreeLnk<Data>::NodeLnk*& node, const Data& dat) noexcept{
  return const_cast<typename BinaryTreeLnk<Data>::NodeLnk*&>(static_cast<const BST<Data> *> (this)->FindPointerTo(node,dat));
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerTo(typename BinaryTreeLnk<Data>::NodeLnk* const& node, const Data& dat) const noexcept{
  typename BinaryTreeLnk<Data>::NodeLnk* const* pointer = &node;
  typename BinaryTreeLnk<Data>::NodeLnk* curr = node;
  if(curr!=nullptr){
      if(curr->val == dat){
        return *pointer;
      }else if(curr->val > dat){
        return FindPointerTo((curr->figlioSinistro), dat);
      }else{
        return FindPointerTo((curr->figlioDestro), dat);
      }
  }else{
    return *pointer;
  }
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*& BST<Data>::FindPointerToPredecessor(typename BinaryTreeLnk<Data>::NodeLnk*& node, const Data& dat) noexcept{
  return const_cast<typename BinaryTreeLnk<Data>::NodeLnk*&>(static_cast<const BST<Data> *> (this)->FindPointerToPredecessor(node,dat));
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToPredecessor(typename BinaryTreeLnk<Data>::NodeLnk* const& node, const Data& dat) const noexcept{
    typename BinaryTreeLnk<Data>::NodeLnk* const* stima = nullptr;
    typename BinaryTreeLnk<Data>::NodeLnk* const* pointer = &node;
    typename BinaryTreeLnk<Data>::NodeLnk* curr = node;
    bool exit = false;

    while(exit==false){
      if(curr->val < dat){
        stima = pointer; //aggiorno la stima
        if(curr->HasRightChild()){
          pointer=&curr->figlioDestro;
          curr=curr->figlioDestro;
          exit=false;
        }else{
          exit=true;
        }
      }else{
        if(curr->val > dat){
        if(curr->HasLeftChild()){
          pointer=&curr->figlioSinistro;
          curr=curr->figlioSinistro;
          exit=false;
        }else{
          exit=true;
        }
      }
      else{
        if(curr->HasLeftChild()){
          exit=true;
          stima = &FindPointerToMax(curr->figlioSinistro);
          curr = FindPointerToMax(curr->figlioSinistro);
        }else{
          exit=true;
        }
      }
    }
    }
    if(stima == nullptr){
      if(curr->HasLeftChild()){
        stima=&curr->figlioDestro;
      }else{
        stima=&curr->figlioSinistro;
      }
    }
    return *stima;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*& BST<Data>::FindPointerToSuccessor(typename BinaryTreeLnk<Data>::NodeLnk*& node, const Data& dat) noexcept{
  return const_cast<typename BinaryTreeLnk<Data>::NodeLnk*&>(static_cast<const BST<Data> *> (this)->FindPointerToSuccessor(node,dat));
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(typename BinaryTreeLnk<Data>::NodeLnk* const& node, const Data& dat) const noexcept{
  typename BinaryTreeLnk<Data>::NodeLnk* const* stima = nullptr;
  typename BinaryTreeLnk<Data>::NodeLnk* const* pointer = &node;
  typename BinaryTreeLnk<Data>::NodeLnk* curr = node;
  bool exit = false;

  while(exit==false){
    if(curr->val > dat){
      stima = pointer; //aggiorno la stima
      if(curr->HasLeftChild()){
        pointer=&curr->figlioSinistro;
        curr=curr->figlioSinistro;
        exit=false;
      }else{
        exit=true;
      }
    }else{
      if(curr->val < dat){
      if(curr->HasRightChild()){
        pointer=&curr->figlioDestro;
        curr=curr->figlioDestro;
        exit=false;
      }else{
        exit=true;
      }
    }
    else{
      if(curr->HasRightChild()){
        exit=true;
        stima = &FindPointerToMin(curr->figlioDestro);
        curr = FindPointerToMin(curr->figlioDestro);
      }else{
        exit=true;
      }
    }
  }
  }
  if(stima == nullptr){
    if(curr->HasRightChild()){
      stima=&curr->figlioSinistro;
    }else{
      stima=&curr->figlioDestro;
    }
  }
  return *stima;
}





/* ************************************************************************** */

}
