#include <iostream>
#include <vector>
#include "employee.h"

using namespace std;


certificate::certificate(int ID1, string cer_name1, string cer_date1, string cer_rank1)
    : ID(ID1), cer_name(cer_name1), cer_date(cer_date1), cer_rank(cer_rank1) {}

void certificate::show_Info() const {
    cout << "Certificate ID: " << ID << endl;
    cout << "Certificate Name: " << cer_name << endl;
    cout << "Certificate Date: " << cer_date << endl;
    cout << "Certificate Rank: " << cer_rank << endl;
}


Employee::Employee(int ID1, string fulname1, string birthday1, string phone1, string email1, employee_type type1)
    : ID(ID1), fulname(fulname1), birthday(birthday1), phone(phone1), email(email1), type(type1) {}

void Employee::show_Info() const {
    cout << "ID: " << ID << endl;
    cout << "Fulname: " << fulname << endl;
    cout << "Birthday: " << birthday << endl;
    cout << "Phone number: " << phone << endl;
    cout << "Email: " << email << endl;
    switch (type) {
        case exp: {
            cout << "Employee Type: Experienced" << endl;
            break;
        }
        case fresher: {
            cout << "Employee Type: Fresher" << endl;
            break;
        }
        case intern: {
            cout << "Employee Type: Intern" << endl;
            break;
        }
    }
    // Display all certificates
    cout << "Certificates: " << certificates.size();
    for (const auto &cert : certificates) {
        cert.show_Info();
    }
}

void Employee::add_Certificate(int cer_ID, string cer_name, string cer_date, string cer_rank) {
    certificates.push_back(certificate(cer_ID, cer_name, cer_date, cer_rank));
}

int Employee::get_ID() const {
    return ID;
}

const vector<certificate>& Employee::get_Certificates() const {
    return certificates;
}


Experience::Experience(int ID1, string fulname1, string birthday1, string phone1, string email1, int exp_years, string skills)
    : Employee(ID1, fulname1, birthday1, phone1, email1, exp), years_of_experience(exp_years), special_skills(skills) {}

void Experience::show_Info() const {
    Employee::show_Info();
    cout << "Years of Experience: " << years_of_experience << endl;
    cout << "Special Skills: " << special_skills << endl;
}



Fresher::Fresher(int ID1, string fulname1, string birthday1, string phone1, string email1, string graduation_date, string graduation_rank, string graduation_uni)
    : Employee(ID1, fulname1, birthday1, phone1, email1, fresher), gra_date(graduation_date), gra_rank(graduation_rank), gra_uni(graduation_uni) {}

void Fresher::show_Info() const {
    Employee::show_Info();
    cout << "Graduation Date: " << gra_date << endl;
    cout << "Graduation Rank: " << gra_rank << endl;
    cout << "Graduation University: " << gra_uni << endl;
}


Intern::Intern(int ID1, string fulname1, string birthday1, string phone1, string email1, string major1, string semester1, string uni_name1)
    : Employee(ID1, fulname1, birthday1, phone1, email1, intern), major(major1), semester(semester1), uni_name(uni_name1) {}

void Intern::show_Info() const  {
    Employee::show_Info();
    cout << "Major: " << major << endl;
    cout << "Semester: " << semester << endl;
    cout << "Uni_name: " << uni_name << endl;
}




Employyee_management::~Employyee_management() {
    // Release any resources, delete dynamically allocated objects
    for (Employee* emp : nv1) {
        delete emp;
    }
    nv1.clear();
}
void Employyee_management::show_Emp(int id) const {
    bool check = false;
    for (int i = 0; i < nv1.size(); i++) {
        if (nv1[i]->get_ID() == id) {
            nv1[i]->show_Info();
            check = true;
            break;
        }
    }
    if (check == false)
        cout << "NhÃ¢n viÃªn khÃ´ng tá»“n táº¡i" << endl;
}

void Employyee_management::show_All_Certificates(int id) const {
    bool check = false;
    for (const auto &emp : nv1) {
        if (emp->get_ID() == id) {
            const vector<certificate> &certificates = emp->get_Certificates();
            for (const auto &cert : certificates) {
                cert.show_Info();
            }
            check = true;
            break;
        }
    }
    if (!check)
        cout << "NhÃ¢n viÃªn khÃ´ng tá»“n táº¡i" << endl;
}

void Employyee_management::add_Emp(Employee * nv) {
    nv1.push_back(nv);
    count++;
}

void Employyee_management::delete_Emp(int id) {
    for (auto it = nv1.begin(); it != nv1.end(); ++it) {
        if ((*it)->get_ID() == id) {
            delete *it;
            nv1.erase(it);
            count--;
            cout << "NhÃ¢n viÃªn vá»›i ID " << id << " Ä‘Ã£ Ä‘Æ°á»£c xÃ³a." << endl;
            return;
        }
    }
    cout << "NhÃ¢n viÃªn khÃ´ng tá»“n táº¡i" << endl;
}

void Employyee_management::get_Emp() {
    cout << "Sá»‘ nhÃ¢n viÃªn trong cÃ´ng ty lÃ : " << count << endl;
}


int Employyee_management::count = 0;


