#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 998244353

int n;
int glasses[100][2];
vector<vector<vector<int>>> dp;

int main() {
	cin >> n;
	F0R(i, n) cin >> glasses[i][0] >> glasses[i][1];

	int ta = 0, tb = 0;
	F0R(i, n) {
		ta += glasses[i][0];
		tb += glasses[i][1];
	}
	dp.resize(n + 1, vector<vector<int>>(n + 1, vector<int>(ta + 1, -1)));

	dp[0][0][0] = 0;
	FOR(i, 1, n + 1) {
		F0R(k, i + 1) {
			F0R(A, ta + 1) {
				if (dp[i - 1][k][A] != -1) dp[i][k][A] = dp[i - 1][k][A];
				if (k > 0 && A >= glasses[i - 1][0] 
					&& dp[i - 1][k - 1][A - glasses[i - 1][0]] != -1) {
					dp[i][k][A] = max(dp[i][k][A],
						dp[i - 1][k - 1][A - glasses[i - 1][0]] + glasses[i - 1][1]);
				}
			}
		}
	}

	double pourwat = tb;
	pourwat /= 2;
	F0R(k, n) {
		double maxwat = 0;
		F0R(i, ta + 1) {
			double a = i;
			double newwat = dp[n][k + 1][i];
			if (newwat == -1) continue;
			newwat /= 2;
			double wat = min(a, pourwat + newwat);
			maxwat = max(maxwat, wat);
		}
		cout << maxwat << ' ';
	}
}