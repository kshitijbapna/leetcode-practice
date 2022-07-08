/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var x=[];
    for(var i=0;i<nums.length;i++){
        x.push([nums[i],i]);
    }
    x.sort((a,b)=>a[0]-b[0]);
    let l=0,r=nums.length-1;
    while(l<r){
        var sum=x[l][0]+x[r][0]
        if(sum==target){
            return [x[l][1],x[r][1]];
        }
        else if(sum<target){
            l++;
        }
        else{
            r--;
        }
    }
    return [];
};