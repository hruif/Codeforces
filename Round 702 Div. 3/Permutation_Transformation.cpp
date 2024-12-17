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
int a[100];
int pos[100];
vi st;

void setst(int n) {
    int sn = 1;
    while (sn < n) sn *= 2;
    st.resize(sn * 2, 0);
}

void updst(int k, int x) {
    int sn = st.size() / 2;
    k += sn;
    st[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        st[k] = max(st[k * 2], st[k * 2 + 1]);
    }
}

int findmax(int a, int b) {
    int sn = st.size() / 2;
    a += sn; b += sn;
    int maxv = 0;
    while (a <= b) {
        if (a % 2 == 1) maxv = max(maxv, st[a++]);
        if (b % 2 == 0) maxv = max(maxv, st[b--]);
        a /= 2; b /= 2;
    }
    return maxv;
}

int ds[100];

int main() {
    fin >> t;
    while (t--) {
        int n;
        fin >> n;
        F0R(i, n) fin >> a[i];
        F0R(i, n) a[i]--;
        F0R(i, n) pos[a[i]] = i;
        setst(n);
        F0R(i, n) updst(i, a[i]);

        queue<pair<pii, pii>> q;
        q.push({  {  n - 1, 0  }, {  0, n - 1  }  });
        while (!q.empty()) {
            pair<pii, pii> vdab = q.front();
            q.pop();
            int v = vdab.first.first, d = vdab.first.second;
            int a = vdab.second.first, b = vdab.second.second;
            int ind = pos[v];
            ds[ind] = d;
            if (a < ind) q.push({  {  findmax(a, ind - 1), d + 1  },
                {  a,  ind - 1  }  });
            if (b > ind) q.push({  {  findmax(ind + 1, b), d + 1  },
                {  ind + 1, b  }  });
        }
        F0R(i, n) fout << ds[i] << ' ';
        fout << '\n';
    }
}