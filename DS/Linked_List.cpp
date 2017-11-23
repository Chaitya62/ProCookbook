#include<iostream>
using namespace std;
#define node struct Node

struct Node{

	node* left;
	node* right;
	int value;

};

class LinkedList{
	private:
		node* start,* end;
	public:
		LinkedList(){
			start = end = newNode(-1);
			start->left = NULL;
			end->right = NULL;
			start->right = end;
			end->left = end;
		}

		node* newNode(int val){
			node* temp;
			temp = new node[1];
			temp->value = val;
			return temp;
		}

		void add(int v){
			if(start->value == -1){
				start->value = v;
			}else{
				node* nn = newNode(v);
				end->right = nn;
				nn->left = end;
				nn->right = NULL;
				end = nn;
			}

			return;
		}

		void display(){
			node* temp = start;
			cout<<"START->";
			while(temp->right != NULL){
				cout<<temp->value<<"->";
				temp = temp->right;
			}
			cout<<"END"<<endl;

			return;
		
		}

		void insertAt(int v, int x){
			node* temp = start;
			while(temp->right != NULL && x != 1){
				if(temp == NULL){
					cout<<"Too few elements....";
					return;
				}
				temp = temp->right;
				x--;
			}
			node* nn = newNode(v);
			nn->right = temp->right;
			nn->left = temp;
			nn->right->left = nn;
			temp->right = nn;
			return;
		}



};



int main(){
	LinkedList a;
	a.add(5);
	a.add(10);
	a.add(100);
	a.insertAt(0, 1);
	a.insertAt(112, 3);
	a.add(12);
	a.display();

	return 0;
}
