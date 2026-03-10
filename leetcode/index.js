// function fibonacci(n) {
//     let a = 0, b = 1, c;
  
//     document.write(a + " " + b + " ");
  
//     for (let i = 2; i < n; i++) {
//       c = a + b;
//       document.write(c + " ");
//       a = b;
//       b = c;
//     }
//   }
  
//   fibonacci(3);



// let result = confirm("Are you sure?");
// if (result) {
//   alert("Confirmed");
// }



// let name = prompt("Enter your name:");
// alert("Hello " + name);



let num = prompt("Enter a number:");
let fact = 1;

for (let i = 1; i <= num; i++) {
  fact = fact * i;
}

alert("Factorial is: " + fact);