#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum employee_type {
    exp = 0,
    fresher = 1,
    intern = 2
};

class certificate {
private:
    int ID;
    string cer_name;
    string cer_date;
    string cer_rank;

public:
    certificate(int ID1, string cer_name1, string cer_date1, string cer_rank1);
    void show_Info() const;
};

class Employee {
private:
    int ID;
    string fulname;
    string birthday;
    string phone;
    string email;
    employee_type type;
    vector<certificate> certificates;

public:
    Employee(int ID1, string fulname1, string birthday1, string phone1, string email1, employee_type type1);
    virtual void show_Info() const ;
    void add_Certificate(int cer_ID, string cer_name, string cer_date, string cer_rank);
    int get_ID() const;

    const vector<certificate>& get_Certificates() const ;
};

class Experience : public Employee {
private:
    int years_of_experience;
    string special_skills;

public:
    Experience(int ID1, string fulname1, string birthday1, string phone1, string email1, int exp_years, string skills);

    void show_Info() const override;
};

class Fresher : public Employee {
private:
    string gra_date;
    string gra_rank;
    string gra_uni;

public:
    Fresher(int ID1, string fulname1, string birthday1, string phone1, string email1, string graduation_date, string graduation_rank, string graduation_uni);

    void show_Info() const override;
};

class Intern : public Employee {
private:
    string major;
    string semester;
    string uni_name;

public:
    Intern(int ID1, string fulname1, string birthday1, string phone1, string email1, string major1, string semester1, string uni_name1);

    void show_Info() const override;
};


class Employyee_management {
private:
    vector<Employee*> nv1;
    static int count;

public:
    ~Employyee_management();
    void show_Emp(int id) const;

    void show_All_Certificates(int id) const;

    void add_Emp(Employee * nv);

    void delete_Emp(int id);

    static void get_Emp() ;
};

