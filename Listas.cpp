
#include <iostream>

class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int dato)
    {
        this->dato = dato;
        siguiente = nullptr;
    }
};


class Lista {

    private:
        Nodo* PrimerN; //Primer Nodo y nodos subsecuentes
        bool listavacia()//Avisa si la lista esta vacia
        {
            return PrimerN == nullptr;
        }
    public:   
        Lista()
        {
            PrimerN = nullptr;
        }
        ~Lista()
        {
            std::cout << "Lista destruida" << std::endl;
        }

        void insertarInicio(int dato)
        {
            Nodo* nuevoNodo = new Nodo(dato);
            if (listavacia())
            {
                PrimerN = nuevoNodo;
            }
            else
            {
                nuevoNodo->siguiente = PrimerN;
                PrimerN = nuevoNodo;
            }
        }

        void insertarFinal(int dato)
        {
            Nodo* nuevoNodo = new Nodo(dato);
            if (listavacia())
            {
                PrimerN = nuevoNodo;
            }
            else
            {
                Nodo* actual = PrimerN;
                while (actual->siguiente != nullptr)//Encuentra el ultimo elemento de la lista
                {
                    actual = actual->siguiente;
                }
                actual->siguiente = nuevoNodo;
            }
        }

        void muestraLista() 
        {
            if (listavacia())
            {
               std::cout<<"\nLa lista esta vacia"<<std::endl;
            }
            else
            {
                Nodo* actual = PrimerN;
                for(int i = 1;actual != nullptr; i++)
                {
                    std::cout << i <<".- " << actual->dato << std::endl;
                    actual = actual->siguiente;
                }
            }
        }
};


int main()
{
    Lista Lista1;
    Lista1.insertarInicio(10);
    Lista1.insertarFinal(7);
    Lista1.muestraLista();

}
