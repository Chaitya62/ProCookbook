/***************************************************
 * Author: vazzup
 * Date: 03/12/16 (DD/MM/YY)
 * Program to calculate Combinations of Large numbers, modulo M
 * Calculates Fact(i) for each value, and inverse factorial ifact(i) for each number
 * Uses formula nCr = fact(n) / (fact(r) * fact(n - r))
 * Uses property (a / b) (mod M) = (a mod M) * (b^-1 mod M)
 * M is the modulo value; Preferably a prime number to ensure an inverse fact exists for all numbers
 * N is number until which one desires to precalculate
 * Precomputation is O(n)
 * Calculation of nCr is O(1)
 **************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007LL
#define N 100005	//Number until which you want to precompute
#define ll long long	//For ease of use

using namespace std;

//Global Variables
vector <ll> fact(N);
vector <ll> ifact(N);

//Function decalrations
ll modPow(ll a, ll b);
void init();
ll nCr(const ll& n, const ll& r);

int main(int argc, char** argv) {
	init();
	ll n, r;
	cout << "Enter the values of n and r\n";
	cin >> n >> r;
	cout << "The answer is " <<  nCr(n, r) <<"\n";
	return 0;
}

ll modPow(ll a, ll b) {
	/********
	 Function to calculate a^b (mod M)
	*********/
	ll ans = 1;
	while(b) {
		if(b & 1) {
			ans *= a;
			if(ans > MOD) {
				ans%=MOD;
			}
		}
		a *= a;
		if(a > MOD) {
			a%=MOD;
		}
		b >>= 1;
	}
	return ans;
}

void init() {
	/********
	 Function to precompute fact and ifact values
	 fact[i] represents factorial of i (mod M)
	 ifact[i] represents modular inverse of fact[i] (mod M)
	*********/
	fact[0]=1;
	for(int i=1; i<N; i++) {
		fact[i] = fact[i-1] * i;
		if(fact[i] > MOD) {
			fact[i] %= MOD;
		}
	}

	ifact[N-1] = modPow(fact[N-1], MOD-2);	//Euler's Theorem, a^-1 = a^M-2 (mod M)

	for(int i = N-2; i>=0; i--) {
		ifact[i] = (i+1) * ifact[i+1];
		if(ifact[i] > MOD) {
			ifact[i] %= MOD;
		}
	}
}

ll nCr(const ll& n, const ll& r) {
	/*********
	 Uses formula nCr = fact(n) / (fact(r) * fact(n - r))
	 Uses property (a / b) (mod M) = (a mod M) * (b^-1 mod M)
	*********/
	ll ans  = 1;
	ans *= fact[n];
	ans *= ifact[r];
	if(ans > MOD) {
		ans %= MOD;
	}
	ans *= ifact[n-r];
	if(ans > MOD) {
		ans %= MOD;
	}
	return ans;
}

