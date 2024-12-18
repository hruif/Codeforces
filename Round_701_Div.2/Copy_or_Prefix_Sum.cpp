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
#include <map>
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

#define MOD (ll)(1e9 + 7)

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef LOCAL_DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#else
#define fin cin
#define fout cout
#endif

int t;
ll b[200000];
map<ll, ll> dp1, dp2;

ll exp(ll b, ll e) {
    if (e == 0) return 1;
    ll val = exp(b, e / 2);
    val *= val;
    if (e % 2) val *= b;
    return val % MOD;
}

int main() {
    fin >> t;
    while (t--) {
        dp1.clear(); dp2.clear();

        int n;
        fin >> n;
        F0R(i, n) fin >> b[i];

        int dp = 1;
        ll cnt = 1;
        ll bv = 0;
        dp1[0] = 1;
        FOR(i, 0, n) {
            ll v = dp1[bv];
            dp1[bv] = cnt;
            bv -= b[i];
            cnt *= 2;
            cnt = cnt + MOD - v;
            cnt %= MOD;
        }
        fout << cnt % MOD << '\n';
    }
}