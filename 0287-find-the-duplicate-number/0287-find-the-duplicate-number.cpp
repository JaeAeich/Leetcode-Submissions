class Solution {
public:
    // Using hare, tortise method.
    // Detecting cycle in LL
    int findDuplicate(vector<int>& v) {
        // Slo and fast pointers
        int slo = v[0], fast = v[0];
        
        // Find the first collision
        do{
            slo = v[slo];
            fast = v[v[fast]];
        }while(slo!=fast);
        
        slo = v[0];
        
        // Find the beginning of cycle
        while(slo!=fast){
            slo = v[slo];
            fast = v[fast];
        }
        return slo;
    }
};