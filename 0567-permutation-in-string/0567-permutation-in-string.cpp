class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> m;
        map<char,int> checker;
        if(s1.length()>s2.length()) return false;
        //tracking the freq of chars of s1 and first s1 length of chars from s2.
        for(int i=0;i<s1.length();i++){
            m[s1[i]]++;
            checker[s2[i]]++;
        }
        
        int i=0,j=s1.length()-1;
        
        while(j<s2.length()){
            //if the first chars of s2 are equal to s1 return true.
            if(checker==m) return true;
            //else slide the window of the string to right and check if those match with m.
            //Note : if i char has freq 1 then we will have to remove its key too because we are comparing maps, else we can just decrement. 
            if(checker[s2[i]]==1) {
                checker.erase(s2[i++]);
            }
            else checker[s2[i++]]--;
            checker[s2[++j]]++;
        }
        return false;
    }
};