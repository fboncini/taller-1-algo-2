#include "Lista.h"

template <typename T>
Lista<T>::Lista() {
    _Primero = nullptr;
    _Ultimo = nullptr;
    _Longitud = 0;
}

// Inicializa una lista vacía y luego utiliza operator= para no duplicar el
// código de la copia de una lista.
template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() { *this = l; } 

template <typename T>
Lista<T>::~Lista() {
    while(_Longitud != 0){
        eliminar(0);
    }
  
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& l) {
    while(_Longitud != 0){
        eliminar(0);
    }
    if (l._Longitud == 0){
        _Primero = nullptr;
        _Ultimo = nullptr;
    } else {
        Nodo* actual = l._Primero;
        int i = l._Longitud ;
        while (i>0){
            agregarAtras(actual->_Elemento);
            actual = actual->_Siguiente;
            i = i-1;
        }

    }
    
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    if (_Longitud == 0){
        _Primero = new Nodo(elem, nullptr, nullptr);
        _Ultimo = _Primero;
    }else{
        Nodo* nuevo = new Nodo(elem, nullptr, _Primero);
        _Primero->_Anterior = nuevo;
        _Primero = nuevo;


    }
    _Longitud = _Longitud + 1;

}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    if (_Longitud == 0){
        _Primero = new Nodo(elem, nullptr, nullptr);
        _Ultimo = new Nodo(elem, nullptr, nullptr);
    }else{
        if(_Longitud != 1) {
            Nodo *nuevo = new Nodo(elem, _Ultimo, nullptr);
            _Ultimo->_Siguiente = nuevo;
            _Ultimo = nuevo;
        } else{
            Nodo *nuevo = new Nodo(elem, _Ultimo, nullptr);
            _Ultimo->_Siguiente = nuevo;
            _Ultimo = nuevo;
            _Primero->_Siguiente = _Ultimo;
        }
    }
    _Longitud = _Longitud + 1;
}

template <typename T>
int Lista<T>::longitud() const {
    return _Longitud;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    Nodo* actual = _Primero;
    while (i>=0){
        actual = actual->_Siguiente;
        i = i-1;
    }
    return actual->_Elemento;
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    if(_Longitud == 1){
        delete _Primero;
        _Primero = nullptr;
        _Ultimo = nullptr;
    }else
    {
        Nodo* actual = _Primero;
        if (i == 0){
            actual = _Primero->_Siguiente;
            delete _Primero;
            _Primero = actual;
            _Primero->_Anterior = nullptr;
        }else{
            if(i == _Longitud -1){
                actual = _Ultimo->_Anterior;
                delete _Ultimo;
                _Ultimo = actual;
                _Ultimo->_Siguiente = nullptr;
            }else{
                if(i == 1){
                    actual = actual->_Siguiente;
                    Nodo* ant_actual = _Primero;
                    Nodo* sig_actual = actual->_Siguiente;
                    ant_actual->_Siguiente = sig_actual;
                    sig_actual->_Anterior = ant_actual;
                    delete actual;
                }else {


                    while (i > 0) {
                        actual = actual->_Siguiente;
                        i = i - 1;
                    }
                    Nodo *ant_actual = actual->_Anterior;
                    Nodo *sig_actual = actual->_Siguiente;
                    ant_actual->_Siguiente = sig_actual;
                    sig_actual->_Anterior = ant_actual;
                    delete actual;
                }
            }   

        } 

    }
    _Longitud = _Longitud-1;

}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    Nodo* actual = _Primero;
    while (i>0){
        actual = actual->_Siguiente;
        i = i-1;
    }
    return actual->_Elemento;
}

template <typename T>
void Lista<T>::mostrar(std::ostream& o) {
    if (_Longitud == 0){
        o << "[]" << endl;
    } else{
        Nodo* actual = _Primero;
        o << "[";
        for(int i = 0; i<_Longitud-1; i++){
            o << actual->_Elemento<< ",";
            actual = actual->_Siguiente;
        }
        o<< _Ultimo->_Elemento<<"]"<< endl;

    }
    /*if (_nodoPrincipal == nullptr){
        o << "[]" << endl;
    } else {
        Nodo *ultimo = _nodoPrincipal;

        while (ultimo->_nodoSig != nullptr){
            o << "[" << ultimo->_valor << ", ";
            ultimo = ultimo->_nodoSig;
        }

        o << ultimo->_valor << "]" << endl;
    }*/
}
