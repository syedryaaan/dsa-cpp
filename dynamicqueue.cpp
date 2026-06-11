#include <iostream>
using namespace std ;
class Node {
    public:
    int data ;
    Node* next;
      Node(int x){
        data = x;
        next = NULL;

      }
};
class Queue{
  public:
   Node*front ;
   Node*rear;
   int sz;
   Queue(){
    front = NULL;
    rear = NULL;
    sz = 0;}
   
   void enqueue(int x){
     Node* n = new Node(x);
     if(front==NULL){
       front = rear = n;
     } 
     else {
       rear->next = n;
       rear = n;
     };
     sz++;

     
   };
   
   int size(){ return sz; }
   
   bool isEmpty(){ return front==NULL; }
   
   int dequeue(){
     if(front==NULL) return -1; 
     Node* t = front;
     int val = t->data;
     front = front->next;
     if(front==NULL) rear = NULL;
     delete t;
     sz--;
     return val;
   }

   int sum() {
     int s = 0;
     Node* temp = front;

     while(temp != NULL) {
       s += temp->data;
       temp = temp->next;
     }

     return s;
   }
};


int main (){
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);

  while(!q.isEmpty()){
    cout<<q.dequeue()<<" ";
  }
  cout<<"\n";

  cout << "sum" << q.sum() << endl;

  return 0;
}
  




