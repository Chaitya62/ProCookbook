/*

Author: Chaitya Shah

AVL + Interval Tree

*/

#include<iostream>
#include<vector>
#include<climits>

#define ll long long
#define node struct Node
#define INF LLONG_MAX
#define ifnw(a) (a == NULL ? 0 : a->weight)
#define max_e(a) (a==NULL ? -1*INF : a->max_end)
#define balance(a) (ifnw(a->left) - ifnw(a->right))


using namespace std;

struct Node{

	ll l,r;
	ll max_end;
	ll weight;
	ll id;
	struct Node* left,*right;
};

class BST{

	public:
		node* root;
		node* nl;

	BST(){
		root = NULL;
		nl = NULL;
	}

	node* createNode(ll a, ll b){
		node* temp = new node[1];
		temp->l = a;
		temp->r = b;
		temp->max_end = -1*INF;
		temp->weight = 1;
		temp->left = NULL;
		temp->right = NULL;

		return temp;
	}

	node* createNode(ll a, ll b, ll i){
		node* temp = new node[1];
		temp->l = a;
		temp->r = b;
		temp->max_end = -1*INF;
		temp->weight = 1;
		temp->left = NULL;
		temp->right = NULL;
		temp->id = i;

		return temp;
	}

	node* rotateRight(node* a){
		node *temp1, *temp2;

		temp1 = a->left;
		temp2 = a->left->right;
		temp1->right = a;
		a->left = temp2;

		a->weight = max(ifnw(a->right)+1, ifnw(a->left)+1);
		a->max_end = max(max_e(a->left), max_e(a->right));
		a->max_end = max(a->max_end, a->r);
		
		temp1->weight = max(ifnw(temp1->right)+1, ifnw(temp1->right)+1);
		temp1->max_end = max(max_e(temp1->right), max_e(temp1->left));
		temp1->max_end = max(temp1->max_end, temp1->r);
		return temp1;

	}

	node* rotateLeft(node* a){
		node *temp1, *temp2;

		temp1 = a->right;
		temp2 = a->right->left;
		temp1->left = a;

		
		a->right = temp2;

		
		a->weight = max(ifnw(a->left)+1, ifnw(a->right)+1);
		a->max_end = max(max_e(a->left), max_e(a->right));
		a->max_end = max(a->max_end, a->r);

		temp1->weight = max(ifnw(temp1->right)+1, ifnw(temp1->left)+1);
		temp1->max_end = max(max_e(temp1->right), max_e(temp1->left));
		temp1->max_end = max(temp1->max_end, temp1->r);


		return temp1;
	}

	node* insert(node* curr, node* a){
		
		if(curr == NULL){
			curr = a;
			curr->max_end = max(curr->max_end, a->r);
			return curr;
		}
		else if(curr->l < a->l){
			curr->right = insert(curr->right, a);
			curr->max_end = max(curr->max_end, curr->right->max_end);
			curr->weight = max(ifnw(curr->right) + 1, ifnw(curr->left) + 1);
		}
		else{
			curr->left = insert(curr->left, a);
			curr->max_end = max(curr->max_end, curr->left->max_end);
			curr->weight = max(ifnw(curr->right) + 1, ifnw(curr->left) + 1);
		}


		ll bal = balance(curr);


		if(bal >1){
			if(curr->left != NULL && a->l < curr->left->l){
			
				return rotateRight(curr);
			}else if(curr->left != NULL && a->l >  curr->left->l){
			
				curr->left = rotateLeft(curr->left);
				return rotateRight(curr);
			}

		}else if(bal < -1){

			if(curr->right != NULL && a->l < curr->right->l){
				curr->right = rotateRight(curr->right);
				return rotateLeft(curr);
			}
			else if(curr->right!=NULL && a->l > curr->right->l){
				return rotateLeft(curr);
			}

		}

		return curr;
	}

	int isOverlapping(node* a, node *b){
		if(a->l > b->r || a->r < b->l) return 0;
		else if(a->l >= b->l && a->r <= b->r) return 1;
		else if(a->l <= b->l && b->r <= a->r) return -1;
		else return -2;
	}

	ll count_overlaps(node* a, node* b){
		return (min(a->r, b->r)-max(a->l,b->l)+1);
	}


	void overlaps(node *curr ,node *a, vector<node> &V){
		if(curr == NULL) return;
		if(isOverlapping(curr, a)!= 0){
			cout<<curr->l<<" -> "<<curr->r<<endl;
			
			//V[curr->id] = count_overlaps(curr, a);

			V.push_back(*curr);	
		}

		if(curr->left != NULL && curr->left->max_end >= a->l){
			overlaps(curr->left, a, V);
		}

		if(curr->right != NULL && curr->right->l <= a->r){
			overlaps(curr->right, a, V);
		}

		return;
		

	}



	void walk(node* curr){
		if(curr == NULL) return;
		walk(curr->left);
		walk(curr->right);

		cout<<curr->l<<" "<<curr->r<<" maxending : "<<curr->max_end<<" weight : "<<curr->weight<<endl;
		return;
	}


};


int main(){
	BST tree;

	cout<<"Starting : :"<<endl;
	tree.root = tree.insert(tree.root, tree.createNode(17, 19));
	tree.root = tree.insert(tree.root, tree.createNode(5, 8));
	tree.root = tree.insert(tree.root, tree.createNode(21, 24));
	tree.root = tree.insert(tree.root, tree.createNode(15, 18));
	tree.root = tree.insert(tree.root, tree.createNode(4, 8));
	// tree.root = tree.insert(tree.root, tree.createNode(6, 10));
	tree.root = tree.insert(tree.root, tree.createNode(7, 10));
	// tree.root = tree.insert(tree.root, tree.createNode(8, 10));
	// tree.root = tree.insert(tree.root, tree.createNode(9, 10));
	tree.root = tree.insert(tree.root, tree.createNode(16, 22));


	cout<<"insertion complete"<<endl;
	vector<node> V;

	

	tree.overlaps(tree.root, tree.createNode(16, 22), V);
	

	//tree.overlaps(tree.root, tree.createNode(21, 23), V);



	Node *a = tree.createNode(1, 10);
	Node *b = tree.createNode(5, 11);
	Node *c = tree.createNode(2, 7);
	Node *d = tree.createNode(23, 25);

	cout<<tree.isOverlapping(a, b)<<endl;
	cout<<tree.isOverlapping(a, c)<<endl;
	cout<<tree.isOverlapping(a, d)<<endl; 
	cout<<tree.isOverlapping(c, a)<<endl;


	tree.walk(tree.root);
}
