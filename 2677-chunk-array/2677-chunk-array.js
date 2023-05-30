/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    var x=[],y=0,z=[];
    for(var i=0;i<arr.length;i++){
        if(y===0){
            z=[];
        }
        z.push(arr[i]);
        y++;
        if(y===size){
            y=0;
            x.push(z);   
        }
    }
    if(z.length!=size&&z.length!=0)
        x.push(z);
    return x;
};
