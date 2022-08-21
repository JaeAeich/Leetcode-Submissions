class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        long long int p=1,c=0;
        for(int i=0;i<v.size();i++){
            if(v[i]) p*=v[i];
            else c++;
        }
        if(c<2){
            if(c==1){
                for(int i=0;i<v.size();i++){
                    if(!v[i]){
                        v[i]=p;
                    }
                    else v[i]=0;
                }
                return v;
            }
            if(c==0){
                for(int i=0;i<v.size();i++){
                    v[i]=p/v[i];
                }
                return v;
            }
        }
        else{
            for(int i=0;i<v.size();i++){
                v[i]=0;
            }
        }
        return v;
    }
};