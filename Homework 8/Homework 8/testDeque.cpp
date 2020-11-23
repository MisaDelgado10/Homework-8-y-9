#include<iostream> 
#include "Deque.h"
using namespace std;

int main()
{
	Deque deque(5);

	deque.push_front(1);
	deque.push_front(2);
	deque.push_front(5);
	deque.push_back(10);
	deque.push_back(17);

	deque.pop_front();
	deque.pop_front();

	cout << "Dato del back "<< " "<< deque.getBack() << endl;
	cout << "Dato del front "<<" "<< deque.getFront() << endl;

	return 0;
}
