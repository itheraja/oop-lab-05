#include <iostream>
using namespace std;


class Project {
public:
    string projectTitle;
    int duration; // in months

    Project() {}
    Project(string title, int dur) {
        projectTitle = title;
        duration = dur;
    }

    void display() {
        cout << "Project: " << projectTitle << ", Duration: " << duration << " months" << endl;
    }
};


class Employee {
private:
    string empName;
    float salary;
    Project project; // Aggregation: Employee "has-a" Project

public:
    static float taxRate; // Shared across all employees

    // Constructor
    Employee(string name, float sal, Project p) {
        empName = name;
        salary = sal;
        project = p;
    }

    // Const function to calculate net salary
    float calculateNetSalary() const {
        float net = salary - (salary * taxRate / 100);
        return net;
    }

    // Static function to change tax rate
    static void changeTaxRate(float newRate) {
        taxRate = newRate;
        cout << "Tax rate updated to " << taxRate << "% for all employees.\n";
    }

    // Display employee info
    void display() const {
        cout << "\nEmployee: " << empName << endl;
        cout << "Gross Salary: $" << salary << endl;
        cout << "Net Salary: $" << calculateNetSalary() << endl;
        project.display();
        cout << "Tax Rate: " << taxRate << "%" << endl;
        cout << "--------------------------\n";
    }
};

// Initialize static member
float Employee::taxRate = 10.0;

int main() {
    cout << "Company Employees and Projects\n\n";

    // Create Projects
    Project p1("AI Development", 12);
    Project p2("Mobile App", 6);
    Project p3("Web Portal", 9);

    // Create Employee array
    Employee employees[3] = {
        Employee("Ali", 5000, p1),
        Employee("Sara", 6000, p2),
        Employee("Hamza", 5500, p3)
    };

    // Display all employees
    for (int i = 0; i < 3; i++) {
        employees[i].display();
    }

    cout << "\nUpdating Tax Rate to 12%...\n";
    Employee::changeTaxRate(12);

    // Display again after tax rate change
    for (int i = 0; i < 3; i++) {
        employees[i].display();
    }

    return 0;
}
