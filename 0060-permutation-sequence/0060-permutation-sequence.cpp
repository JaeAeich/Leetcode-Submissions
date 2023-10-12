class Solution {
private: 
    // Returns the next permutation of the string in lexicographical order
    void nextPerm(string &s){
        int piv = -1;

        /*
        Find the first small character from right
        (comparing characters directly)
        */
        for(int i = s.length() - 2; i >= 0; i--){
            if(s[i] < s[i+1]){
                piv = i;
                break;
            }
        }

        /*
        If the pivot is -1, reverse the entire string
        and return.
        */
        if(piv == -1){
            reverse(begin(s), end(s));
            return;
        }

        for(int i = s.length() - 1; i > piv; i--){
            if(s[i] > s[piv]){
                swap(s[i], s[piv]);
                break;
            }
        }
        
        reverse(s.begin() + piv + 1, end(s));
    }
public:
    string getPermutation(int n, int k) {
        string s = "";
        k--;
        for(int i = 1; i <= n; i++){
            s += to_string(i);
        }
        while(k--){
            nextPerm(s);
        }
        return s;
    }
};
