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

int helper(string a, string b, int n, int m) {

	// using recursion only
	if (n == 0 || m == 0) {
		return 0;
	}
	if (a[n - 1] == b[m - 1]) {
		return 1 + helper(a, b, n - 1, m - 1);
	}
	return max(helper(a, b, n - 1, m), helper(a, b, n, m - 1));

}

//using top down (memoization)
int dp[100][100];
int nice(string a, string b, int n, int m) {
	if (n == 0 || m == 0) {
		return 0;
	}
	if (dp[n][m] != -1) {
		return dp[n][m];
	}

	if (a[n - 1] == b[m - 1]) {
		return dp[n][m] = 1 + nice(a, b, n - 1, m - 1);
	}
	return dp[n][m] = max(nice(a, b, n - 1, m), nice(a, b, n, m - 1));


}

// using bottom up
int wow(string a, string b, int n, int m) {
	int magic[n + 1][m + 1];
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m + 1; j++) {
			if (i == 0 || j == 0) {
				magic[i][j] = 0;
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (a[i - 1] == b[j - 1]) {
				magic[i][j] = 1 + magic[i - 1][j - 1];
			} else {
				magic[i][j] = max(magic[i - 1][j], magic[i][j - 1]);
			}
			// }
		}
	}
	return magic[n][m];

}

void solve() {

	string a, b; cin >> a >> b;
	memset(dp, -1, sizeof(dp));
	cout << helper(a, b, a.size(), b.size()) << endl;
	cout << nice(a, b, a.size(), b.size()) << endl;
	cout << wow(a, b, a.size(), b.size()) << endl;

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