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

int t;

int main() {
	cin >> t;
	while (t--) {
		int s, n;
		cin >> s >> n;
		int ts = s;
		int cnt = 0;
		multiset<int> ans;
		int tens = 1;
		while (cnt < n) {
			while (ts > 0 && ts % 10 == 0) {
				ts /= 10;
				tens *= 10;
			}
			if (ts > 0) {
				ans.insert(1 * tens);
				ts--;
				cnt++;
			}
			else {
				for (auto x : ans) {
					if (x > 1) {
						int ttens = 1;
						int tmp = x;
						while (tmp >= 10) {
							tmp /= 10;
							ttens *= 10;
						}
						ttens /= 10;
						ans.erase(ans.find(x));
						ans.insert(ttens);
						ts = 9 * ttens;
						tens = 1;
						break;
					}
				}
			}
		}
		int f = *ans.begin();
		ans.erase(ans.begin());
		ans.insert(f + ts * tens);
		for (auto x : ans){
			cout << x << ' ';
		}
		cout << '\n';
	}
}