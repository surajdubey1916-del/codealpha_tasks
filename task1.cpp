#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int semesters;

    cout << "Enter the number of semesters: ";
    cin >> semesters;

    double overallGradePoints = 0.0;
    int overallCredits = 0;

    for (int s = 1; s <= semesters; s++) {

        int courses;
        cout << "\nEnter the number of courses in Semester " << s << ": ";
        cin >> courses;

        double semesterGradePoints = 0.0;
        int semesterCredits = 0;

        cout << "\n---------------- Semester " << s << " ----------------\n";
        cout << left << setw(20) << "Course"
             << setw(10) << "Grade"
             << setw(10) << "Credit"
             << setw(15) << "Grade Points" << endl;

        for (int i = 1; i <= courses; i++) {

            string courseName;
            double grade;
            int credit;

            cout << "\nEnter Course Name: ";
            cin.ignore();
            getline(cin, courseName);

            cout << "Enter Grade Point (0-10): ";
            cin >> grade;

            cout << "Enter Credit Hours: ";
            cin >> credit;

            double gradePoints = grade * credit;

            semesterGradePoints += gradePoints;
            semesterCredits += credit;

            cout << left << setw(20) << courseName
                 << setw(10) << grade
                 << setw(10) << credit
                 << setw(15) << gradePoints << endl;
        }

        double semesterGPA = semesterGradePoints / semesterCredits;

        cout << "\nSemester " << s << " Summary";
        cout << "\nTotal Credits     : " << semesterCredits;
        cout << "\nTotal Grade Points: " << semesterGradePoints;
        cout << "\nSemester GPA      : " << fixed << setprecision(2)
             << semesterGPA << endl;

        overallGradePoints += semesterGradePoints;
        overallCredits += semesterCredits;
    }

    double cgpa = overallGradePoints / overallCredits;

    cout << "\n====================================";
    cout << "\nOverall Academic Summary";
    cout << "\n====================================";
    cout << "\nTotal Credits Earned : " << overallCredits;
    cout << "\nOverall Grade Points : " << overallGradePoints;
    cout << "\nFinal CGPA           : " << fixed << setprecision(2)
         << cgpa << endl;

    return 0;
}