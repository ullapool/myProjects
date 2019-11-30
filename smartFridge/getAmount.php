<?php
require_once 'Database.php';
//used to call function in Database.php
$id = $_GET['id'];
$database = new Database();
$database->GetSelectedProduct($id);
header('Location: add_remove.php');
