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

int n, k;
int a[200000];
int sa[200000];

int main() {
    fin >> n >> k;
    F0R(i, n) fin >> a[i];
    F0R(i, n) sa[i] = a[i];
    sort(sa, sa + n);
    int l = 0, r = n;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        int v = sa[mid];
        vi na(n);
        F0R(i, n) {
            if (a[i] < v) na[i] = -1;
            else na[i] = 1;
        }
        FOR(i, 1, n) na[i] += na[i - 1];
        int miv = 0, mav = na[k - 1];
        FOR(i, k, n) {
            miv = min(miv, na[i - k]);
            mav = max(mav, na[i] - miv);
        }
        if (mav > 0) l = mid;
        else r = mid;
    }
    fout << sa[l] << '\n';
}