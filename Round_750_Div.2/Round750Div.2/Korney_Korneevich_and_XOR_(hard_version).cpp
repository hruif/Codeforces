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

#define MOD (ll)(1e9 + 7)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#ifndef ONLINE_JUDGE
ifstream fin("input.txt");
ofstream fout("output.txt");
#else
#define fin cin
#define fout cout
#endif


const int maxn = (1 << 13);

int n;
bool vals[maxn][maxn];
bool ansv[maxn];
vector<int> g[maxn], used[maxn];
set<int> ans;
int a[1000000];

int main() {
	fast_cin();
	memset(vals, false, sizeof(vals));

	fin >> n;

	ans.insert(0);
	for (int i = 0; i < maxn; i++) g[i].push_back(0);
	int maxa = 0;
	F0R(i, n) fin >> a[i];
	F0R(i, n) maxa = max(maxa, a[i]);
	F0R(i, maxn) vals[i][0] = true;
	ll cnt = 0;
	F0R(i, n) {
		int ai = a[i];
		int gais = sz(g[ai]);
		for (int k = 0; k < gais; k++) {
			int v = ai ^ g[ai][k];
			for (int j = ai + 1; j < maxa + 1; j++) {
				if (vals[j][v]) break;
				vals[j][v] = true;
				g[j].push_back(v);
				cnt++;
			}
			if (!ansv[v]) {
				ans.insert(v);
				ansv[v] = true;
			}
		}
		if (!g[ai].empty()) g[ai].clear();
	}

	fout << ans.size() << '\n';
	for (auto x : ans) fout << x << ' ';
	fout << '\n';
}