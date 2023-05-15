class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n=v.size();
        int piv=-1;
        //find the piv,ie the fist ele from the right which ig not sorted increasingly.
        for(int i=n-2;i>=0;i--){
            if(v[i]<v[i+1]) {
                piv=i;
                break;
            }
        }
        //if none found that means this is the last permutation.
        //3 2 1 --> 1 2 3
        if(piv==-1){
            reverse(begin(v),end(v));
            return ;
        } 
        /*
        find the smallest ele right of pivot which is greater than piv.
        swap piv with the smallest to achieve smallest lexicographical num
        ie 1 1 5 4 0 --> 1 4 5 1 0 
        */
        for(int i = n-1; i>piv;i--){
            if(v[i]>v[piv]){
                swap(v[i],v[piv]);
                break;
            }
        }
        
        /*
        now rev from piv + 1 till end because to that side now we have
        increasingly sorted array and to achieve the smallest possible
        combination we need to rev it .
        i.e 1 1 5 4 0 --> 1 4 5 1 0 --> 1 4 0 1 5
        */
        reverse(begin(v)+piv+1,end(v));
    }
};