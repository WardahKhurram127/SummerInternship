<?php
$servername = "localhost";
$username = "root";         
$password = "";             
$database = "practice"; 

$conn = mysqli_connect($servername, $username, $password, $database);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$sql = "SELECT * FROM employees";
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    echo "<h2>Employees Records:</h2>";
    while ($row = mysqli_fetch_assoc($result)) {
        echo "<p>";
        echo "ID: " . $row["e_id"] . "<br>";
        echo "Name: " . $row["e_name"] . "<br>";
        echo "Role: " . $row["role"] . "<br>";
        echo "Date of Joining: " . $row["date_of_joining"] . "<br>";
        echo "-------------------------";
        echo "</p>";
    }
} else {
    echo "No records found.";
}

mysqli_close($conn);
?>
