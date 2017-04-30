#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<set>
using namespace std;
#define uii long long int
#define M(a,b) (a>b ? a : b)
#define m(a,b) (a>b ? b : a)
#define it(a)  ::iterator a
#define slld(a) uii a;scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define plld(a) printf("%lld",a)
#define MAX 10000
#define MOD 1000000007
#define powOf2(a) !(a&a-1)
#define mod(a) (a>0 ? a : (-1*a))
#define tc(a) uii a; for(scanf("%lld",&a);a--;)
#define swap(a,b) a = a^b; b = a^b;a = a^b;
void calculatePatternArray(uii *A,string p){
	uii plen = p.size();
	uii j = 0;
	for(uii i = 1;i<plen;i++){
		if(p[i] == p[j]) A[i] = ++j;
		else if(j == 0) A[i] = 0;
		else{
			j = A[j-1];
			i--;
		}
	}
	return;
}
void kmp(string p, string text){
	
	uii tlen = text.size();
	uii plen = p.size();
	uii A[plen] = {0};
	calculatePatternArray(A,p);
	uii  tp = 0,pp = 0;
	while(tp<tlen){
		if(p[pp] == text[tp]){
			//cout<<"tp : "<<tp<<endl;
			tp++;
			pp++;
		}
		else if(pp == 0){
			tp++;
		}
		else{
			pp = A[pp-1];
		}
		if(pp == plen){
			cout<<"Pattern found at : "<<tp-plen<<endl;
			
			pp = A[pp-1];
		}

	}
	return;
}

int main(){
	string pattern;
	string text = "Load text before hand";
	cin>>pattern;
	kmp(pattern,text);
	return 0;
}


