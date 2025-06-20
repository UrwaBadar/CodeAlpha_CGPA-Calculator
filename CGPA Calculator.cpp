#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to calculate CGPA
void calculate_cgpa() {
    cout << "Welcome to the CGPA Calculator!" << endl;
    cout << "You can customize your grading scale and calculate your GPA and CGPA." << endl;

    // Input the number of semesters
    int num_semesters;
    cout << "How many semesters do you want to calculate CGPA for? ";
    cin >> num_semesters;

    double overall_total_credits = 0;
    double overall_total_grade_points = 0;

    for (int semester = 1; semester <= num_semesters; semester++) {
        cout << "\n--- Semester " << semester << " ---" << endl;

        int num_courses;
        cout << "Enter the number of courses taken: ";
        cin >> num_courses;

        double total_credits = 0;
        double total_grade_points = 0;
        vector<pair<double, double>> course_grades; // Store (grade, credit_hours)

        for (int i = 0; i < num_courses; i++) {
            double grade;
            while (true) {
                cout << "Enter the grade for course " << (i + 1) << " (0.0 - 4.0): ";
                cin >> grade;
                if (grade >= 0.0 && grade <= 4.0) {
                    break;
                }
                else {
                    cout << "Please enter a valid grade between 0.0 and 4.0." << endl;
                }
            }

            double credit_hours;
            while (true) {
                cout << "Enter the credit hours for course " << (i + 1) << ": ";
                cin >> credit_hours;
                if (credit_hours > 0) {
                    break;
                }
                else {
                    cout << "Credit hours must be a positive number." << endl;
                }
            }

            double grade_points = grade * credit_hours;
            total_grade_points += grade_points;
            total_credits += credit_hours;
            course_grades.push_back(make_pair(grade, credit_hours));
        }

        double gpa = (total_credits > 0) ? (total_grade_points / total_credits) : 0;

        cout << "\nIndividual Course Grades:" << endl;
        for (int i = 0; i < course_grades.size(); i++) {
            cout << "Course " << (i + 1) << ": Grade = " << course_grades[i].first
                << ", Credit Hours = " << course_grades[i].second << endl;
        }

        cout << fixed << setprecision(2); // Set precision for GPA output
        cout << "\nGPA for Semester " << semester << ": " << gpa << endl;

        overall_total_credits += total_credits;
        overall_total_grade_points += total_grade_points;
    }

    double overall_cgpa = (overall_total_credits > 0) ? (overall_total_grade_points / overall_total_credits) : 0;

    cout << "\nOverall CGPA after " << num_semesters << " semesters: " << overall_cgpa << endl;
    cout << "Thank you for using the CGPA Calculator!" << endl;
}

// Main function
int main() {
    calculate_cgpa();
    return 0;
}
