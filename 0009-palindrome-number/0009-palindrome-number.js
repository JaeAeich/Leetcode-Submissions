/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x<0) return false;
    
    let ans=0;
    let temp=x;
    while(temp){
        ans*=10;
        ans+=temp%10;
        temp=Math.floor(temp/10);
    }
    return x==ans;
};