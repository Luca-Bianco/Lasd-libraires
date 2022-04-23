
namespace lasd {

/* ************************************************************************** */

// ...

template<typename Data>
QueueLst<Data>::QueueLst(): List<Data>::List(){

}


template<typename Data>
QueueLst<Data>::QueueLst(const LinearContainer<Data>& con): List<Data>::List(con){

}

template<typename Data>
QueueLst<Data>::QueueLst(const QueueLst<Data>& queuelst): List<Data>::List(queuelst){

}

template<typename Data>
QueueLst<Data>::QueueLst(QueueLst<Data>&& queuelst) noexcept{
  std::swap(testa, queuelst.testa);
  std::swap(size, queuelst.size);
  std::swap(tail, queuelst.tail);
}

template<typename Data>
QueueLst<Data>::~QueueLst(){

}

template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& queuelst){
  lasd::List<Data>::operator=(queuelst);
  return *this;
}

template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& queuelst) noexcept{
  lasd::List<Data>::operator=(std::move(queuelst));
  return *this;
}


template<typename Data>
bool QueueLst<Data>::operator==(const QueueLst& queuelst) const noexcept{
  return lasd::List<Data>::operator==(queuelst);
}

template<typename Data>
bool QueueLst<Data>::operator!=(const QueueLst& queuelst) const noexcept{
  return lasd::List<Data>::operator!=(queuelst);
}

template<typename Data>
void QueueLst<Data>::Enqueue(const Data& val){
  lasd::List<Data>::InsertAtBack(val);
}

template<typename Data>
void QueueLst<Data>::Enqueue(Data&& val){
  lasd::List<Data>::InsertAtBack(val);
}

template<typename Data>
Data& QueueLst<Data>::Head(){
  if(size!=0){
    return lasd::List<Data>::Front();
  }else{
    throw std::length_error("Accesso ad una queue vuota");
  }
}

template<typename Data>
void QueueLst<Data>::Dequeue(){
  if(size!=0){
    lasd::List<Data>::RemoveFromFront();
  }else{
    throw std::length_error("Accesso ad una queue vuota");
  }
}

template<typename Data>
Data QueueLst<Data>::HeadNDequeue(){
  if(size!=0){
    return lasd::List<Data>::FrontNRemove();
  }else{
    throw std::length_error("Accesso ad una queue vuota");
  }
}

template<typename Data>
void QueueLst<Data>::Clear(){
  lasd::List<Data>::Clear();
}

/* ************************************************************************** */

}
