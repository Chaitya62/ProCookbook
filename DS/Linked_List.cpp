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
		long long int len;
		long long int sizeLimit;
	public:
		LinkedList(){
			start = newNode(-1);
			end = start;
			start->left = NULL;
			end->right = NULL;
			start->right = end;
			end->left = end;
			len = 0;
		}

		LinkedList(long long int sl){
			new (this)LinkedList();
			sizeLimit = sl;	
		}

		node* newNode(int val){
			node* temp;
			temp = new node[1];
			temp->value = val;
			return temp;
		}

		void add(int v){
			if(len >= sizeLimit){
				cout<<"Maximum size reached"<<endl;
				return;
			}
			if(start->value == -1){
				start->value = v;
			}else{
				node* nn = newNode(v);
				end->right = nn;
				nn->left = end;
				nn->right = NULL;
				end = nn;
			}
			increaseLength();
			return;
		}

		void display(){
			node* temp = start;
			cout<<"START->";
			while(temp != NULL){
				cout<<temp->value<<"->";
				temp = temp->right;
			}
			cout<<"END"<<endl;

			return;
		
		}

		int increaseLength(){
			len++;
			if(len >= sizeLimit){
				cout<<"Size Limit Reached...."<<endl;
			}
			return 0;
		}

		int decreaseLength(){
			len--;
			return 0;
		}

		node* findAt(int x){
			node *temp = start;
			while(temp != NULL && x != 1){
				if(temp == NULL){
					cout<<"Too few elements....";
					return NULL;
				}
				temp = temp->right;
				x--;
			}
				
			return temp;
		
		}

		void insertAt(int v, int x){
			if(len >= sizeLimit){
				cout<<"Maximum Size reached"<<endl;
				return;
			}
			node* temp = findAt(x);
			if(temp == NULL) return;
			node* nn = newNode(v);
			nn->right = temp->right;
			nn->left = temp;
			nn->right->left = nn;
			temp->right = nn;
			increaseLength();
			return;
		}

		void deleteAt(int x){
			node* temp = findAt(x);
			if(temp == NULL) return;
			temp->right->left = temp->left;
			temp->left->right = temp->right;
			delete []temp;
			decreaseLength();
			return;
		}
		
		long long int length() {return len;}


};



int main(){
	LinkedList a(10);
	a.add(5);
	a.add(10);
	a.add(100);
	a.insertAt(0, 1);
	//for(int i = 0;i<4;i++) a.add(i);
	a.insertAt(112, 3);
	a.deleteAt(2);
	a.add(12);
	a.add(10);
	a.deleteAt(4);
	a.add(100);
	a.add(101);
	a.add(102);
	a.display();
	cout<<a.length()<<endl;

	return 0;
}
