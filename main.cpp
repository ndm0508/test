#include <iostream>
#include <vector>
#include "employee.h"

using namespace std;
int main() {
    Employyee_management company;

    // Add an experienced employee with a certificate
    Experience * expEmp = new Experience(1, "John Doe", "1990-01-01", "123-456-7890", "john@example.com", 5, "C++");
    expEmp->add_Certificate(101, "Programming Certificate", "2022-01-01", "Advanced");
    company.add_Emp(expEmp);

    // Add a fresher employee with a certificate
    Fresher * fresherEmp = new Fresher(2, "Jane Smith", "1995-05-15", "987-654-3210", "jane@example.com", "2023-06-01", "Excellent", "University of Tech");
    fresherEmp->add_Certificate(102, "Internship Certificate", "2024-01-01", "Outstanding");
    company.add_Emp(fresherEmp);

    // Add an intern employee without a certificate
    Intern * internEmp = new Intern(3, "Bob Johnson", "2000-08-20", "555-123-4567", "bob@example.com", "Computer Science", "Spring 2024", "Tech University");
    company.add_Emp(internEmp);

    // Show information for employee with ID 2
    company.show_Emp(2);

    // Show all certificates for employee with ID 2
    //cout << "\nCertificates for employee with ID 2:\n";
    //company.show_All_Certificates(2);

    // Show total number of employees in the company
    Employyee_management::get_Emp();

    return 0;
}