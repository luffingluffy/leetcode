class Solution {
   public:
    bool isAcyclic(int u, vector<bool>& visited, vector<bool> st, vector<vector<int>>& AL) {
        if (st[u]) return false;
        if (visited[u]) return true;

        st[u] = true;
        visited[u] = true;
        for (auto v : AL[u]) {
            if (!isAcyclic(v, visited, st, AL)) {
                return false;
            }
        }
        st[u] = false;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> AL(numCourses);
        for (auto prerequisite : prerequisites) {
            AL[prerequisite[1]].push_back(prerequisite[0]);
        }

        vector<bool> visited(numCourses), st(numCourses);
        for (int u = 0; u < numCourses; u++) {
            if (!isAcyclic(u, visited, st, AL)) {
                return false;
            }
        }

        return true;
    }
};