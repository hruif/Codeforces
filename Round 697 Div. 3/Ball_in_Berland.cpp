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
map<pii, int> paircnt;
vector<ll> ttlpairs[2];
vector<vi> pwith;

int main() {
	cin >> t;
	while (t--) {
		ttlpairs[0].clear(); ttlpairs[1].clear();
		paircnt.clear();
		pwith.clear();

		int a, b, k;
		cin >> a >> b >> k;
		ttlpairs[0].resize(a), ttlpairs[1].resize(b);
		pwith.resize(a);
		F0R(i, k) {
			cin >> pairs[i][0]; pairs[i][0]--;
		}
		F0R(i, k) {
			cin >> pairs[i][1]; pairs[i][1]--;
			pwith[pairs[i][0]].push_back(pairs[i][1]);
		}
		F0R(i, k) paircnt[{ pairs[i][0], pairs[i][1] }]++;

		F0R(i, k) {
			ttlpairs[0][pairs[i][0]]++;
			ttlpairs[1][pairs[i][1]]++;
		}

		ll ttlcnt = 0;
		F0R(i, a) {
			ll cnt1 = ttlpairs[0][i];
			F0R(j, pwith[i].size()) {
				ll cnt2 = ttlpairs[1][pwith[i][j]];
				ttlcnt += k - cnt1 - cnt2 + paircnt[{ i, pwith[i][j] }];
			}
		}
		cout << ttlcnt / 2 << '\n';
	}
}