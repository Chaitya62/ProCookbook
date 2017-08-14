#include<iostream>
#include<cstdio>
using namespace std;
#define mul(a,b) a*b
#define MOD 1000000007
#define uii long long int
uii pow(uii x,uii n){
	if(n==1) return x%MOD;
	if(n%2==0) return  pow(mul(x,x)%MOD,n/2)%MOD;
	return ((x%MOD) * pow(mul(x,x)%MOD,n/2))%MOD;
}

int main(){
	int  s;
	int a;
	cin>>s;
	cin>>a;
	cout<<pow(s,a);
	return 0;
}
