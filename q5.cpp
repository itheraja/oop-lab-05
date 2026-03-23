#include <iostream>
using namespace std;


class Department {
public:
    string name;
    string code;

    Department() {}  // default constructor
    Department(string n, string c) {
        name = n;
        code = c;
    }

    void display() {
        cout << "Department: " << name << " (" << code << ")" << endl;
    }
};


class Student {
public:
    string name;
    int age;
    Department dept; // composition

    Student() {}  // default constructor
    Student(string n, int a, Department d) {
        name = n;
        age = a;
        dept = d;
    }

    void display() {
        cout << "Student Name: " << name << ", Age: " << age << endl;
        dept.display();
      
    }
};

int main() {
    cout << "University Students:\n\n";

    // Create Departments
    Department cs("Computer Science", "CS");
    Department ee("Electrical Engineering", "EE");
    Department me("Mechanical Engineering", "ME");

    // Create Students array
    Student students[3] = {
        Student("Ali", 20, cs),
        Student("Sara", 21, ee),
        Student("Hamza", 22, me)
    };

    // Display all students
    for (int i = 0; i < 3; i++) {
        students[i].display();
    }

    return 0;
}
