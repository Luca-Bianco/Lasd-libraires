
// ...
#include "./test.hpp"
#include "../zlasdtest/test.hpp"
#include <iostream>
#include <string>
#include "./test.hpp"
#include "../container/container.hpp"
#include "../iterator/iterator.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../bst/bst.hpp"
#include "../matrix/matrix.hpp"
#include "../matrix/csr/matrixcsr.hpp"
#include "../matrix/vec/matrixvec.hpp"


#include <random>
#include<algorithm>
#include <ctime>
#include <unistd.h>

using namespace std;

unsigned int sceltaImplementazione;
unsigned int sceltaTipo;
unsigned int sceltaUtente;
unsigned long numeroRighe;
unsigned long numeroColonne;
bool uscita = false;
bool sceltaDelTipo = false;
bool popolamentoEffettuato = false;

lasd::MatrixCSR<int> csrInt;
lasd::MatrixCSR<float> csrFloat;
lasd::MatrixCSR<string> csrString;

lasd::MatrixVec<int> vecInt;
lasd::MatrixVec<float> vecFloat;
lasd::MatrixVec<string> vecString;


void miotest(){
    cout << endl << "~*~#~*~ Welcome to the LASD Test Suite ~*~#~*~ " << endl;

    uscita = false;
  do{
    cout<<" scegli l'operazione:"<<endl;
    cout<<"0 - test professore"<<endl;
    cout<<"1 - scelta dell'implementazione e del tipo" << endl;
    cout<<"2 - popolamento della struttura con dimensione data in ingresso" << endl;
    cout<<"3 - visualizzazione in pre-ordine di tutti gli elementi"<<endl;
    cout<<"4 - visualizzazione in post-Ordine di tutti gli elementi"<<endl;
    cout<<"5 - controllo di esistenza di un valore"<<endl;
    cout<<"6 - operazioni di manipolazione e lettura di elementi della matrice"<<endl;
    cout<<"7 - prodotto degli interi minori di n, somma per i float maggiori di n, concatenazione di stringhe con lunghezza minore o uguale a n con n dato in ingresso"<<endl;
    cout<<"8 - a tutti gli elementi 2n per gli interi, (-n)^3 per i float, e concatenazione in testa di una specifica stringa data in ingresso dall'utente per le stringhe"<<endl;
    cout<<"9 - esci e chiudi applicazione"<<endl;


    cin>>sceltaUtente;

    switch (sceltaUtente) {
      case 0:
          lasdtest();
          break;
      case 1:
          SceltaB();
          break;
      case 2:
          SceltaC();
          break;
      case 3:
         SceltaD();
          break;
      case 4:
          SceltaE();
          break;
      case 5:
          SceltaF();
          break;
     case 6:
          subMenu();
          break;
      case 7:
      SceltaG();
          break;
      case 8:
      SceltaH();
          break;
      case 9:
          uscita=true;
          break;
    }

  }while(uscita == false);

    cout << endl << "Goodbye!" << endl;
}

void SceltaB(){
  sceltaDelTipo=true;
  popolamentoEffettuato=false;
  cout<<"Scegliere l'implementazione 0(serializzazione vettoriale) 1(Yale Format)"<<endl;
  cin>>sceltaImplementazione;
  cout<<"Scegliere il tipo di dati della struttura 0(interi) 1(float) 2(stringhe) :";
  cin>>sceltaTipo;
}

void SceltaC(){
  if(sceltaDelTipo == true){
  popolamentoEffettuato=true;
  cout<<"Inserire la dimensione della matrice ";
  cout<<"Inserire il numero di righe: ";
  cin>>numeroRighe;
  cout<<"Inserire il numero di colonne: ";
  cin>>numeroColonne;

  switch(sceltaTipo){
    case 0:
            if(sceltaImplementazione == 0){
              PopolamentoCasualeVecInt();
            }else{
              PopolamentoCasualeCsrInt();
            }
            break;
    case 1:
            if(sceltaImplementazione == 0){
              PopolamentoCasualeVecFloat();
            }else{
              PopolamentoCasualeCsrFloat();
            }
            break;
    case 2:
            if(sceltaImplementazione == 0){
              PopolamentoCasualeVecString();
            }else{
              PopolamentoCasualeCsrString();
            }
            break;
  }
}else{
  cout<<"Prima del popolamento bisogna scegliere l'implementazione ed il tipo"<<endl;
}
}

void SceltaD(){
    if(sceltaDelTipo == true && popolamentoEffettuato == true){
      switch(sceltaTipo){
        case 0:
                if(sceltaImplementazione == 0){
                  vecInt.MapPreOrder(&MapPrint<int>, 0);
                }else{
                  csrInt.MapPreOrder(&MapPrint<int>, 0);
                }
                break;
        case 1:
                if(sceltaImplementazione == 0){
                  vecFloat.MapPreOrder(&MapPrint<float>, 0);
                }else{
                  csrFloat.MapPreOrder(&MapPrint<float>, 0);
                }
                break;
        case 2:
                if(sceltaImplementazione == 0){
                  vecString.MapPreOrder(&MapPrint<string>, 0);
                }else{
                  csrString.MapPreOrder(&MapPrint<string>, 0);
                }
                break;
      }
    }else{
        cout<<"Prima del popolamento bisogna scegliere l'implementazione ed il tipo e popolare la matrice"<<endl;
    }
}

void SceltaE(){
    if(sceltaDelTipo == true && popolamentoEffettuato == true){
      switch(sceltaTipo){
        case 0:
                if(sceltaImplementazione == 0){
                  vecInt.MapPostOrder(&MapPrint<int>, 0);
                }else{
                  csrInt.MapPostOrder(&MapPrint<int>, 0);
                }
                break;
        case 1:
                if(sceltaImplementazione == 0){
                  vecFloat.MapPostOrder(&MapPrint<float>, 0);
                }else{
                  csrFloat.MapPostOrder(&MapPrint<float>, 0);
                }
                break;
        case 2:
                if(sceltaImplementazione == 0){
                  vecString.MapPostOrder(&MapPrint<string>, 0);
                }else{
                  csrString.MapPostOrder(&MapPrint<string>, 0);
                }
                break;
      }
    }else{
        cout<<"Prima del popolamento bisogna scegliere l'implementazione ed il tipo e popolare la matrice"<<endl;
    }
}

void SceltaF(){
    if(sceltaDelTipo == true && popolamentoEffettuato == true){
      bool exists=false;
      switch(sceltaTipo){
        case 0:{
                int dat;
                cout<<"Inserisci l'intero da cercare: ";
                cin>>dat;
                if(sceltaImplementazione == 0){
                  vecInt.FoldPreOrder(&AuxFoldExists<int>, &dat, &exists);
                }else{
                  csrInt.FoldPreOrder(&AuxFoldExists<int>, &dat, &exists);
                }
              }
                break;
        case 1:{
                float dat;
                cout<<"Inserisci il float da cercare: ";
                cin>>dat;
                if(sceltaImplementazione == 0){
                  vecFloat.FoldPreOrder(&AuxFoldExists<float>, &dat, &exists);
                }else{
                  csrFloat.FoldPreOrder(&AuxFoldExists<float>, &dat, &exists);
                }
              }
                break;
        case 2:{
                string dat;
                cout<<"Inserisci la stringa da cercare: ";
                cin>>dat;
                if(sceltaImplementazione == 0){
                  vecString.FoldPreOrder(&AuxFoldExists<string>, &dat, &exists);
                }else{
                  csrString.FoldPreOrder(&AuxFoldExists<string>, &dat, &exists);
                }
              }
                break;
      }
      if(exists==true){
        cout<<"l'elemento esiste";
      }else{
        cout<<"l'elemento non esiste";
      }
    }else{
        cout<<"Prima del popolamento bisogna scegliere l'implementazione ed il tipo e popolare la matrice"<<endl;
    }
}


void SceltaG(){
if(sceltaDelTipo == true && popolamentoEffettuato == true){
  int n;
  cout<<"Inserisci n: ";
  cin>>n;
  cout<<endl;
  switch(sceltaTipo){
    case 0: {
              int acc=1;
              if(sceltaImplementazione == 0){
                vecInt.FoldPreOrder(ProdottoInteri, &n, &acc);
              }else{
                csrInt.FoldPreOrder(ProdottoInteri, &n, &acc);
              }
              cout<<"il risultato e' " <<acc;
              break;
            }
    case 1: {
              float acc=0;
              if(sceltaImplementazione == 0){
                vecFloat.FoldPreOrder(SommaFloat, &n, &acc);
              }else{
                csrFloat.FoldPreOrder(SommaFloat, &n, &acc);
              }
              cout<<"il risultato e' " <<acc;
              break;
            }
    case 2: {
              string acc = "";
              if(sceltaImplementazione == 0){
                vecString.FoldPreOrder(FoldConcatenazioneStringhe, &n, &acc);
              }else{
                csrString.FoldPreOrder(FoldConcatenazioneStringhe, &n, &acc);
              }
              cout<<"il risultato e' " <<acc;
              break;
             }
  }
}else{
cout<<"Scegliere prima il tipo di dato e popolare l'albero"<<endl;
}
}

void subMenu(){
  bool exit = false;
  int choice;

    if(sceltaDelTipo == true && popolamentoEffettuato==true){

      exit=false;
      do{

      cout<<"0 - Inserimento di un dato valore in una cella"<<endl;
      cout<<"1 - Lettura dell'elemento di una cella"<<endl;
      cout<<"2 - Verifica dell'esistenza di una cella"<<endl;
      cout<<"3 - Ridimensionamento delle righe"<<endl;
      cout<<"4 - Ridimensionamento delle colonne"<<endl;
      cout<<"5 - Esci dal subMenu"<<endl;

      cin>>choice;

      switch(choice){
        case 0:
                SceltaK();
                break;
        case 1:
                SceltaJ();
                break;
        case 2:
                SceltaL();
                 break;
        case 3:
                SceltaM();
                break;
        case 4:
                SceltaN();
                break;
        case 5:
                exit=true;
                break;
      }
    }while(exit==false);

    }else{
      cout<<"Prima del popolamento bisogna scegliere l'implementazione ed il tipo"<<endl;
    }
}

void SceltaH(){
  if(sceltaDelTipo == true && popolamentoEffettuato == true){
    switch(sceltaTipo){
      case 0: if(sceltaImplementazione == 0){
                vecInt.MapPreOrder(&raddoppiaInteri, 0); cout<<endl;
              }else{
                csrInt.MapPreOrder(&raddoppiaInteri, 0); cout<<endl;
              }
              break;
      case 1: if(sceltaImplementazione == 0){
                vecFloat.MapPreOrder(&cuboFloat, 0); cout<<endl;
              }else{
                csrFloat.MapPreOrder(&cuboFloat, 0); cout<<endl;
              }
              break;
      case 2: if(sceltaImplementazione == 0){
                string concat;
                cout<<"inserisci la stringa da concatenare"<<endl;
                cin>>concat;
                 vecString.MapPreOrder(&concatenazioneStringhe, &concat);cout<<endl;
               }else{
                 string concat;
                 cout<<"inserisci la stringa da concatenare"<<endl;
                 cin>>concat;
                 csrString.MapPreOrder(&concatenazioneStringhe, &concat);cout<<endl;
               }
               break;
      }
}else{
cout<<"Scegliere prima il tipo di dato e popolare l'albero"<<endl;
}
}

void SceltaJ(){
  unsigned long i;
  unsigned long j;
  cout<<"Inserisci l'indice della riga: ";
  cin>>i;
  cout<<"Inserisci l'indice della colonna: ";
  cin>>j;
  if(sceltaDelTipo == true && popolamentoEffettuato == true){
    switch(sceltaTipo){
      case 0:{

              if(sceltaImplementazione == 0){
                stampaCella(vecInt,i,j);
              }else{
                stampaCella(csrInt,i,j);
              }
            }
              break;
      case 1:{

              if(sceltaImplementazione == 0){
                stampaCella(vecFloat,i,j);
              }else{
                stampaCella(csrFloat,i,j);
              }
            }
              break;
      case 2:{

              if(sceltaImplementazione == 0){
                stampaCella(vecString,i,j);
              }else{
                stampaCella(csrString,i,j);
              }
            }
              break;
    }
cout<<endl;
  }else{
      cout<<"Prima del popolamento bisogna scegliere l'implementazione ed il tipo e popolare la matrice"<<endl;
  }
}

void SceltaL(){
  unsigned long i;
  unsigned long j;
  cout<<"Inserisci l'indice della riga: ";
  cin>>i;
  cout<<"Inserisci l'indice della colonna: ";
  cin>>j;
  if(sceltaDelTipo == true && popolamentoEffettuato == true){
    bool exists = false;
    switch(sceltaTipo){
      case 0:{

              if(sceltaImplementazione == 0){
                exists = vecInt.ExistsCell(i,j);
              }else{
                exists = csrInt.ExistsCell(i,j);
              }
            }
              break;
      case 1:{

              if(sceltaImplementazione == 0){
                exists = vecFloat.ExistsCell(i,j);
              }else{
                exists = csrFloat.ExistsCell(i,j);
              }
            }
              break;
      case 2:{

              if(sceltaImplementazione == 0){
                exists = vecString.ExistsCell(i,j);
              }else{
                exists = csrString.ExistsCell(i,j);
              }
            }
              break;
    }
    if(exists == true){
      cout<<"la cella esiste";
    }else{
      cout<<"la cella non esiste";
    }
    cout<<endl;
  }else{
      cout<<"Prima del popolamento bisogna scegliere l'implementazione ed il tipo e popolare la matrice"<<endl;
  }
}

void SceltaK(){
  unsigned long i;
  unsigned long j;
  cout<<"Inserisci l'indice della riga: ";
  cin>>i;
  cout<<"Inserisci l'indice della colonna: ";
  cin>>j;
  if(sceltaDelTipo == true && popolamentoEffettuato == true){
    switch(sceltaTipo){
      case 0:{
              int dat;
              cout<<"Inserisci l'intero da inserire: ";
              cin>>dat;
              if(sceltaImplementazione == 0){
                vecInt(i,j)=dat;
              }else{
                csrInt(i,j) = dat;
              }
            }
              break;
      case 1:{
              float dat;
              cout<<"Inserisci il float da inserire: ";
              cin>>dat;
              if(sceltaImplementazione == 0){
                vecFloat(i,j) = dat;
              }else{
                csrFloat(i,j) = dat;
              }
            }
              break;
      case 2:{
              string dat;
              cout<<"Inserisci la stringa da inserire: ";
              cin>>dat;
              if(sceltaImplementazione == 0){
                vecString(i,j) = dat;
              }else{
                csrString(i,j) = dat;
              }
            }
              break;
    }
cout<<endl;
  }else{
      cout<<"Prima del popolamento bisogna scegliere l'implementazione ed il tipo e popolare la matrice"<<endl;
  }
}

void SceltaM(){
  unsigned long newRows;
  cout<<"Inserisci il numero di righe: ";
  cin>>newRows;

  if(sceltaDelTipo == true && popolamentoEffettuato == true){
    switch(sceltaTipo){
      case 0:{

              if(sceltaImplementazione == 0){
                vecInt.RowResize(newRows);
              }else{
                csrInt.RowResize(newRows);
              }
            }
              break;
      case 1:{

              if(sceltaImplementazione == 0){
                vecFloat.RowResize(newRows);
              }else{
                csrFloat.RowResize(newRows);
              }
            }
              break;
      case 2:{

              if(sceltaImplementazione == 0){
                vecString.RowResize(newRows);
              }else{
                csrString.RowResize(newRows);
              }
            }
              break;
    }
    cout<<endl;
  }else{
      cout<<"Prima del popolamento bisogna scegliere l'implementazione ed il tipo e popolare la matrice"<<endl;
  }
}

void SceltaN(){
  unsigned long newColumns;
  cout<<"Inserisci il numero di colonne: ";
  cin>>newColumns;

  if(sceltaDelTipo == true && popolamentoEffettuato == true){
    switch(sceltaTipo){
      case 0:{

              if(sceltaImplementazione == 0){
                vecInt.ColumnResize(newColumns);
              }else{
                csrInt.ColumnResize(newColumns);
              }
            }
              break;
      case 1:{

              if(sceltaImplementazione == 0){
                vecFloat.ColumnResize(newColumns);
              }else{
                csrFloat.ColumnResize(newColumns);
              }
            }
              break;
      case 2:{

              if(sceltaImplementazione == 0){
                vecString.ColumnResize(newColumns);
              }else{
                csrString.ColumnResize(newColumns);
              }
            }
              break;
    }
    cout<<endl;
  }else{
      cout<<"Prima del popolamento bisogna scegliere l'implementazione ed il tipo e popolare la matrice"<<endl;
  }
}




void PopolamentoCasualeVecInt(){
  vecInt = lasd::MatrixVec<int>(numeroRighe, numeroColonne);
  default_random_engine gen(random_device{}());
  unsigned int num = 0;
  uniform_int_distribution<int> distRighe(0,numeroRighe-1);
  uniform_int_distribution<int> distColonne(0,numeroColonne-1);
  uniform_int_distribution<int> distTwo(-100,100);

  cout<<"Inserisci il numero di elementi da inserire casualmente ";
  cin>>num;
  while(num > numeroRighe*numeroColonne){
    cout<<"il valore inserito non e' valido, inserire un valore minore: ";
    cin>>num;
  }

  unsigned int index;
  for(index=0; index < num; index++){
    int i = distRighe(gen);
    int j = distColonne(gen);
    vecInt(i,j)=distTwo(gen);
  }
}

void PopolamentoCasualeCsrInt(){
  csrInt.Clear();
  csrInt.RowResize(numeroRighe+1);
  csrInt.ColumnResize(numeroColonne+1);

  default_random_engine gen(random_device{}());
  unsigned int num = 0;
  uniform_int_distribution<int> distRighe(0,numeroRighe-1);
  uniform_int_distribution<int> distColonne(0,numeroColonne-1);
  uniform_int_distribution<int> distTwo(-100,100);

  cout<<"Inserisci il numero di elementi da inserire casualmente ";
  cin>>num;
  while(num > numeroRighe*numeroColonne){
    cout<<"il valore inserito non e' valido, inserire un valore minore: ";
    cin>>num;
  }
  unsigned int index;
  for(index=0; index < num; index++){
    int i = distRighe(gen);
    int j = distColonne(gen);
    while(csrInt.ExistsCell(i,j)){
      i = distRighe(gen);
      j = distColonne(gen);
    }
    csrInt(i,j)=distTwo(gen);
  }
}

void PopolamentoCasualeVecFloat(){
  vecFloat = lasd::MatrixVec<float>(numeroRighe, numeroColonne);
  default_random_engine gen(random_device{}());
  unsigned int num = 0;
  uniform_int_distribution<int> distRighe(0,numeroRighe-1);
  uniform_int_distribution<int> distColonne(0,numeroColonne-1);
  uniform_real_distribution<float> distTwo(-100.0,100.0);

  cout<<"Inserisci il numero di elementi da inserire casualmente ";
  cin>>num;
  while(num > numeroRighe*numeroColonne){
    cout<<"il valore inserito non e' valido, inserire un valore minore: ";
    cin>>num;
  }

  unsigned int index;
  for(index=0; index < num; index++){
    int i = distRighe(gen);
    int j = distColonne(gen);
    vecFloat(i,j)=distTwo(gen);
  }
}

void PopolamentoCasualeCsrFloat(){
  csrFloat.Clear();
  csrFloat.RowResize(numeroRighe+1);
  csrFloat.ColumnResize(numeroColonne+1);
  default_random_engine gen(random_device{}());
  unsigned int num = 0;
  uniform_int_distribution<int> distRighe(0,numeroRighe-1);
  uniform_int_distribution<int> distColonne(0,numeroColonne-1);
  uniform_real_distribution<float> distTwo(-100.0,100.0);

  cout<<"Inserisci il numero di elementi da inserire casualmente ";
  cin>>num;
  while(num > numeroRighe*numeroColonne){
    cout<<"il valore inserito non e' valido, inserire un valore minore: ";
    cin>>num;
  }

  unsigned int index;
  for(index=0; index < num; index++){
    int i = distRighe(gen);
    int j = distColonne(gen);
    while(csrFloat.ExistsCell(i,j)){
      i = distRighe(gen);
      j = distColonne(gen);
    }
    csrFloat(i,j)=distTwo(gen);
  }
}

void PopolamentoCasualeVecString(){
  vecString = lasd::MatrixVec<string>(numeroRighe, numeroColonne);
  unsigned int i=0;
  unsigned int j=0;
  default_random_engine gen(random_device{}());
  unsigned int num = 0;
  uniform_int_distribution<int> distRighe(0,numeroRighe-1);
  uniform_int_distribution<int> distColonne(0,numeroColonne-1);

  cout<<"Inserisci il numero di elementi da inserire casualmente ";
  cin>>num;
  while(num > numeroRighe*numeroColonne){
    cout<<"il valore inserito non e' valido, inserire un valore minore: ";
    cin>>num;
  }

  unsigned int index;
  for(index=0; index < num; index++){
    i = distRighe(gen);
    j = distColonne(gen);
    vecString(i,j)=randomStringGenerator();
  }
}

void PopolamentoCasualeCsrString(){
  csrString.Clear();
  csrString.RowResize(numeroRighe+1);
  csrString.ColumnResize(numeroColonne+1);
  default_random_engine gen(random_device{}());
  unsigned int num = 0;
  uniform_int_distribution<int> distRighe(0,numeroRighe-1);
  uniform_int_distribution<int> distColonne(0,numeroColonne-1);

  cout<<"Inserisci il numero di elementi da inserire casualmente ";
  cin>>num;
  while(num > numeroRighe*numeroColonne){
    cout<<"il valore inserito non e' valido, inserire un valore minore: ";
    cin>>num;
  }

  unsigned int index;
  for(index=0; index < num; index++){
    int i = distRighe(gen);
    int j = distColonne(gen);
    while(csrString.ExistsCell(i,j)){
      i = distRighe(gen);
      j = distColonne(gen);
    }
    csrString(i,j)=randomStringGenerator();
  }
}

std::string randomStringGenerator(){
    default_random_engine random(random_device{}());
    uniform_int_distribution<char> distribuzioneChar('0', 'z');
    string tmp_s = "";
    const unsigned int len = 6;
    for (unsigned int i = 0; i < len; i++)
    tmp_s += distribuzioneChar(random);

    return tmp_s;
}

template<typename Data>
void stampaCella(const lasd::Matrix<Data>& mtrx, unsigned long i, unsigned long j){
  cout<<mtrx(i,j)<<endl;
}

template <typename Data>
void MapPrint(const Data& dat, void* _) {
  std::cout << dat << " ";
}

template<typename Data>
void AuxFoldExists(const Data& dat, const void* val, void* exists){
  if(dat == *((Data*) val)){
    *((bool*) exists) = true;
  }
}

void ProdottoInteri(const int& dat, const void* n, void* acc) {
  if ((dat < (*((int*) n))) && (dat!=0)){
  *((int*) acc) *= dat;
  }
}

void SommaFloat(const float& dat, const void* n, void* acc) {
  if(dat > *((int*)n)){
  *((float*) acc) += dat;
  }
}
void FoldConcatenazioneStringhe(const std::string& dat, const void* n, void* acc) {
  if(dat.length() <= *((int*)n)){
  ((std::string*) acc)->append(dat);
  }
}

void raddoppiaInteri(int& val, void* _){
  val=2*val;
}
void cuboFloat(float& val, void* _){
  val=(-val)*(-val)*(-val);
}
void concatenazioneStringhe(string& val, void* conc){
  val.append(*(std::string*) conc);
}
