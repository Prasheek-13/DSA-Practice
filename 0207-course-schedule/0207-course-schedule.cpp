class Solution {
public:
    bool dfs(int curr, vector<vector<int>>& prerequisites, vector<bool>& vis,
             vector<bool>& recpath) {
        vis[curr] = true;
        recpath[curr] = true;
        for (int i = 0; i < prerequisites.size(); i++) {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];
            if (u == curr) {
                if (!vis[v]) {
                    if (dfs(v, prerequisites, vis, recpath)) {
                        return true;
                    }
                } else if (recpath[v]) {
                    return true;
                }
            }
        }
        /*for(int v: prerequisites[curr]){
            if(!vis[v]){
                if(dfs(v,prerequisites,vis,recpath)){
                    return true;
                }
                else if(recpath[v]){
                    return true;
                }
            }
        }*/
        recpath[curr] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> recpath(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, prerequisites, vis, recpath)) {
                    return false;
                }
            }
        }
        return true;
    }
};