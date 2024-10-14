#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace man_management {

    struct Man {
        string surname;
        string name;
        int age;
        string birthDate;
    };

  
    void sortBySurname(vector<Man>& people) {
        sort(people.begin(), people.end(), [](const Man& a, const Man& b) {
            return a.surname < b.surname;
        });
    }

    void sortByName(vector<Man>& people) {
        sort(people.begin(), people.end(), [](const Man& a, const Man& b) {
            return a.name < b.name;
        });
    }

    
    void BirthdayMonth(const vector<Man>& people, const string& month) {
        cout << "Birthday celebrants in the month of " << month << ":\n";
        for (const auto& person : people) {
            if (person.birthDate.substr(3, 2) == month) { 
                cout << person.name << " " << person.surname << " (Birth date: " << person.birthDate << ")\n";
            }
        }
    }

   
    void findPerson(const vector<Man>& people, const string& surname, const string& name) {
        for (const auto& person : people) {
            if (person.surname == surname && person.name == name) {
                cout << "Found: " << person.name << " " << person.surname << " (Age: " << person.age << ", Birth date: " << person.birthDate << ")\n";
                return;
            }
        }
        cout << "Person not found\n";
    }

 
    void editPerson(vector<Man>& people, const string& surname, const string& name, const Man& newPerson) {
        for (auto& person : people) {
            if (person.surname == surname && person.name == name) {
                person = newPerson;
                cout << "Record updated\n";
                return;
            }
        }
        cout << "Person not found for editing\n";
    }

}

int main() {
    using namespace man_management;

    vector<Man> people = {
        {"Ivanov", "Ivan", 19, "15.03.2005"},
        {"Petrov", "Petr", 14, "20.05.2010"},
        {"Sidorov", "Sergey", 16, "25.03.2008"},
        {"Kozlov", "Alex", 11, "12.09.2013"}
    };

    //sur sort 
    sortBySurname(people);
    
   //bir sort 
    BirthdayMonth(people, "03");

    //pers sort 
    findPerson(people, "Petrov", "Petr");

    // Edit 
    Man newPerson = {"Petrov", "Petr", 14, "20.05.2010"};
    editPerson(people, "Petrov", "Petr", newPerson);

    return 0;
}