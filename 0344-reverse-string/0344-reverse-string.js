/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
// // using inbuilt function
// var reverseString = function(s) {
//     s.reverse();
//     return s;
// };

var reverseString = function(s) {
    let i=0,j=s.length-1;
    
    while(i<j){
        [s[i],s[j]]=[s[j],s[i]];
        i++;
        j--;
    }
    return s;
}
