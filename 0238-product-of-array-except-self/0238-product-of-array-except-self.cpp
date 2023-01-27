class Solution {
public:
    // //with div operator
    // vector<int> productExceptSelf(vector<int>& v) {
    //     long long int p=1,c=0;
    //     for(int i=0;i<v.size();i++){
    //         // taking product of all nums but zero.
    //         if(v[i]) p*=v[i];
    //         //counting number of zeroes.
    //         else c++;
    //     }
    //     if(c<2){
    //         // If one zero is present then except that zero all ele will be zero.
    //         if(c==1){
    //             for(int i=0;i<v.size();i++){
    //                 if(!v[i]){
    //                     v[i]=p;
    //                 }
    //                 else v[i]=0;
    //             }
    //         }
    //         // if number of zeroes is 1 then each ele=total product/ele.
    //         if(c==0){
    //             for(int i=0;i<v.size();i++){
    //                 v[i]=p/v[i];
    //             }
    //         }
    //     }
    //     // if there are more than 2 zeroes, all ele will become zeroes.
    //     else{
    //         for(int i=0;i<v.size();i++){
    //             v[i]=0;
    //         }
    //     }
    //     return v;
    // }
    
    //without div operator
    vector<int> productExceptSelf(vector<int>& v) {
        int n=v.size();
        //creating a prefix product array
        vector<int> p(n,1);
        //creating a suffix product array
        vector<int> s(n,1);
        int prev_p=1,prev_s=1;
        for(int i=1,j=n-2;i<v.size();i++,j--){
            //creating a prefix prod array.
            p[i]=prev_p*v[i-1];
            prev_p=p[i];
            //creating a suffix prod array.
            s[j]=prev_s*v[j+1];
            prev_s=s[j];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=s[i]*p[i];
        }
        return ans;
    }
};