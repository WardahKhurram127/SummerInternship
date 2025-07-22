<?php
class Employee {
    protected $name;
    protected $role;
    protected $doj;

    public function __construct($name, $role, $doj) {
        $this->name = $name;
        $this->role = $role;
        $this->doj = $doj;
    }

    public function getInfo() {
        return "Name: {$this->name}<br>Role: {$this->role}<br>Date of Joining: {$this->doj}";
    }
}

// Factory Method
class EmployeeFactory {
    public static function create($name, $role, $doj) {
        return new Employee($name, $role, $doj);
    }
}
?>
