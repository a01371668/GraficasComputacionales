#pragma once

#include <string>

class Employee {
	public:
		Employee(int id, std::string firstName, std::string lastName, int salary);

		int GetId();
		std::string GetFirstName();
		std::string GetLastName();
		std::string GetName();
		int GetSalary();
		int GetAnualSalary();
		std::string Print();
		
		void SetSalary(int salary);
		int RaiseSalary(int percent);
	private:
		int _id;
		std::string _firstName;
		std::string _lastName;
		int _salary;
};