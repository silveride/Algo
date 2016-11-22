function findvar(str,sub){
  
  for (var i =0; i<= (str.length-sub.length); ++i) {
    
    j = 0;
    
    while(j < sub.length && str[i+j] == sub[j]) j++;
    
    if (j == sub.length) return true;
  }
  return false;
}


///////////////////////////////////////////
// Test Part
//////////////////////////////////////////


var test = findvar("test var", "test");

console.log(test)