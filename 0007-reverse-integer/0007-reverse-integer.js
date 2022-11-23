/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let ans=0;
    let flag=false;
    if(x<0){
        x*=-1;
        flag=true;
    }
    while(x){
        ans*=10;
        ans+=x%10;
        x=Math.floor(x/10);
    }
    
    ans=flag?-ans:ans;
    
    if(ans>2147483647 || ans<-2147483648) return 0;
    return ans;
};