#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class NodoBST {
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
        static void recorridoPostOrder(NodoBST<T> * actual){
            if(actual) { 
                recorridoPostOrder(actual->getIzq());
                recorridoPostOrder(actual->getDer());
                cout<<actual->getDato()<<" ";
            }
        }
        static void recorridoLevelByLevel(NodoBST<T> * actual){
            if(actual) {
                queue<NodoBST<T>*> q;
                q.push(actual);
                while(!q.empty()) {
                    NodoBST<T> * actual = q.front();
                    cout<<actual->getDato()<<" ";
                    if(actual->getIzq()!=NULL) {
                        q.push(actual->getIzq());
                    }
                    if(actual->getDer()!=NULL) {
                        q.push(actual->getDer());
                    }
                    q.pop();
                }
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
        static int encontrarAltura(NodoBST<T> * actual){
            if (actual) {
                return max(encontrarAltura(actual->getDer()),encontrarAltura(actual->getIzq()))+1;
            }
            return 0;
            
        }
        static bool antecesor(NodoBST<T> * actual){
             if (actual){

                bool left = antecesor(actual->getIzq());
                // search node in the right subtree
                bool right = false;
                if (!left) {
                    right = antecesor(actual->getDer());
                }
            
                // if the given node is found in either left or right subtree,
                // the current node is an ancestor of a given node
                if (left || right) {
                    cout << actual->getDato() << " ";
                }
            
                // return true if a node is found
                return left || right;
            }
            return false;

        }
        




};