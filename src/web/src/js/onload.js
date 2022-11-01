


function get(){
  var res = document.getElementById("res");
  fetch("http://127.0.0.1:18080").then((resp)=>{
    return resp.text();
  }).then((arg)=>{
    res.innerHTML=arg;
  });
  return 0;
}

