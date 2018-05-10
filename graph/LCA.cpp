// For visual studio 
#define  _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

#define ll long long

using namespace std;

vector<ll> Tree[1001];
ll depth[2000];
ll pa[1000][20];


ll LCA(ll a, ll b) {
	if (depth[a] < depth[b]) {
		ll temp = a;
		a = b;
		b = temp;
	}

	ll diff = depth[a] - depth[b];


	// bring both nodes at equal level
	for (ll i = 0; i < 20; i++) {
		if (diff >> i & 1) a = pa[a][i];
	}


	// if equal we found the LCA
	if (a == b) return a;


	// jump to the level just before they become equal
	for (ll i = 20 - 1; i >= 0; i--) {
		if (pa[a][i] != pa[b][i]) {
			a = pa[a][i];
			b = pa[b][i];
		}
	}

	// return LCA 
	return pa[a][0];

}

void dfs(ll next, ll prev, ll d) {
	pa[next][0] = prev;
	depth[next] = d;

	for (ll v : Tree[next]) {
		if (v != prev) {
			dfs(v, next, d + 1);
		}
	}
	return;


}

void addEdge(ll a, ll b) {
	
	Tree[a].push_back(b);
	Tree[b].push_back(a);

	return;

}

int main() {
	
	ll n = 10;


	// create tree
	addEdge(8, 2);
	addEdge(2, 3);
	addEdge(2, 4);
	addEdge(3, 5);
	addEdge(3, 6);
	addEdge(1, 7);
	addEdge(7, 8);
	addEdge(8, 9);
	addEdge(7, 10);


	// dfs to update depth and pre-compute parent at height 1 or 2^0
	dfs(1, -1, 0);


	// check
	for (ll i = 1; i <= n; i++) cout << depth[i] << " ";
	cout << endl;

	// check
	for (ll i = 1; i <= n; i++) cout << pa[i][0] << " ";
	cout << endl;


	// DP for parents at powers of 2
	for (ll i = 1; i < 13; i++) {
		for (ll j = 1; j <= n; j++) {
			if (pa[j][i - 1] != -1)
				pa[j][i] = pa[pa[j][i - 1]][i - 1];
		}
		cout << endl;
	}

	ll a, b;
	a = 10;
	b = 6;
	cout<<"LCA of "<<a<<" and "<<b<<" is : " << LCA(a, b)<<endl;



	return 0;
}
