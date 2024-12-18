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
using vvll = vector<vll>;
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

int n1, n2, n3, n4;
int m1, m2, m3;
ll a[150000], b[150000], c[150000], c[150000];
vvi ba, bb, bc;

int main() {
    fin >> n1 >> n2 >> n3 >> n4;
    ba.resize(n1); bb.resize(n2); bc.resize(n3);
    F0R(i, n1) fin >> a[i];
    F0R(i, n2) fin >> b[i];
    F0R(i, n3) fin >> c[i];
    F0R(i, n4) fin >> d[i];
    fin >> m1;
    F0R(i, m1) {
        int x, y;
        fin >> x >> y;
        x--; y--;
        ba[x].push_back(y);
    }
    fin >> m2;
    F0R(i, m2) {
        int x, y;
        fin >> x >> y;
        x--; y--;
        bb[x].push_back(y);
    }
    fin >> m3;
    F0R(i, m3) {
        int x, y;
        fin >> x >> y;
        x--; y--;
        bc[x].push_back(y);
    }

    
}