#include <iostream>
#include <string>
#include "Employee.h"

Employee::Employee(int id, std::string firstName, std::string lastName, int salary) {

}

int Employee::GetId() {
	return _id;
}

std::string Employee::GetFirstName()
{
	return _firstName;
}

std::string Employee::GetLastName() {
	return _lastName;
}

std::string Employee::GetName()
{
	return (_firstName + _lastName);
}

int Employee::GetSalary() {
	return _salary;
}

int Employee::GetAnualSalary() {
	return _salary*12;
}

std::string Employee::Print()
{
	return (std::to_string(_id) + "Name= " + _firstName + " " + _lastName + std::to_string(_salary));
}

void Employee::SetSalary(int salary)
{
	_salary = salary;
}

int Employee::RaiseSalary(int percent)
{
	return _salary * (percent/100);
}
