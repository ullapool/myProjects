<?php
require_once "Database.php";
$database = new Database();
$con = $database->GetDatabaseInstance();
//echo only for testing
//echo("Scan your Barcode\n");
//$trigger = 1;
//get Barcode from remote local machine

$ean = $_REQUEST['ean'];
//$response["x"]= "Hey";
//json_encode($response);


//$query = "SELECT * FROM products WHERER EAN = $ean";
/*$result = $con->query($query);
if($result) {
    if(mysqli_num_rows($result)) {
        header('Location: add_remove.php');
    }
} else { */

//connection token for remote db
    $token = 'hfict17';
    $xml = file_get_contents("https://api.ean-search.org/api?" . "op=barcode-lookup&token=$token&ean=$ean");
//get full name of product
    $response = new SimpleXMLElement($xml);
    $productName = $response->product->name;
//check if available
    echo $response;
    if ($response == "test") {
        echo("EAN $ean no product found\n");
    } else {
        $productName = $response->product->name;
        $amount = 1;

        //echo ("EAN $ean => $productName \n");

        $sql = "insert into products (EAN, Name, Amount) values(?,?,?)";
        $stmt = $con->prepare($sql);
        $stmt->bind_param('isi', $ean, $productName, $amount);
        echo $stmt->execute();


}
?>

