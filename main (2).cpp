#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    std::string roll_number;
    float cgpa;
};

// Custom comparison function to sort students by CGPA in descending order
bool compareStudentsByCGPA(const Student& a, const Student& b) {
    return a.cgpa > b.cgpa; // Sort in descending order
}

// Function to sort a list of students by CGPA
void sort_students(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), compareStudentsByCGPA);
}

int main() {
    // Test the sort_students function with a list of student objects
    std::vector<Student> students = {
        {"Alice", "A123", 3.8},
        {"Bob", "B456", 3.6},
        {"Charlie", "C789", 3.9},
        {"David", "D012", 3.7}
    };

    std::cout << "Before sorting by CGPA:" << std::endl;
    for (const Student& student : students) {
        std::cout << "Name: " << student.name << ", Roll Number: " << student.roll_number << ", CGPA: " << student.cgpa << std::endl;
    }

    sort_students(students);

    std::cout << "\nAfter sorting by CGPA:" << std::endl;
    for (const Student& student : students) {
        std::cout << "Name: " << student.name << ", Roll Number: " << student.roll_number << ", CGPA: " << student.cgpa << std::endl;
    }

    return 0;
}
