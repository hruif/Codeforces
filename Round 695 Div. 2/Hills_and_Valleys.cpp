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
int a[300000];
vi intim;

int main() {
	fast_cin();

	cin >> t;
	while (t--) {
		intim.clear();

		int n;
		cin >> n;
		intim.resize(n, 0);
		F0R(i, n) cin >> a[i];

		int inin = 0; // initial intimidation
		FOR(i, 1, n - 1) {
			if ((a[i] < a[i - 1] && a[i] < a[i + 1])
				|| (a[i] > a[i - 1] && a[i] > a[i + 1])) {
				inin++;
				intim[i] = a[i] < a[i - 1] ? -1 : 1;
			}
		}

		int maxsub = 0;
		F0R(i, n) {
			int sub = 0;
			if (intim[i] != 0) sub++;
			if (i > 0 && intim[i - 1] != 0) sub++;
			if ((i < n - 1 && i > 0) && ((intim[i + 1] == 1 && a[i - 1] >= a[i + 1])
				|| (intim[i + 1] == -1 && a[i - 1] <= a[i + 1]))) sub++;
			maxsub = max(maxsub, sub);
			sub = 0;
			if (intim[i] != 0) sub++;
			if (i < n - 1 && intim[i + 1] != 0) sub++;
			if ((i < n - 1 && i > 0) && ((intim[i - 1] == 1 && a[i + 1] >= a[i - 1])
				|| (intim[i - 1] == -1 && a[i + 1] <= a[i - 1]))) sub++;
			maxsub = max(maxsub, sub);
		}

		cout << inin - maxsub << '\n';
	}
}