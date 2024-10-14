#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace student_management {

    struct Student {
        string surname;
        string group;
        int grades[5];
    };

    void beststudents(const vector<Student>& students) {
        cout << "[Beststudents list]:\n";
        for (const auto& student : students) {
            int excellentCount = 0;
            for (int grade : student.grades) {
                if (grade == 5) {
                    excellentCount++;
                }
            }
            if (excellentCount >= 4) { 
                cout << student.surname << " (" << student.group << ")\n";
            }
        }
    }

    // Функція для виведення студентів двієчників
    void badstudents(const vector<Student>& students) {
        cout << "[BadStudents list]:\n";
        for (const auto& student : students) {
            int lowGradesCount = 0;
            for (int grade : student.grades) {
                if (grade == 2 || grade == 3) {
                    lowGradesCount++;
                }
            }
            if (lowGradesCount > 2) { 
                cout << student.surname << " (" << student.group << ")\n";
            }
        }
    }

}

int main() {
    using namespace student_management;

    vector<Student> students = {
        {"Ryapalov", "group1-A", {5, 4, 5, 5, 5}},
        {"Popovich", "group2-B", {3, 2, 4, 3, 3}},
        {"Tkach", "group1-C", {2, 2, 3, 2, 3}},
        {"Boychyuk", "group3-D", {4, 5, 5, 5, 5}},
    };

    // best cout
    beststudents(students);
    
    // bad cout 
    badstudents(students);

    return 0;
}
