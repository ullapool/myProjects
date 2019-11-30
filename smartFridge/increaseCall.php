<?php
require_once 'Database.php';
$ean = $_GET['id'];
$database = new Database();
$database->IncreaseAmount($ean);
header('Location: add_remove.php');
?>
