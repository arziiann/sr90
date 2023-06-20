/*function_1{concat()}
const array1 = ['h', 'e', 'l', 'l', 'o'];
const array2 = ['w', 'o', 'r', 'l', 'd'];
const array3 = array1.concat(array2);
//console.log(array3);

/*function_2{every()}
const array = [1, 2, 3, 4, 5];
const is_even = (number) => number % 2 === 0;
const result = array.every(isEven);
console.log(result);*/

/*function_3{filter()}
const array = [1, 2, 3, 4, 5];
const is_even = (number) => number % 2 === 0;
const filteredArray = array.filter(is_even);
console.log(filteredArray);*/

/*function_4{flat()}
const array = [1, [2, [3, [4, 5]]]];
const new_array = array.flat();
console.log(new_array);*/

/*function_5{forEach()}
const array = [1, 2, 3, 4, 5];
array.forEach((element, index) => {
  console.log(`Element at index ${index}: ${element}`);
});*/

/*function_6{lastIndexOf()}
const array = [2, 5, 9, 2];
const lastIndex = array.lastIndexOf(2);
console.log(lastIndex); */

/*function_7{map()}
const array = [1, 2, 3, 4, 5];
const doubledArray = array.map((element) => element * 2);
console.log(doubledArray); */

/*function_8{reduce()}
const array = [1, 2, 3, 4, 5];
const sum = array.reduce((accumulator, currentValue) => accumulator + currentValue);
console.log(sum); */

/*function_9{reverse()}
const array = [1, 2, 3, 4, 5];
array.reverse();
console.log(array); */

/*function_10{split()}
const array = [1, 2, 3, 4, 5];
const slicedArray = array.slice(-3, -1);
console.log(slicedArray); */

/*function_11{some()}
const array = [1, 3, 5, 7, 9];
const hasEvenNumber = array.some((element) => element % 2 === 0);
console.log(hasEvenNumber); */

/*function_12{sort()}
const array = [3, 1, 4, 2, 5];
array.sort();
console.log(array);*/

/*function_13{splice()}
const array = [1, 2, 3, 4, 5];
const removedElements = array.splice(-2, 2);
console.log(array); 
console.log(removedElements); */

/*function_14{entries()}
const array = ['a', 'b', 'c'];
const iterator = array.entries();
for (const entry of iterator) {
  console.log(entry);
}*/

/*function_15{fill()}
const array = [1, 2, 3, 4, 5];
array.fill(0, 1, 4);
console.log(array); */

/*function_16{find()}
const array = [1, 2, 3, 4, 5];
const evenNumber = array.find((element) => element % 2 === 0);
console.log(evenNumber); */

/*function_17{fifindIndex()}
const array = [1, 3, 5, 7, 9];
const evenIndex = array.findIndex((element) => element % 2 === 0);
console.log(evenIndex); */


/*function_18{includes()}
const array = [1, 2, 3, 4, 5];
console.log(array.includes(3)); 
console.log(array.includes(6)); */

/*function_19{join()}
const array = [1, 2, 3, 4, 5];
const joinedString = array.join(', ');
console.log(joinedString); // Output: "1, 2, 3, 4, 5"*/

/*function_20{with()}
const person = {
  name: "Narek",
  age: 18,
  city: "Yerevan"
};

console.log(person.name);
console.log(person.age); 
console.log(person.city); 


with (person) {
  console.log(name); 
  console.log(age); 
  console.log(city); 
}*/





















