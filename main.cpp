#include "BST.hpp"

int main(){

    //NUEVO ARBOL
    cout<<"***NUEVO ARBOL***"<<endl;
    BST<int> * arbol2=new BST<int>();
    arbol2->agregarNodo(8);
    arbol2->agregarNodo(10);
    arbol2->agregarNodo(3);
    arbol2->agregarNodo(1);
    arbol2->agregarNodo(6);
    arbol2->agregarNodo(14);
    arbol2->agregarNodo(4);
    arbol2->agregarNodo(13);
    arbol2->agregarNodo(7);

    //visit
    arbol2->visit(1);
    arbol2->visit(2);
    arbol2->visit(3);

    //altura
    arbol2->height();

    //Antecesor
    arbol2->imprimirAntecesor(8);

    //NodeLevel
    arbol2->getNodeLevel(8);

    return 0;
}