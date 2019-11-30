<?php

class Database
{
    private static $connectionInstance;
    function __construct()
    {
        if (static::$connectionInstance === null) {
            static::$connectionInstance = new mysqli("127.0.0.1", "root","hfict","smartFridge");
        }
        return static::$connectionInstance;
    }
    public function GetDatabaseInstance()
    {
        return static::$connectionInstance;
    }
    public function CloseDatabaseConnection($connection){
        $connection->close();
        static::$connectionInstance = null;
    }
    public function GetAllProducts()
    {
        $connection = Database::GetDatabaseInstance();
        $sql = "SELECT Ean, Name, Amount, Date FROM products WHERE Amount > 0";
        $products = $connection->query($sql);
        return $products;
    }

    public function GetSelectedProduct($EAN)
    {
        $connection = Database::GetDatabaseInstance();
        //$result = mysqli_query($connection, "SELECT * FROM products WHERE Ean = $EAN");
        //$row = mysqli_fetch_row($result);
        //return $row;
        $sql = "SELECT Amount FROM products WHERE Ean = $EAN";
        $result = $connection->query($sql);
        //$result->bind_param("s",$EAN);
        if($result->num_row >=0) {
            while($row = mysqli_fetch_assoc($result)) {
                return $row['Amount'];
            }
            } else {
            return null;
        }
        //$row = mysqli_fetch_assoc(mysqli_query($connection, $sql));
       // $amount = $row['Amount'];
        //$row = mysqli_result(mysqli_query($connection, $sql));



        /*$connection = Database::GetDatabaseInstance();
        $sql = "SELECT * FROM products WHERE Ean = ?";
        $stmt = $connection->prepare($sql);
        $stmt->bind_param("s",$EAN);
        $stmt->execute();
        return $stmt->get_result();*/

    }
    public function AddProduct($EAN,$Name,$Amount,$Date){
        $connection = Database::GetDatabaseInstance();
        $sql = "INSERT INTO Product(Ean, Name, Amount, Date) VALUES(?,?,?,?)";
        $stmt= $connection->prepare($sql);
        $stmt->bind_param("ssis", $EAN, $Name, $Amount,$Date);
        return $stmt->execute();
    }

    public function RemoveProduct($EAN)
    {
        $connection = Database::GetDatabaseInstance();
        $stmt = $connection->prepare("UPDATE products SET Amount = 0 WHERE Ean = ?");
        $stmt->bind_param("s", $EAN);
        return $stmt->execute();

    }
    public function IncreaseAmount($EAN)
    {
        $connection = Database::GetDatabaseInstance();
        $stmt = "UPDATE products SET Amount = Amount + 1 WHERE Ean = ?";
        $stmt = $connection->prepare($stmt);
        $stmt->bind_param("s", $EAN);
        return $stmt->execute();
        //$stmt->execute();
        /*if(mysqli_query($connection, $sql)) {

            header('Location: add_remove.php');
        } else {
            echo "Error";
        }*/
    }

    public function DecreaseAmount($EAN)
    {
        $connection = Database::GetDatabaseInstance();
        //$product = $this->GetSelectedProduct($EAN);
        $stmt ="UPDATE products SET Amount = Amount - 1 WHERE Ean = ?";
        $stmt = $connection->prepare($stmt);
        $stmt->bind_param("s",$EAN);
        return $stmt->execute();
    }
}