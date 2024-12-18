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

#define MOD 1

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef LOCAL_DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#else
#define fin cin
#define fout cout
#endif

int t;
int x[1000], y[1000];

int main() {
    fin >> t;
    while (t--) {
        int n;
        fin >> n;
        int tx = 0, ty = 0;
        F0R(i, n) fin >> x[i] >> y[i];
        sort(x, x + n);
        sort(y, y + n);
        ll xcnt = x[n / 2] - x[(n - 1) / 2] + 1;
        ll ycnt = y[n / 2] - y[(n - 1) / 2] + 1;
        fout << xcnt * ycnt << '\n';
    }
}