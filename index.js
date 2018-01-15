var lwip = require('lwip');
var diffPixel = require('./sample/diffPixel');

// obtain an image object:
lwip.open('./sample/test_image.jpg', function (err, input) {
    var w = input.width();
    var h = input.height();
    lwip.create(w, h, 'white', function (err, output) {
        diffPixel(input, output, () => {
            output.writeFile('./output/diff_image.jpg', function (err) { })
        })
    });
});