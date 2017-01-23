


function binSearch(tree, val) {
  
  if (tree != null ) {
    if (val == tree.val) {
      
      console.log("Found the value" + tree.val);
      return true;
    } else if (val < tree.val) {
      return binSearch(tree.left, val)
    } else {
      return binSearch(tree.right, val)
    }
  }
}


var obj = {
  val : 20,
  left : {
  val :10,
  left : null,
  right : null
},
    right : {
      val : 20,
      left : null,
      right :null
    }
}

if (!binSearch(obj,70)) {
  console.log("Did not find the element")
}
