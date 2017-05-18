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
#define trie struct Trie
struct Trie{
	map<char, trie* > a;
	bool end;
	uii wordCount;
};

trie* newNode(){
	trie* temp = new trie[1];
	temp->end = false;
	temp->wordCount = 0;
	return temp;
}

void insert(trie* root,string k){
	uii klen = k.size();
	trie* temp = root;
	for(uii i = 0;i<klen;i++){
		if(temp->a.find(k[i]) == temp->a.end()){
			temp->a[k[i]] = newNode();
			//temp->wordCount++;
		}
		temp->wordCount++;
		temp = temp->a[k[i]];
		
	}
	temp->end = 1;
	temp->wordCount++;
	return;
}

bool find(trie* root, string k,uii &count){
	uii klen = k.size();
	trie* temp = root;
	for(uii i= 0; i<klen; i++){
		if(temp->a.find(k[i]) == temp->a.end())
			return false;
		temp = temp->a[k[i]];
		count++;
	}
	return temp->end;
}

bool remove(trie* root, string k,uii i){
		uii klen = k.size();
		trie* temp = root;
		if(i == klen) return true;
		if(temp->a.find(k[i]) == temp->a.end()) return false;
		temp = temp->a[k[i]];
		if(i == klen-1){
			if(temp->end){
				temp->end = 0;
			}
			else return false;
		}
		bool check = remove(temp, k, i+1);
		if(!check) return false;
		temp->wordCount--;
		if(temp->wordCount <= 0){
			delete []temp;
		}
		return check;
}	


int main(){
     trie* root = newNode();
	insert(root, "Hello World");
	insert(root, "Hello");
	insert(root, "Wake me up !");
	insert(root, "Wassup");
	uii count = 0;
	cout<<find(root, "Hello World", count)<<" : ";
	cout<<count<<endl;
   	cout<<remove(root,"Wass",0)<<endl;
	count = 0;
   	cout<<remove(root,"Hello World",0)<<endl;
	cout<<remove(root,"Hello",0)<<endl;
	cout<<find(root, "Hello", count)<<" : ";
	cout<<count<<endl;
	count= 0;
	cout<<find(root, "Wassup", count)<<" : ";
	cout<<count<<endl;


	return 0;
}


