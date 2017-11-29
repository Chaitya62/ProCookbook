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

// naive Algorithm
int prepareZArray(vector<ll> &za, string s){
	ll len = s.size();
	for(ll i = 1;i<len;i++){
		ll cnt = 0, j = 0, k = i;
		while(s[k++] == s[j++]) cnt++;
		za[i] = cnt;
	}
	return 0;
}


// L, R method

int prepZArray(vector<ll> &za, string s){
	ll len = s.size();
	ll l = 0,r=0;
	za[0] = 1;
	for(ll i = 1;i<len;i++){
		if(i > r){
			l = r = i;
			while( r<len && s[r-l] == s[r]) r++;
			r--;
			za[i] = r-l+1;
		}else{
			ll k = i-l;
			if(s[k]<r-i+1){
				za[i] = za[k];	
			}else{
				l = i;
				while(r<len && s[r-l] == s[r]) r++;
				za[i] = r-l;
				r--;
			}
		}
	}

}

int solve(){
	vector<ll> za(1000);
	string text = "This is a test";
	string pattern = "test";
	string f = pattern+"|"+text;
	prepZArray(za, f);
	for(ll i = 0;i<f.size();i++){
		if(za[i] == pattern.size()) cout<<endl<<"Found it at "<<i-pattern.size()-1<<endl;
	}
	cout<<endl;

	return 0;
}


int main(){
  	solve();
	return 0;
}


