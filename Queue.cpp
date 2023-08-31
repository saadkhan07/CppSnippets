#include<iostream>
using namespace std;

class Queue
{
	int* arr;
	int front;
	int rear;
	int size;

public:
	Queue()
	{
		arr = nullptr;
		front = rear = -1;
	}
	Queue(int size)
	{
		this->size = size;
		arr = new int[size];
		front = rear = -1;
	}
	bool IsFull()
	{
		return ((rear + 1) % size == front);
	}
	bool IsEmpty()
	{
		return (rear == -1 && front == -1);
	}
	void enqueue(int data)
	{
		if (!IsFull())
		{
			if (rear == front)
				front = 0;

			rear = (rear + 1) % size;
			arr[rear] = data;
		}
	}
	void dequeue()
	{
		if (rear == front)
			front = rear = -1;

		else if (!IsEmpty())
		{
			arr[front] = -1;
			front = (front + 1) % size;
		}

	}
	void print()
	{

		while (front != rear)
		{
			cout << arr[front] << " ";
			front = (front + 1) % size;
		}
		cout << arr[rear];
	}

};

int main()
{
	Queue q1(4);
	q1.enqueue(12);
	q1.enqueue(42);
	q1.enqueue(23);
	q1.enqueue(14);
	q1.enqueue(59);
	q1.enqueue(20);
	q1.dequeue();
	q1.enqueue(3);


	q1.print();

}