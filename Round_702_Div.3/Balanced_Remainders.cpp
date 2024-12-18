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
int a[30000], c[3];

int main() {
    fin >> t;
    while (t--) {
        F0R(i, 3) c[i] = 0;

        int n;
        fin >> n;
        F0R(i, n) fin >> a[i];
        F0R(i, n) c[a[i] % 3]++;
        int div3 = n / 3;
        int cnt = 0;
        if (c[0] > div3) {
            int dif = c[0] - div3;
            c[0] = div3;
            cnt += dif;
            c[1] += dif;
        }
        if (c[1] > div3) {
            int dif = c[1] - div3;
            c[1] = div3;
            cnt += dif;
            c[2] += dif;
        }
        if (c[2] > div3) {
            int dif = c[2] - div3;
            c[2] = div3;
            cnt += dif;
            c[0] += dif;
        }
        if (c[0] > div3) {
            int dif = c[0] - div3;
            cnt += dif;
            c[1] += dif;
        }
        fout << cnt << '\n';
    }
}