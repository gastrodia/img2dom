
var util = require('./util');
module.exports = function(input, output, callback) {
    var w = input.width();
    var h = input.height();

    var prePixel = {};
    util.rangeIterator([[0, w], [0, h]], function (x, y, callback) {
        var pixel = input.getPixel(x, y);
        if (prePixel.r != pixel.r && prePixel.g != pixel.g && prePixel.b != pixel.b)  {
            output.setPixel(x, y, pixel, callback);
        } else {
            callback();
        }
        prePixel = pixel;
    }, callback)

}
