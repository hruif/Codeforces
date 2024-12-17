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

#define fin cin
#define fout cout

int n;

int main() {
    fin >> n;
    fout << "? 1 " << n << "\n";
    fout.flush();
    int m2;
    fin >> m2;
    int m3;
    if (m2 != 1) {
        fout << "? 1 " << m2 << "\n";
        fout.flush();
        fin >> m3;
    }
    else m3 = m2 + 1;
    int l = 1, r = m2;
    int lv = 1, rv = m2;
    if (m3 != m2) {
        l = m2, r = n;
        lv = m2, rv = n;
    }
    if (l == m2) {
        while (l < r) {
            int mid = (l + r) / 2;
            if (mid == m2) {
                l = r; break;
            }
            fout << "? " << m2 << ' ' << mid << '\n';
            fout.flush();m
            fin >> m3;
            if (m2 == m3) r = mid;
            else l = mid + 1;
        }
    }
    else {
        while (l < r) {
            int mid = (l + r) / 2 + ((l + r) % 2);
            if (mid == m2) {
                r = l; break;
            }
            fout << "? " << mid << ' ' << m2 << '\n';
            fout.flush();
            fin >> m3;
            if (m2 != m3) r = mid - 1;
            else l = mid;
        }
    }
    fout << "! " << l << '\n';
    fout.flush();
}