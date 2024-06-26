/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let initial = init;
    let obj = {
        increment : function(){
            return ++init;
        } ,
        decrement : function(){
            return --init;
        },
        reset : function(){
            init = initial;
            return init;  

        }
    }
    return obj;
    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */