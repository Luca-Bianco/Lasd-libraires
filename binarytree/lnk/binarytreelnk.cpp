
namespace lasd {

/* ************************************************************************** */

// ...
template<typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept{
  return val;
}

template<typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{
  return val;
}

template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& dat){
  val=dat;
}

template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& dat) noexcept{
  std::swap(val,dat);
}

template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk(){
  delete figlioSinistro;
  delete figlioDestro;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& nodo){
  val=nodo.val;
  figlioSinistro=nodo.figlioSinistro;
  figlioDestro=nodo.figlioDestro;
  return *this;
}

template<typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& nodo) noexcept{
  std::swap(val, nodo.val);
  std::swap(figlioSinistro, nodo.figlioSinistro);
  std::swap(figlioDestro, nodo.figlioDestro);
  return *this;
}

template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept{
  if(figlioSinistro != nullptr){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept{
  if(figlioDestro != nullptr){
    return true;
  }else{
    return false;
  }
}

template<typename Data>
typename BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{
  if(HasLeftChild()==true){
    return *figlioSinistro;
  }else{
    throw std::out_of_range("this node hasn't got a LeftChild");
  }
}


template<typename Data>
typename BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
  if(HasRightChild()==true){
    return *figlioDestro;
  }else{
    throw std::out_of_range("this node hasn't got a RightChild");
  }
}

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& con){
  size=con.Size();
  if(size!=0){
    root=new NodeLnk();
    auxBinaryTreeLnk(root, 0, con);
  }
}

template<typename Data>
void BinaryTreeLnk<Data>::auxBinaryTreeLnk(NodeLnk* nodo, unsigned long index, const LinearContainer<Data>& con){
  nodo->val=con[index];

  if(((2*index)+1) < con.Size()){
    nodo->figlioSinistro=new NodeLnk();
    auxBinaryTreeLnk(nodo->figlioSinistro, ((2*index)+1), con);
  }

  if(((2*index)+2) < con.Size()){
    nodo->figlioDestro=new NodeLnk();
    auxBinaryTreeLnk(nodo->figlioDestro, ((2*index)+2), con);
  }
}

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& bt){
  size=bt.size;
  if(size!=0){
    root = new NodeLnk();
    auxBinaryTreeLnkCopyConstructor(root, bt.Root());
  }
}

template<typename Data>
void BinaryTreeLnk<Data>::auxBinaryTreeLnkCopyConstructor(NodeLnk* nuovoNodo, struct BinaryTree<Data>::Node& copyNode){
  nuovoNodo->val=copyNode.val;

  if(copyNode.HasLeftChild()==true){
    nuovoNodo->figlioSinistro= new NodeLnk();
    auxBinaryTreeLnkCopyConstructor(nuovoNodo->figlioSinistro, copyNode.LeftChild());
  }

  if(copyNode.HasRightChild()==true){
    nuovoNodo->figlioDestro = new NodeLnk();
    auxBinaryTreeLnkCopyConstructor(nuovoNodo->figlioDestro, copyNode.RightChild());
  }

}

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& bt) noexcept{
  std::swap(size, bt.size);
  std::swap(root, bt.root);
}


template<typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk(){
  delete root;
  root=nullptr;
  size=0;
}

template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk& bt){
  size=bt.size;
  if(size!=0){
    root = new NodeLnk();
    auxBinaryTreeLnkCopyConstructor(root, bt.Root());
  }
  return *this;
}

template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk&& bt) noexcept{
  std::swap(size, bt.size);
  if(size!=0){
    std::swap(root, bt.root);
  }
  return *this;
}

template<typename Data>
typename BinaryTree<Data>::Node& BinaryTreeLnk<Data>::Root() const{
  if(size != 0){
    return *root;
  }else{
    throw std::length_error("Empty tree");
  }
}

template<typename Data>
void BinaryTreeLnk<Data>::Clear(){
    delete root;
    root=nullptr;
    size=0;
}

/* ************************************************************************** */

}
