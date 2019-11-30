<?php
require_once 'Database.php';

$database = new Database();
$products = $database->GetAllProducts();
$con = $database->GetDatabaseInstance();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>smartFridge</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="index.css" type="text/css" media="screen">
    <script>

        function deleteIfYes(ean, name) {
            if (window.confirm("Bist du sicher, dass du \"" + name + "\" (Ean " + ean + ") löschen willst?")) {
                window.location.href="delete.php?id=" + ean;

            }
        }
    </script>

</head>
<body>


<h1><b>Current items-list</b></h1>
<table>
    <tr>
        <th>Name</th>
        <th>Amount</th>
        <th>Added</th>
        <th>Edit</th>
        <th>Delete</th>
    </tr>
    <?php
    if ($products->num_rows > 0):
        while ($row = $products->fetch_assoc()):
            ?>
            <tr>
                <td><?php echo $row["Name"] ?></td>
                <td><?php echo $row["Amount"] ?></td>
                <td><?php echo $row["Date"] ?></td>
                <td>
                    <a href="add_remove.php?id=<?php echo $row['Ean'] ?>">
                        <button>Edit</button>
                    </a>
                </td>
                <td>
                    <button onclick="deleteIfYes(<?php echo $row['Ean']; ?>, '<?php echo $row['Name']; ?>') ">
                            Delete
                    </button>
                </td>
            </tr>
        <?php
        endwhile;
    endif;
    ?>
</table>
</body>
</html>