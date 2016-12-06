function insertion_sort(arr) {
  for(var i =0; i<arr.length-1;++i) {
    for(var j = 0; j <= i ; ++j){
      // Find where to put i+1
      if (arr[j] > arr[i+1]) {
        console.log('Next val:'+arr[i+1]+'is different to:'+arr[j])
        // shift everything from j to i to the right
        console.log('str:'+arr+' strj:'+arr[j]+' next_val:'+arr[i+1])
        temp = arr[j]
        arr[j] = arr[i+1]
        arr[i+1] = temp
        console.log('str:'+arr+' strj:'+arr[j]+' next_val:'+arr[i+1])
      }
    }
  }
  console.log('Ending:'+arr)
}


insertion_sort([7,6,1,3,9,2,5,6,3,3])