#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<set>
#include<queue>
#include<stack>
#include<climits>
using namespace std;
#define uii long long int
#define it(a)  ::iterator a
#define slld(a) uii a;scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define plld(a) printf("%lld",a)
#define MAX 10000
#define MOD 1000000007
#define SIZE 100000
#define INF LLONG_MAX
#define powOf2(a) !(a&a-1)
#define mod(a) (a>0 ? a : (-1*a))
#define tc(a) uii a; for(scanf("%lld",&a);a--;)
#define swap(a,b) a = a^b; b = a^b;a = a^b;
/*
 G[i] contains vector of pairs with first = weight
 and second = other node
*/
bool visited[SIZE];
uii dist[SIZE] ;
set< pair<uii,uii> > pq;
vector< pair<uii,uii> > G[SIZE];
void addEdge(uii a, uii b, uii w){
	G[a].push_back(make_pair(w,b));
	G[b].push_back(make_pair(w,a));
	return;
} 
void addDirectedEdge(uii a, uii b, uii w){
	G[a].push_back(make_pair(w,b));
	return;
}
void  dijsktra(uii a){
	pq.insert(make_pair(0,a));
	dist[a] = 0;
	vector< pair<uii,uii> > ::iterator it;
	while(!pq.empty()){
		pair<uii,uii> p = *(pq.begin());
		uii u = p.second;
		pq.erase(pq.begin());
		if(visited[p.second]) continue;
		visited[p.second] = true;
		for(it = G[p.second].begin();it!=G[p.second].end();it++){
			uii v = it->second;
			uii w = it->first;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.insert(make_pair(dist[v],v));
			}
		}
	}
	return;
}
void printGraph(uii N){
	vector< pair<uii,uii> > ::iterator it;
	for(uii i = 1;i<=N;i++){
		for(it= G[i].begin();it!=G[i].end();it++){
			cout<<i<<" ---> "<<it->second<<" W: "<<it->first<<endl;
		}
	}	 	
	return;

}
int main(){
     	/*Simple test */
	addEdge(1,4,10);
	addEdge(4,3,10);
	addEdge(3,2,2);
	addEdge(3,4,1);
	printGraph(4);
	for(uii i = 1;i<=4;i++){
		dist[i] = INF;
	}
   	dijsktra(1);
	for(uii i = 1;i<=4;i++){
		cout<<i<<" : "<<dist[i]<<endl;
	}
	cout<<endl;




	return 0;
}


