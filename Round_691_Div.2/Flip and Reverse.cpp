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

#define MOD 998244353

int T;
vector<vector<int>> vals;

int main() {

	cin >> T;
	while (T--) {
		vals.clear();

		string s;
		cin >> s;
		string ns = s;
		int ss = s.size();
		int val = 0;
		vals.resize(ss * 2 + 10, vector<int>(2, 0));
		F0R(i, s.size()) {
			vals[val + ss + 1][s[i] - '0']++;
			if (s[i] == '0') val++;
			else val--;
		}

		val = 0;
		int numtrav = 0;
		while (numtrav < ss) {
			int ind = val + ss + 1;
			if (vals[ind][0] > 0 && vals[ind][1] > 0) {
				if (vals[ind + 1][1] == 0) {
					vals[ind][1]--;
					ns[numtrav] = '1';
					val--;
				}
				else {
					vals[ind][0]--;
					ns[numtrav] = '0';
					val++;
				}
			}
			else {
				if (vals[ind][0] > 0) {
					vals[ind][0]--;
					ns[numtrav] = '0';
					val++;
				}
				else {
					vals[ind][1]--;
					ns[numtrav] = '1';
					val--;
				}
			}
			numtrav++;
		}
		cout << ns << '\n';
	}
}