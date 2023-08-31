#include<iostream>
using namespace std;
template<class T>
class Stack{
class Node{
T data;
Node*next;
friend class Stack<T>;
public:
Node(){
this->next=NULL;
}
Node(T data){
this->next=NULL;
this->data=data;
}
};
Node *top;
int size;
public:
Stack(){
top=NULL;
size=0;
}
void push(int value){
size++;
if(size<5)
{
Node*n=new Node(value);
if(top!=NULL)
   {
n->next=top;
}
top=n;
}
else
cout<<" Stack size full "<<endl;
}
bool isempty(){
if(top==NULL)
return true;
return false;
}
bool isfull(){
if(size<5){
cout<<" Stack not full"<<endl;
return false;
}
else
cout<<" Stack is full"<<endl;
return true;
}
void pop(){
Node*temp=top;
top=top->next;
delete temp;
}
T topmost(T &val){
if(top==NULL)
cout<<" No stack data "<<endl;
val=top->data;
return top->data;
}
void print(){
Node*temp=top;
while(temp!=NULL)
{
cout<<temp->data<<" -> ";
temp=temp->next;
}
cout<<"NULL"<<endl;
}
~Stack(){
Node*temp2=top;
top=top->next;
delete temp2;
}
};
int main(){
Stack<int>s1;int a,b;
s1.push(6);
s1.push(8);
s1.push(4);
s1.push(72);
s1.print();
a=s1.topmost(b);
cout<<"Top most elem is : "<<a<<endl;
system("pause");
return 0;
}
 