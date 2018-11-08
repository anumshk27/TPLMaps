
function fromCompressedGeometry( /*String*/ str, /*SpatialReference*/ sr) {
    var xDiffPrev = 0,
    yDiffPrev = 0,
    points = [],
    x, y,
    strings,
    coefficient;
    
    console.log (str);
    // Split the string into an array on the + and - characters
    strings = str.match(/((\+|\-)[^\+\-]+)/g);
    
    // The first value is the coefficient in base 32
    coefficient = parseInt(strings[0], 32);
    console.log(coefficient);
    
    for (var j = 1; j < strings.length; j += 2) {
        // j is the offset for the x value
        // Convert the value from base 32 and add the previous x valuez
        x = (parseInt(strings[j], 32) + xDiffPrev);
        xDiffPrev = x;
        
        // j+1 is the offset for the y value
        // Convert the value from base 32 and add the previous y value
        y = (parseInt(strings[j + 1], 32) + yDiffPrev);
        yDiffPrev = y;
        
        points.push([x / coefficient, y / coefficient]);
    }
    
    return points;
}

function decodeGeometry(encoded) {
    var len = encoded.length;
    var index = 0;
    var array = [];
    var lat = 0;
    var lng = 0;
    
    while (index < len) {
        var b;
        var shift = 0;
        var result = 0;
        do {
            b = encoded.charCodeAt(index++) - 63;
            result |= (b & 0x1f) << shift;
            shift += 5;
        } while (b >= 0x20);
        var deltaLat = ((result & 1) ? ~(result >> 1) : (result >> 1));
        lat += deltaLat;
        
        shift = 0;
        result = 0;
        do {
            b = encoded.charCodeAt(index++) - 63;
            result |= (b & 0x1f) << shift;
            shift += 5;
        } while (b >= 0x20);
        var deltaLon = ((result & 1) ? ~(result >> 1) : (result >> 1));
        lng += deltaLon;
        
        array.push([lng * 1e-5, lat * 1e-5]);
    }
    return array;
};

