#include "Stud.h"

void input(Stud &Lok, int hwCount) {
    cout << "Input student's name and surname: " << endl;
    cin >> Lok.name >> Lok.surname;

    double hwSum = 0;
    int hw;

    cout << "Enter the homework grades for " << "\033[1;3m" << Lok.name << " " << Lok.surname << "\033[0m: " << endl;
    for (int i = 0; i < hwCount; i++) {
            while (true) {
                cin >> hw;
                if ((hw < 1) || (hw > 10)) {
                cout << "Invalid number! Try again." <<endl;
                }
            else {
                hwSum += hw;
                Lok.HW.push_back(hw);
                }
            }
    }
    cout << "Enter the exam grade: " << endl;
    int m = 1;
    for (int i = 0; i < m; i++) {
        cin >> Lok.exam;
        if ((Lok.exam < 1) || (Lok.exam > 10)) {
            cout << "Invalid number! Try again." <<endl;
            i--;
            }
    }

    Lok.HW.push_back(Lok.exam);
    Lok.med = calculateMedian(Lok.HW);
    Lok.avg = (hwSum + Lok.exam) / (hwCount + 1);
}


void inputgrades(Stud &Lok) {
    cout << "Input student's name and surname: " << endl;
    cin >> Lok.name >> Lok.surname;

    int hw;
    int hwSum = 0;
    int hwCount = 0;

    cout << "Enter the homework grades for \033[1;3m" << Lok.name << " "
         << Lok.surname << "\033[0m, when you are done, type 0." << endl;

    while (true) {
        cin >> hw;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Try again." << endl;
        }
        else if (hw == 0) {
            break;
        }
        else if (hw < 1 || hw > 10) {
            cout << "Invalid number! Try again." << endl;
        }
        else {
            hwSum += hw;
            hwCount++;
            Lok.HW.push_back(hw);
        }
    }

    cout << "Enter the exam grade: " << endl;
    while (true) {
        cin >> Lok.exam;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Try again." << endl;
        }
        else if (Lok.exam < 1 || Lok.exam > 10) {
            cout << "Invalid number! Try again." << endl;
        }
        else break;
    }

    Lok.HW.push_back(Lok.exam);
    Lok.med = calculateMedian(Lok.HW);
    Lok.avg = (hwSum + Lok.exam) / (hwCount + 1);
}

void readFromFile(const std::string &line, Stud &Lok) {
    std::stringstream ss(line);
    ss >> Lok.name >> Lok.surname;

    int hw;
    int hwSum = 0;
    int hwCount = 0;

    while (ss >> hw) {
        hwSum += hw;
        hwCount++;
        Lok.HW.push_back(hw);
    }

    Lok.exam = Lok.HW.back();
    Lok.HW.pop_back(); // Remove the exam grade from homework grades
    Lok.avg = (hwSum + Lok.exam) / (hwCount + 1);

    Lok.HW.push_back(Lok.exam);
    Lok.med = calculateMedian(Lok.HW);

}

void randomgrades(Stud &Lok, int hwCount) {
    cout << "Input student's name and surname: " << endl;
    cin >> Lok.name >> Lok.surname;

    int hw;
    int hwSum = 0;
    cout << Lok.name << " " << Lok.surname << " grades are: ";

    for (int i = 0; i < hwCount; i++) {
        hw = (rand() % 10) + 1;
        Lok.HW.push_back(hw);
        hwSum += hw;
        cout << hw << " ";
    }
    Lok.exam = (rand() % 10) + 1;
    Lok.HW.push_back(Lok.exam);
    cout << "; Exam grade: " << Lok.exam << endl;

    Lok.med = calculateMedian(Lok.HW);
    Lok.avg = (hwSum + Lok.exam) / (hwCount + 1);

}

double calculateMedian(vector<double>& grades) {
    if (grades.empty()) return 0;

    sort(grades.begin(), grades.end());

    size_t size = grades.size();
    if (size % 2 == 0) {
        return (grades[size / 2 - 1] + grades[size / 2]) / 2;
    } else {
        return grades[size / 2];
    }
}

void printHeaderavg() {
    cout << left << setw(15) << "Surname"
         << setw(15) << "Name"
         << setw(8) << "Average" << endl;
    cout << string(15 + 15 + 8, '-') << endl;
}

void printHeadermed() {
    cout << left << setw(15) << "Surname"
         << setw(15) << "Name"
         << setw(8) << "Median" << endl;
    cout << string(15 + 15 + 8, '-') << endl;
}

//void inputnull(Stud &Lok) {/////////////////////////////////////
//    cout << "Input student's name and surname: " << endl;
//    cin >> Lok.name >> Lok.surname;
//
//    Lok.med = 0;
//    Lok.avg = 0;
//}/////////////////////////////////////////////

void outputavg(Stud Lok) {
    cout << left << setw(15) << Lok.surname
         << setw(15) << Lok.name
         << setw(8) << fixed << setprecision(2) << Lok.avg << endl;
}

void outputmed(Stud Lok) {
    cout << left << setw(15) << Lok.surname
         << setw(15) << Lok.name
         << setw(8) << fixed << setprecision(2) << Lok.med << endl;
}

void clean(Stud &Lok) {
    Lok.name.clear();
    Lok.surname.clear();
    Lok.HW.clear();
}
