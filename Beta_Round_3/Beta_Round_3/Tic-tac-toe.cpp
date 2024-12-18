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
#define F0R(i,b) FOR(i, 0, b)
#define F0R2(i, j, a, b) F0R(i, a) F0R(j, b)
#define RFOR(i, a, b) for (int i = a - 1; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

char grid[3][3];

bool isWin(char c) {
	F0R(i, 3) {
		if (grid[i][0] == c && grid[i][1] == c && grid[i][2] == c) {
			return true;
		}
		if (grid[0][i] == c && grid[1][i] == c && grid[2][i] == c) {
			return true;
		}
	}
	if (grid[1][1] == c) {
		if (grid[0][0] == c && grid[2][2] == c) {
			return true;
		}
		if (grid[0][2] == c && grid[2][0] == c) {
			return true;
		}
	}
	return false;
}

int main() {
	int dots = 0, x = 0, o = 0;
	F0R(i, 3) {
		F0R(j, 3) {
			cin >> grid[i][j];
			if (grid[i][j] == '.') dots++;
			if (grid[i][j] == 'X') x++;
			if (grid[i][j] == '0') o++;
		}
	}
	if (abs(x - o) > 1 || o > x) cout << "illegal\n";
	else {
		bool xwin = isWin('X'), owin = isWin('0');
		if (xwin && owin) cout << "illegal\n";
		else {
			if (!xwin && !owin) {
				if (dots == 0) cout << "draw\n";
				else {
					if (x == o) cout << "first\n";
					else cout << "second\n";
				}
			}
			else if (xwin) {
				if (x == o) cout << "illegal\n";
				else {
					bool possible = false;
					F0R(i, 3) {
						F0R(j, 3) {
							if (grid[i][j] == 'X') {
								grid[i][j] = '.';
								if (!isWin('X')) possible = true;
								grid[i][j] = 'X';
							}
						}
					}
					if (possible) cout << "the first player won\n";
					else cout << "illegal";
				}
			}
			else {
				if (x > o) cout << "illegal\n";
				else {
					bool possible = false;
					F0R(i, 3) {
						F0R(j, 3) {
							if (grid[i][j] == '0') {
								grid[i][j] = '.';
								if (!isWin('0')) possible = true;
								grid[i][j] = '0';
							}
						}
					}
					if (possible) cout << "the second player won\n";
					else cout << "illegal";
				}
			}
		}
	}
}