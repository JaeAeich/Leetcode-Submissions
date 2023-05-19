class Solution {
public:
    bool colorGraph(vector<vector<int>>&g, vector<int>& c,int i=0,int fillColor=0){
        //if this node is colored but not the color which is expected return false.
        if(c[i]!=-1 && c[i]!=fillColor) return false;
        //if it is already colored return true.
        if(c[i]==fillColor) return true;
        
        bool ans = true;
        //color the node.
        c[i]=fillColor;
        
        //color its children a opposite the color of the node.
        for(int child : g[i]){
            ans= ans && colorGraph(g,c,child,!fillColor);
            if(!ans) return false;
        }
        return ans;
    }
    
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        //make a colors array to keep track of the color of node
        vector<int> color(n,-1);
        bool ans = 1;
        for(int i=0;i<n;i++){
            if(color[i]==-1) ans &= colorGraph(g,color,i);
        }
        return ans;
    }
};