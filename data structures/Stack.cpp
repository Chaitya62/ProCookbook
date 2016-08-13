/*Stack implementation
(Using singly linked list)
Written by Chaitya Shah
*/
#include<iostream>
using namespace std;


template<class X>
class Stack{
private:
        class  Node{

            X data;
            Node *next;
            friend class Stack<X>;
        public:
            Node(){
                next = NULL;
            }
        };
        Node *start;
        Node *pnode;
public:
    Stack(){
        start = NULL;
    }

    //push operation
    int push(X d){
        pnode = new Node[1];
        pnode->data = d;
        if(isEmpty()){
            pnode->next = NULL;
            start = pnode;
        }
        else{
            pnode->next = start;
            start = pnode;


        }
        return 0;
    }
    //pop operation
    X pop(){
        int temp_data;
        Node *temp;
        temp = new Node[1];
        temp = start;
        start = start->next;
        temp_data = temp->data;
        delete []temp;
        return temp_data;

    }
    //view the top element of the stack
    X peep(){
        return start->data;
    }

    //returns true if stack is empty
    bool isEmpty(){
        return (start == NULL ? true : false );
    }
};
int main(){
    int a ;
    Stack<int> x;
    /*x.push(12);
    x.push(34);
    x.push(345);
    cout<<x.pop();
    cout<<x.pop();
    cout<<x.peep();*/
    //cin>>a;
    for(int i =0;i<30000;i++)x.push(i);
    for(int i = 0;i<30000;i++) cout<<x.pop()<<endl;

    return 0;
}
