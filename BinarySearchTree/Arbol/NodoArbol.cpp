#include "NodoArbol.h"
#include <iostream>
#include <string>

using namespace std;

NodoArbol::NodoArbol() {
	derecha = NULL;
	izquierda = NULL;
}
NodoArbol::NodoArbol(std::string _dato) {
	dato = _dato;
	derecha = NULL;
	izquierda = NULL;
}

std::string NodoArbol::getDato() { //Accesor
	return dato;
}
void NodoArbol::setDato(std::string _dato) {//Modificador 
	dato = _dato;
}

NodoArbol* NodoArbol::getDerecha() {//Accesor
	return derecha;
}
void NodoArbol::setDerecha(NodoArbol* _derecha) {//Modificador
	derecha = _derecha;
}

NodoArbol* NodoArbol::getIzquierda() {//Accesor
	return izquierda;
}
void NodoArbol::setIzquierda(NodoArbol* _izquierda) {//Modificador
	izquierda = _izquierda;
}

NodoArbol::~NodoArbol() {

}