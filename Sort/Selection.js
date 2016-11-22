// Selection sort:
//  23134
//  13234
//  12334 
//  Repeatedly identifies the next smallest number and add to list.

// Complexity
// Outer loop goes n time and inner loop n-j-1 (j the index of outer loop)
// The if statement is executed as (n-1) +(n-2) ...2+1 = n(n-1)/2 => O(n^2), Om(n^2), om(n^2)




function selection_sort(array) {
  
  for (var j=0 ; j < array.length; ++j) {
    min = j;
    for (var i=j+1; i< array.length;++i){
      // Complexity depends on how many times this is run
      if(array[i] < array[min]) min = i;
    }
    //swap arr[j] and arr[min]
    var temp = array[j];
    array[j] = array[min];
    array[min] = temp;
  }
}

//////////////////////////////////////////
// Test Area
/////////////////////////////////////////

var test_array = [2,4,1,7,5]; //TODO: To see discernabletime, this should be substantial

var start = Date.now() // Start time of the selection in milliseconds

selection_sort(test_array);

var end = Date.now() // End time in ml

console.log(end-start)

console.log(test_array);