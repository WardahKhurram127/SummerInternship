<?php
require_once 'Database.php';
require_once 'Employee.php';
require_once 'EmployeeDecorator.php';
require_once 'Subject.php';

$conn = Database::getInstance()->getConnection();

$subject = new Subject();
$subject->attach(new Logger());

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $name = $_POST['e_name'];
    $role = $_POST['role'];
    $doj = $_POST['date_of_joining'];

    $emp = EmployeeFactory::create($name, $role, $doj);
    $decorated = new BadgeDecorator($emp);

    $stmt = $conn->prepare("INSERT INTO employees (e_name, role, date_of_joining) VALUES (?, ?, ?)");
    $stmt->bind_param("sss", $name, $role, $doj);
    if ($stmt->execute()) {
        $subject->notify("New employee added: $name ($role)");
        echo "<p style='color:green;'>Employee added successfully!</p>";
    }

    echo $decorated->getInfo();
}
?>

<h2>Add Employee</h2>
<form method="POST">
    <input type="text" name="e_name" placeholder="Name" required><br>
    <input type="text" name="role" placeholder="Role" required><br>
    <input type="date" name="date_of_joining" required><br>
    <input type="submit" value="Add">
</form>
