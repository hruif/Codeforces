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
using vvi = vector<vi>;
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
int v[200000];
vi ch[200000];
int a[200000];
int l[200000];
vll dp;
vvi ls;
vvi vals;

int main() {
    fin >> t;
    while (t--) {
        dp.clear();
        ls.clear();
        vals.clear();

        int n;
        fin >> n;
        dp.resize(n);
        F0R(i, n) ch[i].clear();
        F0R(i, n - 1) fin >> v[i + 1];
        F0R(i, n - 1) v[i + 1]--;
        F0R(i, n - 1) ch[v[i + 1]].push_back(i + 1);
        F0R(i, n - 1) fin >> a[i + 1];
        
        l[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (i != 0) l[i] = l[v[i]] + 1;
            if (ls.size() == l[i]) {
                ls.push_back(vi());
                vals.push_back(vi());
            }
            ls[l[i]].push_back(i);
            vals[l[i]].push_back(a[i]);
            F0R(j, ch[i].size()) q.push(ch[i][j]);
        }
        F0R(i, vals.size()) sort(vals[i].begin(), vals[i].end());

        dp[0] = 0;
        FOR(i, 1, ls.size()) {
            int mav1 = 0, mav2 = 0;
            ll miv1 = 1000000000000000000, miv2 = 1000000000000000000;

            F0R(j, ls[i].size()) {
                int node = ls[i][j];
                int val = a[node];
                if (val > mav1) mav1 = val;
                if (val < miv1) miv1 = val;
            }

            ll m11 = 0, m12 = 0, m21 = -1000000000000000000, m22 = 0;
            F0R(j, ls[i].size()) {
                int node = ls[i][j];
                ll val = a[node];
                ll maxdif = max(mav1 - val, val - miv1);
                ll pv = dp[v[node]];
                dp[node] = pv + maxdif;
                ll dv1 = pv + a[node], dv2 = pv - a[node];
                if (dv1 > m11) m11 = dv1;
                if (dv2 > m21) m21 = dv2;
            }

            F0R(j, ls[i].size()) {
                int node = ls[i][j];
                int val = a[node];
                ll pv = dp[v[node]];
                ll dv1 = pv + a[node], dv2 = pv - a[node];
                dp[node] = max(dp[node], m11 - val);
                dp[node] = max(dp[node], m21 + val);
            }
        }

        ll ans = 0;
        F0R(i, n) {
            ans = max(ans, dp[i]);
        }
        fout << ans << '\n';
    }
}