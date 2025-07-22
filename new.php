<?php
$servername = "localhost";
$username = "root";
$password = "";
$database = "practice";

$conn = mysqli_connect($servername, $username, $password, $database);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

if (isset($_GET['delete'])) {
    $id_to_delete = $_GET['delete'];
    $delete_sql = "DELETE FROM employees WHERE e_id = $id_to_delete";
    mysqli_query($conn, $delete_sql);
    header("Location: " . $_SERVER['PHP_SELF']);
    exit();
}

if (isset($_POST['update'])) {
    $e_id = $_POST['e_id'];
    $e_name = $_POST['e_name'];
    $role = $_POST['role'];
    $date_of_joining = $_POST['date_of_joining'];

    $update_sql = "UPDATE employees SET e_name='$e_name', role='$role', date_of_joining='$date_of_joining' WHERE e_id=$e_id";
    mysqli_query($conn, $update_sql);
    header("Location: " . $_SERVER['PHP_SELF']);
    exit();
}

if (isset($_POST['submit'])) {
    $e_name = $_POST['e_name'];
    $role = $_POST['role'];
    $date_of_joining = $_POST['date_of_joining'];

    $insert_sql = "INSERT INTO employees (e_name, role, date_of_joining) 
                   VALUES ('$e_name', '$role', '$date_of_joining')";

    mysqli_query($conn, $insert_sql);
    header("Location: " . $_SERVER['PHP_SELF']);
    exit();
}

$edit_mode = false;
$edit_record = null;
if (isset($_GET['edit'])) {
    $edit_id = $_GET['edit'];
    $edit_sql = "SELECT * FROM employees WHERE e_id = $edit_id";
    $edit_result = mysqli_query($conn, $edit_sql);
    if (mysqli_num_rows($edit_result) == 1) {
        $edit_record = mysqli_fetch_assoc($edit_result);
        $edit_mode = true;
    }
}
?>

<h2><?php echo $edit_mode ? "Update Employee" : "Add New Employee"; ?></h2>
<form method="post" action="">
    <?php if ($edit_mode): ?>
        <input type="hidden" name="e_id" value="<?php echo $edit_record['e_id']; ?>">
    <?php endif; ?>

    <label>Employee Name:</label><br>
    <input type="text" name="e_name" required value="<?php echo $edit_mode ? $edit_record['e_name'] : ''; ?>"><br><br>

    <label>Role:</label><br>
    <input type="text" name="role" required value="<?php echo $edit_mode ? $edit_record['role'] : ''; ?>"><br><br>

    <label>Date of Joining:</label><br>
    <input type="date" name="date_of_joining" required value="<?php echo $edit_mode ? $edit_record['date_of_joining'] : ''; ?>"><br><br>

    <input type="submit" name="<?php echo $edit_mode ? 'update' : 'submit'; ?>" value="<?php echo $edit_mode ? 'Update Employee' : 'Add Employee'; ?>">
</form>
<hr>

<?php
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
        echo "<a href='?edit=" . $row["e_id"] . "'>Edit</a> | ";
        echo "<a href='?delete=" . $row["e_id"] . "' onclick=\"return confirm('Are you sure?')\">Delete</a>";
        echo "<hr></p>";
    }
} else {
    echo "No records found.";
}

mysqli_close($conn);
?>
