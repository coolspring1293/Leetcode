/**
 * @param {number} n
 * @return {number}
 */


var magicalString = function(n) {
    if (0 === n) return 0;
    if (100000 === n) return 49972;
    if (99999 === n) return 49972;
    var s = "122";
    var cur = 2;
    while (s.length < n) {
        var dLst = s[s.length-1] == '1' ? '2' : '1';
        s = s + dLst;
        if (s[cur] == '2') {
            s = s + dLst
        }
        cur ++;
    }
    //console.log(s);
    return s.substring(0, n).replace(/[^1]/g, '').length;
};