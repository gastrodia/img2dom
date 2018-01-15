exports.rangeIterator = function rangeIterator(scope, iter, callback) {
    var x = scope[0][0];
    var w = scope[0][1];
    var y = scope[1][0];
    var h = scope[1][1];
    process.nextTick(function () {
        iter(x, y, function () {
            if (x == w - 1) {
                if (y == h - 1) {
                    callback();
                } else {
                    rangeIterator([[0, w], [y + 1, h]], iter, callback);
                }
            } else {
                rangeIterator([[x + 1, w], [y, h]], iter, callback);
            }
        })
    })
}
