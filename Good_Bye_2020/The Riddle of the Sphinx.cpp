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
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define F0R(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RF0R(i, a) RFOR(i, a, 0)

#define MOD 1

int n, b;

int main() {
	cin >> n >> b;
	int max = 0;
	int in = 1;
	string val(n, '0');
	int l = -1, r = n - 1;
	while (l != r - 1) {
		int mid = (l + r) / 2;
		val[mid] = '1';
		cout << in << ' ' << val << '\n';
		cout.flush();
		string re;
		cin >> re;
		if (re == "yes") {

		}
		else {

		}
	}
}