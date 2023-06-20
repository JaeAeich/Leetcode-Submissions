class Solution {
public:
    void helper(string &s){
        int n = s.length();
        int piv = -1;
        
        for(int i=n-2;i>=0;i--){
            if(s[i]<s[i+1]){
                piv = i;
                break;
            }
        }
        
        if(piv==-1){
            reverse(begin(s),end(s));
            return ;
        }
        
        for(int i=n-1;i>=0;i--){
            if(s[i]>s[piv]){
                swap(s[i],s[piv]);
                break;
            }
        }
        reverse(begin(s)+piv+1,end(s));
        return ;
    }
    
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++){
            s+=to_string(i);
        }
        while(--k){
            helper(s);
       }
        return s;
    }
};