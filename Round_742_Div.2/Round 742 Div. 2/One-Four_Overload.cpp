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

int n, m;
char grid[500][500];
int vals[500][500];

int main() {
	cin >> n >> m;
	F0R(i, n) {
		F0R(j, m) {
			cin >> grid[i][j];
		}
	}
	bool poss = true;
	F0R(i, n) {
		F0R(j, m) {
			int sum = 0, cnt = 0;
			if (grid[i][j] == 'X') {
				if (grid[i - 1][j] != 'X') {
					sum += vals[i - 1][j];
					if (vals[i - 1][j] == 0) cnt++;
				}
				if (grid[i + 1][j] != 'X') {
					sum += vals[i + 1][j];
					if (vals[i + 1][j] == 0) cnt++;
				}
				if (grid[i][j - 1] != 'X') {
					sum += vals[i][j - 1];
					if (vals[i][j - 1] == 0) cnt++;
				}
				if (grid[i][j + 1] != 'X') {
					sum += vals[i][j + 1];
					if (vals[i][j + 1] == 0) cnt++;
				}
				if ((cnt % 2 > 0) != (sum % 5) > 0) {
					poss = false;
				}
				if (grid[i - 1][j] != 'X' && vals[i - 1][j] == 0) {
					vals[i - 1][j] = 5 - (sum % 5);
					if (vals[i - 1][j] == 5) vals[i - 1][j] = 1;
					sum += vals[i - 1][j];
				}
				if (grid[i + 1][j] != 'X' && vals[i + 1][j] == 0) {
					vals[i + 1][j] = 5 - (sum % 5);
					if (vals[i + 1][j] == 5) vals[i + 1][j] = 1;
					sum += vals[i + 1][j];
				}
				if (grid[i][j - 1] != 'X' && vals[i][j - 1] == 0) {
					vals[i][j - 1] = 5 - (sum % 5);
					if (vals[i][j - 1] == 5) vals[i][j - 1] = 1;
					sum += vals[i][j - 1];
				}
				if (grid[i][j + 1] != 'X' && vals[i][j + 1] == 0) {
					vals[i][j + 1] = 5 - (sum % 5);
					if (vals[i][j + 1] == 5) {
						poss = false;
					}
					vals[i][j + 1];
				}
			}
		}
	}
	if (poss) {
		cout << "YES\n";
		F0R(i, n) {
			F0R(j, m) {
				if (grid[i][j] == 'X') cout << 5 << ' ';
				else {
					if (vals[i][j] == 0) cout << 4 << ' ';
					else cout << vals[i][j] << ' ';
				}
			}
			cout << '\n';
		}
	}
	else cout << "NO\n";
}