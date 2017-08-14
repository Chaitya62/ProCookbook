#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<set>
#include<queue>
#include<stack>
using namespace std;
#define uii long long int
#define it(a)  ::iterator a
#define slld(a) uii a;scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define plld(a) printf("%lld",a)
#define MAX 10000
#define MOD 1000000007
#define SIZE 100000
#define powOf2(a) !(a&a-1)
#define mod(a) (a>0 ? a : (-1*a))
#define tc(a) uii a; for(scanf("%lld",&a);a--;)
#define swap(a,b) a = a^b; b = a^b;a = a^b;
/*
 G[i] contains vector of pairs with first = weight
 and second = other node
*/
bool visited[SIZE];
queue< pair<uii,uii> > q;
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
void  bfs(uii a){
	q.push(make_pair(0,a));
	vector< pair<uii,uii> > ::iterator it;
	while(!q.empty()){
		pair<uii,uii> p = q.front();
		q.pop();
		//cout<<p.second<<endl;
		if(visited[p.second]) continue;
		visited[p.second] = true;
		for(it = G[p.second].begin();it!=G[p.second].end();it++){
			if(!visited[it->second]) q.push((*it));
		}

		cout<<" "<<p.second<<" ";
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
   	cout<<"BFS :";
	bfs(1);
	cout<<endl;




	return 0;
}


