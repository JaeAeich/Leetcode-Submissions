/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let c=0,ans=0;
    for (let i=0;i<nums.length;i++){
        if(nums[i]==1) {
            c++;
            ans=Math.max(ans,c);
        }
        else {
            c=0;
        }
    }
    return ans;
};