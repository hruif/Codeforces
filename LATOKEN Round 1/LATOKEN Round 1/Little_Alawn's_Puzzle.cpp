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
int a[2][400000];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) cin >> a[0][i];
		F0R(i, n) cin >> a[1][i];
		vector<vector<int>> places(2, vector<int>(n));
		F0R(i, n) {
			places[0][a[0][i] - 1] = i;
			places[1][a[1][i] - 1] = i;
		}
		vector<bool> visited(n, false);
		int cnt = 0;
		F0R(i, n) {
			if (visited[i]) continue;
			cnt++;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int i = q.front();
				q.pop();
				if (visited[i]) continue;

				visited[i] = true;
				q.push(places[0][a[1][i] - 1]);
				q.push(places[1][a[0][i] - 1]);
			}
		}

		ll ans = 1;
		F0R(i, cnt) {
			ans *= 2;
			ans %= 1000000007;
		}
		cout << ans << '\n';
	}
}