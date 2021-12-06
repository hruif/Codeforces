#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int a, b, c, ab, bc, abc;

    Node() {
        a = b = c = ab = bc = abc = 0;
    }

    Node(char x) {
        a = b = c = ab = bc = abc = 0;
        if (x == 'a') a++;
        if (x == 'b') b++;
        if (x == 'c') c++;
    }

    Node operator+(const Node& o) const {
        Node n;
        n.a = a + o.a;
        n.b = b + o.b;
        n.c = c + o.c;
        n.ab = min(a + o.ab, ab + o.b);
        n.bc = min(b + o.bc, bc + o.c);
        n.abc = min({ a + o.abc, ab + o.bc, abc + o.c });
        return n;
    }
};

int n, q;
vector<Node> st;
string s;

void set_st(int n) {
    int sn = 1;
    while (sn < n) sn *= 2;
    st.resize(sn * 2, Node());
}

Node find_n(int a, int b) {
    int sn = st.size() / 2;
    a += sn; b += sn;
    Node ans1, ans2;
    while (a <= b) {
        if (a % 2 == 1) ans1 = ans1 + st[a++];
        if (b % 2 == 0) ans2 = st[b--] + ans2;
        a /= 2; b /= 2;
    }
    return ans1 + ans2;
}

void change_val(int k, Node x) {
    int sn = st.size() / 2;
    k += sn;
    st[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        st[k] = st[k * 2] + st[k * 2 + 1];
    }
}

int main() {
    cin >> n >> q;
    set_st(n);
    cin >> s;
    for (int i = 0; i < n; i++) change_val(i, Node(s[i]));
    for (int i = 0; i < q; i++) {
        int pos;
        char c;
        cin >> pos >> c;
        pos--;
        change_val(pos, c);
        s[pos] = c;
        Node ans = find_n(0, n - 1);
        cout << ans.abc << '\n';
    }
}