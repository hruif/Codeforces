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

#define MOD 998244353

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;
int a[200000];

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n) cin >> a[i];
		F0R(i, n) a[i]--;
		vi b(n, -1);
		vi last(n, -1);
		vb gifted(n, false);
		F0R(i, n) {
			if (gifted[a[i]]) {
				b[last[a[i]]] = -1;
			}
			b[i] = a[i];
			gifted[a[i]] = true;
			last[a[i]] = i;
		}
		set<int> need_gift;
		F0R(i, n) if (!gifted[i]) need_gift.insert(i);
		int last_gift = -1;
		/*for (int i = 0; i < n; i++) {
			if (b[i] == -1) {
				int to_gift = *(need_gift.begin());
				need_gift.erase(need_gift.begin());
				if (to_gift == i) {
					if (last_gift == -1) {
						if (i == 0) {
							if (need_gift.empty()) {
								b[i] = b[i + 1];
								b[i + 1] = i;
							}
							else {
								int tmp = to_gift;
								int to_gift = *(need_gift.begin());
								need_gift.erase(need_gift.begin());
								need_gift.insert(tmp);
								b[i] = to_gift;
							}
						}
						else {
							if (need_gift.empty()) {
								b[i] = b[i - 1];
								b[i - 1] = i;
							}
							else {
								int tmp = to_gift;
								int to_gift = *(need_gift.begin());
								need_gift.erase(need_gift.begin());
								need_gift.insert(tmp);
								b[i] = to_gift;
							}
						}
					}
					else {
						b[i] = to_gift;
						swap(b[i], b[last_gift]);
					}
				}
				else b[i] = to_gift;
				last_gift = i;
			}
		}*/
		F0R(i, n) {
			if (need_gift.empty()) break;
			if (b[i] == -1) {
				if (need_gift.find(i) != need_gift.end()) {
					int gift = *(need_gift.begin());
					need_gift.erase(need_gift.begin());
					if (gift == i) {
						if (need_gift.empty()) {
							int tmp = gift;
							gift = a[i];
							b[last[gift]] = tmp;
						}
						else {
							int tmp = gift;
							gift = *(need_gift.begin());
							need_gift.erase(need_gift.begin());
							need_gift.insert(tmp);
						}
					}
					b[i] = gift;
				}
			}
		}
		F0R(i, n) {
			if (b[i] == -1) {
				int gift = *(need_gift.begin());
				need_gift.erase(need_gift.begin());
				b[i] = gift;
			}
		}

		int cnt = 0;
		F0R(i, n) if (a[i] == b[i]) cnt++;
		cout << cnt << '\n';
		F0R(i, n) cout << b[i] + 1 << ' ';
		cout << '\n';
	}
}