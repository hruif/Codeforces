#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vc = vector<char>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define FORI(i, a, b, p) for (int i = a; i < b; i += p)
#define FOR(i, a, b) FORI(i, a, b, 1)
#define FOR0(i,b) FOR(i, 0, b)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define RFOR0(i, a) RFOR(i, a, 0)

#define MOD 998244353

int t;
char a[1000000];
char b[1000000];
int counts[26];

int main() {
	cin >> t;
	while (t--) {
		memset(counts, 0, sizeof(counts));
		int n, k;
		cin >> n >> k >> a >> b;
		FOR0(i, n) {
			counts[a[i] - 'a']--;
			counts[b[i] - 'a']++;
		}
		bool impossible = false;
		int total = 0;
		RFOR0(i, 25) {
			total += counts[i];
			if (total < 0) {
				impossible = true;
				break;
			}
		}
		FOR0(i, 26) {
			if (counts[i] % k != 0) {
				impossible = true;
				break;
			}
		}
		if (impossible) {
			cout << "No\n";
		}
		else {
			cout << "Yes\n";
		}
	}
}