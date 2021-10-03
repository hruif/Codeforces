#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <climits>

using namespace std;
using ll = long long;
using str = string;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using vstr = vector<string>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define sz(x) (int)(x.size())
#define rsz resize
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define pb push_back
#define eb emplace_back

#define lb lower_bound
#define ub upper_bound

// for loops
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, b) FOR(i, 0, b)
#define F1R(i, b) FOR(i, 1, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		int s2c = 0, s3c = 0;
		F0R(i, sz(s1)) {
			if (s1[i] != s2[i]) s2c++;
			if (s1[i] != s3[i]) s3c++;
		}
		string us = "NO";
		if (s2c <= n) us = s2;
		else if (s3c <= n) us = s3;
		else {
			int s23c = 0;
			F0R(i, sz(s1)) {
				if (s2[i] != s3[i]) s23c++;
			}
			if (s23c <= n) {
				s1 = s2;
				us = s3;
			}
		}
		if (us != "NO") {
			string s;
			F0R(i, sz(s1)) {
				if (s1[i] != us[i]) {
					s.push_back(s1[i]);
					s.push_back(us[i]);
				}
				else s.push_back(s1[i]);
			}
			cout << s << '\n';
		}
		else {
			string ans;
			bool found = false;
			string s[] = { s1, s2, s3 };
			F0R(i, 3) {
				F0R(j, 3) {
					if (i == j) continue;
					string cur = s[i] + s[j].substr(n, n);
					int p = 0;
					F0R(k, 2 * n) {
						if (p >= 3 * n) {
							p = -1;
							break;
						}
						while (p < 3 * n && cur[p] != s[j][k]) {
							p++;
						}
						p++;
					}
					if (p != -1) {
						ans = cur;
						found = true;
						break;
					}
					cur = s[j].substr(0, n) + s[i];
					p = 0;
					F0R(k, 2 * n) {
						if (p >= 3 * n) {
							p = -1;
							break;
						}
						while (p < 3 * n && cur[p] != s[j][k]) {
							p++;
						}
						p++;
					}
					if (p != -1) {
						ans = cur;
						found = true;
						break;
					}

				}
				if (found) break;
			}
			while (!found) {
				int a = 5;
			}
			cout << ans << '\n';
		}
	}
}