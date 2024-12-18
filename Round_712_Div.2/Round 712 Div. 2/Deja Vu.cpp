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

int main() {
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		bool pal = true;
		int ind;
		for (int i = 0; i <= s.size() / 2; i++) {
			int b = s.size() - 1 - i;
			if (s[i] != 'a') {
				s.insert(s.begin() + b + 1, 'a');
				pal = false;
				break;
			}
			if (s[b] != 'a') {
				s.insert(s.begin() + i, 'a');
				pal = false;
				break;
			}
			if (s[i] != (b == s.size() - 1 ? 'a' : s[b + 1])) {
				s.insert(s.end() - 1, 'a');
				pal = false;
				break;
			}
			if (s[b] != (i == 0 ? 'a' : s[i - 1])) {
				s.insert(s.begin(), 'a');
				pal = false;
				break;
			}
		}
		if (!pal) cout << "YES\n" << s << '\n';
		else cout << "NO\n";
	}
}