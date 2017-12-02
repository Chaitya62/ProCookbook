#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits> 
using namespace std;
#define ll long long int
#define it(a)  ::iterator a
#define sd(a) double a;scanf("%lf",&a);
#define slld(a) ll a;scanf("%lld",&a)
#define plld(a) printf("%lld",a)
#define INF LLONG_MAX
#define all(a) a.begin(), a.end()
#define notIn(M,a) M.find(a) == M.end()
#define MOD 1000000007
#define powOf2(a) !(a&a-1)
#define tc(a) ll a; for(scanf("%lld",&a);a--;)
#define repd(i,a,n) for(ll i = n-1;i>=a;i--)
#define rep(i,a,n) for(ll i = a;i<n;i++)
#define toLower(s, len) rep(i, 0, len) s[i] = (s[i]>='A' && s[i]<='Z' ? s[i]-'A'+'a' : s[i]); 
#define toUpper(s, len) rep(i, 0, len) s[i] = (s[i]>='a' && s[i]<='z' ? s[i]-'a'+'A' : s[i]);
#define set(n,x) x |= (1 << n)
#define unset(n,x) x &= ~(1<<n)
#define check(n,x) (x & 1 << n) != 0
#define ppi pair<ll, pair<ll, ll> >
 
ll inv = 0;
vector<ll> B;
	
 
int merge(ll start, ll mid, ll end, vector<ll> &V){
	//cout<<"start : "<<start<<" mid : "<<mid<<" end: "<<end<<endl;	
 
	for(ll i = start;i<=end;i++){
		B[i] = V[i];
	}
	ll i = start,j = mid+1, k = start;
	while(k <= end){
		//cout<<" i : "<<i<<" j : "<<j<<" k : "<<k<<endl;
		if(i > mid) V[k++] = B[j++];
		else if(j > end) V[k++] = B[i++];
		else if(B[i] > B[j]){
			V[k++] = B[j++];
			inv += ((mid-i+1));
		}
		else V[k++] = B[i++];
	}
 
	return 0;
}
 
int mergesort(ll start, ll end, vector<ll> &V){
	if(start == end) return 0;
	//cout<<"start :"<<start<<" end : "<<end<<endl;
	ll mid = (start+end)/2;
	mergesort(start, mid, V);
	mergesort(mid+1, end, V);
	merge(start, mid, end, V);
	return 0;
}
 
 
 
int solve(){
		slld(n);
		vector<ll> V;
		rep(i, 0, n){
			slld(temp);
			V.push_back(temp);
		}
		inv = 0;
		rep(i, 0, n+1) B.push_back(0);
		mergesort(0, n-1, V);
		//for(ll i = 0;i<n;i++) cout<<V[i]<<" ";
		//cout<<endl;
		printf("%lld\n", inv);
		
 
	return 0;
}
 
 
int main(){
  	solve();
	return 0;
}
 
 