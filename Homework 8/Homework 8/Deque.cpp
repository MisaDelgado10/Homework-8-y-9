#include "Deque.h"

Deque::Deque(int size) {
	front = -1;
	back = 0;
	this->size = size;
}

Deque::Deque() {
	//Se inicializa con un tamaño 100 por defecto
	front = -1;
	back = 0;
	size = N;
}

bool Deque::isFull()
{
	//Checa si la deque está llena o no
	//Entrada: ninguna
	//Salida: true si está llena, false si no
	return ((front == 0 && back == size - 1) || front == back + 1);
}

bool Deque::isEmpty()
{
	//Checa si la deque está vacía o no
	//Entrada: ninguna
	//Salida: true si está vacía, false si no
	return (front == -1);
}


void Deque::push_front(int dato)
{
	//Inserta un dato al principio de la deque
	//Entrada: dato-> dato de tipo int a insertar
	//Salida: ninguna
	if (isFull())
	{
		cout << "No puedes insertar más datos. Deque llena\n" << endl;
		return;
	}

	// Si no hay dato agregaré el dato en la posición
	if (front == -1)
	{
		front = 0;
		back = 0;
	}

	// si ya hay dato en la primera posición el nuevo lo inserto en size - 1
	else if (front == 0)
		front = size - 1;

	else // decrementa front en -1
		front = front - 1;

	// agregamos el dato al Deque
	arr[front] = dato;
}


void Deque::push_back(int dato)
{
	//Inserta un dato al final de la deque
	//Entrada: dato-> dato de tipo int a insertar
	//Salida: ninguna
	if (isFull())
	{
		cout << " Deque Lleno\n " << endl;
		return;
	}

	// Si al principio esta vacio inserto en la primer posición
	if (front == -1)
	{
		front = 0;
		back = 0;
	}

	// si back esta al final de la cola
	else if (back == size - 1)
		back = 0;

	// incrementamos back en +1
	else
		back = back + 1;

	// insertamos el valor al Deque
	arr[back] = dato;
}

void Deque::pop_front()
{
	//Elimino un dato del frente
	//Entrada: Ninguna
	//Salida: Si no hay dato para eliminar imprimo mensaje en pantalla
	if (isEmpty())
	{
		cout << "No hay ningun dato para eliminar\n";
	}

	// si solo hay un elemento en el Deque 
	if (front == back)
	{
		front = -1;
		back = -1;
	}
	else
		// volvemos a la posicion inicial 
		if (front == size - 1)
			front = 0;

		else // incrementamos front en +1 para eliminar el front actual del Deque
			front = front + 1;
}


void Deque::pop_back()
{
	//Elimino un dato del back
	//Entrada: Ninguna
	//Salida: Si no hay dato para eliminar imprimo mensaje en pantalla
	if (isEmpty())
	{
		cout << "No hay ningun dato para eliminar\n";
	}

	// si el Deque tiene solo un elemento
	if (front == back)
	{
		front = -1;
		back = -1;
	}
	
	else if (back == 0)
		back = size - 1;
	else
		back = back - 1;
}


int Deque::getFront()
{
	//Obtengo el dato del front
	//Entrada: Ninguna
	//Salida: si hay dato en el front lo devuelvo como entero
	if (isEmpty())
	{
		cout << "No hay dato en el front\n" << endl;
		return -1;
	}
	return arr[front]; 
}


int Deque::getBack()
{
	//Obtengo el dato del back
	//Entrada: Ninguna
	//Salida: si hay dato en el back lo devuelvo como entero
	if (isEmpty() || back < 0)
	{
		cout << " el Deque est� vacio\n" << endl;
		return -1;
	}
	return arr[back]; 
}
Deque::~Deque() {

}