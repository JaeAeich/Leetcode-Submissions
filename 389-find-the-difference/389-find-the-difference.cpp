#include<bits/stdc++.h>
class Solution {
public:
    // //Brute force
    // char findTheDifference(string s, string t) {
    //     map<char,int> m;
    //     for(int i=0;s[i]!='\0';i++){
    //         if(m.find(s[i])==m.end()){
    //             m[s[i]]=1;
    //         }
    //         else m[s[i]]++;
    //     }
    //     char ret;
    //     for(int i=0;t[i]!='\0';i++){
    //         if(m.find(t[i])==m.end()){
    //             ret =t[i];
    //             break;
    //         }
    //         else {
    //             if(m[t[i]]) m[t[i]]--;
    //             else {
    //                 ret=t[i];
    //                 break;
    //             }
    //         }
    //     }
    //     return ret ;
    // }
    
    // //Sort and Xor 
    // char findTheDifference(string s, string t) {
    //     sort(begin(s),end(s));
    //     sort(begin(t),end(t));
    //     char ret=t.back();
    //     for(int i=0;s[i]!='\0';i++){
    //         int a=(int)s[i];
    //         int b=(int)t[i];
    //         if(a^b){
    //             ret =t[i];
    //             break;
    //         }
    //     }
    //     return ret;
    // }
    
    //frequency counter using array
    char findTheDifference(string s, string t){
        vector<int> f(26);
        char ret;
        for(char c:s){
            f[c-'a']++;
        }
        // for(int i=0;i<f.size();i++){
        //     cout<<f[i]<<" ";
        // }
        // cout<<endl;
        for(char c:t){
            f[c-'a']--;
        }
        // for(int i=0;i<f.size();i++){
        //     cout<<f[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<26;i++){
            if(f[i]==-1){
                ret =(char)('a'+i);
            }
        }
        return ret;
    }
};










