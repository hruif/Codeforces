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
#define F1R(i, b) FOR(i, 1, b);
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
map<pair<string, string>, int> append_cnts;
map<string, ll> cnts;
map<string, string> var_vals;

int main() {
	cin >> t;
	while (t--) {
		append_cnts.clear();
		cnts.clear();
		var_vals.clear();

		int n;
		cin >> n;
		F0R(i, n) {
			string var;
			cin >> var;
			char o;
			cin >> o;
			string new_string;
			if (o == ':') {
				cin >> o;
				cin >> new_string;

				var_vals[var] = new_string;
				int cnt = 0;
				bool ha = false;
				for (int i = 0; i < new_string.size() - 1; i++) {
					if (new_string.substr(i, 2) == "ha") {
						if (ha) cnt++;
						ha = true;
						i++;
					}
					else ha = false;
				}
				cnts[var] = cnt;
				//for (auto v : var_vals) {
				//	string appended = new_string + v.second;
				//	int cnt = 0;
				//	bool ha = false;
				//	for (int i = max(0, sz(new_string) - 3); i < min(sz(new_string) + 2, sz(appended) - 1); i++) {
				//		if (appended.substr(i, 2) == "ha") {
				//			if (ha) cnt++;
				//			ha = true;
				//			i++;
				//		}
				//		else ha = false;
				//	}
				//	append_cnts[{ var, v.first }] = cnt;

				//	appended = v.second + new_string;
				//	cnt = 0;
				//	ha = false;
				//	for (int i = max(0, sz(v.second) - 3); i < min(sz(v.second) + 2, sz(appended) - 1); i++) {
				//		if (appended.substr(i, 2) == "ha") {
				//			if (ha) cnt++;
				//			ha = true;
				//			i++;
				//		}
				//		else ha = false;
				//	}
				//	append_cnts[{ v.first, var }] = cnt;
				//}
			}
			else {
				string s1, s2;
				char p;
				cin >> s1 >> p >> s2;
				new_string = var_vals[s1].substr(0, max((int)(sz(var_vals[s1])), 4)) + var_vals[s2].substr(max(0, (int)(sz(var_vals[s2])) - 4));

				var_vals[var] = new_string;
				ll init_cnt = cnts[s1] + cnts[s2] + append_cnts[{ s1, s2 }];
				cnts[var] = init_cnt;
			}
			for (auto v : var_vals) {
				string appended = new_string + v.second;
				int cnt = 0;
				bool ha = false;
				for (int i = max(0, sz(new_string) - 3); i < min(sz(new_string) + 2, sz(appended) - 1); i++) {
					if (appended.substr(i, 2) == "ha") {
						if (ha) cnt++;
						ha = true;
						i++;
					}
					else ha = false;
				}
				append_cnts[{ var, v.first }] = cnt;

				appended = v.second + new_string;
				cnt = 0;
				ha = false;
				for (int i = max(sz(v.second) - 3, 0); i < min(sz(v.second) + 2, sz(appended) - 1); i++) {
					if (appended.substr(i, 2) == "ha") {
						if (ha) cnt++;
						ha = true;
						i++;
					}
					else ha = false;
				}
				append_cnts[{ v.first, var }] = cnt;
			}
			if (i == n - 1) cout << cnts[var] << '\n';
		}
	}
}