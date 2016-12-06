function duplicate(str) {
  
  for (var i=0; i<str.length;++i){
    for(var j=i+1; j<str.length;++j){
      if (str[i] == str[j]) return true;
    }
  }
  
  return false;
}


console.log(duplicate('anaconda'))
console.log(duplicate('great'))