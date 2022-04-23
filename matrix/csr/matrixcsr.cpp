
namespace lasd {

/* ************************************************************************** */

// ...
template<typename Data>
MatrixCSR<Data>::MatrixCSR(){
  rowVec[0] = &testa;
}

template<typename Data>
MatrixCSR<Data>::MatrixCSR(unsigned long newRows, unsigned long newColumns){
  testa=nullptr;
  tail=nullptr;
  numColonne = newColumns;
  numRighe = newRows;
  rowVec.Resize(newRows + 1);
  for(unsigned long index=0; index<newRows+1; index++){
    rowVec[index] = &testa;
  }
}

template<typename Data>
MatrixCSR<Data>::MatrixCSR(const MatrixCSR& mtrx): MatrixCSR(mtrx.numRighe, mtrx.numColonne){
  for(unsigned long rowIndex=0; rowIndex<numRighe; rowIndex++){
  Node** pointer = mtrx.rowVec[rowIndex];
  while(pointer!=mtrx.rowVec[rowIndex+1]){
    (*this)(rowIndex, (*pointer)->val.second) = (*pointer)->val.first;
    pointer = &((*pointer)->nextNode);
  }
  }
}

  template<typename Data>
  MatrixCSR<Data>::MatrixCSR(MatrixCSR&& mtrx) noexcept{
    std::swap(testa, mtrx. testa);
    std::swap(tail, mtrx.tail);
    std::swap(size, mtrx.size);
    std::swap(numRighe, mtrx.numRighe);
    std::swap(numColonne, mtrx.numColonne);
    std::swap(rowVec, mtrx.rowVec);
    std::swap(rowVec[0], mtrx.rowVec[0]);
    unsigned long i = 1;
    while(i<numRighe+1 && rowVec[i] == &mtrx.testa){
      rowVec[i] = &testa;
      i++;
    }
    i=1;
    while(i<mtrx.numRighe+1 && mtrx.rowVec[i]==&testa){
      mtrx.rowVec[i]=&mtrx.testa;
      i++;
    }
  }

  template<typename Data>
  bool MatrixCSR<Data>::operator==(const MatrixCSR& mtrx) const noexcept{
    if(numRighe == mtrx.numRighe && numColonne == mtrx.numColonne){
    for(unsigned long rowIndex=0; rowIndex<numRighe; rowIndex++){
      Node** secondPointer=mtrx.rowVec[rowIndex];
      Node** pointerToNextRowOne = rowVec[rowIndex+1];
      Node** pointerToNextRowTwo = mtrx.rowVec[rowIndex+1];
      Node** pointer = rowVec[rowIndex];
      while(pointer!=pointerToNextRowOne && secondPointer!=pointerToNextRowTwo){
        if((*pointer)->val.first != (*secondPointer)->val.first){
          return false;
        }
        pointer= &(*pointer)->nextNode;
        secondPointer= &(*secondPointer)->nextNode;
      }
      if( !(pointer==pointerToNextRowOne && secondPointer == pointerToNextRowTwo)){
        return false;
      }
    }
    return true;
  }else{
   return false;
  }
}

  template<typename Data>
  bool MatrixCSR<Data>::operator!=(const MatrixCSR& mtrx) const noexcept{
    return !(*this == mtrx);
  }

  template<typename Data>
  void MatrixCSR<Data>::RowResize(const unsigned long newRows){
    if(newRows==0){
      List<std::pair<Data, unsigned long>>::Clear();
      rowVec.Resize(1);
      numRighe=newRows;
    }else{
    if(newRows != numRighe){
      if(newRows>numRighe){
        rowVec.Resize(newRows+1);
        for(unsigned long index = numRighe + 1; index <= newRows; index++){
          rowVec[index]=rowVec[index-1];
        }
      }else{
        Node** nodo = rowVec[newRows];
        while((*nodo) != nullptr){
          size--;
          nodo= &((*nodo)->nextNode);
        }
        nodo=rowVec[newRows];
        Node* toDel = *nodo;
        *nodo=nullptr;
        DeleteNodes(toDel);
        rowVec.Resize(newRows+1);
      }
      numRighe = newRows;
    }
  }
  }

  template<typename Data>
  MatrixCSR<Data>& MatrixCSR<Data>::operator=(const MatrixCSR& mtrx){
    MatrixCSR<Data>* tmpMtrx = new MatrixCSR<Data>(mtrx);
    std::swap(*tmpMtrx, *this);
    delete tmpMtrx;
    return *this;
  }

  template<typename Data>
  MatrixCSR<Data>& MatrixCSR<Data>::operator=(MatrixCSR&& mtrx)noexcept{
    std::swap(rowVec, mtrx.rowVec);
    std::swap(testa, mtrx. testa);
    std::swap(tail, mtrx.tail);
    std::swap(rowVec[0], mtrx.rowVec[0]);
    std::swap(size, mtrx.size);
    std::swap(numRighe, mtrx.numRighe);
    std::swap(numColonne, mtrx.numColonne);
    unsigned long i = 1;
    while(i<numRighe+1 && rowVec[i] == &mtrx.testa){
      rowVec[i] = &testa;
      i++;
    }
    i=1;
    while(i<mtrx.numRighe+1 && mtrx.rowVec[i]==&testa){
      mtrx.rowVec[i]=&mtrx.testa;
      i++;
    }
    return *this;
  }

  template<typename Data>
  void MatrixCSR<Data>::ColumnResize(const unsigned long newColumns){
    if(newColumns==0){
      List<std::pair<Data, unsigned long>>::Clear();
      numColonne=newColumns;
    }else{
      if(newColumns<numColonne){
        Node** pointer = &testa;
        unsigned long index = 1;
        while(index < numRighe+1){
          Node* currNode;
          Node** pointerToNextRow = rowVec[index];
          while(pointer != pointerToNextRow && (*pointer)->val.second < newColumns){
            currNode = *pointer;
            pointer = &(currNode->nextNode);
          }
          if(pointer != pointerToNextRow){
            if(pointerToNextRow == rowVec[numRighe]){
              tail=currNode;
            }
            Node* tmp = *pointer;
            *pointer = *pointerToNextRow;
            *pointerToNextRow=nullptr;
            Node* toDel = tmp;
            while(toDel != nullptr){
              size--;
              toDel=toDel->nextNode;
            }
            DeleteNodes(tmp);
          }
          while((index<numRighe+1) && (rowVec[index] == pointerToNextRow)){
            rowVec[index]=pointer; //=pointer or tmp?
            index++;
          }
        }
      }
      numColonne = newColumns;
  }
  }

  template<typename Data>
  bool MatrixCSR<Data>::ExistsCell(unsigned long i, unsigned long j) const noexcept{
    if(i<numRighe && j<numColonne){
      Node** pointer = rowVec[i];
      while(pointer != rowVec[i+1]){
        if((*pointer)->val.second == j){
          return true;
        }else if((*pointer)->val.second > j){
          return false;
        }
        pointer= &((*pointer)->nextNode);
      }
      return false;
    }
    return false;
  }

  template<typename Data>
  Data& MatrixCSR<Data>::operator()(const unsigned long i, const unsigned long j){
    if(i<numRighe && j<numColonne){
      Node** pointer = rowVec[i];
      Node** pointerToNextRow = rowVec[i+1];
      while(pointer != pointerToNextRow && (*pointer)->val.second<=j){
        if((*pointer)->val.second == j){
          return ((*pointer)->val.first);
        }
        pointer= &((*pointer)->nextNode);
      }
      if((*pointer)->val.second > j && pointer!= pointerToNextRow){
        size++;
        Node* tmp = new Node();
        tmp->val.second = j;
        tmp->nextNode = (*pointer);
        *pointer=tmp;
        return tmp->val.first;
      }else{
        size++;
        Node* newNode = new Node();
        newNode->val.second = j;
        newNode->nextNode = (*pointer);
        *pointer=newNode;
        unsigned long index = i+1;
        while(index<numRighe+1 && rowVec[index] == pointerToNextRow){
          rowVec[index] = &(newNode->nextNode);
          index++;
        }
        return newNode->val.first;
      }
    }else{
      throw std::out_of_range("index out of range");
    }
  }

  template<typename Data>
  const Data& MatrixCSR<Data>::operator()(const unsigned long i, const unsigned long j) const{
    if(i<numRighe && j<numColonne){
      Node** pointer = rowVec[i];
      Node** pointerToNextRow = rowVec[i+1];
      while(pointer != pointerToNextRow && (*pointer)->val.second<=j){
        if((*pointer)->val.second == j){
          return ((*pointer)->val.first);
        }
        pointer= &((*pointer)->nextNode);
      }
        throw std::length_error("elemento non presente");
    }else{
      throw std::out_of_range("index out of range");
    }
  }

  template<typename Data>
  void MatrixCSR<Data>::Clear(){
    lasd::List<std::pair<Data, unsigned long>>::Clear();
    rowVec.Resize(1);
    testa=nullptr;
    tail=nullptr;
    numRighe=0;
    numColonne=0;
  }

  template<typename Data>
  void MatrixCSR<Data>::DeleteNodes(Node* node){
    if(node != nullptr){
      DeleteNodes(node->nextNode);
      delete node;
      node=nullptr;
    }
  }

  template<typename Data>
  void MatrixCSR<Data>::MapPreOrder(const MapFunctor fun, void* par){
    List<std::pair<Data, unsigned long>>::MapPreOrder([&fun](std::pair<Data, unsigned long>& datx, void* parx){
      fun(datx.first, parx);}, par);
  }

  template<typename Data>
  void MatrixCSR<Data>::MapPostOrder(const MapFunctor fun, void* par){
    List<std::pair<Data, unsigned long>>::MapPostOrder([&fun](std::pair<Data, unsigned long>& datx, void* parx){
      fun(datx.first, parx);
    }, par);
  }

  template<typename Data>
  void MatrixCSR<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const{
    List<std::pair<Data, unsigned long>>::FoldPreOrder([&fun](const std::pair<Data, unsigned long>& datx, const void* parx, void* accx){
      fun(datx.first, parx, accx);
    }, par, acc);
  }

  template<typename Data>
  void MatrixCSR<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const{
    List<std::pair<Data, unsigned long>>::FoldPostOrder([&fun](const std::pair<Data, unsigned long>& datx, const void* parx, void* accx){
      fun(datx.first, parx, accx);
    }, par, acc);
  }
















/* ************************************************************************** */

}
