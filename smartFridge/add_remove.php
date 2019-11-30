<!DOCTYPE html>
<html lang="en">
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>"SmartFridge"</title>
    <link rel="stylesheet" href="add_remove.css" type="text/css" media="screen">
    <script>
        var strDecrease;
        var strIncrease;
        var strCurrentAmount;
           function IncreaseAmount(strIncrease){
               window.location.href="increaseCall.php?id=" + strIncrease;

           }

           function DecreaseAmount(strDecrease) {
               window.location.href="decreaseCall.php?id=" + strDecrease;

           }

           function getCurrentAmount(strCurrentAmount) {

                window.location.href="getAmount.php?id=" + strCurrentAmount;
           }
    </script>

</head>

<body>
<a href="index.php" class="previous round"> back</a>

<h1>Increase or reduce/remove this product</h1>

<?php
    require_once 'Database.php';
    $id = $_GET['id'];
    $database = new Database();
// echo $database->GetSelectedProduct($id)
?>

<div class="image-counter">

    <img src="img/barcode.png" alt="placeholder">
    <div class="buttons">
        <div class="round-button-outer">
            <div class="round-button green">
                <a type="button"   onclick=" IncreaseAmount(strIncrease = '<?php echo $id ?>')"
                   class="round-button">Increase</a>


            </div>
        </div>
        <div class="round-button-outer">
            <div class="round-button submit">
                <a type="text"  class="round-button"><?php echo $database->GetSelectedProduct($id)?></a>
            </div>
        </div>

        <div class="round-button-outer">
            <div class="round-button red">
                <a type="button" id="decrement" onclick=" DecreaseAmount(strDecrease = '<?php echo $id ?>') "
                   class="round-button">Reduce</a>


            </div>
        </div>

    </div>


</div>
</body>
</html>