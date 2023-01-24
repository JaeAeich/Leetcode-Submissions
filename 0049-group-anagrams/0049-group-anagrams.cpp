// class Solution {
// public:
//     //using hash map (attemp 1)
//     //TC:vector_length*string_length => O(len(v)*len(str))
//     vector<vector<string>> groupAnagrams(vector<string>& v) {
//         vector<vector<string>> ans;
//         map<map<char,int>,vector<string>> m;
//         //Getting frequency cout of each string.
//         for(int i=0;i<v.size();i++){
//             map<char,int> temp;
//             for(auto c:v[i]){
//                 temp[c]++;
//             }
//             //if the frequency count matches then adding then storing the string.
//             m[temp].push_back(v[i]);
//         }
//         //Storing string in the patterns the question asks.
//         for(auto it=m.begin();it!=m.end();it++){
//             ans.push_back(it->second);
//         }
//         return ans;
//     }
// };
//Note:The above  solution is inefficient because of search time in map, and we cant use unordered map with complex key data str.

//solution 2
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        //storing string with key as sorted string.
        //ie m["abc"]="bac" and m["abc"]=cab, this way we can hash ANAGRAMS together.
        for(int i=0;i<v.size();i++){
            string temp = v[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(v[i]);
        }

        for(auto it=m.begin();it!=m.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
