#include "Abb.h"
#include <iostream>

using namespace std;

Abb::Abb() {
	root = NULL;
}

Abb::~Abb() {
}

NodoArbol* Abb::getRoot() {
	return root;
}

void Abb::setRoot(NodoArbol* _root) {
	root = _root;
}

void Abb::Inserta(string num) {
	NodoArbol* nuevo = new NodoArbol(num);
	NodoArbol* aux = root;
	NodoArbol* antes = root;

	if (root == NULL)
	{
		root = nuevo;
	}

	else {

		while (aux!=NULL&&nuevo->getDato()!=aux->getDato())
		{
			antes = aux;
			if (aux->getDato() > num)
			{
				aux = aux->getIzquierda();
			}
			else
				aux = aux->getDerecha();
		}

		if (aux != NULL) {
			//cout << "Repetido" << endl;
		}
		else {
			if (antes->getDato() > num)
				antes->setIzquierda(nuevo);
			else
				antes->setDerecha(nuevo);
		}
	}
}

int Abb::contarNodos(NodoArbol* aux, int cont) {
	if (aux != NULL) {
		cont++;
		cont = contarNodos(aux->getIzquierda(), cont);
		cont = contarNodos(aux->getDerecha(), cont);
	}
	return cont;
}

int Abb::contarInternos(NodoArbol* aux, int cont) {
	if (aux != NULL)
	{
		if (aux->getIzquierda() != NULL || aux->getDerecha() != NULL)
			cont++;
		cont = contarInternos(aux->getIzquierda(), cont);
		cont = contarInternos(aux->getDerecha(), cont);
	}
	return cont;
}

int Abb::contarHojas(NodoArbol* aux, int cont) {
	if (aux != NULL)
	{
		if (aux->getIzquierda() == NULL && aux->getDerecha() == NULL)
			cont++;
		cont = contarHojas(aux->getIzquierda(), cont);
		cont = contarHojas(aux->getDerecha(), cont);
	}
	return cont;
}

void Abb::contarNodosIH(NodoArbol* aux, int& internos, int& hojas) {
	internos = 0;
	hojas = 0;
	internos = contarInternos(aux, internos);
	hojas = contarHojas(aux, hojas);
}

vector<string> Abb::preorden(NodoArbol* aux, vector<string>& num)
{
	/*
	 La raíz se recorre antes que los recorridos de los subárboles izquierdo y derecho
	 Entrada: aux, es el nodo raíz por el que se inicia el recorrido
	 Salida: Muestra los nodos en pantalla en ese orden
	*/
	if (aux != NULL) {
		num.push_back(aux->getDato());
		preorden(aux->getIzquierda(), num);
		preorden(aux->getDerecha(), num);
	}
	return num;
}

void Abb::preorden(NodoArbol* aux)
{
	/*
	 La raíz se recorre antes que los recorridos de los subárboles izquierdo y derecho
	 Entrada: aux, es el nodo raíz por el que se inicia el recorrido
	 Salida: Muestra los nodos en pantalla en ese orden
	*/
	if (aux != NULL) {
		cout << aux->getDato() << endl;
		preorden(aux->getIzquierda());
		preorden(aux->getDerecha());
	}
}

void Abb::posorden(NodoArbol* aux)
{
	if (aux != NULL) {
		posorden(aux->getIzquierda());
		posorden(aux->getDerecha());
		cout << aux->getDato() <<endl;
	}
}

void Abb::inorden(NodoArbol* aux)
{
	if (aux != NULL) {
		inorden(aux->getIzquierda());
		cout << aux->getDato()<<endl;
		inorden(aux->getDerecha());
	}
}

void Abb::definir(string str) { //Decir si es hoja o 1hijo o 2hijos
	NodoArbol* antes = root;
	NodoArbol* aux = root;
	while (aux != NULL && str != aux->getDato()) {
		antes = aux;
		if (str < aux->getDato()) {
			aux = aux->getIzquierda();
		}
		else {
			aux = aux->getDerecha();
		}
	}
	if (aux != NULL) {
		cout << "Dato encontrado" << endl;
		if (aux->getDerecha() == NULL && aux->getIzquierda() == NULL) {
			cout << "Dato HOJA" << endl;
		}
		else if (aux->getDerecha() == NULL && aux->getIzquierda() != NULL || aux->getDerecha() != NULL && aux->getIzquierda() == NULL)
		{
			cout << "Dato 1 HIJO" << endl;
		}
		else
		{
			cout << "Dato 2 HIJOS" << endl;
		}
	}
	else {
		cout << "Dato NO encontrado" << endl;
	}
}

void Abb::borrar(string str) { //Decir si es hoja o 1hijo o 2hijos
	NodoArbol* antes = root;
	NodoArbol* aux = root;
	while (aux != NULL && str != aux->getDato()) {
		antes = aux;
		if (str < aux->getDato()) {
			aux = aux->getIzquierda();
		}
		else {
			aux = aux->getDerecha();
		}
	}
	if (aux != NULL) {
		//cout << "Dato encontrado" << endl;
		if (aux->getDerecha() == NULL && aux->getIzquierda() == NULL) {
			//cout << "Dato HOJA" << endl;
			if (aux == root) {
				root = BorrarSinHijos(antes, aux);
			}
			else
				antes = BorrarSinHijos(antes, aux);
			//BorrarSinHijos(antes, aux);
		}
		else if (aux->getDerecha() == NULL && aux->getIzquierda() != NULL || aux->getDerecha() != NULL && aux->getIzquierda() == NULL)
		{
			//cout << "Dato 1 HIJO" << endl;
			BorrarUnHijo(antes, aux);
		}
		else
		{
			//cout << "Dato 2 HIJOS" << endl;
			BorrarDosHijos(antes, aux);
		}
	}
	else {
		cout << "Dato NO encontrado" << endl;
	}
}

bool Abb::buscar(string str)
{
	NodoArbol* antes = root;
	NodoArbol* aux = root;
	while (aux != NULL && str != aux->getDato()) {
		antes = aux;
		if (str < aux->getDato()) {
			aux = aux->getIzquierda();
		}

		else {
			aux = aux->getDerecha();
		}
	}
	if (aux != NULL) {
		cout << str << " encontrado en lineas ";
		return true;
	}
	else {
		cout << str  << " NO encontrado" << endl;
		return false;
	}
}

NodoArbol* Abb::BorrarSinHijos(NodoArbol* antes, NodoArbol* aux) {
	// borra nodos hojas
  // ENTRADA: antes, padre del nodo que se borra, aux, nodo que se borra
  // SALIDA: nodo padre del nodo que se borro
	if (aux == root)
		return NULL;
	else {
		if (antes->getDerecha() == aux)
			antes->setDerecha(NULL);
		else
			antes->setIzquierda(NULL);
		return antes;
	}
}

NodoArbol* Abb::BorrarUnHijo(NodoArbol* antes, NodoArbol* aux) {
	// borra un nodo con un hijo
   // ENTRADA: antes, padre del nodo que se borra, aux, nodo que se borra
   // SALIDA: nodo padre del nodo que se borro
	if (aux == root) {
		if (root->getIzquierda() == NULL)
			root = root->getDerecha();
		else
			root = root->getIzquierda();
		delete aux;
		return root;
	}
	else {
		NodoArbol* hijo; // el que borro tiene hijo der o izq
		if (aux->getDerecha() == NULL)
			hijo = aux->getIzquierda();
		else
			hijo = aux->getDerecha();
		if (antes->getDerecha() == aux) // el que borro es hijo izq o der
			antes->setDerecha(hijo);
		else
			antes->setIzquierda(hijo);
		delete aux;
		return antes;
	}
}

NodoArbol* Abb::BorrarDosHijos(NodoArbol* antes, NodoArbol* aux) {
	// borra un nodo con dos hijos
   // ENTRADA: antes, padre del nodo que se borra, aux, nodo que se borra
   // SALIDA: nodo padre del nodo que se borro
	NodoArbol* antesd = aux->getDerecha(), * auxd = antesd;
	while (auxd->getIzquierda() != NULL) { // busco sustituto del nodo que borro, el mas izquierdo de la derecha
		antesd = auxd;
		auxd = auxd->getIzquierda();
	}
	if (aux == root) {// el nodo que borro es raiz con dos hijos
		if (auxd != antesd) {
			antesd->setIzquierda(auxd->getDerecha());
			auxd->setDerecha(antesd);
		}
		auxd->setIzquierda(aux->getIzquierda());
		delete aux;
		//Asignamos la RAIZ
		root = auxd;
		return auxd;
	}
	else {// el nodo que borro es cualquiera
		if (auxd == antesd)// el sustituto es inmediato derecho del que borro
			auxd->setIzquierda(aux->getIzquierda());
		else {
			antesd->setIzquierda(auxd->getDerecha());
			auxd->setIzquierda(aux->getIzquierda());
			auxd->setDerecha(aux->getDerecha());
		}
		if (antes->getDerecha() == aux) // el nodo que borro es hijo derecho
			antes->setDerecha(auxd);
		else
			antes->setIzquierda(auxd); // el que borro es hijo izquierdo
		delete aux;
		return antes;
	}
}