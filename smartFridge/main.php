<!DOCTYPE html>

<html>
<head id="secondPage">
    <title>"SmartFridge"</title>
    <link rel="stylesheet" href="style.css"  type="text/css" media="screen" >

     <script type="text/javascript">

         var amount = 1;


         function increaseValue(){
             amount = document.getElementById("changeValue").stepUp();

         }

         function decreaseValue() {
             amount = document.getElementById("changeValue").stepDown();
             if(amount < 0 ){
                 document.write("Amount can't be smaller than 0!");
                 amount = 0;
             }
         }
     </script>

    <?php
     /*  "version using php server sided"
    session_start();
    // Page was not reloaded via a button press
    if (!isset($_POST['add'])) {
        $_SESSION['attnum'] = 1; // Reset counter
    }
      */
    ?>
   <!--
   <form method='post'>
        <input name='add' type="submit" value='+'>
        <h3><em>att <?php /* echo $_SESSION['attnum']++ */?>: </em></h3>
    </form>
    -->

</head>
<a href="addRemove.php" class="previous round">&#8249;</a>
<h1>  Increase or reduce/remove this product</h1>

<body>

<div class="image-counter">
<img src=" img/ravioli.jpeg" alt="placeholder">
<h3>Amount:</h3>
<input type="number" id="changeValue" onchange="name=this.amount">
</div>


<div class="round-button"><div class="round-button-circle"><a type="submit" onclick="increaseValue()" class="round-button">Increase</a></div></div>

<div class="round-button-reduce"><div class="round-button-reduce-circle"><a type="submit" onclick="decreaseValue()" class="round-button-reduce">Reduce</a></div></div>


  <!--<input type="button" value="add" onclick=myFunction()>
<button  class="button btnAdd" type="submit" onclick="increaseValue()"> <b>Increase(+)</b> </button>
</div>
<div>
<button class="button btnRemove" type="submit" onclick="decreaseValue()"> <b>reduce(-)</b> or <b>remove</b> </button>
</div>-->

</body>

</html>

