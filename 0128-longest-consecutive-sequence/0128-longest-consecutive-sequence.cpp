class Solution {
public:
//     // Using sorting and counting the freq
//     int longestConsecutive(vector<int>& v) {
//         if(v.size()<=1) return v.size();
//         sort(begin(v),end(v));
//         int ans = 1;
//         int f=1;
//         for(int i=1;i<v.size();i++){
//             // If same ele as prev continue
//             if(v[i]==v[i-1]) continue;
            
//             // If consecutve count the freq
//             if(v[i]-v[i-1]==1){
//                 f++;
//                 ans=max(ans,f);
//             }
            
//             // If a non-consecutive ele found, start a new subsequence
//             else{
//                 f=1;
//             }
//         }
//         return ans;
//     }
    
    // Using unordered_set
    int longestConsecutive(vector<int>& v) {
        unordered_set<int> s;
        int ans = 0;
        
        // Push all the value in set
        for(auto val : v){
            s.insert(val);
        }
        
        for(auto it=begin(s);it!=end(s);it++){
            // If there is ele - 1, then no operation
            if(s.find(*it-1)!=s.end()) continue;
            
            // There is a possibility for consecutive sequence
            else{
                int f=1;
                int prev = *it;
                // Find how many consecutive ele are present
                while(s.find(prev+1)!=s.end()){
                    f++;
                    prev = prev+1;
                }
                ans = max(ans,f);
            }
        }
        return ans;
    }
};