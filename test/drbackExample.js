
function A(){
        var x = Math.random();
        function X(){
                return x;
        }   
        X();
}

var Y = A();
var Z = A;


console.log(Y);
console.log(Z());
