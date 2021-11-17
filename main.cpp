#include "BST.hpp"

int main(){
    BST<int> * arbol= new BST<int>();
    arbol->agregarNodo(21);
    arbol->agregarNodo(13);
    arbol->agregarNodo(10);
    arbol->agregarNodo(18);
    arbol->agregarNodo(33);
    arbol->agregarNodo(25);
    arbol->agregarNodo(40);

    //1->preorder 2->postorder 3->levelbylevel
    arbol->visit(1);
    arbol->height();

    arbol->eliminarNodo(18);
    arbol->imprimirInOrder();
    arbol->eliminarNodo(13);
    arbol->imprimirInOrder();
    arbol->eliminarNodo(33);
    arbol->imprimirInOrder();
    arbol->eliminarNodo(17);

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


    return 0;
}