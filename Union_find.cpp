/*
Union Find 
Written By
Chaitya Shah
*/
#include<iostream>
using namespace std;
template<class X>
struct node{
	int size;
	X i;

};
template<class T>
class UnionFind{
	struct node<T> *A;
	public:
		UnionFind(int N){
			A = new struct node<T>[N];
			for(int i = 0;i<N;i++){
				A[i].i = i;
				A[i].size = 1;
			}
		}
		T root(T i){
			cout<<A[i]<<endl;
			while(A[i].i != i ) i  = A[i].i;
			return i;
		}

		int Union(T a, int b){
			T roota = root(a);
			T rootb = root(b);
			if(A[roota].size > A[rootb].size){
				A[rootb].i = A[roota].i;
				A[roota].size += A[rootb].size;
			}
			else{
				A[roota].i = A[rootb].i;
				A[rootb].size += A[roota].size;
			}
			return 0;
		}

		bool find(T a, T b){
			return root(a) == root(b);
		}
};


int main(){
	int a,b;
	UnionFind<int> U(10); // can use long long int ,int 
	for(int i = 0;i<3;i++){
		//int a,b;
		cin>>a>>b;
		U.Union(a,b);
	}	
	for(int i = 0;i<3;i++){
		//int a,b;
		cin>>a>>b;
		cout<<U.find(a,b)<<endl;
	}




	return 0;
}
