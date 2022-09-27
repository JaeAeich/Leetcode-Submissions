class Solution {
public:
    int minBitFlips(int s, int g) {
        int loop=max((s)?log2(s)+1:0,(g)?log2(g)+1:0);
        int c=0;
        for(int i=0;i<loop;i++){
            int s_lsb=(s>>i)&1;
            int g_lsb=(g>>i)&1;
            if(s_lsb^g_lsb) c++;
        }
        return c;
    }
};