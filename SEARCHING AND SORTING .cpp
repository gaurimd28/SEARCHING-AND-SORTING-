#include <iostream>
#include <cstring>
#include <cstdlib>  // For malloc, realloc, free
#include <ctime>    // For time measurement
using namespace std;

struct Student {
    int id;
    char name[15];
    float cgpa;
};

// Global variables
Student* students = NULL;
int size = 0;

// Function to add student
void addStudent() {
    Student temp;
    cout << "Enter ID: ";
    cin >> temp.id;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(temp.name, 100);
    cout << "Enter CGPA: ";
    cin >> temp.cgpa;

    students = (Student*)realloc(students, (size + 1) * sizeof(Student));
    if (students == NULL) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }
    students[size] = temp;
    size++;
}

// Linear Search
int linearSearch(int id) {
    for (int i = 0; i < size; i++) {
        if (students[i].id == id)
            return i;
    }
    return -1;
}

// Binary Search (requires sorted by ID)
int binarySearch(int id) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (students[mid].id == id)
            return mid;
        else if (students[mid].id < id)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Bubble Sort by Name
void bubbleSortByName() {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (strcmp(students[j].name, students[j+1].name) > 0) {
                swap(students[j], students[j+1]);
            }
        }
    }
}

// Selection Sort by CGPA
void selectionSortByCGPA(bool ascending = true) {
    for (int i = 0; i < size - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < size; j++) {
            if ((ascending && students[j].cgpa < students[idx].cgpa) ||
                (!ascending && students[j].cgpa > students[idx].cgpa)) {
                idx = j;
            }
        }
        if (idx != i) swap(students[i], students[idx]);
    }
}

// Sort by ID (for binary search)
void sortByID() {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (students[j].id > students[j+1].id)
                swap(students[j], students[j+1]);
        }
    }
}

// Display all students
void displayStudents() {
    cout << "\nStudent Records:\n";
    for (int i = 0; i < size; i++) {
        cout << "ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", CGPA: " << students[i].cgpa << endl;
    }
}

// Performance Analysis
void compareSearchPerformance(int search_id) {
    clock_t start, end;

    start = clock();
    int index1 = linearSearch(search_id);
    end = clock();
    double time_linear = double(end - start) / CLOCKS_PER_SEC;

    sortByID();  // Sort for binary search
    start = clock();
    int index2 = binarySearch(search_id);
    end = clock();
    double time_binary = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nPerformance Analysis:";
    cout << "\nLinear Search Time: " << time_linear << " seconds";
    cout << "\nBinary Search Time: " << time_binary << " seconds\n";

    if (index1 != -1) {
        cout << "Student Found (Linear): " << students[index1].name << endl;
    } else {
        cout << "Student Not Found (Linear)" << endl;
    }

    if (index2 != -1) {
        cout << "Student Found (Binary): " << students[index2].name << endl;
    } else {
        cout << "Student Not Found (Binary)" << endl;
    }
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n--- Student Database Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Sort by Name (Bubble Sort)\n";
        cout << "4. Sort by CGPA (Selection Sort - Asc)\n";
        cout << "5. Sort by CGPA (Selection Sort - Desc)\n";
        cout << "6. Search by ID (Linear & Binary + Performance)\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: bubbleSortByName(); displayStudents(); break;
            case 4: selectionSortByCGPA(true); displayStudents(); break;
            case 5: selectionSortByCGPA(false); displayStudents(); break;
            case 6: {
                int id;
                cout << "Enter ID to search: ";
                cin >> id;
                compareSearchPerformance(id);
                break;
            }
            case 7: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    free(students); // Free memory
    return 0;
}

