var firebaseConfig = {
  apiKey: "AIzaSyCNMHSlvUOgSTrFr-0HbGMaIE7IFRwbzjA",
  authDomain: "iot59tdh.firebaseapp.com",
  databaseURL: "https://iot59tdh-default-rtdb.firebaseio.com",
  projectId: "iot59tdh",
  storageBucket: "iot59tdh.appspot.com",
  messagingSenderId: "773261677026",
  appId: "1:773261677026:web:0a3207a929d48c44efe9bb",
  measurementId: "G-Z5YTNQ2CG2"
};
// Initialize Firebase
firebase.initializeApp(firebaseConfig);
var all = document.getElementById('all');
var tb1 = document.getElementById('tb1');
var tb2 = document.getElementById('tb2');
var tb3 = document.getElementById('tb3');
var tb4 = document.getElementById('tb4');
// du lieu 

var a = 0
var b = 0;

function sleep(milliseconds) {
  const date = Date.now();
  let currentDate = null;
  do {
    currentDate = Date.now();
  } while (currentDate - date < milliseconds);
}

  function btn_tb1(){
    if (tb1.innerHTML==="ON_TB1"){
       tb1.innerText= "OFF_TB1"
       tb1.style.color= "white"
     document.getElementById('btn_tb1').style.backgroundColor=' #4391f0'
   
       firebase.database().ref().child("/btl/ttb1").set(1);
      
       console.log("a",a)
    }
    
    else{
      tb1.innerText= "ON_TB1"
      //tb1.innerText= "ALL"
     tb1.style.color='#4391f0'
      document.getElementById('btn_tb1').style.backgroundColor='#fff'
      firebase.database().ref().child("/btl/ttb1").set(0);
      
      console.log("b",b)
    }
  }
  function btn_tb2(){
    if (tb2.innerHTML==="ON_TB2"){
       tb2.innerText= "OFF_TB2"
       tb2.style.color= "white"
     document.getElementById('btn_tb2').style.backgroundColor=' #4391f0'
     firebase.database().ref().child("/btl/ttb2").set(2);
    
    }
    
    else{
      tb2.innerText= "ON_TB2"
      //tb2.innerText= "ALL"
     tb2.style.color='#4391f0'
      document.getElementById('btn_tb2').style.backgroundColor='#fff'
      firebase.database().ref().child("/btl/ttb2").set(7);
     
    }
  }
  function btn_tb3(){
    if (tb3.innerHTML==="ON_TB3"){
       tb3.innerText= "OFF_TB3"
       tb3.style.color= "white"
     document.getElementById('btn_tb3').style.backgroundColor=' #4391f0'
     firebase.database().ref().child("/btl/ttb3").set(3);
    
    }
    
    else{
      tb3.innerText= "ON_TB3"
      //tb3.innerText= "ALL"
     tb3.style.color='#4391f0'
      document.getElementById('btn_tb3').style.backgroundColor='#fff'
      firebase.database().ref().child("/btl/ttb3").set(8);
     
    }
  }
  function btn_tb4(){
    if (tb4.innerHTML==="ON_TB4"){
       tb4.innerText= "OFF_TB4"
       tb4.style.color= "white"
     document.getElementById('btn_tb4').style.backgroundColor=' #4391f0'
     firebase.database().ref().child("/btl/ttb4").set(4);
  
    }
    
    else{
      tb4.innerText= "ON_TB4"
      //tb4.innerText= "ALL"
     tb4.style.color='#4391f0'
      document.getElementById('btn_tb4').style.backgroundColor='#fff'
      firebase.database().ref().child("/btl/ttb4").set(9);
    
    }
  }




  function click12(){
    $('#staticBackdrop').modal('show');
  }
  function btn_man(){
    document.getElementById('gr_input').style.display='block'
    firebase.database().ref().child("/btl/auto_man").set("m");
  }
  function btn_auto(){
    document.getElementById('gr_input').style.display='none'
    firebase.database().ref().child("/btl/auto_man").set("a");

  }

  var check = firebase.database().ref().child("/btl/check")
  check.on('value',function(check){
    // AS.innerHTML=check.val();

    console.log(check.val());
      //document.getElementById('couter').innerHTML=check.val();
      if(check.val()== 1){
      document.getElementById('status').innerHTML = "Đã kết nối"
      }
      else{
        document.getElementById('status').innerHTML = "Không kết nối UART"
      }
    });
  var red = firebase.database().ref().child("/btl/traffic")
  red.on('value',function(red){
    // AS.innerHTML=red.val();

    console.log(red.val());
      document.getElementById('couter').innerHTML=red.val();
    
    
    if(red.val()=='g'){
      document.getElementById('yeloow').style.backgroundColor='white'
      document.getElementById('green').style.backgroundColor='green'
      document.getElementById('red').style.backgroundColor='white'
    }
    });

    var gr = firebase.database().ref().child("/btl/traffic")
    gr.on('value',function(gr){
      // AS.innerHTML=gr.val();
  
      console.log(gr.val());
      document.getElementById('couter').innerHTML=gr.val();
      if(gr.val()=='y'){
        document.getElementById('yeloow').style.backgroundColor='yellow'
        document.getElementById('green').style.backgroundColor='white'
        document.getElementById('red').style.backgroundColor='white'
      }
      });

      var yl = firebase.database().ref().child("/btl/traffic")
      yl.on('value',function(yl){
        // AS.innerHTML=yl.val();
    
        console.log(yl.val());
        document.getElementById('couter').innerHTML=yl.val();
        if(yl.val()=='r'){
          document.getElementById('yeloow').style.backgroundColor='white'
          document.getElementById('green').style.backgroundColor='white'
          document.getElementById('red').style.backgroundColor='red'
        }
        });

// tb1
        var tb11 = firebase.database().ref().child("btl/ttb1")
        tb11.on('value',function(tb11){
          if(tb11.val()== 1)
          {
            document.getElementById('tb_1').style.backgroundColor='green'

          }
          if(tb11.val()==0){
            document.getElementById('tb_1').style.backgroundColor='red'
          }
          console.log(tb11.val());
          });
// tb2
          var tb22 = firebase.database().ref().child("btl/ttb2")
          tb22.on('value',function(tb22){
            if(tb22.val()== 2)
            {
              document.getElementById('tb_2').style.backgroundColor='green'
  
            }
            if(tb22.val()==7){
              document.getElementById('tb_2').style.backgroundColor='red'
            }
            console.log(tb22.val());
            });
// tb3
            var tb33 = firebase.database().ref().child("btl/ttb3")
            tb33.on('value',function(tb33){
              if(tb33.val()== 3)
              {
                document.getElementById('tb_3').style.backgroundColor='green'
    
              }
              if(tb33.val()==8){
                document.getElementById('tb_3').style.backgroundColor='red'
              }
              console.log(tb33.val());
              });
//tb4
              var tb44 = firebase.database().ref().child("btl/ttb4")
              tb44.on('value',function(tb44){
                if(tb44.val()== 4)
                {
                  document.getElementById('tb_4').style.backgroundColor='green'
      
                }
                if(tb44.val()==9){
                  document.getElementById('tb_4').style.backgroundColor='red'
                }
                console.log(tb44.val());
                });

// auto manual 
//manual
function manual(){
  firebase.database().ref().child("/btl/auman").set("j");
  console.log("j")
  document.getElementById('btnau').style.backgroundColor='white'
  document.getElementById('btnau').style.color='#1e90ff'
}
function au(){
  firebase.database().ref().child("/btl/auman").set("f");
  console.log("f")
  document.getElementById('btnman').style.backgroundColor='white'
  document.getElementById('btnman').style.color='#1e90ff'
}

var automan = firebase.database().ref().child("/btl/auman")

automan.on('value',function(automan){
if(automan.val()=='f'){
  document.getElementById('btnau').style.backgroundColor='#1e90ff'
  document.getElementById('btnau').style.color='white'
}
if(automan.val()=='j'){
  document.getElementById('btnman').style.backgroundColor='#1e90ff'
  document.getElementById('btnman').style.color='white'
}

});

// kiem tra nut bam 


function btn_all(){
  if (all.innerHTML==="ON_ALL"){
     all.innerText= "OFF_ALL"
     all.style.color= "white"
   document.getElementById('btn_all1').style.backgroundColor=' #4391f0'
    firebase.database().ref().child("/btl/ttb1").set(1);
    firebase.database().ref().child("/btl/ttb2").set(2);
    firebase.database().ref().child("/btl/ttb3").set(3);
    firebase.database().ref().child("/btl/ttb4").set(4);
    tb1.innerText= "OFF_TB1"
    tb2.innerText= "OFF_TB2"
    tb3.innerText= "OFF_TB3"
    tb3.innerText= "OFF_TB4"
    document.getElementById('btn_tb1').style.backgroundColor=' #4391f0'
    document.getElementById('btn_tb2').style.backgroundColor=' #4391f0'
    document.getElementById('btn_tb3').style.backgroundColor=' #4391f0'
    document.getElementById('btn_tb4').style.backgroundColor=' #4391f0'

    // font 
    document.getElementById('btn_tb1').style.color='white'
    document.getElementById('btn_tb2').style.color='white'
    document.getElementById('btn_tb3').style.color='white'
    document.getElementById('btn_tb4').style.color='white'
  }

  else{
    all.innerText= "ON_ALL"
    //all.innerText= "ALL"
   all.style.color='#4391f0'
    document.getElementById('btn_all1').style.backgroundColor='white'
   
     //firebase.database().ref().child("/btl/all").set(6);
     firebase.database().ref().child("/btl/ttb1").set(0);
     firebase.database().ref().child("/btl/ttb2").set(7);
     firebase.database().ref().child("/btl/ttb3").set(8);
     firebase.database().ref().child("/btl/ttb4").set(9);

     tb1.innerText= "ON_TB1"
     tb2.innerText= "ON_TB2"
     tb3.innerText= "ON_TB3"
     tb3.innerText= "ON_TB4"
     document.getElementById('btn_tb1').style.backgroundColor=' white'
     document.getElementById('btn_tb2').style.backgroundColor=' white'
     document.getElementById('btn_tb3').style.backgroundColor=' white'
     document.getElementById('btn_tb4').style.backgroundColor=' white'

    //  font color 
    document.getElementById('btn_tb1').style.color='#4391f0'
    document.getElementById('btn_tb2').style.color='#4391f0'
    document.getElementById('btn_tb3').style.color='#4391f0'
    document.getElementById('btn_tb4').style.color='#4391f0'
  }
}


function red1(){
  firebase.database().ref().child("/btl/ledtr").set("r");
  console.log("r")

}
function yl1(){
  firebase.database().ref().child("/btl/ledtr").set("y");
  console.log("y")

}
function gr1(){
  firebase.database().ref().child("/btl/ledtr").set("g");
  console.log("g")
}
