
namespace lasd {

/* ************************************************************************** */

// ...


template<typename Data>
StackVec<Data>::StackVec(): Vector<Data>::Vector(6){
  ultimoElemento=0;
}

template<typename Data>
StackVec<Data>::StackVec(unsigned long val): Vector<Data>::Vector(val){
  ultimoElemento=0;
}

template<typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data>& con): Vector<Data>::Vector(con){
  ultimoElemento = con.Size();
}

template<typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stkvec): Vector<Data>::Vector(stkvec){
  ultimoElemento = stkvec.ultimoElemento;
}

template<typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stkvec) noexcept: Vector<Data>::Vector(std::move(stkvec)){
  std::swap(ultimoElemento, stkvec.ultimoElemento);
}

template<typename Data>
StackVec<Data>::~StackVec(){
  ultimoElemento = 0;
}

template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stkvec){
  ultimoElemento = stkvec.ultimoElemento;
  lasd::Vector<Data>::operator=(stkvec);
  return *this;
}

template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stkvec) noexcept{
  std::swap(ultimoElemento, stkvec.ultimoElemento);
  lasd::Vector<Data>::operator=(stkvec);
  return *this;
}

template<typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& stkvec) const noexcept{
  if(ultimoElemento == stkvec.ultimoElemento){
    for(unsigned int index = 0; index < ultimoElemento; index++){
      if(lasd::Vector<Data>::operator[](index) != stkvec.Elements[index]){
        return false;
      }
    }
    return true;
  }else{
    return false;
  }
}

template<typename Data>
bool StackVec<Data>::operator!=(const StackVec<Data>& stkvec) const noexcept{
  if(ultimoElemento == stkvec.ultimoElemento){
    for(unsigned int index = 0; index < ultimoElemento; index++){
      if(lasd::Vector<Data>::operator[](index) == stkvec.Elements[index]){
        return false;
      }
    }
    return true;
  }else{
    return true;
  }
}

template<typename Data>
void StackVec<Data>::Push(const Data& val){
  if(ultimoElemento < size - 1){
    lasd::Vector<Data>::operator[](ultimoElemento) = val;
    ultimoElemento++;
  }else{
    Expand();
    lasd::Vector<Data>::operator[](ultimoElemento) = val;
    ultimoElemento++;
  }

}

template<typename Data>
void StackVec<Data>::Push(Data&& val){
  if(ultimoElemento < size - 1){
    std::swap(lasd::Vector<Data>::operator[](ultimoElemento), val);
    ultimoElemento++;
  }else{
    Expand();
    std::swap(lasd::Vector<Data>::operator[](ultimoElemento), val);
    ultimoElemento++;
  }
}

template<typename Data>
Data& StackVec<Data>::Top(){
  if(ultimoElemento != 0){
    return lasd::Vector<Data>::operator[](ultimoElemento-1);
  }else{
    throw std::length_error("Accesso ad uno stack vuoto");
  }
}

template<typename Data>
void StackVec<Data>::Pop(){
  if(ultimoElemento != 0){
    ultimoElemento--;
    if(ultimoElemento < (size/3)){
      Reduce();
    }
  }else{
    throw std::length_error("Accesso ad uno stack vuoto");
  }
}

template<typename Data>
Data StackVec<Data>::TopNPop(){
  Data tmp = lasd::Vector<Data>::operator[](ultimoElemento-1);
  if(ultimoElemento != 0){
    ultimoElemento--;
    if(ultimoElemento < (size/3)){
      Reduce();
    }
    return tmp;
  }else{
    throw std::length_error("Accesso ad uno stack vuoto");
  }
}


template<typename Data>
bool StackVec<Data>::Empty() const noexcept{
  if(ultimoElemento == 0){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
unsigned long StackVec<Data>::Size() const noexcept{
  return ultimoElemento;
}

template<typename Data>
void StackVec<Data>::Clear(){
  ultimoElemento = 0;
}


template<typename Data>
void StackVec<Data>::Expand(){

  unsigned long index;
  Data tmpvec[size];

  for(index=0; index<size-1; index++){
    tmpvec[index] = Elements[index];
  }

  // Elements = new Data[size*2]{};
  Vector<Data>::Resize(2*size);

  size=size*2;
  for(index=0; index<ultimoElemento; index++){
    lasd::Vector<Data>::operator[](index) = tmpvec[index];
  }
}

template<typename Data>
void StackVec<Data>::Reduce(){

  unsigned long index;
  unsigned long oldSize = size;

  Data tmpvec[size];
  for(index=0; index<size-1; index++){
    tmpvec[index] = Elements[index];
  }

  Vector<Data>::Clear();
  size=oldSize;

  Elements = new Data[ultimoElemento+4]{};
  size=ultimoElemento+4;

  for(index=0; index<ultimoElemento; index++){
    lasd::Vector<Data>::operator[](index) = tmpvec[index];
  }

}

/* ************************************************************************** */

}
