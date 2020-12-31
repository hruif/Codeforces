#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <unordered_set>

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

#define MOD 1 // placeholder

int n;
int nums[100000];
int ops[100000];
int zps[100000];
bool m, a, s;
int nsops;
int sops[100000];

int altarr[100000];
int prevs[100000];
ll dp[100000];
ll gp[100000][3];
ll gmults[100000];
void findops(int l, int r) {
	if (l > r) return;

	int l1s = 0;
	while (nums[l] == 1 && l < r) {
		l1s++;
		l++;
	}
	if (l == r) {
		FOR(i, l - l1s, r) {
			cout << nums[i] << '+';
		}
		cout << nums[r];
		return;
	}
	int r1s = 0;
	while (nums[r] == 1) {
		r1s++;
		r--;
	}

	if (l == r) {
		FOR(i, l - l1s, r + r1s) {
			cout << nums[i] << '+';
		}
		cout << 1;
		return;
	}

	F0R(i, l1s) {
		cout << 1 << '+';
	}

	ll ttl = 1;
	FOR(i, l, r + 1) {
		ttl *= nums[i];
		if (ttl >= 10000000000000000) {
			FOR(i, l, r) cout << nums[i] << '*';
			cout << nums[r];
			F0R(i, r1s) cout << "+1";
			return;
		}
	}

	int gps = 0;
	FOR(i, l, r + 1) {
		if (gps % 2 == 0) {
			gp[gps][0] = i;
			gp[gps][2] = 1;
			while (i < r + 1 && nums[i] > 1) {
				gp[gps][1] = i;
				gp[gps][2] *= nums[i++];
			}
		}
		else {
			gp[gps][0] = i;
			gp[gps][2] = 0;
			while (i < r + 1 && nums[i] == 1) {
				gp[gps][1] = i;
				gp[gps][2] += nums[i++];
			}
		}
		i--;
		gps++;
	}

	dp[0] = gp[0][2];
	FOR(i, 1, gps) {
		if (i % 2 == 0) dp[i] = dp[i - 1] * gp[i][2];
		else dp[i] = dp[i - 1];
	}
	memset(prevs, -1, sizeof(prevs));
	FOR(i, 1, gps) {
		if (dp[i - 1] + gp[i][2] > dp[i]) {
			dp[i] = dp[i - 1] + gp[i][2];
			prevs[i] = i - 1;
		}
		if (i % 2 == 0) {
			ll total = gp[i][2];
			FOR(j, i + 1, gps) {
				if (j % 2 == 0) total *= gp[j][2];
				if (total + dp[i - 1] > dp[j]) {
					dp[j] = total + dp[i - 1];
					prevs[j] = i - 1;
				}
			}
		}
	}

	int p = prevs[gps - 1];
	int nsops = 0;
	memset(sops, 0, sizeof(sops));
	while (p != -1) {
		sops[gp[p][1]] = 1;
		p = prevs[p];
	}
	F0R(i, gps - 1) {
		char c = i % 2 == 1 && sops[gp[i][1]] ? '+' : '*';
		FOR(j, gp[i][0], gp[i][1] + 1) {
			cout << nums[j];
			if (sops[j]) cout << '+';
			else cout << c;
		}
	}
	FOR(i, gp[gps - 1][0], gp[gps - 1][1]) {
		cout << nums[i] << '*';
	}
	cout << nums[r];

	F0R(i, r1s) cout << "+1";

	//int la = 0;
	//dp[0] = 0;
	//int dpp = 2;
	//dp[1] = nums[l];
	//cout << nums[l];
	//FOR(i, l + 1, r + 1) {
	//	int add = dp[dpp - 1] + nums[i];
	//	int mult = (dp[dpp - 1] - dp[la]) * nums[i] + dp[la];
	//	if (add > mult) {
	//		dp[dpp] = add;
	//		la = dpp - 1;
	//		cout << '+';
	//	}
	//	else {
	//		dp[dpp] = mult;
	//		cout << '*';
	//	}
	//	dpp++;
	//	cout << nums[i];
	//}

	//F0R(i, r1s) {
	//	cout << '+' << 1;
	//}
}

int main() {
	cin >> n;
	F0R(i, n) cin >> nums[i];
	
	string usable;
	cin >> usable;
	F0R(i, usable.size()) {
		switch (usable[i]) {
		case '*':
			m = true;
			break;
		case '+':
			a = true;
			break;
		case '-':
			s = true;
			break;
		}
	}
	
	if (!m) {
		char c;
		if (a) c = '+';
		else c = '-';

		F0R(i, n - 1) cout << nums[i] << c;
		cout << nums[n - 1] << '\n';
	}
	else {
		if (!a) {
			if (s) {
				if (nums[0] != 0) {
					int p = 0;
					while (p < n - 1 && nums[p + 1] != 0) {
						cout << nums[p++] << '*';
					}
					if (p == n - 1) {
						cout << nums[p] << '\n';
					}
					else {
						cout << nums[p++] << '-';
						while (p < n - 1) cout << nums[p++] << '*';
						cout << nums[p] << '\n';
					}
				}
				else {
					F0R(i, n - 1) {
						cout << nums[i] << '*';
					}
					cout << nums[n - 1];
				}
			}
			else {
				F0R(i, n - 1) cout << nums[i] << '*';
				cout << nums[n - 1];
			}
		}
		else {
			int zs = 0;
			F0R(i, n) {
				if (nums[i] == 0) {
					zps[zs] = i;
					zs++;
				}
			}

			int prev = 0;
			F0R(i, zs) {
				findops(prev, zps[i] - 1);
				prev = zps[i] + 1;
				if (zps[i] != 0 && nums[zps[i] - 1] != 0) cout << '+';
				cout << "0";
				if (prev != n) cout << '+';
			}
			findops(prev, n - 1);
		}
	}
	cout << '\n';
}