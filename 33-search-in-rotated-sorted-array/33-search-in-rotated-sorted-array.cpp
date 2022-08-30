class Solution {
public:
    int search(vector<int>& v, int t) {
        int n=v.size();
        if(n==1) return v[0]==t?0:-1;
        int lo=0,hi=n-1,s=0,e=n-1;
        int peak;
        //finding the point of inflextion
        if(v[0]>v.back()){
            while(hi>=lo){
                int mid=lo+(hi-lo)/2;
                if(v[mid]-v[0]<0) peak=mid,hi=mid-1;
                else lo=mid+1;
            }
            if(t>=v[0]) e=peak;
            else s=peak;
        }
        // cout<<"search space: "<<s<<"to "<<e<<endl;
        //Finding ele
        auto it=lower_bound(begin(v)+s,begin(v)+e,t)-begin(v);
        return v[it]==t?it:-1;
    }
};