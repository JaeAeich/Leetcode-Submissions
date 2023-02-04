class Solution {
public:
    // TC:O(N^2)
    int max(int a, int b){
        return a>b?a:b;
    }
    
    int lengthOfLongestSubstring(string s) {
        int siz=s.length();
        map<char,int> m;
        int i=0,j=i;
        int ans=0;
        //sliding window or two pointer approach
        while(j<siz){
            //if we get a character that is repeated, shorten the string from left.
            if(m[s[j]]>=1){
                m[s[i]]--;
                i++;
            }
            //lengthen the string from right and increase answer.
            else{
                m[s[j]]++;
                j++;
                ans=max(ans,j-i);
            }
        }
        return ans;
    }
};