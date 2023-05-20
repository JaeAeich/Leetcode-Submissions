class Solution {
public:
    void DFS(map<string, vector<pair<string, double>>> &g, map<string, bool> &vis, string &s, string &e,double ans,double &finans) {
        if (s == e) {
            finans=ans;
            return ;
        }
        if (vis[s]==true) {
            return;
        }
        vis[s] = true;
        for (auto child : g[s]) {
            DFS(g, vis, child.first, e,child.second*ans,finans);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& val, vector<vector<string>>& que) {
        map<string, vector<pair<string, double>>> g;
        map<string,bool> node;
        vector<double> ans;
        for (int i = 0; i < e.size(); i++) {
            node[e[i][0]]=node[e[i][1]]=true;
            g[e[i][0]].push_back({e[i][1], val[i]});
            g[e[i][1]].push_back({e[i][0], (1 * 1.0) / val[i]});
        }
        for (auto q : que) {
            map<string, bool> vis;
            double finans=-1;
            if(node.find(q[0])==node.end() || node.find(q[1])==node.end()) {
                ans.push_back(-1);
                continue;
            }
            DFS(g, vis, q[0], q[1],1,finans);
            ans.push_back(finans);
        }
        return ans;
    }
};
