/*Adjacency list graph implementation */
#include<iostream>
#include<vector>
using namespace std;
vector< vector<int> > G;
vector<int> ::iterator it;
//initializing the graph
int initializeGraph(int V){
     vector<int> a ;
    for(int i=0;i<V;i++){
        G.push_back(a);
    }
    return 0;
}

//connect two vertices
int connect(int a, int b){
    G[a-1].push_back(b);
    G[b-1].push_back(a);
    return 0;
}


int main(){
    int V=5;  //number of vertices
    initializeGraph(V);
    int a,b;
    int E;
    cin>>E;
    for(int i=0;i<E;i++){
        cin>>a>>b;
        connect(a,b);
    }
    //prints the adjacency list
    for(int i=0;i<V;i++){
        for(it=G[i].begin();it!=G[i].end();it++){
            cout<<*it;
        }
        cout<<endl;
    }
    return 0;
}
