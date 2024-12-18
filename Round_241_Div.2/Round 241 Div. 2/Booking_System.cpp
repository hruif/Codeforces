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
#define F0R(i,b) FOR(i, 0, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, k;
vector<pair<pii, int>> visitors;
vpii tables;

bool compareVis(const pair<pii, int>&a, const pair<pii, int>&b) {
	return a.first.second < b.first.second;
}

bool compss(const int& a, const pair<pii, int>& b) {
	return a < b.first.first;
}

int main() {
	cin >> n;
	visitors.rsz(n);
	F0R(i, n) {
		cin >> visitors[i].first.first >> visitors[i].first.second;
		visitors[i].second = i + 1;
	}
	cin >> k;
	tables.rsz(k);
	F0R(i, k) {
		cin >> tables[i].first;
		tables[i].second = i;
	}
	
	sort(all(tables));
	sort(all(visitors));
	vpii ans;
	ll cost = 0;
	F0R(i, k) {
		auto big = ub(visitors.begin(), visitors.end(), tables[i].first, compss);
		if (big == visitors.bg()) continue;
		sort(visitors.bg(), big, compareVis);
		cost += (*(big - 1)).first.second;
		ans.push_back({ (*(big - 1)).second, tables[i].second + 1 });
		visitors.erase(big - 1);
	}
	cout << sz(ans) << ' ' << cost << '\n';
	F0R(i, sz(ans)) cout << ans[i].first << ' ' << ans[i].second << '\n';
}