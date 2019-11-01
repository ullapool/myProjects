<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/index.css" type="text/css" media="screen" >
    <?php

    $servername = "127.0.0.1";
    $username = "root@localhost";
    $password = "hfict";
    $DbName = "smartFridge";
    $portNum = "3307";

    // Create connection
    $conn = new mysqli($servername,$portNum, $DbName, $username, $password);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    echo "Connected successfully";


    $sql = "SELECT id, Product_Name, Amount, Date_Added FROM products";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        echo "<table><tr><th>ID</th><th>Name</th></tr>";
        // output data of each row
        while($row = $result->fetch_assoc()) {
            echo "<tr><td>".$row["id"]."</td><td>".$row["Product_Name"]." ".$row["Amount"]." ".$row["Date_Added"]."</td></tr>";
        }
        echo "</table>";
    } else {
        echo "0 results";
    }
    $conn->close();
    ?>

</head>
    <body>
    <h1><b>Current items-list</b></h1>

    <form>
        <table>
            <tr>
                <th>Product</th>
                <th>Amount</th>
                <th>Edit</th>
                <th>Delete</th>
            </tr>

            <tr>
                <td>Milk</td>
                <td>1</td>
                <td> <input type="button" value="edit" onclick="window.location.href='add_remove.php'"> </input></td>
                <td> <input type="button" value="delete" onclick="window.location.href='add_remove.php'"> </input></td>
            </tr>

            <tr>
                <td>Creme Fraiche</td>
                <td>2</td>
                <td> <input type="button" value="edit" onclick="window.location.href='add_remove.php'"> </input></td>
                <td> <input type="button" value="delete" onclick="window.location.href='add_remove.php'"> </input></td>
            </tr>

            <tr>
                <td>Bier</td>
                <td>10</td>
                <td> <input type="button" value="edit" onclick="window.location.href='add_remove.php'"> </input></td>
                <td> <input type="button" value="delete" onclick="window.location.href='add_remove.php'"> </input></td>
            </tr>

            <tr>
                <td>Mozarella</td>
                <td>1</td>
                <td> <input type="button" value="edit" onclick="window.location.href='add_remove.php'"> </input></td>
                <td> <input type="button" value="delete" onclick="window.location.href='add_remove.php'"> </input></td>
            </tr>

        </table>
    </form>

</body>
</html>

