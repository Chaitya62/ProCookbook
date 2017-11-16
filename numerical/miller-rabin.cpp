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



// miller rabin
bool isPrime(ll n){
	ll k = 0, temp = n-1, m;
	ll a = 2; // can be any number
	while(temp%2 == 0){
		k++;
		temp/=2;
	}
	m = temp;
	ll T = (ll)(pow(a, m)) % n;
	if(T == 1 || T == -1 || T == n-1 ) return true;
	rep(i, 0, k-1){
		T = (T*T) %n;
		if(T == -1 || T == n-1) return true;
		if(T == 1) return false;
	}
	return false;
}



int solve(){
	if(isPrime(109)) cout<<"109 is a prime"<<endl;
	else cout<<"109 is not a prime"<<endl;
	return 0;
}


int main(){
  	solve();
	return 0;
}


