class Solution {
public:
    int reverse(int x) {
        long long ans=0;
        while(x){
            int temp=int(ans*10+x%10);
            if(temp/10!=ans){
                return 0;
            }
            ans=temp;
            x/=10;
        }
        return ans;
    }
};