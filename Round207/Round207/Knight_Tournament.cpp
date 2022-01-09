#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> st, marked;

void push(int node) {
	if (marked[node]) {
		st[node * 2] = st[node * 2 + 1] = st[node];
		marked[node * 2] = marked[node * 2 + 1] = true;
		marked[node] = false;
	}
}

void set_val(int node, int tl, int tr, int l, int r, int x) {
	if (l > r) return;
	if (l == tl && r == tr) {
		st[node] = x;
		marked[node] = true;
	}
	else {
		push(node);
		int tm = (tl + tr) / 2;
		set_val(node * 2, tl, tm, l, min(r, tm), x);
		set_val(node * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
	}
}

int query(int node, int tl, int tr, int pos) {
	if (tl == tr) return st[node];
	push(node);
	int tm = (tl + tr) / 2;
	if (pos <= tm) return query(node * 2, tl, tm, pos);
	else return query(node * 2 + 1, tm + 1, tr, pos);
}

void set_st(int n) {
	int sn = 1;
	while (sn < n) sn *= 2;
	st.resize(sn * 2, 0);
	marked.resize(sn * 2, false);
}

int qs[300000][3];

int main() {
	cin >> n >> m;
	set_st(n);
	for (int i = 0; i < n; i++)
		set_val(1, 0, st.size() / 2 - 1, i, i, -1);
	for (int i = 0; i < m; i++) cin >> qs[i][0] >> qs[i][1] >> qs[i][2];
	for (int i = m - 1; i >= 0; i--) {
		int l = qs[i][0], r = qs[i][1], x = qs[i][2];
		l--; r--; x--;
		set_val(1, 0, st.size() / 2 - 1, l, x - 1, x);
		set_val(1, 0, st.size() / 2 - 1, x + 1, r, x);
	}
	for (int i = 0; i < n; i++) {
		int win = query(1, 0, st.size() / 2 - 1, i);
		cout << win + 1 << ' ';
	}
	cout << '\n';
}