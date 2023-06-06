class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Create a ans vector
        vector<vector<int>> v(n,vector<int>(n));
        
        // Four pointers right, left, bottom, top.
        int r=0,t=0;
        int l=n-1,b=n-1;
        
        // Value to input in answer
        int val = 1;
        
        while(r<l && t<b){
            for(int i=r;i<l;i++,val++){
                v[t][i]=val;
            }

            for(int i=t;i<b;i++,val++){
                v[i][l]=val;
            }

            for(int i=l;i>r;i--,val++){
                v[b][i]=val;
            }

            for(int i=b;i>t;i--,val++){
                v[i][r]=val;
            }
            
            t++,b--;
            r++,l--;
        }
        
        // Last unfilled spot.
        if(n%2) v[r][r]=val;
        
        return v;
    }
};