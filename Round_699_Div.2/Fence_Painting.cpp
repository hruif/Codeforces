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

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef LOCAL_DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#else
#define fin cin
#define fout cout
#endif

int t;
vi a, b, c;
vector<set<int>> cols;

int main() {
    fin >> t;
    while (t--) {
        a.clear(); b.clear(); c.clear();
        cols.clear();

        int n, m;
        fin >> n >> m;
        a.resize(n); b.resize(n);
        c.resize(m);
        cols.resize(n + 1);

        F0R(i, n) fin >> a[i];
        F0R(i, n) fin >> b[i];
        F0R(i, m) fin >> c[i];


        int wastei = -1;
        F0R(i, n) {
            if (b[i] == c[m - 1]) {
                wastei = i;
                break;
            }
        }
        if (wastei == -1) {
            fout << "NO\n";
            continue;
        }
        F0R(i, n) {
            if (a[i] != b[i]) cols[b[i]].insert(i);
        }
        vi ans;
        if (cols[c[m - 1]].size() > 0) {
            wastei = *cols[c[m - 1]].rbegin();
        }
        F0R(i, m) {
            if (cols[c[i]].size() != 0) {
                ans.push_back(*cols[c[i]].begin());
                cols[c[i]].erase(cols[c[i]].begin());
            }
            else {
                ans.push_back(wastei);
            }
        }
        bool inv = false;
        F0R(i, n + 1) {
            if (cols[i].size() != 0) {
                inv = true;
                break;
            }
        }
        if (inv) {
            fout << "NO\n";
            continue;
        }
        fout << "YES\n";
        F0R(i, m - 1) {
            fout << ans[i] + 1 << ' ';
        }
        fout << wastei + 1 << '\n';
    }
}