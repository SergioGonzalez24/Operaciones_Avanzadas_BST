#include <iostream>
using namespace std;

template <typename T>
class NodoBST{
    T dato;
    NodoBST<T> * izq;
    NodoBST<T> * der;
    NodoBST<T> * padre;

    public:
        //Ejemplos de métodos de instancia 
        //getters y setters
         T getDato(){return this->dato;}
        NodoBST<T> * getIzq(){return this->izq;}
        NodoBST<T> * getDer(){return this->der;}
        NodoBST<T> * getPadre(){return this->padre;}
        //Métodos set
        void setDato(T dato){this->dato=dato;}
        void setIzq(NodoBST<T> * izq){this->izq=izq;}
        void setDer(NodoBST<T> * der){this->der=der;}
        void setPadre(NodoBST<T> * padre){this->padre=padre;}

        //Constructores
        NodoBST(NodoBST<T> * padre, T dato){
            this->izq=nullptr;
            this->der=nullptr;
            this->padre=padre;
            this->dato=dato;
        }
        //Destructor (delete)
        ~NodoBST(){
            cout<<"Destruccion"<<endl;
        }

        //Metodo de clase
        static void recorridoInOrder(NodoBST<T> * actual){
            if(actual){
                recorridoInOrder(actual->getIzq());
                cout<<actual->getDato()<<" ";
                recorridoInOrder(actual->getDer());
            }
        }
        static void recorridoPreOrder(NodoBST<T> * actual){
            if(actual){
                cout<<actual->getDato()<<" ";
                recorridoPreOrder(actual->getIzq());                
                recorridoPreOrder(actual->getDer());
            }
        }
        static NodoBST<T> * valorMenor(NodoBST<T> * actual){
            if(actual)
                while(actual->getIzq())
                    actual=actual->getIzq();                
            return actual;
        }
        static NodoBST<T> * valorMayor(NodoBST<T> * actual){
            if(actual)
                while(actual->getDer())
                    actual=actual->getDer();                
            return actual;
        }


};