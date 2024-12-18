#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findbestscore(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<vector<int>>& comp, vector<bool>& pst, vector<bool>& pme, int paired) {
        if (paired == pst.size()) return 0;
        int p = 0;
        while (pme[p]) p++;
        int ans = 0;
        pme[p] = true;
        for (int i = 0; i < pst.size(); i++) {
            if (!pst[i]) {
                pst[i] = true;
                int tmpans = comp[p][i];
                tmpans += findbestscore(students, mentors, comp, pst, pme, paired + 1);
                ans = max(ans, tmpans);
                pst[i] = false;
            }
        }
        pme[p] = false;
        return ans;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<vector<int>> comp(mentors.size(), vector<int>(mentors.size(), mentors[0].size()));
        for (int i = 0; i < mentors.size(); i++) {
            for (int j = 0; j < students.size(); j++) {
                int cnt = 0;
                for (int l = 0; l < mentors[i].size(); l++) {
                    if (mentors[i][l] == students[j][l]) cnt++;
                }
                comp[i][j] = cnt;
            }
        }
        vector<bool> pst(students.size(), false);
        vector<bool> pme(mentors.size(), false);
        return findbestscore(students, mentors, comp, pst, pme, 0);
    }
};

int main() {
    Solution a;
    vector<vector<int>> students = { {1,1,0},{1,0,1},{0,0,1} };
    vector<vector<int>> mentors = { {1,0,0} ,{0,0,1} ,{1,1,0} };
        cout << a.maxCompatibilitySum(students, mentors) << '\n';
}