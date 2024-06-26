/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let filterArray = []; 
    for(let i = 0; i < arr.length; i++){
        let ans = fn(arr[i],i);
        if(ans)
        filterArray.push(arr[i]);
    }
    return filterArray;
};
