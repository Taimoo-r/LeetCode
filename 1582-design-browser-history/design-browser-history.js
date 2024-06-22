/**
 * @param {string} homepage
 */
var BrowserHistory = function(homepage) {
    this.history = [homepage];
    this.curr =  0;
    
};

/** 
 * @param {string} url
 * @return {void}
 */
BrowserHistory.prototype.visit = function(url) {
    this.history = this.history.slice(0,this.curr+1);
    this.history.push(url);
    this.curr++;
};

/** 
 * @param {number} steps
 * @return {string}
 */
BrowserHistory.prototype.back = function(steps) {
    this.curr = Math.max(0,this.curr-steps);
    return this.history[this.curr];
};

/** 
 * @param {number} steps
 * @return {string}
 */
BrowserHistory.prototype.forward = function(steps) {
    this.curr = Math.min(this.history.length-1,this.curr+steps);
    return this.history[this.curr];
    
};

/** 
 * Your BrowserHistory object will be instantiated and called as such:
 * var obj = new BrowserHistory(homepage)
 * obj.visit(url)
 * var param_2 = obj.back(steps)
 * var param_3 = obj.forward(steps)
 */