#include<iostream>
#define ll long long int
#define MAX 1000000
using namespace std;
ll A[MAX];
/*Consider prime if A[i] is 0 
 This reduces Looping to set all elements 1;
*/
int Sieve(ll N){
	for(ll i = 0;i<=N;i++){
		if(A[i]==0){
			for(ll j = i;i*j<=N;j++){
				A[i*j] = 1; 
				//Set all multiples of i to 1 i.e not prime;
			}
		}
	}
	return 0;	
}


int main(){
	A[0] = 1; //Not a Prime
	A[1] = 1; //Not a Prime
	Sieve(100000);
	for(ll i =0;i<=100000;i++){
		if(A[i]==0) cout<<i<<endl;
	}


	return 0;
}

