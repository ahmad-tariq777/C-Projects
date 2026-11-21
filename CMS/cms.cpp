#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct Person {
    string name;
    string id;
    string extra1; // course or education
    string extra2; // class or experience
    string contact;
};

const int MAX = 100;

class ManagementSystem {
protected:
    Person people[MAX];
    int total = 0;
    string filename;

public:
    ManagementSystem(string file) : filename(file) {}

    void loadFromFile() {
        ifstream file(filename);
        total = 0;
        while (file >> people[total].name >> people[total].id >> people[total].extra1 >> people[total].extra2 >> people[total].contact) {
            total++;
        }
        file.close();
    }

    void saveToFile() {
        ofstream file(filename);
        for (int i = 0; i < total; ++i) {
            file << people[i].name << " " << people[i].id << " " << people[i].extra1 << " " << people[i].extra2 << " " << people[i].contact << endl;
        }
        file.close();
    }

    void enterData(const string& label1, const string& label2) {
        int ch;
        cout << "How many records do you want to enter? ";
        cin >> ch;
        for (int i = total; i < total + ch; ++i) {
            cout << "\nEnter Data for Person " << i + 1 << endl;
            cout << "Enter Name: ";
            cin >> people[i].name;
            cout << "Enter ID: ";
            cin >> people[i].id;
            cout << "Enter " << label1 << ": ";
            cin >> people[i].extra1;
            cout << "Enter " << label2 << ": ";
            cin >> people[i].extra2;
            cout << "Enter Contact: ";
            cin >> people[i].contact;
        }
        total += ch;
        saveToFile();
    }

    void showData(const string& role, const string& label1, const string& label2) {
        if (total == 0) {
            cout << "No data is entered yet." << endl;
            return;
        }
        for (int i = 0; i < total; ++i) {
            cout << "\n" << role << " " << i + 1 << " Details:" << endl;
            cout << "Name: " << people[i].name << endl;
            cout << "ID: " << people[i].id << endl;
            cout << label1 << ": " << people[i].extra1 << endl;
            cout << label2 << ": " << people[i].extra2 << endl;
            cout << "Contact: " << people[i].contact << endl;
        }
    }

    void searchData(const string& id) {
        for (int i = 0; i < total; ++i) {
            if (people[i].id == id) {
                cout << "\nRecord Found:\n";
                cout << "Name: " << people[i].name << endl;
                cout << "ID: " << people[i].id << endl;
                cout << "Detail 1: " << people[i].extra1 << endl;
                cout << "Detail 2: " << people[i].extra2 << endl;
                cout << "Contact: " << people[i].contact << endl;
                return;
            }
        }
        cout << "Record with ID " << id << " not found." << endl;
    }

    void updateData(const string& id, const string& label1, const string& label2) {
        for (int i = 0; i < total; ++i) {
            if (people[i].id == id) {
                cout << "\nEnter New Data for ID " << id << ":\n";
                cout << "Enter Name: ";
                cin >> people[i].name;
                cout << "Enter " << label1 << ": ";
                cin >> people[i].extra1;
                cout << "Enter " << label2 << ": ";
                cin >> people[i].extra2;
                cout << "Enter Contact: ";
                cin >> people[i].contact;
                saveToFile();
                return;
            }
        }
        cout << "Record with ID " << id << " not found." << endl;
    }
};

void clearScreen() {
    system("CLS"); // Use "clear" for Linux/Mac
}

void menu(ManagementSystem& ms, const string& role, const string& label1, const string& label2) {
    int choice;
    string id;
    while (true) {
        clearScreen();
        cout << "\n--- " << role << " MANAGEMENT MENU ---" << endl;
        cout << "1. Enter Data\n";
        cout << "2. Show Data\n";
        cout << "3. Search by ID\n";
        cout << "4. Update by ID\n";
        cout << "5. Go Back\n";
        cout << "Choose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                ms.enterData(label1, label2);
                break;
            case 2:
                ms.showData(role, label1, label2);
                break;
            case 3:
                cout << "Enter ID to search: ";
                cin >> id;
                ms.searchData(id);
                break;
            case 4:
                cout << "Enter ID to update: ";
                cin >> id;
                ms.updateData(id, label1, label2);
                break;
            case 5:
                return;
            default:
                cout << "Invalid option. Try again.\n";
        }
        system("pause");
    }
}

int main() {
    ManagementSystem studentSys("students.txt");
    ManagementSystem teacherSys("teachers.txt");
    ManagementSystem employeeSys("employees.txt");

    studentSys.loadFromFile();
    teacherSys.loadFromFile();
    employeeSys.loadFromFile();

    int mainChoice;
    while (true) {
        clearScreen();
        cout << "\n--- CAMPUS MANAGEMENT SYSTEM ---\n";
        cout << "1. Student Management\n";
        cout << "2. Teacher Management\n";
        cout << "3. Employee Management\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                menu(studentSys, "Student", "Course", "Class");
                break;
            case 2:
                menu(teacherSys, "Teacher", "Course", "Class");
                break;
            case 3:
                menu(employeeSys, "Employee", "Education", "Experience");
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid option.\n";
        }
    }

    return 0;
}
