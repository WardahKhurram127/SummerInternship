<?php
require_once 'Employee.php';

class EmployeeDecorator extends Employee {
    protected $employee;

    public function __construct(Employee $employee) {
        parent::__construct($employee->name, $employee->role, $employee->doj);
        $this->employee = $employee;
    }

    public function getInfo() {
        return $this->employee->getInfo();
    }
}

class BadgeDecorator extends EmployeeDecorator {
    public function getInfo() {
        $baseInfo = parent::getInfo();
        return $baseInfo . "<br><strong>[Badge: {$this->employee->role}]</strong>";
    }
}
