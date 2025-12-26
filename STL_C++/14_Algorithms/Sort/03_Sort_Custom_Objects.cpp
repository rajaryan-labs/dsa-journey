#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// ==========================================
// 3. SORTING CUSTOM OBJECTS (STRUCTS)
// ==========================================
/*
    When sorting custom objects (like a Student struct or a Car class),
    std::sort doesn't know how to verify if Student A < Student B.
    
    We MUST provide a Comparator (or overload the < operator).
*/

struct Student {
    string name;
    int marks;
};

// Comparator: Sort Students by Marks in ASCENDING order.
bool compareByMarks(const Student& a, const Student& b) {
    if (a.marks < b.marks) return true;  // a comes before b
    return false;
}

// Comparator: Sort Students by Name (Lexicographically)
bool compareByName(const Student& a, const Student& b) {
    return a.name < b.name;
}

int main() {
    vector<Student> students = {
        {"Raj", 85},
        {"Aryan", 92},
        {"Amit", 78},
        {"Zara", 85}
    };

    cout << "Original List:" << endl;
    for(const auto& s : students) cout << s.name << " (" << s.marks << ")" << endl;

    // 1. Sort by Marks
    sort(students.begin(), students.end(), compareByMarks);

    cout << "\nSorted by Marks (Ascending):" << endl;
    for(const auto& s : students) cout << s.name << " (" << s.marks << ")" << endl;

    // 2. Sort by Name
    sort(students.begin(), students.end(), compareByName);

    cout << "\nSorted by Name (A-Z):" << endl;
    for(const auto& s : students) cout << s.name << " (" << s.marks << ")" << endl;

    return 0;
}
