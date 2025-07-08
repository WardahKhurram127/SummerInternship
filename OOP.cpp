#include<iostream>
using namespace std;
//Base Class: User
class User {        //this is an abstract class becoz it has virtual function.can't create objects of abstract class(User u;?)(User* u = new Student();? pointer to abstract base class)
private:
	//-> Encapsulation:making variables private and then get them by getters setters
	string name;
	string email;
public:
	//Public getter setters 
	void setName(string n)
	{
		name = n;
	}
	void setEmail(string e)
	{
		email = e;
	}
	string getName()
	{
		return name;
	}
	string getEmail()
	{
		return email;
	}
	//pure virtual function (just declaring the function here, every child class has its own definition of this functionn.) 
	virtual void dashboard() = 0; //making it virtual so that it can be overridden by a derived class
	virtual ~User() {}       //destructor
};

//Derived Class:Student ->INHERITANCE
class Student : public User {
private:
	string course;
public:
	void setCourse(string c)
	{
		course = c;
	}
	string getCourse()
	{
		return course;
	}
	//polymorphism that it works for student logic here
	void dashboard() override {
		cout << "************Student Dashboard for " << getName() <<"***********" << endl;
		cout << "Course Enrolled" << getCourse() << endl;
		cout << "Check Lectures and assignments.";
	}
};

class Teacher : public User {
private:
	string department;
public:
	void setDepartment(string d)
	{
		department = d;
	}
	string getDepartment()
	{
		return department;
	}
	void dashboard() override {
		cout<< "************Teacher Dashboard for " << getName() << "***********" << endl;
		cout << "Department" << getDepartment() << endl;
		cout << "Upload lectures and grade students.";
	}
};

int main()
{
	User* user1 = new Student();
	user1->setName("Wardah");
	user1->setEmail("wardahkh.11@gmail.com");
	((Student*)user1)->setCourse(": Artificial Intelligence");

	User* user2 = new Teacher();
	user2->setName("Yasar Mehmood");
	user2->setEmail("yasar.mehmood@gmail.com");
	((Teacher*)user2)->setDepartment(": Software Engineering");

	user1->dashboard();
	cout << endl;
	user2->dashboard();

	delete user1;
	delete user2;
}





