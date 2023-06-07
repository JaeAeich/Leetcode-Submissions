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
    
    // Using hashmap
    int longestConsecutive(vector<int>& v) {
        map<int,int> m;
        set<int> s;
        int ans = 0;
        
        // Push all the value in map and set
        for(auto val : v){
            // Don't store repetitive values 
            if(m.find(val)==m.end()) s.insert(val);
            m[val]++;
        }
        
        // For all non repetive value
        for(auto it=begin(s);it!=end(s);it++){
            // If there is ele - 1, then no operation
            if(m.find(*it-1)!=m.end()) continue;
            
            // There is a possibility for consecutive sequence
            else{
                int f=1;
                int prev = *it;
                // Find how many consecutive ele are present
                while(m.find(prev+1)!=m.end()){
                    f++;
                    prev = prev+1;
                }
                ans = max(ans,f);
            }
        }
        return ans;
    }
};