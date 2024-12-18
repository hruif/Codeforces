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
#define F0R(i, b) FOR(i, 0, b)
#define F1R(i, b) FOR(i, 1, b);
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
queue<int> q;
map<pii, int> rookplaces;
set<int> ss;

int main() {
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int r = 1;
		vi rows(n, 0), cols(n, 0);
		vpii rooks;
		F0R(i, m) {
			int x, y;
			cin >> x >> y;
			rookplaces[{ x - 1, y - 1 }] = r;
			rows[x - 1] = r;
			cols[y - 1] = r;
			rooks.push_back({ x - 1, y - 1 });
			r++;
		}
		int cnt = m;
		int cop = 0;
		vector<bool> checked(m, false);
		for (auto i : rookplaces) {
			if (true) {
				if (i.first.first == i.first.second) {
					checked[i.second - 1] = true;
					cnt--;
				}
				else {
					if (checked[i.second - 1]) continue;
					q.push(i.second - 1);
					int times = 0;
					while (!q.empty()) {
						int cur = q.front();
						q.pop();
						if (cur == -1) continue;
						if (ss.find(cur) != ss.end()) {
							cnt++;
							break;
						}
						ss.insert(cur);
						checked[cur] = true;
						if (cols[rooks[cur].first] - 1 == -1) continue;
						if (ss.find(cols[rooks[cur].first] - 1) != ss.end()) {
							cnt++;
							break;
						}
						q.push(cols[rooks[cur].first] - 1);
					}
					if (times > 1) cnt++;
					ss.clear();
				}
			}
		}
		cnt += cop / 2;
		cout << cnt << '\n';
		rookplaces.clear();
	}
}