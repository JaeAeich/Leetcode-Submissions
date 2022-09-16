class Solution {
public:
//     //brute force.
//     //Genrate gray code using its property.
//     vector<string> genGray(int n){
//         if(n==1) return {"0","1"};
        
//         vector<string> rev=genGray(n-1);
//         vector<string> str=rev;
//         reverse(begin(rev),end(rev));
        
//         for(int i=0;i<str.size();i++){
//             str[i]="0"+str[i];
//         }
//         for(int i=0;i<rev.size();i++){
//             rev[i]="1"+rev[i];
//         }
//         str.insert(str.end(),rev.begin(),rev.end());
//         return str;
//     }
//     //Convert gray code string into a number.
//     int makeNum(string s){
//         int ans=0;
//         int mul=1;
//         for(int i=s.length()-1;i>=0;i--){
//             if(s[i]=='1') ans+=mul*1;
//             mul*=2;
//         }
//         return ans;
//     }
//     //Driver code
//     vector<int> grayCode(int n) {
//         vector<int> ans={};
//         vector<string> v=genGray(n);
//         for(string s:v){
//             ans.push_back(makeNum(s));
//         }
//         return ans;
//     }
    
    //Maths--> n th gray code is n^(n/2) ie xor of num and num/2.    
    vector<int> grayCode(int n){
        vector<int> v;
        int p=(1<<n);
        for(int i=0;i<p;i++){
            v.push_back(i^(i/2));
        }
        return v;
    }

};