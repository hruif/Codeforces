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
#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, a, b;
vector<vb> adjmat;

int main() {
	cin >> n >> a >> b;
	adjmat.resize(n, vb(n, false));
	bool swapped = false;
	if (a > 1 && b > 1) cout << "NO\n";
	else {
		if (a == 1) {
			swapped = true;
			swap(a, b);
		}
		bool nono = false;
		if (a == 1) {
			if (n <= 3 && n > 1) nono = true;
			F0R(i, n - 1) {
				adjmat[i][i + 1] = true;
				adjmat[i + 1][i] = true;
			}
		}
		else {
			F0R(i, n - a) {
				adjmat[i][n - a] = true;
				adjmat[n - a][i] = true;
			}
		}
		if (nono) cout << "NO\n";
		else {
			cout << "YES\n";
			F0R(i, n) {
				F0R(j, n) {
					if (i == j) cout << 0;
					else {
						if (swapped) adjmat[i][j] = !adjmat[i][j];
						cout << adjmat[i][j] ? 1 : 0;
					}
				}
				cout << '\n';
			}
		}
	}
}