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
			if (rear == front && front==-1)
				front = 0;

			rear = (rear + 1) % size;
			arr[rear] = data;
		}
	}
	int dequeue()
	{
		int z;
		if (rear == front)
			front = rear = -1;

		else if (!IsEmpty())
		{
			 z = arr[front];
			front = (front + 1) % size;
		}
		return z;
	}
	void josephus(int key) {
		int tsize = size;
		int staying;
		if (!IsEmpty()) {
			while (tsize > 1) {
				for (int i = 0;i < key-1;i++) {
					enqueue(dequeue());
				}
				dequeue();
				tsize -= 1;
				cout << endl;
				print();
			}
		}
	}
	void print()
	{
		int temp = front;
		while (temp != rear)
		{
			cout << arr[temp] << " ";
			temp = (temp + 1) % size;
		}
		cout << arr[rear];
	}

};
int main()
{
	int people,gap;
	cout << " Enter Total People : ";
	cin >> people;
	cout << " Enter the Gap: ";
	cin >> gap;
	Queue q1(people);
	for (int i = 1;i < (people+1);i++) {
		q1.enqueue(i);
	}
	q1.print();
	q1.josephus(gap);
	return 0;
}