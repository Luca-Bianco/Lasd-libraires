
namespace lasd {

/* ************************************************************************** */

// ...
//from hereee
template<typename Data>
QueueVec<Data>::QueueVec(): Vector<Data>::Vector(6){
  testa=0;
  tail=0;
}

template<typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& con): Vector<Data>::Vector(con){
  testa=0;
  tail=con.Size();
}

template<typename Data>
QueueVec<Data>::QueueVec(unsigned long val): Vector<Data>::Vector(val){
  testa=0;
  tail=0;
}

template<typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& queuevec): Vector<Data>::Vector(queuevec){
  testa=queuevec.testa;
  tail=queuevec.tail;
}

template<typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& queuevec)noexcept: Vector<Data>::Vector(std::move(queuevec)){
  std::swap(testa, queuevec.testa);
  std::swap(tail, queuevec.tail);
}

template<typename Data>
QueueVec<Data>::~QueueVec(){
  testa=0;
  tail=0;
}

template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& queuevec){
  testa=queuevec.testa;
  tail=queuevec.tail;
  lasd::Vector<Data>::operator=(queuevec);
  return *this;
}

template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& queuevec) noexcept{
  lasd::Vector<Data>::operator=(queuevec);
  std::swap(testa, queuevec.testa);
  std::swap(tail, queuevec.tail);
  return *this;
}

template<typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data>& queuevec) const noexcept{
  unsigned int indexPrimo=testa;
  unsigned int indexSecondo=queuevec.testa;


  if(Size() == queuevec.Size()){

    while(indexPrimo != tail){
      if(lasd::Vector<Data>::operator[](indexPrimo) != queuevec.Elements[indexSecondo]){
        return false;
      }
      if(indexPrimo<size){
        indexPrimo++;
      }else{
        indexPrimo=0;
      }
      if(indexSecondo<queuevec.size){
        indexSecondo++;
      }else{
        indexSecondo=0;
      }
    }
    return true;
  }else{
    return false;
  }

}

template<typename Data>
bool QueueVec<Data>::operator!=(const QueueVec<Data>& queuevec) const noexcept{
  return !(lasd::QueueVec<Data>::operator==(queuevec));
}

template<typename Data>
void QueueVec<Data>::Enqueue(const Data& val){


  if((size-Size()) > 1){
    lasd::Vector<Data>::operator[](tail) = val;
    if(tail<=size-1){
      tail++;
    }else{
      tail=0;
    }
  }else{
    Expand();
    lasd::Vector<Data>::operator[](tail) = val;
    if(tail<size-1){
      tail++;
    }else{
      tail=0;
    }
  }

}

template<typename Data>
void QueueVec<Data>::Enqueue(Data&& val){

  if((size-Size()) > 1){
    std::swap(lasd::Vector<Data>::operator[](tail), val);
    if(tail<size){
      tail++;
    }else{
      tail=0;
    }
  }else{
    Expand();
    std::swap(lasd::Vector<Data>::operator[](tail) , val);
    if(tail<size-1){
      tail++;
    }else{
      tail=0;
    }
  }

}

template<typename Data>
Data& QueueVec<Data>::Head(){
  if(tail!=testa){
    return lasd::Vector<Data>::operator[](testa);
  }else{
    throw std::length_error("Accesso ad una queue vuota");
  }
}

template<typename Data>
void QueueVec<Data>::Dequeue(){
  if(tail!=testa){
    if(testa < size-1){
      testa++;
    }else{
      testa=0;
    }
    if(lasd::QueueVec<Data>::Size() < size/3){
      Reduce();
    }
  }else{
    throw std::length_error("Accesso ad una queue vuota");
  }
}

template<typename Data>
Data QueueVec<Data>::HeadNDequeue(){
  if(tail!=testa){
    Data tmp = lasd::Vector<Data>::operator[](testa);
    if(testa < size){
      testa++;
    }else{
      testa=0;
    }
    if(lasd::QueueVec<Data>::Size() < size/3){
      Reduce();
    }
    return tmp;
  }else{
    throw std::length_error("Accesso ad una queue vuota");
  }
}

template<typename Data>
bool QueueVec<Data>::Empty() const noexcept{
  if(lasd::QueueVec<Data>::Size() == 0){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
unsigned long QueueVec<Data>::Size() const noexcept{
  if(testa<tail){
    return ((tail - testa));
  }else if(tail<testa){
      return (size-(testa - tail));
    }else{
      return 0;
    }
}


template<typename Data>
void QueueVec<Data>::Clear(){
  testa=0;
  tail=0;
}

template<typename Data>
void QueueVec<Data>::Expand(){

  unsigned long oldTesta = testa;
  unsigned long oldTail = tail;
  unsigned long oldSize = size;
  unsigned long index;

  Data tmpvec[size];
  for(index=0; index<size-1; index++){
    tmpvec[index] = Elements[index];
  }

  // Elements = new Data[size*2]{};
  Vector<Data>::Resize(size*2);
  tail=0;
  testa=0;
  size=size*2;


  while(oldTesta != oldTail){
    lasd::Vector<Data>::operator[](tail)=tmpvec[oldTesta];

    if(oldTesta < oldSize){
      oldTesta++;
    }else{
      oldTesta=0;
    }
    tail++;
  }

}


template<typename Data>
void QueueVec<Data>::Reduce(){

  unsigned long oldTesta = testa;
  unsigned long oldTail = tail;
  unsigned long oldSize = size;
  unsigned long index;

  Data tmpvec[size];
  for(index=0; index<size-1; index++){
    tmpvec[index] = Elements[index];
  }

  // Elements = new Data[size + 4]{};//or Size()?
  // Vector<Data>::Resize(size+4);
  Vector<Data>::Clear();
  size=oldSize;
  Elements = new Data[size + 4]{};//or Size()?
  tail=0;
  testa=0;
  size=size+4;

  while(oldTesta != oldTail){
    lasd::Vector<Data>::operator[](tail)=tmpvec[oldTesta];
    if(oldTesta < oldSize){
      oldTesta++;
    }else{
      oldTesta=0;
    }
    tail++;
  }

}


/* ************************************************************************** */

}
