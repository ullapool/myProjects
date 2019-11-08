<?php
//echo only for testing
echo("Scan your Barcode\n");

//get scanned barcode from cli
$ean = readline();
echo("\r\n");
//connection token for db
$token = 'replace with password';
$xml = file_get_contents("https://api.ean-search.org/api?"."op=barcode-lookup&token=$token&ean=$ean");
//get full name of product
$response = new SimpleXMLElement($xml);
$productName = $response->product->name;
//check if available
if ($response == "Barcode not found") {
echo ("EAN $ean no product found\n");
} else {
    //spilt full name
    $prodName = explode(" ", $productName);
    //use common product name
    echo ("EAN $ean => $prodName[2] \n");
//save digit in separate var -> will be used as amount in db
preg_match_all('!\d+!', $productName, $matches);
$amount = $matches[0][0];
echo("Amount: $amount");
}
?>

