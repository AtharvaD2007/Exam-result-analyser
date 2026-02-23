#include <iostream>
using namespace std;

class Student {
private:
    int roll;
    int marks[5];
    int total;
    float percentage;
    string result;

public:
    Student() {
        total = 0;
        percentage = 0;
        result = "";
    }

    void inputStudent(int r) {
        roll = r;
        cout << "Enter marks for Roll No " << roll << ":" << endl;
        
        cout << "English: ";
        cin >> marks[0];
        
        cout << "Maths: ";
        cin >> marks[1];

        cout << "Science: ";
        cin >> marks[2];

        cout << "SST: ";
        cin >> marks[3];

        cout << "IT: ";
        cin >> marks[4];

        calculateResult();
    }

    void calculateResult() {
        total = 0;
        for (int i = 0; i < 5; i++) {
            total += marks[i];
        }
        percentage = total / 5.0;

        if (percentage >= 40)
            result = "Pass";
        else
            result = "Fail";
    }

    float getPercentage() {
        return percentage;
    }

    string getResult() {
        return result;
    }

    void displayStudent() {
        cout << "Roll No: " << roll
             << " | Percentage: " << percentage
             << " | Result: " << result << endl;
    }
};

class ExamResultAnalyzer {
private:
    Student s[50];
    int n;

public:
    ExamResultAnalyzer(int count) {
        n = count;
    }

    void inputAllStudents() {
        for (int i = 0; i < n; i++) {
            s[i].inputStudent(i + 1);
        }
    }

    void analyzeResults() {
        int passCount = 0;
        int failCount = 0;
        float highest = 0;

        for (int i = 0; i < n; i++) {
            if (s[i].getResult() == "Pass")
                passCount++;
            else
                failCount++;

            if (s[i].getPercentage() > highest)
                highest = s[i].getPercentage();
        }

        cout << "-------------------------------" << endl;
        cout << "------- Class Analysis --------" << endl;
        cout << "-------------------------------" << endl;
        cout << "Total Students: " << n << endl;
        cout << "Passed: " << passCount << endl;
        cout << "Failed: " << failCount << endl;
        cout << "Pass Percentage: " 
             << (passCount * 100.0) / n << "%" << endl;

        cout << "-------------------------------" << endl;
        cout << "--------- Top Ranker ----------" << endl;
        cout << "-------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            if (s[i].getPercentage() == highest)
                s[i].displayStudent();
        }
    }

    void displayAll() {
        cout << endl << "--- Student Results ---" << endl;
        for (int i = 0; i < n; i++) {
            s[i].displayStudent();
        }
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    ExamResultAnalyzer analyzer(n);

    analyzer.inputAllStudents();
    analyzer.displayAll();
    analyzer.analyzeResults();
    

    return 0;
}