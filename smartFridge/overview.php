<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" href="overview.css" type="text/css" media="screen" >

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
    <?php
    /**
     * Created by PhpStorm.
     * User: thomaslang
     * Date: 27.09.19
     * Time: 13:17
     */
    $conn = mysqli_connect('', 'admin', 'hfict', 'smartFridge','3307', '');
    if ($conn-> connect_error) {
        die("connection failed:". $conn-> connect_error);
    }
    $sql = "SELECT id, Product_Name, Amount, Date_Added from smartFridge";
    $result = $conn-> query($sql);

    if($result-> num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            echo "<tr><td>" . $row["id"] . "</td><td></td>" . $row["Product_Name"] . "</td><td></td>" . $row["Amount"]
                . "</td><td></td>" . $row["Date_Added"];
        }
        echo "</table>";
    }
    else{
        echo "0 result";
    }
    $conn-> close();
    ?>

</body>
</html>

