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

int n, m;
int mat[500][500];

int exp(int b, int e) {
    if (e == 0) return 1;
    int val = exp(b, e / 2);
    val *= val;
    if (e % 2) val *= b;
    return val;
}

int main() {
    int n, m;
    fin >> n >> m;
    int mv = 0;
    F0R(i, n) {
        F0R(j, m) {
            fin >> mat[i][j];
            mv = max(mv, mat[i][j]);
        }
    }

    int primes[] = { 2, 3, 5, 7, 11, 13 };
    vector<int> mults(6);
    F0R(i, mv) {
        int val = i + 1;
        F0R(j, 6) {
            int cnt = 0;
            while (val % primes[j] == 0) {
                val /= primes[j];
                cnt++;
            }
            mults[j] = max(mults[j], cnt);
        }
    }
    int def = 1;
    F0R(i, mults.size()) def *= exp(primes[i], mults[i]);

    F0R(i, n) {
        F0R(j, m) {
            int v = mat[i][j];
            if (j != 0) fout << ' ';
            if ((i + j) % 2) {
                fout << def;
            }
            else {
                fout << def + (v * v * v * v);
            }
        }
        fout << '\n';
    }
}