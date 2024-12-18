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

int main() {
    fin >> t;
    while (t--) {
        int a, b;
        fin >> a >> b;
        int init = 0;
        if (b == 1) init++;
        int ta = a;
        while (ta > 0) {
            ta /= b + (b == 1 ? 1 : 0);
            init++;
        }
        for (int tb = b + 1; tb < 10000; tb++) {
            int ta = a;
            int cnt = tb - b;
            while (ta > 0) {
                ta /= tb;
                cnt++;
            }
            init = min(init, cnt);
        }
        fout << init << '\n';
    }
}