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

int n, q, k;
int ar[100000];
ll bdcs[100000];
vll st;

ll findC(int a, int b) {
    if (a == b) return k - 1;
    ll c = (ar[++a] - 2) + (k - ar[--b] - 1);
    int sn = st.size() / 2;
    a += sn; 
    b += sn;
    while (a <= b) {
        if (a % 2 == 1) c += st[a++];
        if (b % 2 == 0) c += st[b--];
        a /= 2; b /= 2;
    }
    return c;
}

void addV(int k, int x) {
    int sn = st.size() / 2;
    k += sn;
    st[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        st[k] = st[k * 2] + st[k * 2 + 1];
    }
}

void setst(int s) {
    int sn = 1;
    while (sn < s) sn *= 2;
    st.resize(sn * 2, 0);
    F0R(i, n) addV(i, bdcs[i]);
}

int main() {
    fin >> n >> q >> k;
    F0R(i, n) fin >> ar[i];

    F0R(i, n) {
        int mi = 1, ma = k;
        if (i > 0) mi = ar[i - 1] + 1;
        if (i < n - 1) ma = ar[i + 1] - 1;
        bdcs[i] = ma - mi;
    }
    setst(n);

    F0R(i, q) {
        int l, r;
        fin >> l >> r;
        fout << findC(l - 1, r - 1) << '\n';
    }
}