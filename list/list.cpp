#include "iostream"
namespace lasd {

/* ************************************************************************** */

// ...

//costruttore base
template<typename Data>
List<Data>::Node::Node(const Data& newValue){
  val = newValue;
  nextNode = nullptr;
}
//Lista<Data>::Node::nomemetodo

//copy constructor
template<typename Data>
List<Data>::Node::Node(const Node& copynode){
  val = copynode.val;
  nextNode = nullptr;
}

//move constructor
template<typename Data>
List<Data>::Node::Node(Node&& movenode) noexcept{
  std::swap(val, movenode.val);
  nextNode = nullptr;
}

//Destructor

//Comparison operators
template<typename Data>
bool List<Data>::Node::operator==(const Node& comp) const noexcept{
  if(val == comp.val){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
bool List<Data>::Node::operator!=(const Node& comp) const noexcept{
  if(val != comp.val){
    return true;
  }else{
    return false;
  }
}
//costruttore di default
template<typename Data>
List<Data>::List(){
  testa=nullptr;
  tail=nullptr;
  size=0;
}
//costruttore con dimensione
template<typename Data>
List<Data>::List(const unsigned long newsize){
  size=newsize;
  if(newsize>0){
    testa = new Node();
    testa->nextNode = costruisciLista(newsize - 1);
    tail=auxRecuperaUltimoNodo();
  }else{
    testa=nullptr;
    tail=nullptr;
  }
}
//operator[]
  template<typename Data>
  Data& List<Data>::operator[](const unsigned long index) const{
    if(index < size){
      return auxAccessToNumber(index, testa);
    }else
    throw std::out_of_range("Access at index" + std::to_string(index) + "; list size " + std::to_string(size) + ".");
  }

template<typename Data>
 typename List<Data>::Node* List<Data>::costruisciLista(unsigned long newsize){
  if(newsize > 0){
    Node* nuovoNodo = new Node();
    nuovoNodo->nextNode = costruisciLista(newsize - 1);
    return nuovoNodo;
  }else{
    return nullptr;
  }
}

template<typename Data>
List<Data>::List(const LinearContainer<Data>& con){
  if(con.Size()>0){
    size=con.Size();
    testa = new Node();
    testa->nextNode = costruisciLista(size - 1);
    tail=auxRecuperaUltimoNodo();
    for(unsigned long index=0; index < size; index++){
        List<Data>::operator[](index) = con[index];
    }
  }else{
    testa=nullptr;
    tail=nullptr;
    size=0;
  }
}
//copy constructor
template <typename Data>
List<Data>::List(const List<Data>& lis){
  if(lis.Size()>0){
    size=lis.Size();
    testa = new Node();
    testa->nextNode = costruisciLista(size - 1);
    auxCopy(testa, lis.testa);
  }else{
    testa=nullptr;
    tail=nullptr;
    size=0;
  }
}

template<typename Data>
  void List<Data>::auxCopy(Node* testa1, const Node* testa2){
    if(testa2 != nullptr){
      testa1->val=testa2->val;
      tail=testa1;
      auxCopy(testa1->nextNode, testa2->nextNode);
    }
  }


  //Move constructor
  template <typename Data>
  List<Data>::List(List<Data>&& lis) noexcept{
      std::swap(testa, lis.testa);
      std::swap(size, lis.size);
      std::swap(tail, lis.tail);
    }

  //Destructor
  template <typename Data>
  List<Data>::~List(){
    Clear();
  }

  //Copy assignment
  template<typename Data>
  List<Data>& List<Data>::operator=(const List<Data>& lis){
    List<Data>* tmplis = new List<Data>(lis);
    std::swap(*tmplis, *this);
    delete tmplis;
    return *this;
  }

  //Move assignment
  template<typename Data>
  List<Data>& List<Data>::operator=(List<Data>&& lis) noexcept{
    std::swap(testa, lis.testa);
    std::swap(size, lis.size);
    std::swap(tail, lis.tail);
    return *this;
  }

  //Comparison operators
  template<typename Data>
  bool List<Data>::operator==(const List<Data>& lis) const noexcept{
    if(size==lis.Size()){
      if(uguaglianzaListe(testa, lis.testa) == true){
        return true;
      }else{
        return false;
      }
    }else{
      return false;
    }
  }

  template<typename Data>
  bool List<Data>::uguaglianzaListe(const Node* testa1, const Node* testa2) const{
    bool ret = true;
    if(testa1 != nullptr){
      if(testa1->val==testa2->val){
        ret = uguaglianzaListe(testa1->nextNode, testa2->nextNode);
      }else{
        ret = false;
      }
    }
    return ret;
  }

  template<typename Data>
  bool List<Data>::operator!=(const List<Data>& lis) const noexcept{
    return !(*this == lis);
  }


// InsertAtFront
template<typename Data>
  void List<Data>::InsertAtFront(const Data& newVal){
    if(size!=0){
      size++;
      Node* nuovoNodo = new Node();
      nuovoNodo->val=newVal;
      nuovoNodo->nextNode = testa;
      testa=nuovoNodo;
    }else{
      size++;
      Node* nuovoNodo = new Node();
      nuovoNodo->val=newVal;
      nuovoNodo->nextNode = testa;
      testa=nuovoNodo;
      tail=nuovoNodo;
    }
  }

template<typename Data>
  void List<Data>::stampaLista(Node* head){
    if(head!=nullptr){
      std::cout<<head->val<<"->";
      stampaLista(head->nextNode);
    }else{
      std::cout<<"nullptr";
    }
  }
template<typename Data>
  void List<Data>::stampaLista(){
  Node* head = new Node();
  head = testa;
    while(head!=nullptr){
      std::cout<<head->val<<"->";
      head=head->nextNode;
    }
    std::cout<<"nullptr";
  }

template<typename Data>
  void List<Data>::InsertAtFront(Data&& newVal){

  if(size!=0){
      size++;
      Node* nuovoNodo = new Node();
      std::swap(nuovoNodo->val, newVal);
      nuovoNodo->nextNode = testa;
      testa=nuovoNodo;
  }else{
    size++;
    Node* nuovoNodo = new Node();
    std::swap(nuovoNodo->val, newVal);
    nuovoNodo->nextNode = testa;
    testa=nuovoNodo;
    tail=nuovoNodo;
    }
  }
//RemoveFromFront
template<typename Data>
  void List<Data>::RemoveFromFront(){
    if(size==1){
     tail=nullptr;
   }
    if(size!=0){
      size--;
      Node* nodotmp = nullptr;
      nodotmp = testa;
      testa=testa->nextNode;
     delete nodotmp;
    }else{
      throw std::length_error("Access to an empty list");
    }
  }
//FrontNRemove
template<typename Data>
  Data List<Data>::FrontNRemove(){
    if(size!=0){
      Data tmp = Front();
      RemoveFromFront();
      return tmp;
    }else{
        throw std::length_error("Access to an empty list");
    }
  }

//InsertAtBack
template<typename Data>
  void List<Data>::InsertAtBack(const Data& newVal){
    if(size!=0){
      Node* nuovoNodo = new Node(newVal);
      nuovoNodo->nextNode = nullptr;
      tail->nextNode = nuovoNodo;
      tail=tail->nextNode;
    }else{
      testa = new Node(newVal);
      tail=testa;
    }
    size++;
  }

  template<typename Data>
    void List<Data>::Tail(){
      if(tail!=nullptr){
      std::cout << "tail value: " <<tail->val;
    }else{
      std::cout << "nullptr";
    }
    }

//auxRecuperaUltimoNodo
template<typename Data>
  typename List<Data>::Node* List<Data>::auxRecuperaUltimoNodo() const{
    if(size!=0){
      Node* ultimoNodo = nullptr;
      ultimoNodo = testa;
      while(ultimoNodo->nextNode != nullptr){
      ultimoNodo=ultimoNodo->nextNode;
      }
      return ultimoNodo;
    }else{
      return testa;
    }

  }

//InsertAtBack
template<typename Data>
  void List<Data>::InsertAtBack(Data&& newVal){
  if(size!=0){
    Node* nuovoNodo = new Node();
    std::swap(nuovoNodo->val, newVal);
    nuovoNodo->nextNode = nullptr;
    tail->nextNode = nuovoNodo;
    tail=tail->nextNode;
  }else{
    testa = new Node();
    std::swap(testa->val, newVal);
    tail=testa;
  }
  size++;
}

template<typename Data>
  void List<Data>::Clear(){
    if(testa!=nullptr){
        while(size!=0){
          RemoveFromFront();
          }
        }
    testa = nullptr;
    tail=nullptr;
    size=0;
  }

//Front
  template<typename Data>
  Data& List<Data>::Front() const{
    if(size!=0){
      return testa->val;
    }else{
      throw std::length_error("Access to an empty List");
    }
  }
//Back
  template<typename Data>
  Data& List<Data>::Back() const{
    if(size!=0){
      return tail->val;
    }else{
      throw std::length_error("Access to an empty List");
    }
  }
//auxAccessToNumber
  template<typename Data>
  Data& List<Data>::auxAccessToNumber(unsigned long index, Node* head) const{
    if(index == 0){
      return head->val;
    }else{
      return auxAccessToNumber(index-1, head->nextNode);
    }
  }
//MapPreOrder
  template<typename Data>
  void List<Data>::MapPreOrder(const MapFunctor fun, void* par){
    auxMapPreOrder(fun, par, testa);
  }
//auxMapPreOrder
template<typename Data>
  void List<Data>::auxMapPreOrder(const MapFunctor fun, void* par, Node* head){
    if(head!=nullptr){
      fun(head->val, par);
      auxMapPreOrder(fun, par, head->nextNode);
    }
  }

  //MapPostOrder
  template<typename Data>
    void List<Data>::MapPostOrder(const MapFunctor fun, void* par){
      unsigned long index = size;
      while(index > 0){
        index--;
        fun(List<Data>::operator[](index), par);
      }
    }

  //FoldPreOrder
  template<typename Data>
  void List<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const{
  if(testa!=nullptr){
    auxFoldPreOrder(fun, par, acc, testa);
    }
  }

  template<typename Data>
  void List<Data>::auxFoldPreOrder(const FoldFunctor fun, const void* par, void* acc, Node* head) const{
    if(head != nullptr){
      fun(head->val, par, acc);
      auxFoldPreOrder(fun, par, acc, head->nextNode);
    }
  }

  template<typename Data>
  void List<Data>::auxFoldPreOrderWithSize(const FoldFunctor fun, const void* par, void* acc, Node* head, const unsigned long tmpSize) const{
    if(tmpSize != 0){
      fun(head->val, par, acc);
      auxFoldPreOrderWithSize(fun, par, acc, head->nextNode, tmpSize-1);
    }
  }

  template<typename Data>
  void List<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const{
    unsigned long index = size;
    while(index > 0){
      index--;
      fun(List<Data>::operator[](index), par, acc);
    }
  }


/* ************************************************************************** */

}
