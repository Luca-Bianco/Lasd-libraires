
namespace lasd {

/* ************************************************************************** */

// ...
template<typename Data>
MatrixVec<Data>::MatrixVec(){
  vec = Vector<Data>(0);
  numRighe=0;
  numColonne=0;
}

template<typename Data>
MatrixVec<Data>::MatrixVec(const unsigned long rows, const unsigned long columns){
  vec = Vector<Data>(rows*columns);
  numRighe=rows;
  numColonne=columns;
}

template<typename Data>
MatrixVec<Data>::MatrixVec(const MatrixVec& mtrx){
  vec = Vector<Data>(mtrx.vec);
  numRighe = mtrx.numRighe;
  numColonne = mtrx.numColonne;
}

template<typename Data>
MatrixVec<Data>::MatrixVec(MatrixVec&& mtrx) noexcept{
  std::swap(vec, mtrx.vec);
  std::swap(numRighe, mtrx.numRighe);
  std::swap(numColonne, mtrx.numColonne);
}

template<typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(const MatrixVec& mtrx){
  MatrixVec<Data>* tmpMtrx = new MatrixVec<Data>(mtrx);
  std::swap(tmpMtrx->vec, vec);
  std::swap(tmpMtrx->numRighe, numRighe);
  std::swap(tmpMtrx->numColonne, numColonne);
  delete tmpMtrx;
  return *this;
}

template<typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(MatrixVec&& mtrx) noexcept{
  std::swap(mtrx.vec, vec);
  std::swap(mtrx.numRighe, numRighe);
  std::swap(mtrx.numColonne, numColonne);
  return *this;
}

template<typename Data>
bool MatrixVec<Data>::operator==(const MatrixVec& mtrx) const noexcept{
  return vec==mtrx.vec;
}

template<typename Data>
bool MatrixVec<Data>::operator!=(const MatrixVec& mtrx) const noexcept{
  return !(*this==mtrx);
}

template<typename Data>
void MatrixVec<Data>::RowResize(const unsigned long newRows){
  if(newRows!=numRighe){
    vec.Resize(newRows*numColonne);
    numRighe=newRows;
  }
}

template<typename Data>
void MatrixVec<Data>::ColumnResize(const unsigned long newColumns){
  if(newColumns != numColonne){
    if(newColumns>numColonne){
      lasd::Vector<Data> tmpMtrx = Vector<Data>(numRighe*newColumns);
      unsigned long j=0;
      unsigned long i=0;
      if(numColonne!=0){
      while(i < (numRighe * numColonne)){
        unsigned long cont=0;
        while(cont<numColonne){
          tmpMtrx[j]=vec[i];
          i++;
          j++;
          cont++;
        }
        unsigned long sec=0;
        while(sec<(newColumns - numColonne)){
          j++;
          sec++;
        }
      }
    }
      std::swap(vec, tmpMtrx);
    }else{
      if(newColumns<numColonne){
      lasd::Vector<Data> tmpMtrx = Vector<Data>(numRighe*newColumns);
      unsigned long j=0;
      unsigned long i=0;
      if(newColumns!=0){
      while(j< (numRighe*numColonne)){
        unsigned long cont=0;
        while(cont<newColumns){
          tmpMtrx[i] = vec[j];
          j++;
          i++;
          cont++;
        }
        unsigned long sec=0;
        while(sec<(numColonne - newColumns)){
          j++;
          sec++;
        }
      }
    }
      std::swap(vec, tmpMtrx);
    }else{
      vec.Clear();
    }
  }
    numColonne=newColumns;
  }
}

template<typename Data>
bool MatrixVec<Data>::ExistsCell(const unsigned long i, const unsigned long j) const noexcept{
  return(i<numRighe && j<numColonne);
}

template<typename Data>
Data& MatrixVec<Data>::operator()(const unsigned long i, const unsigned long j) {
  return const_cast<Data&>(static_cast<const MatrixVec<Data>*> (this)->operator()(i,j));
}

template<typename Data>
const Data& MatrixVec<Data>::operator()(const unsigned long i, const unsigned long j) const{
  if(i<numRighe && j<numColonne){
    return vec[(i * numColonne) + j];
  }else{
    throw std::out_of_range("index out of range");
  }
}

template<typename Data>
void MatrixVec<Data>::Clear(){
  vec.Clear();
  numRighe=0;
  numColonne=0;
}

template<typename Data>
void MatrixVec<Data>::MapPreOrder(const MapFunctor fun, void* par){
  vec.MapPreOrder(fun, par);
}

template<typename Data>
void MatrixVec<Data>::MapPostOrder(const MapFunctor fun, void* par){
  vec.MapPostOrder(fun, par);
}

template<typename Data>
void MatrixVec<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const{
  vec.FoldPreOrder(fun, par, acc);
}

template<typename Data>
void MatrixVec<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const{
  vec.FoldPostOrder(fun, par, acc);
}

/* ************************************************************************** */

}
