/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (value) {

    let obj = {
        toBe: function(val){
            if (value === val) 
                return true;
            else
                throw new Error("Not Equal")
        },
        notToBe: function(val) {
            if (value !== val) 
                return true;
            else
                throw new Error("Equal");
        }
    }
    return obj;
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */