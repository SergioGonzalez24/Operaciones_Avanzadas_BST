#include "NodoBST.hpp"

template <typename T>
class BST{
    NodoBST<T> * raiz;
    int numNodos;
    public:
        //getters y setters
        NodoBST<T> * getRaiz(){return this->raiz;}
        void setRaiz(NodoBST<T> * raiz){this->raiz=raiz;}
        int getNumNodos(){return this->numNodos;}
        void setNumNodos(int numNodos){this->numNodos=numNodos;} 
        //constructor
        BST(){
            this->raiz=nullptr;
            this->numNodos=0;
        }
        ~BST(){

        }

        void agregarNodo(T dato){
            NodoBST<T> * actual= this->raiz;
            NodoBST<T> * padre;
            if(this->raiz){//Arbol no vacio
                if(this->buscarNodo(dato)) //Nodo encontrado
                    cout<<"Nodo existente"<<endl;                
                else{ //Nodo inexistente, 
                    //Encontrar al nodo padre
                    while(actual){
                        padre=actual;
                        //Relacion de orden de los nodos
                        if(dato<actual->getDato())
                            actual=actual->getIzq();
                        else
                            actual=actual->getDer();
                    }
                    //Colocar el nuevo nodo
                    padre->getDato()>dato?padre->setIzq(new NodoBST<T>(padre,dato)):padre->setDer(new NodoBST<T>(padre,dato));
                    this->numNodos++;
                }
            }else{//Arbol vacio
                this->raiz = new NodoBST<T>(nullptr,dato);
                this->numNodos++;
            }
            return; //opcional
        }

        NodoBST<T> * buscarNodo(T dato){
            //Primer paso crear el apuntador a nodo raiz
            NodoBST<T> * actual = this->raiz;
            while(actual){
                //Si el nodo actual es el valor que busco
                if(actual->getDato()==dato)
                    return actual;
                else//cond?opc_verdadera:opc_falsa
                    actual=actual->getDato()>dato?actual->getIzq():actual->getDer();
            }
            return nullptr; //return actual;
        }

        void imprimirPreOrder(){
            cout<<"Pre Order: ";
            NodoBST<T>::recorridoPreOrder(this->raiz);
            cout<<endl;
        }

        void imprimirPostOrder(){
            cout<<"Post Order: ";
            NodoBST<T>::recorridoPostOrder(this->raiz);
            cout<<endl;
        }

        void imprimirInOrder(){
            cout<<"In Order: ";
            NodoBST<T>::recorridoInOrder(this->raiz);
            cout<<endl;
        }
        
        void imprimirLevelByLevel(){
            cout<<"Level By Level: ";
            NodoBST<T>::recorridoLevelByLevel(this->raiz);
            cout<<endl;
        }

        void visit(int seleccion) {
            if (seleccion==1) {
                imprimirPreOrder();
            }
            else if (seleccion==2) {
                imprimirPostOrder();
            }
            else if (seleccion==3) {
                imprimirLevelByLevel();
            }else {
                cout<<"VALOR NO VALIDO"<<endl;

            }
        }

        void eliminarNodo(T dato){
            NodoBST<T> * eliminar = this->buscarNodo(dato);
            NodoBST<T> * padre = nullptr;
            if(eliminar){ //El nodo que quiero eliminar existe
                //Establezco el nodo padre
                padre=eliminar->getPadre();
                //Caso 1: eliminar nodo hoja
                if(!eliminar->getIzq()&&!eliminar->getDer()){
                    //Actualizar la referencia del padre
                    if(!padre) //this->numNodos==1 si es nodo raiz
                        this->raiz=nullptr;
                    else if(padre->getDato()>eliminar->getDato()) //Nodo hoja es hijo izq
                        padre->setIzq(nullptr);
                    else //Nodo hoja es hijo derecho
                        padre->setDer(nullptr);
                    delete eliminar;
                //Caso2: nodo con un hijo    
                }else if(eliminar->getIzq()&&!eliminar->getDer()){//Caso 2.1 eliminar un nodo con un hijo izq
                    //Actualizar los apuntadores
                    if(!padre)//Nodo raiz con hijo izq
                        this->raiz=eliminar->getIzq();                        
                    else if(padre->getDato()>eliminar->getDato())//Dato a eliminar es izq
                        padre->setIzq(eliminar->getIzq()); //izq izq                       
                    else
                        padre->setDer(eliminar->getIzq());//der izq
                    eliminar->getIzq()->setPadre(padre);
                    delete eliminar;
                }else if(!eliminar->getIzq()&&eliminar->getDer()){//Caso 2.2 eliminar un nodo con un hijo der
                    //Actualizar los apuntadores
                    if(!padre)//Nodo raiz con hijo der
                        this->raiz=eliminar->getDer();                        
                    else if(padre->getDato()>eliminar->getDato())//Dato a eliminar es izq
                        padre->setIzq(eliminar->getDer()); //izq der                        
                    else
                        padre->setDer(eliminar->getDer());//der der
                    eliminar->getDer()->setPadre(padre);                    
                    delete eliminar;
                //Caso 3: eliminar nodo con 2 hijos (sucesor) 
                }else{
                    NodoBST<T> * sucesor = NodoBST<T>::valorMenor(eliminar->getDer());
                    //NodoBST<T> * predecesor = NodoBST<T>::valorMayor(eliminar->getIzq());
                    eliminar->setDato(sucesor->getDato());
                    if(sucesor->getPadre()->getDato()>sucesor->getDato()) //Sucesor es hijo izq
                    //if(sucesor->getPadre()->getIzq()==sucesor)
                        if(sucesor->getDer()){ //sucesor hijo der
                            sucesor->getPadre()->setIzq(sucesor->getDer());
                            sucesor->getDer()->setPadre(sucesor->getPadre());
                        }else //nodo izq no tiene un hijo
                            sucesor->getPadre()->setIzq(nullptr);
                    else
                       if(sucesor->getDer()){ //sucesor hijo der
                            sucesor->getPadre()->setDer(sucesor->getDer());
                            sucesor->getDer()->setPadre(sucesor->getPadre());
                        }else //nodo izq no tiene un hijo
                            sucesor->getPadre()->setDer(nullptr); 
                    delete sucesor;
                }
                this->numNodos--;
            }else
                cout<<"Valor inexistente en el árbol"<<endl;
        }

        void height(){
            cout<<"la altura es de: ";
            cout<<NodoBST<T>::encontrarAltura(this->raiz);
            cout<<endl;
        }
        void imprimirAntecesor(T dato){
            cout<<"El predecesor de "<<dato<<" es :"<<endl;
            NodoBST<T> * actual = this->raiz;
            if(!actual){
                cout<<nullptr;
            }else{
                if(!actual->getDer()&&!actual->getIzq()){
                    cout<<actual->getPadre();
                }
                else if(actual->getIzq()){
                    actual=actual->getIzq();
                    while(actual->getDer()){
                        actual=actual->getDer();
                    }    
                    cout<<actual->getDato();
                }else{
                    actual=actual->getDer();
                    while(actual->getIzq())
                        actual=actual->getIzq();
                    cout<<actual->getDato();
                }
                else if (actual->getDato()>dato){
                    antecesor(dato);
                }else{
                    antecesor(dato);
                }
            } 
            cout<<nullptr; 
        }
};