#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int roll;
    float cgpa;
    string branch;
    int attendance;
};

Student s[100];
int countStudents = 0;

void loadData() {
    ifstream file("students.txt");

    if (!file) {
        cout << "No existing records found. Starting fresh.\n";
        return;
    }

    countStudents = 0;
    while (file >> s[countStudents].roll 
                >> s[countStudents].name 
                >> s[countStudents].cgpa
                >> s[countStudents].branch
                >> s[countStudents].attendance) 
    {
        countStudents++;
    }

    if (countStudents == 0)
        cout << "No existing records found. Starting fresh.\n";
    else
        cout << "Loaded " << countStudents << " student records.\n";

    file.close();
}

void saveData() {
    ofstream file("students.txt");

    for (int i = 0; i < countStudents; i++) {
        file << s[i].roll << " "
             << s[i].name << " "
             << s[i].cgpa << " "
             << s[i].branch << " "
             << s[i].attendance << endl;
    }

    file.close();
}

void displayStudents() {
    if (countStudents == 0) {
        cout << "\nNo student records found!\n";
        return;
    }

    cout << "\n--- All Student Records ---\n";
    for (int i = 0; i < countStudents; i++) {
        cout << "Roll: " << s[i].roll
             << ", Name: " << s[i].name
             << ", CGPA: " << s[i].cgpa
             << ", Branch: " << s[i].branch
             << ", Attendance: " << s[i].attendance << "%\n";
    }
}

void addStudent() {
    cout << "\nAdding a Student:\n";

    cout << "Enter Student Name       : ";
    cin >> s[countStudents].name;

    cout << "Enter Roll Number        : ";
    cin >> s[countStudents].roll;

    cout << "Enter CGPA               : ";
    cin >> s[countStudents].cgpa;

    cout << "Enter Branch (CSE/ECE..) : ";
    cin >> s[countStudents].branch;

    cout << "Enter Attendance (%)     : ";
    cin >> s[countStudents].attendance;

    countStudents++;

    cout << "Student Added Successfully!\n";
}

void searchStudent() {
    int r;
    cout << "\nEnter Roll Number to Search: ";
    cin >> r;

    for (int i = 0; i < countStudents; i++) {
        if (s[i].roll == r) {
            cout << "\nRecord Found:\n";
            cout << "Name: " << s[i].name
                 << ", Roll: " << s[i].roll
                 << ", CGPA: " << s[i].cgpa
                 << ", Branch: " << s[i].branch
                 << ", Attendance: " << s[i].attendance << "%\n";
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

void deleteStudent() {
    int r;
    cout << "\nEnter Roll Number to Delete: ";
    cin >> r;

    for (int i = 0; i < countStudents; i++) {
        if (s[i].roll == r) {

            for (int j = i; j < countStudents - 1; j++)
                s[j] = s[j + 1];

            countStudents--;
            cout << "Student Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

int main() {
    int option;

    loadData(); // Load records at start

    while (1) {
        cout << "\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n";
        cout << "1. Display All Students\n";
        cout << "2. Add Student\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Save & Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1: displayStudents(); break;
            case 2: addStudent(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: saveData(); 
                    cout << "Data saved. Exiting...\n";
                    return 0;
            default: cout << "Invalid option! Try again.\n";
        }
    }
}