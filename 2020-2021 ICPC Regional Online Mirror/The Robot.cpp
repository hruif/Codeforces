#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

int t;
int xys[5000][2];
int ans[2];

int main() {
	cin >> t;
	while (t--) {
		ans[0] = 0, ans[1] = 0;

		string s;
		cin >> s;
		int x = 0, y = 0;
		int ssize = s.size();
		F0R(i, ssize) {
			switch (s[i]) {
			case 'L': x--; break;
			case 'R': x++; break;
			case 'D': y--; break;
			case 'U': y++; break;
			}
			xys[i][0] = x;
			xys[i][1] = y;
		}
		F0R(i, ssize) {
			int ex = xys[i][0], ey = xys[i][1];
			int x = 0, y = 0;
			F0R(i, ssize) {
				switch (s[i]) {
				case 'L': x--; break;
				case 'R': x++; break;
				case 'D': y--; break;
				case 'U': y++; break;
				}
				if (x == ex && y == ey) {
					switch (s[i]) {
					case 'L': x++; break;
					case 'R': x--; break;
					case 'D': y++; break;
					case 'U': y--; break;
					}
				}
				if (x == 0 && y == 0 && i == ssize - 1) {
					ans[0] = ex;
					ans[1] = ey;
				}
			}
		}
		cout << ans[0] << ' ' << ans[1] << '\n';
	}
}