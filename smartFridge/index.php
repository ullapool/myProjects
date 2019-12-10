<!DOCTYPE html>
<html lang="en">
<head>

    <title>smartFridge</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="index.css" type="text/css" media="screen">
</head>
<body>
<h1><b>Current items-list</b></h1>
<table>
    <tr>
        <!--<th>EAN</th>-->
        <th>Name</th>
        <th>Amount</th>
        <th>Added</th>
        <th>Edit</th>
        <th>Delete</th>
    </tr>
    <tbody id="1234">

    </tbody>

</table>
</body>
</html>
<script>

    var ajax = new XMLHttpRequest();
    var methode = "GET";
    var url = "Database.php?m=2";
    var asynch = true;

    ajax.open(methode,url,asynch);
    ajax.send();
    ajax.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200){
            var data= JSON.parse(this.responseText);
            console.log(data);
            updateSide(data);
        }
    }

    function deleteIfYes(ean, name) {
        if (window.confirm("Bist du sicher, dass du \"" + name + "\" (Ean " + ean + ") löschen willst?")) {
            //window.location.href="delete.php?id=" + ean;
            var methode = "GET";
            var url = "Database.php?m=3&ean="+ ean;
            var asynch = true;

            ajax.open(methode, url, asynch);
            ajax.send();
            ajax.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    var data= JSON.parse(this.responseText);
                    console.log(data);
                    updateSide(data);
                }
            }
        }
    }

    function updateSide(data) {
        var html = "";

        for (var i = 0;i < data.length; i++)
        {
            var ean = data[i].EAN;
            var name = data[i].Name;
            var amount = data[i].Amount;
            var date = data[i].Date;

            html += "<tr>";
           // html += "<td>" + ean + "</td>";
            html += "<td>" + name + "</td>";
            html += "<td>" + amount + "</td>";
            html += "<td>" + date + "</td>";
            html += "<td>" +
                "<a href='add_remove.php?ean="+data[i].EAN+"&amount="+data[i].Amount+"&name="+data[i].Name+"'>" +
                "<button>Edit</button>" +
                "</a>" +
                "</td>";
            html += "<td>" +
                "<button onclick='deleteIfYes("+data[i].EAN+")'>Delete</button>" +
                "</td>";
            html += "</tr>";
        }
        document.getElementById("1234").innerHTML = html;
    }
</script>