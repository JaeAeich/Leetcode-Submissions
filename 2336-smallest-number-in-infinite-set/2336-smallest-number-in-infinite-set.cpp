class SmallestInfiniteSet {
vector<int> v;
public:
    SmallestInfiniteSet() {
        v.resize(1001);
        fill(begin(v), end(v), 1);
    }
    
    int popSmallest() {
        for(int i = 1 ; i <= v.size(); i++){
            if(v[i]){
                v[i] = 0;
                return i;
            }
        }
        return -1;
    }
    
    void addBack(int num) {
        v[num] = 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */