var customSnap = require('../build/Release/takeCustomSnap.node');

function A(){
        var x = Math.random();
        function X(){
                return x;
        }   
        X();
}

var Y = A();
var Z = A();


customSnap.takeCustomSnap(Y);
