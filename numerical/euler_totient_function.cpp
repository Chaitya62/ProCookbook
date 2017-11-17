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

bool isPrime(ll n){
	for(ll i = 2;i*i<=n;i++){
			if(n%i == 0) return false;
	}
	return true;
}



ll phi(ll n){
	if(isPrime(n)) return n-1;
	else{
		map<ll, ll> factors;
		ll temp = n;
		for(ll i = 2;i*i<n;i++){
			while( temp>0 && temp%i == 0){
				temp/=i;
				if(notIn(factors, i)) factors[i]  = 1;
				else factors[i]++;
			}
		}
		if(temp > 1) factors[temp] = 1;
		ll ans = 1;
		for(pair<ll, ll> p : factors){
			ans *= (pow(p.first, p.second-1)*(p.first-1));
		}
		return ans;

	}

}


int solve(){
	slld(n);
	cout<<phi(n)<<endl;
	return 0;
}


int main(){
  	solve();
	return 0;
}

