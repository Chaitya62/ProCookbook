/*
normal and extended GCD 
Written By Chaitya Shah
*/
#include<iostream>
#define ll long long int
#define MAX 100000
using namespace std;

//normal GCD
ll gcd(ll a,ll b){
	if(a==0) return b;
	return gcd(b%a,a);
}


//Extended GCD 
ll gcd(ll a,ll b,ll *x,ll *y){
	if(a==0){

		*x = 0;
		*y = 1;
		return b;
	}
	ll x1,y1; // store results of recursive call
	ll g = gcd(b%a,a,&x1,&y1);
	//Update x and y using results of recursive call
	*x = y1-(b/a) * x1;
	*y = x1;
	return g;
}




int main(){
	ll x,y;
	ll a,b;
	cin>>a>>b;
	cout<<gcd(a,b,&x,&y);
	cout<<" "<<x<<" "<<y;
	return 0;
}
