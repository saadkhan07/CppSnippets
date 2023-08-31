#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
	Node* curr;
};
void add(Node*n,int val) {
	n->curr = n;
	Node* nnew = new Node;
	nnew->data = val;
	nnew->next = n->next;
	n->next = nnew;
	n->curr = nnew;
}
void disp(Node*n) {
	Node* temp = n->next;
	while (temp != NULL) {
		cout << temp->data << "\t";
		temp = temp->next;
}
	cout << endl;
}
int main() {
	Node* n1 = new Node;
	n1->next = NULL;
	add(n1,8);
	add(n1, 5);
	add(n1, 3);
	disp(n1);
	return 0;
}