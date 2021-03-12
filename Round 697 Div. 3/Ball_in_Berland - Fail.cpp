#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
int pairs[200000][2];
vector<vector<int>> inpairs[2];
map<pii, int> paircnt;
vector<int> ttlpairs[2];

int main() {
	cin >> t;
	while (t--) {
		ttlpairs[0].clear(); ttlpairs[1].clear();
		inpairs[0].clear(); inpairs[1].clear();
		paircnt.clear();

		int a, b, k;
		cin >> a >> b >> k;
		inpairs[0].resize(a); inpairs[1].resize(b);
		F0R(i, k) {
			cin >> pairs[i][0]; pairs[i][0]--;
			inpairs[0][pairs[i][0]].push_back(i);
		}
		F0R(i, k) {
			cin >> pairs[i][1]; pairs[i][1]--;
			inpairs[1][pairs[i][1]].push_back(i);
		}
		F0R(i, k) paircnt[{ pairs[i][0], pairs[i][1] }]++;

		F0R(i, a) {
			int cnt = 0;
			F0R(j, inpairs[0][i].size()) {
				cnt += paircnt[{ i, pairs[inpairs[0][i][j]][1] }];
			}
			ttlpairs[0].push_back(cnt);
		}
		F0R(i, b) {
			int cnt = 0;
			F0R(j, inpairs[1][i].size()) {
				cnt += paircnt[{ pairs[inpairs[1][i][j]][0], i }];
			}
			ttlpairs[1].push_back(cnt);
		}

		int ttlcnt = 0;
		F0R(i, a) {
			int cnt1 = ttlpairs[0][i];
			F0R(j, b) {
				if (paircnt[{ i, j }] == 0) continue;
				int cnt2 = ttlpairs[1][j];
				ttlcnt += k - cnt1 - cnt2 + paircnt[{ i, j }];
			}
		}
		cout << ttlcnt / 2 << '\n';
	}
}