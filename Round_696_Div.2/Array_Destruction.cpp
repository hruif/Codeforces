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
int a[2000];
vi inds[1000001];
bool visited[2000];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n * 2) {
			cin >> a[i];
			inds[a[i]].push_back(i);
		}
		sort(a, a + n * 2);
		vpii ans(n);
		int ansn = 0;

		bool throwable = false;
		for (int i = n * 2 - 2; i >= 0; i--) {
			vi vd;
			ansn = 0;
			memset(visited, false, sizeof(visited));
			visited[n * 2 - 1] = true;
			visited[i] = true;
			vd.push_back(n * 2 - 1); vd.push_back(i);
			ans[ansn++] = make_pair(a[n * 2 - 1], a[i]);
			int x = a[n * 2 - 1];
			for (int j = n * 2 - 1; j >= 0; j--) {
				while (j >= 0 && visited[j]) j--;
				if (j < 0) {
					throwable = true;
					break;
				}
				bool nothrow = true;
				for (int k = 0; k < inds[x - a[j]].size(); k++) {
					int p = inds[x - a[j]][k];
					nothrow = false;
					if (!visited[p] && j != p) {
						visited[j] = true;
						visited[p] = true;
						vd.push_back(j); vd.push_back(p);
						ans[ansn++] = make_pair(a[j], a[p]);
						x = a[j];
						break;
					}
				}
				if (nothrow) break;
			}
			F0R(i, vd.size()) visited[vd[i]] = false;
			if (throwable) break;
		}
		if (throwable) {
			cout << "YES\n";
			cout << ans[0].first + ans[0].second << '\n';
			for (int i = 0; i < ansn; i++) {
				cout << ans[i].first << ' ' << ans[i].second << '\n';
			}
		}
		else cout << "NO" << '\n';
		F0R(i, n * 2) inds[a[i]].clear();
	}
}