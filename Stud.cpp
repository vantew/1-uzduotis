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

    Lok.avg = (hwSum + Lok.exam) / (hwCount + 1);
    Lok.HW.push_back(Lok.exam); // ipushinam Lok.exam i Vec1 vektoriu del medianos skaiciavimo
    Lok.med = calculateMedian(Lok.HW);

}


void inputgrades(Stud &Lok) {
    cout << "Input student's name and surname: " << endl;
    cin >> Lok.name >> Lok.surname;

    int hw;
    double hwSum = 0;
    double hwCount = 0;

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

    Lok.avg = (hwSum + Lok.exam) / (hwCount + 1);
    Lok.HW.push_back(Lok.exam); // ipushinam Lok.exam i Vec1 vektoriu del medianos skaiciavimo
    Lok.med = calculateMedian(Lok.HW);

}

void readfile(const string &line, Stud &Lok) {
    stringstream inputline(line);
    inputline >> Lok.name >> Lok.surname;

    int hw;
    double hwSum = 0;
    double hwCount = 0;

    while (inputline >> hw) {
        hwSum += hw;
        hwCount++;
        Lok.HW.push_back(hw);
    }

    Lok.avg = (hwSum) / (hwCount);
    Lok.med = calculateMedian(Lok.HW);
}

void randomgrades(Stud &Lok, int hwCount) {
    cout << "Input student's name and surname: " << endl;
    cin >> Lok.name >> Lok.surname;

    int hw;
    double hwSum = 0;
    cout << Lok.name << " " << Lok.surname << " grades are: ";

    for (int i = 0; i < hwCount; i++) {
        hw = (rand() % 10) + 1;
        Lok.HW.push_back(hw);
        hwSum += hw;
        cout << hw << " ";
    }
    Lok.exam = (rand() % 10) + 1;

    cout << "; Exam grade: " << Lok.exam << endl;

    Lok.avg = (hwSum + Lok.exam) / (hwCount + 1);
    Lok.HW.push_back(Lok.exam);
    Lok.med = calculateMedian(Lok.HW);

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

void printHeaderfile(ofstream &outfile) {
    outfile << left << setw(15) << "Surname"
            << setw(15) << "Name"
            << setw(8) << "Average"
            << setw(8) << "Median" << endl;
    outfile << string(15 + 15 + 8 + 8, '-') << endl;
}

void printHeadernull() {
    cout << left << setw(15) << "Surname"
            << setw(15) << "Name"
            << setw(8) << "Average"
            << setw(8) << "Median" << endl;
    cout << string(15 + 15 + 8 + 8, '-') << endl;
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

void inputnull(Stud &Lok) {
    cout << "Input student's name and surname: " << endl;
    cin >> Lok.name >> Lok.surname;
}

void outputnull(Stud Lok) {
    Lok.avg = 0;
    Lok.med = 0;
    cout << left << setw(15) << Lok.surname
         << setw(15) << Lok.name
         << setw(8) << fixed << setprecision(2) << Lok.avg << setw(8) << fixed << setprecision(2) << Lok.med << endl;
}

void outputfile(ofstream &outfile, Stud Lok) {
    outfile << left << setw(15) << Lok.surname
            << setw(15) << Lok.name
            << setw(8) << fixed << setprecision(2) << Lok.avg
            << setw(8) << fixed << setprecision(2) << Lok.med << endl;
}

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

void sortsurname(vector<Stud> &Lok) {
    sort(Lok.begin(), Lok.end(), [](const Stud &a, const Stud &b) {
        if (a.surname == b.surname) {
            return a.name < b.name; // jei pavardes yra vienodos, sortina pagal varda
        }
        return a.surname < b.surname;
    });
}

void clean(Stud &Lok) {
    Lok.name.clear();
    Lok.surname.clear();
    Lok.HW.clear();
}

//////////////////////////////////////////////////////////////////////
///////////////// V0.2
//////////////////////////////////////////////////////////////////////
void filegeneration(const string &filename, int numEntries, int numHW, vector<Stud> &Vec1) {
    ofstream file(filename);
    auto start = std::chrono::high_resolution_clock::now();

    if (!file) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    srand(static_cast<unsigned int>(time(0)));

    file << fixed << left << setw(15) << "Vardas"
                          << setw(15) << "Pavarde"
                          << setw(10) << "Average" << endl;

    for (int j = 1; j <= numEntries; j++) {
        Stud Temp;
        Temp.name = "Vardas" + to_string(j);
        Temp.surname = "Pavarde" + to_string(j);
        file << fixed << left << setw(15) << Temp.name << setw(15) << Temp.surname;

        for (int i = 0; i < numHW; i++) {
            Temp.HW.push_back(rand() % 10 + 1);
        }

        Temp.exam = rand() % 10 + 1;
        Temp.avg = (Temp.exam + accumulate(Temp.HW.begin(), Temp.HW.end(), 0.00)) / (numHW + 1);
        file << fixed << left << setprecision(2) << setw(10) << Temp.avg << endl;

        Vec1.push_back(Temp);
    }

    file.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "File with " << numEntries << " entries generated in: " << elapsed.count() << " seconds" << endl;
}

void filterbelow5(const string &inputfile, vector<Stud> &below5) {
    auto start = std::chrono::high_resolution_clock::now();

    ifstream file(inputfile);

    if (!file.is_open()) {
        cerr << "Failed to open input file: " << inputfile << endl;
        return;
    }

    string line;
    getline(file, line); // skippina headeri

    below5.clear();

    while (getline(file, line)) {
        istringstream inputline(line); // istringstream naudojamas visokiu tipo duomenim nuskaityt
        Stud student;
        if (inputline >> student.name >> student.surname >> student.avg) {
            if (student.avg < 5.0) {
                below5.push_back(student);
            }
        }
    }

    file.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Time it takes to read and filter students below 5 average: " << elapsed.count() << " seconds" << endl;
}

void filterabove5(const string &inputfile, vector<Stud> &above5) {
    auto start = std::chrono::high_resolution_clock::now();

    ifstream file(inputfile);

    if (!file.is_open()) {
        cerr << "Failed to open input file: " << inputfile << endl;
        return;
    }

    string line;
    getline(file, line); // skippina headeri

    above5.clear();

    while (getline(file, line)) {
        istringstream inputline(line); // istringstream naudojamas visokiu tipo duomenim nuskaityt
        Stud student;
        if (inputline >> student.name >> student.surname >> student.avg) {
            if (student.avg >= 5.0) {
                above5.push_back(student);
            }
        }
    }

    file.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Time it takes to read and filter students above or equal to 5 average: " << elapsed.count() << " seconds" << endl;
}

void savetofile(const string &filename, const vector<Stud> &students) {
    auto start = std::chrono::high_resolution_clock::now();

    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Failed to open output file: " << filename << endl;
        return;
    }

    for (const auto &student : students) {
        file << fixed << left << setw(20) << student.name
             << setw(20) << student.surname
             << setw(10) << setprecision(2) << student.avg << endl;
    }

    file.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Time elapsed to print filtered students to files " << filename << ": " << elapsed.count() << " seconds" << endl;
}
