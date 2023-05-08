/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    // console.log(arr.length);
    for(var i=0;i<arr.length;i++){
        // console.log(fn(arr[i]));
        arr[i]=fn(arr[i],i);
    }
    return arr;
};