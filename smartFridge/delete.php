<?php
require_once 'Database.php';
//used to call function in Database.php
$id = $_GET['id'];
$database = new Database();
$database->RemoveProduct($id);
header('Location: index.php');
