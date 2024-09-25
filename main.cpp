#include "Mylib.h"
#include "Stud.h"


int main() {
    vector<Stud> Vec1;
    Stud Temp;

    int n;
    while (true) {
        cout << "How many students? " << endl;
        cin >> n;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please enter a number." << endl;
        }
        else if (n > 0) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a positive number." << endl;
        }
    }

    char hw;

while (true) {
        do {
            cout << "Do you know the number of homework assignments per student? (y/n):" << endl;
            cin >> hw;

            if (hw != 'y' && hw != 'Y' && hw != 'n' && hw != 'N') {
                cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            }
        } while (hw != 'y' && hw != 'Y' && hw != 'n' && hw != 'N');

        if (hw == 'y' || hw == 'Y') {
            int hwCount;
            while (true) {
                cout << "Enter the number of assignments: " << endl;

                cin >> hwCount;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Invalid input. Please enter a number." << endl;
                }
                else if (hwCount < 0) cout << "Enter a positive number." <<endl;
                    else break;
            }

            char random;
            do {
                cout << "Do you want to generate random grades? (y/n): " << endl;
                cin >> random;

                if (random != 'y' && random != 'Y' && random != 'n' && random != 'N') {
                    cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                }
            } while (random != 'y' && random != 'Y' && random != 'n' && random != 'N');

            if (random == 'y' || random == 'Y') { // sugeneruoja random grades
                for (int i = 0; i < n; i++) {
                    randomgrades(Temp, hwCount);
                    Vec1.push_back(Temp);
                    clean(Temp);
                }
            }
            else if (random == 'n' || random == 'N') { // suvedam grades, zinodami hwCount
                for (int i = 0; i < n; i++) {
                    input(Temp, hwCount);
                    Vec1.push_back(Temp);
                    clean(Temp);
                }
            }
            break;
        }

        else if (hw == 'n' || hw == 'N') { // suvedam grases, nezinodami hwCount
            for (int i = 0; i < n; i++) {
                inputgrades(Temp);
                Vec1.push_back(Temp);
                clean(Temp);
            }
            break;
        }
    }

int option;

do {
        cout << "Choose option: 1 to view average, 2 to view median: " << endl;

        cin >> option;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (option == 1) {
            printHeaderavg();
            for (Stud student : Vec1) {
                outputavg(student);
            }

            char viewMedian;
            do {
                cout << "Do you want to view the Median as well? (y/n): " << endl;
                cin >> viewMedian;
                if (viewMedian == 'y' || viewMedian == 'Y') {
                    printHeadermed();
                    for (Stud student : Vec1) {
                        outputmed(student);
                    }
                } else if (viewMedian != 'n' && viewMedian != 'N') {
                    cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                }
            } while (viewMedian != 'y' && viewMedian != 'Y' && viewMedian != 'n' && viewMedian != 'N');
        } else if (option == 2) {
            printHeadermed();
            for (Stud student : Vec1) {
                outputmed(student);
            }

            char viewAverage;
            do {
                cout << "Do you want to view the Average as well? (y/n): " << endl;
                cin >> viewAverage;
                if (viewAverage == 'y' || viewAverage == 'Y') {
                    printHeaderavg();
                    for (Stud student : Vec1) {
                        outputavg(student);
                    }
                } else if (viewAverage != 'n' && viewAverage != 'N') {
                    cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                }
            } while (viewAverage != 'y' && viewAverage != 'Y' && viewAverage != 'n' && viewAverage != 'N');
        } else {
            cout << "Invalid option! Please try again." << endl;
        }

    } while (option != 1 && option != 2);

system("pause");
}
