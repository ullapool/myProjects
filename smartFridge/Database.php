<?php
$database = new Database();
if ($_GET['m'] == 1)
{
    echo "Test ist Test 11";
}
elseif ($_GET['m'] == 2){
    echo json_encode($database->GetAllProducts());
}
elseif ($_GET['m'] == 3){
    $database->RemoveProduct($_GET['ean']);
    echo json_encode($database->GetAllProducts());
}
elseif ($_GET['m'] == 4)
{
    echo json_encode($database->GetSelectedProduct($_GET['ean']));
}
elseif ($_GET['m'] == 5)
{
    $database->IncreaseAmount($_GET['ean']);
    echo json_encode($database->GetSelectedProduct($_GET['ean']));
}
elseif ($_GET['m'] == 6)
{
    $database->ReduceAmount($_GET['ean']);
    echo json_encode($database->GetSelectedProduct($_GET['ean']));
}


class Database
{

    private static $connectionInstance;

    function __construct()
    {
        if (static::$connectionInstance === null) {
            static::$connectionInstance = new mysqli("127.0.0.1", "admin", "hfict", "smartFridge");
        }
        return static::$connectionInstance;
    }

    public function GetDatabaseInstance()
    {
        return static::$connectionInstance;
    }

    public function GetAllProducts()
    {
        $connection = Database::GetDatabaseInstance();
        $result = mysqli_query($connection, "SELECT * FROM products WHERE Amount > 0");
        $data = array();
        while ($row = mysqli_fetch_assoc($result)) {
            $data[] = $row;
        }

        return $data;
    }

    public function GetSelectedProduct($EAN)
    {
        $connection = Database::GetDatabaseInstance();
        $result = mysqli_query($connection, "SELECT * FROM products WHERE EAN = $EAN");
        $data = array();
        while ($row = mysqli_fetch_assoc($result)) {
            $data[] = $row;
        }
        return $data;
    }
    public function RemoveProduct($EAN)
    {
        $connection = Database::GetDatabaseInstance();
        $stmt = $connection->prepare("UPDATE products SET Amount = 0 WHERE EAN = ?");
        $stmt->bind_param("s", $EAN);
        return $stmt->execute();
    }

    public function IncreaseAmount($EAN)
    {
        $connection = Database::GetDatabaseInstance();
        mysqli_query($connection, "UPDATE products SET Amount = Amount + 1 WHERE EAN = $EAN");
    }

    public function ReduceAmount($EAN)
    {
        $connection = Database::GetDatabaseInstance();
        mysqli_query($connection, "UPDATE products SET Amount = Amount - 1 WHERE EAN = $EAN");
    }
}