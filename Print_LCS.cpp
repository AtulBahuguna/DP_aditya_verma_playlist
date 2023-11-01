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


void solve() {

	string a, b; cin >> a >> b;
	int n = a.length();
	int m = b.length();

	int dp[n + 1][m + 1];
	rep(i, 0, n + 1) {
		rep(j, 0, m + 1) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
		}
	}
	rep(i, 1, n + 1) {
		rep(j, 1, m + 1) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	string ans = "";
	int i = n , j = m ;
	while (i > 0 && j > 0) {
		if (a[i - 1] == b[j - 1]) {
			ans += a[i - 1];
			i--, j--;
		} else if (dp[i][j - 1] > dp[i - 1][j]) {
			j--;
		} else {
			i--;
		}
	}
	// cout << ans << endl;
	reverse(ans.begin(), ans.end());
	cout << ans << endl;

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