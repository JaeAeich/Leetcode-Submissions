class Solution {
public:    
    int calc(int a, int b){
        // nCr =nC(n-r)
        if(b>a-b) b=a-b;
        int res = 1;
        
        // res = a!/(a-b)!b! = ((a)(a-1)*..*(a-b+1))/((b+1)(b)*..*1);
        for(int i =0;i<b;i++){
            res*=a-i;
            res/=i+1;
        }
        return res;
    }
    
    vector<vector<int>> generate(int numRows) {
        // nth row of the pascals triangle is series of nCr, where 0<=r<=n 
        vector<vector<int>> ans ={};
        
        // Create the series for all the row
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                temp.push_back(calc(i,j));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};