// for visual studio
#define  _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS



#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

#define ll long long

using namespace std;

vector< pair<ll, ll> > Tree[1001];
ll depth[2000];
ll pa[1000][20];
ll subsize[2000];
ll chainHead[2000], indexInBase[2000], chainInd[2000];
ll baseArray[6000];


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
	subsize[next] = 1;


	for (pair<ll, ll> p : Tree[next]) {
		ll v = p.first;
		if (v != prev) {
			dfs(v, next, d + 1);
			subsize[next] += subsize[v];
		}
	}



	return;


}

ll query_up(ll a, ll b) {
	if (a == b) return 0;

	ll achain, bchain = chainInd[b];

	ll ans = -1;

	while (1) {
	
		achain = chainInd[a];

		// both nodes are in the same chain
		if (achain == bchain) {
			if (a == b) break;
			// query_dummy(u, v)
			// here you query the datastructure you have build on the chains

			// update ans

			break;
		}

		// if not in the same chain, go to the  chain head

		// query_dummy(u, chainHead[u]);
		// here you query the datastructure you have build on the chain to go upto chainHead


		// update ans 

		// change the chain
		a = chainHead[a];
		a = pa[a][0]; // this step changes the chain 

	}

	return ans;

}

void query_hld(ll a, ll b) {
	// divide into two parts
	ll lca = LCA(a, b);
	

	// query a->lca and b->lca
	ll x = query_up(a, lca);
	ll y = query_up(b, lca);



}

void HLD(ll curr, ll &chainNo, ll &ptr, ll cost, ll prev) {
	//cout<<"here"<<endl;
	// return;
	if (chainHead[chainNo] == -1) {
		chainHead[chainNo] = curr;
	}

	chainInd[curr] = chainNo;
	indexInBase[curr] = ptr;
	// enter the quantity here you want to associate with the array
	baseArray[ptr++] = cost;


	int sc = -1, ncost;

	for (pair<ll, ll> p : Tree[curr]) {
		ll v = p.first;
		ll cst = p.second;
		if (prev == v) continue;
		if (sc == -1 || subsize[sc] < subsize[v]) {
			sc = v;
			ncost = cst;
		}
	}

	// cout<<"special Child : "<<sc<<endl;
	if (sc != -1LL) {
		HLD(sc, chainNo, ptr, ncost, curr);
	}

	for (pair<ll, ll> p : Tree[curr]) {

		ll v = p.first;
		ll cst = p.second;

		if (prev == v) continue;
		if (v != sc) {
			chainNo++;
			HLD(v, chainNo, ptr, cst, curr);
		}
	}
	cout << "chainNo: " << chainNo << endl;
	return;

}

void addEdge(ll a, ll b, ll cost) {

	Tree[a].push_back(make_pair(b, cost));
	Tree[b].push_back(make_pair(a, cost));

	return;

}

int main() {

	ll n = 17;


	// create tree
	addEdge(8, 2, 1);
	addEdge(2, 3, 2);
	addEdge(2, 4, 3);
	addEdge(3, 5, 5);
	addEdge(3, 6, 1);
	addEdge(1, 7, 4);
	addEdge(7, 8, 12);
	addEdge(8, 9, 10);
	addEdge(7, 10, 11);
	addEdge(1, 11, 12);
	addEdge(11, 12, 23);
	addEdge(11, 13, 123);
	addEdge(12, 14, 122);
	addEdge(12, 15, 153);
	addEdge(15, 16, 12);
	addEdge(15, 17, 1231);


	/*

	Above Tree
	Special children marked with *


                    1
                /        \
              11          7*
            /    \      /  \
           12*   13    10   8*
         /    \            / \
        14     15*        2*  9
       /  \              / \
      16* 17            3*  4
                       / \
                      5*  6
	*/


	// dfs to update depth and pre-compute parent at height 1 or 2^0
	dfs(1, -1, 0);


	// check
	for (ll i = 1; i <= n; i++) cout << depth[i] << " ";
	cout << endl;

	// check
	for (ll i = 1; i <= n; i++) cout << pa[i][0] << " ";
	cout << endl;

	//cout<<"here"<<endl;

	// DP for parents at powers of 2
	for (ll i = 1; i < 13; i++) {
		for (ll j = 1; j <= n; j++) {
			if (pa[j][i - 1] != -1)
				pa[j][i] = pa[pa[j][i - 1]][i - 1];
			//cout<<"here"<<endl;
		}
		//	cout << endl;
	}

	ll a, b;
	a = 10;
	b = 6;
	//cout<<"LCA of "<<a<<" and "<<b<<" is : " << LCA(a, b)<<endl;

	//cout<<"idhar "<<endl;
	ll ptr = 0;
	ll chainNo = 0;
	HLD(1, chainNo, ptr, 0, -1);

	for (ll i = 0; i < ptr; i++) {
		cout << baseArray[i] << " ";
	}
	cout << endl;

	for (ll i = 1; i <= n; i++) {
		cout << chainInd[i] << " ";
	}
	cout << endl;
	

	return 0;
}
