class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        long long int p=1,c=0;
        for(int i=0;i<v.size();i++){
            // taking product of all nums but zero.
            if(v[i]) p*=v[i];
            //counting number of zeroes.
            else c++;
        }
        if(c<2){
            // If on ezero is present then except that zero all ele will be zero.
            if(c==1){
                for(int i=0;i<v.size();i++){
                    if(!v[i]){
                        v[i]=p;
                    }
                    else v[i]=0;
                }
            }
            // if number of zeroes is 1 then each ele=total product/ele.
            if(c==0){
                for(int i=0;i<v.size();i++){
                    v[i]=p/v[i];
                }
            }
        }
        // if there are more than 2 zeroes, all ele will become zeroes.
        else{
            for(int i=0;i<v.size();i++){
                v[i]=0;
            }
        }
        return v;
    }
};