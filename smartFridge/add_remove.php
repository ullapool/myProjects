<!DOCTYPE html>
<html lang="en">
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>"SmartFridge"</title>
    <link rel="stylesheet" href="add_remove.css" type="text/css" media="screen">
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.2/jquery.min.js"></script>
</head>
<body>
<a href="index.php" class="previous round"> back</a>

<h1>Increase or reduce this product</h1>

<div class="image-counter">

    <p id="55" hidden><?php echo $_GET['ean']?></p>
    <video  controls autoplay loop>
        <source src="img/vid.mp4" type="video/mp4">
        Your browser does not support the video tag.
    </video>

    <h2><?php echo $_GET['name']?></h2>
    <div class="buttons">
        <div class="round-button-outer">
            <div class="round-button green">
                <a type="button" class="round-button" onclick="IncreaseAmount(<?php echo $_GET['ean']?>)">Increase</a>
            </div>
        </div>
        <div class="round-button-outer">
            <div class="round-button submit">
                <p id="1234" type="text" class="round-button"><?php echo $_GET['amount']?></p>
            </div>
        </div>

        <div class="round-button-outer">
            <div class="round-button red">
                <a type="button" id="decrement" class="round-button" onclick="ReduceAmount(<?php echo $_GET['ean']?>)">Reduce</a>
            </div>
        </div>
    </div>

    <div>
        <button class="trigger" type="button" onclick="">Start Scanner</button>
    </div>

    <script type="text/javascript">
        $(document).ready(function() {
            $("button").click(function(){
                $.ajax({
                    type: 'POST',
                    url: 'ssh.php',
                    success: function() {
                        alert();
                    }
                });
            });
        });
    </script>

</div>

</body>
</html>

<script>

    var ajax = new XMLHttpRequest();
    var methode = "GET";
    var url = "Database.php?m=4&ean=" +<?php echo $_GET['ean']?>;
    var asynch = true;

    ajax.open(methode,url,asynch);
    ajax.send();
    ajax.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200){
            console.log(this.response);
            document.getElementById("1234").innerText = <?php echo $_GET['amount']?>;
        }
    }

    function IncreaseAmount(EAN){
        var ajax = new XMLHttpRequest();
        var methode = "GET";
        var url = "Database.php?m=5&ean=" +EAN;
        var asynch = true;

        ajax.open(methode,url,asynch);
        ajax.send();
        ajax.onreadystatechange = function () {
            if (this.readyState == 4 && this.status == 200){
                var data= JSON.parse(this.responseText);
                console.log(this.response);
                updateSide(data);
            }
        }
    }

    function ReduceAmount(EAN){
        var ajax = new XMLHttpRequest();
        var methode = "GET";
        var url = "Database.php?m=6&ean=" +EAN;
        var asynch = true;

        ajax.open(methode,url,asynch);
        ajax.send();
        ajax.onreadystatechange = function () {
            if (this.readyState == 4 && this.status == 200){
                var data= JSON.parse(this.responseText);
                console.log(this.response);
                updateSide(data);
            }
        }
    }

    function updateSide(data) {
        var html = "";
        var amount;
        for (var i = 0;i < data.length; i++)
        {
            amount = data[i].Amount;
        }
        html += "<div class='round-button submit'>";
        html += "<p id='1234' type='text' class='round-button'>" + amount + "</p>";
        html += "</div>";
        document.getElementById("1234").innerHTML = html;
    }
</script>

