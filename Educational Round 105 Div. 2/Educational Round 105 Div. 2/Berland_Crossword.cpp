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

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int t;

int main() {
	cin >> t;
	while (t--) {
		int n, U, R, D, L;
		cin >> n >> U >> R >> D >> L;
		if ((U > 1 && R > 1 && D > 1 && L > 1) ||
			(U < n - 1 && R < n - 1 && D < n - 1 && L < n - 1)) cout << "YES\n";
		else {
			bool poss = true;
			for (int i = 0; i < 4; i++) {
				if (U == 0) {
					if (R == n || L == n) poss = false;
					int cnt = 0;
					if (R == n - 1) cnt++;
					if (L == n - 1) cnt++;
					if (D < cnt) poss = false;
				}
				if (U == 1) {
					if (R == n && L == n) poss = false;
					int cnt = 0;
					if (R >= n - 1) cnt++;
					if (R == n) cnt++;
					if (L >= n - 1) cnt++;
					if (L == n) cnt++;
					if (U + D < cnt) poss = false;
				}

				int tmp = R;
				R = U;
				swap(D, tmp);
				swap(L, tmp);
				swap(U, tmp);
			}
			if (poss) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}