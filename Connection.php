<?php
class DBConnection 
{
    private static $instance = null;
    private $conn;

    private $servername = "localhost";
    private $username = "root";
    private $password = "";

    private function __construct() 
    {
        $this->conn = mysqli_connect($this->servername, $this->username, $this->password);
        if (!$this->conn) 
        {
            die("Connection failed: " . mysqli_connect_error());
        }
    }
   
    public static function getInstance() 
    {
        if (!self::$instance) 
        {
            self::$instance = new DBConnection();
        }
        return self::$instance;
    }

    public function getConnection() 
    {
        return $this->conn;
    }
}
$db = DBConnection::getInstance();
$conn = $db->getConnection();

echo "Connection Successful<br>";

$sql = "CREATE DATABASE dbwardah0";
$result = mysqli_query($conn, $sql);

if ($result) 
{
    echo "DB created...";
} else 
{
    echo "DB not created. Error: " . mysqli_error($conn);
}
?>
