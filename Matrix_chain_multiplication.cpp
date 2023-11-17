/*

user: Atul Bahuguna

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i,st,en) for(ll i=st;i<en;i++)
#define F first
#define S second
#define vi vector<ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

/*****************************GCD function***********************/

int gcd(int a, int b) {

	if (a == 0) {
		return b;
	}

	// make sure always pass abs(a) and abs(b);

	return gcd(b, a % b);
}


ll power(ll base, ll n) {
	ll res = 1;
	while (n) {
		if (n % 2 == 1) {
			res = res * base;
			n--;
		}
		base = base * base;
		n /= 2;
	}

	return res;
}

bool is_prime[10000001];

void sieve() {

	ll maxN = 10000000;

	for (ll i = 1; i <= maxN; i++) {
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;

	for (ll i = 2; i * i <= maxN; i++) {
		if (is_prime[i]) {
			for (ll j = i * i; j <= maxN; j += i) {
				is_prime[j] = false;
			}
		}
	}


}


/*******************************Main function Program*******************/

ll dp[1001][1001];
ll helper(vector<ll>&arr, ll i, ll j) {
	if (i >= j) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	ll res = INT_MAX;
	for (ll k = i; k <= j - 1; k++) {
		ll temp = helper(arr, i, k) + helper(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
		res = min(res, temp);
	}
	return dp[i][j] = res;
}
void solve() {


	ll n; cin >> n;
	vi arr(n);
	rep(i, 0, n)cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	cout << helper(arr, 1, n - 1) << endl;


}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

	ios::sync_with_stdio(false); cin.tie(NULL);
	sieve();
	ll T;
	cin >> T;
	while (T--) {
		solve();

	}
	return 0;
}