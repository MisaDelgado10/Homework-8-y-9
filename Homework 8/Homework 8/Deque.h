#pragma once
#include<iostream> 
using namespace std;
 
#define N 100 

class Deque
{
	int arr[N];
	int front;
	int back;
	int size;
public:
	Deque(int _size);
	Deque();
	~Deque();

	// Operations on Deque: 
	void push_front(int);
	void push_back(int);
	void pop_front();
	void pop_back();
	int getFront();
	int getBack();
	bool isFull();
	bool isEmpty();
};

