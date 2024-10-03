#include "Mylib.h"
#include "Stud.h"

int main() {
    vector<Stud> Vec1;

    Stud Temp;

    char fileoption;
    do {
        cout << "Do you want to read student information from a file? (y/n): ";
        cin >> fileoption;

        if (fileoption != 'y' && fileoption != 'Y' && fileoption != 'n' && fileoption != 'N') {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        }

    } while (fileoption != 'y' && fileoption != 'Y' && fileoption != 'n' && fileoption != 'N');

    if (fileoption == 'y' || fileoption == 'Y') {
        try {
            ifstream file("studentai10000.txt");
            if (!file.is_open()) {
                throw runtime_error("Failed to open input file.");
            }

            ofstream outfile("outputas.txt");
            if (!outfile.is_open()) {
                throw runtime_error("Failed to open output file.");
            }

            string line;
            getline(file, line); // headeri nuskaito

            while (getline(file, line)) { // nuskaitomas failas pagal eilutes
                readfile(line, Temp);
                Vec1.push_back(Temp);
                clean(Temp);
            }

            printHeaderfile(outfile);

            for (const Stud &student : Vec1) {
                outputfile(outfile, student);
            }
            file.close();
            outfile.close();
            cout << "Printed to output file." << endl;
            system("pause");
            return 0;
        }
        catch (const exception &e) {
            cerr << e.what() << endl;
            system("pause");
            return 1; //
        }
    } else if (fileoption == 'n' || fileoption == 'N') {
        char generatefiles;
        cout << "Do you want to generate files for v0.2? (y/n): ";
//////////////////////////////////////////////////////////////////////
///////////////// V0.2
//////////////////////////////////////////////////////////////////////
        cin >> generatefiles;
        if (generatefiles == 'y' || generatefiles == 'Y') {

            int numHW;
            cout << "Enter the number of homework grades: ";
            cin >> numHW;
            cout << endl;

        vector<Stud> below5;
        vector<Stud> above5;

        auto start1000 = std::chrono::high_resolution_clock::now();
        filegeneration("studentai_1000.txt", 1000, numHW, Vec1);
        filterbelow5("studentai_1000.txt", below5);
        filterabove5("studentai_1000.txt", above5);
        savetofile("nuskriaustukai_1000.txt", below5);
        savetofile("kietakai_1000.txt", above5);
        auto end1000 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed1000 = end1000 - start1000;
        cout << "Total time elapsed: " << elapsed1000.count() << " seconds" << endl;
        cout << endl;

        auto start10000 = std::chrono::high_resolution_clock::now();
        filegeneration("studentai_10000.txt", 10000, numHW, Vec1);
        filterbelow5("studentai_10000.txt", below5);
        filterabove5("studentai_10000.txt", above5);
        savetofile("nuskriaustukai_10000.txt", below5);
        savetofile("kietakai_10000.txt", above5);
        auto end10000 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed10000 = end10000 - start10000;
        cout << "Total time elapsed: " << elapsed10000.count() << " seconds" << endl;
        cout << endl;

        auto start100000 = std::chrono::high_resolution_clock::now();
        filegeneration("studentai_100000.txt", 100000, numHW, Vec1);
        filterbelow5("studentai_100000.txt", below5);
        filterabove5("studentai_100000.txt", above5);
        savetofile("nuskriaustukai_100000.txt", below5);
        savetofile("kietakai_100000.txt", above5);
        auto end100000 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed100000 = end100000 - start100000;
        cout << "Total time elapsed: " << elapsed100000.count() << " seconds" << endl;
        cout << endl;

        auto start1000000 = std::chrono::high_resolution_clock::now();
        filegeneration("studentai_1000000.txt", 1000000, numHW, Vec1);
        filterbelow5("studentai_1000000.txt", below5);
        filterabove5("studentai_1000000.txt", above5);
        savetofile("nuskriaustukai_1000000.txt", below5);
        savetofile("kietakai_1000000.txt", above5);
        auto end1000000 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed1000000 = end1000000 - start1000000;
        cout << "Total time elapsed: " << elapsed1000000.count() << " seconds" << endl;
        cout << endl;

        auto start10000000 = std::chrono::high_resolution_clock::now();
        filegeneration("studentai_10000000.txt", 10000000, numHW, Vec1);
        filterbelow5("studentai_10000000.txt", below5);
        filterabove5("studentai_10000000.txt", above5);
        savetofile("nuskriaustukai_10000000.txt", below5);
        savetofile("kietakai_10000000.txt", above5);
        auto end10000000 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed10000000 = end10000000 - start10000000;
        cout << "Total time elapsed: " << elapsed10000000.count() << " seconds" << endl;
        cout << endl;

        system("pause");
        return 0;
//////////////////////////////////////////////////////////////////////
///////////////// V0.2
//////////////////////////////////////////////////////////////////////
        } else {
            int n;
            while (true) {
                cout << "How many students will you be grading? ";
                cin >> n;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                } else if (n > 0) {
                    break;
                } else {
                    cout << "Invalid input. Please enter a positive number." << endl;
                }
            }

            char hw;
            while (true) {
                do {
                    cout << "Do you know the number of homework assignments per student? (y/n): ";
                    cin >> hw;

                    if (hw != 'y' && hw != 'Y' && hw != 'n' && hw != 'N') {
                        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                    }
                } while (hw != 'y' && hw != 'Y' && hw != 'n' && hw != 'N');

                if (hw == 'y' || hw == 'Y') {
                    int hwCount;
                    while (true) {
                        cout << "Enter the number of assignments: ";
                        cin >> hwCount;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter a number." << endl;
                        } else if (hwCount < 0) {
                            cout << "Enter a positive number." << endl;
                        } else if (hwCount == 0) {
                            for (int i = 0; i < n; i++) {
                                inputnull(Temp);
                            }
                            printHeadernull();
                            for (int i = 0; i < n; i++) {
                                outputnull(Temp);
                            }
                            system("pause");
                            return 0;
                        } else break;
                    }

                    char random;
                    do {
                        cout << "Do you want to generate random grades? (y/n): ";
                        cin >> random;

                        if (random != 'y' && random != 'Y' && random != 'n' && random != 'N') {
                            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                        }
                    } while (random != 'y' && random != 'Y' && random != 'n' && random != 'N');

                    if (random == 'y' || random == 'Y') {
                        for (int i = 0; i < n; i++) {
                            randomgrades(Temp, hwCount);
                            Vec1.push_back(Temp);
                            clean(Temp);
                        }
                    } else if (random == 'n' || random == 'N') {
                        for (int i = 0; i < n; i++) {
                            input(Temp, hwCount);
                            Vec1.push_back(Temp);
                            clean(Temp);
                        }
                    }
                    break;
                } else if (hw == 'n' || hw == 'N') {
                    for (int i = 0; i < n; i++) {
                        inputgrades(Temp);
                        Vec1.push_back(Temp);
                        clean(Temp);
                    }
                    break;
                }
            }
        }
    }

    int option;
    do {
        cout << "Choose option: 1 to view average, 2 to view median: ";
        cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (option == 1) {
            printHeaderavg();
            sortsurname(Vec1);
            for (const Stud &student : Vec1) {
                outputavg(student);
            }

            char viewMedian;
            do {
                cout << "Do you want to view the Median as well? (y/n): ";
                cin >> viewMedian;
                if (viewMedian == 'y' || viewMedian == 'Y') {
                    printHeadermed();
                    sortsurname(Vec1);
                    for (const Stud &student : Vec1) {
                        outputmed(student);
                    }
                } else if (viewMedian != 'n' && viewMedian != 'N') {
                    cout << "Invalid input. Please enter 'y' or 'n'." << endl;
                }
            } while (viewMedian != 'y' && viewMedian != 'Y' && viewMedian != 'n' && viewMedian != 'N');

        } else if (option == 2) {
            printHeadermed();
            sortsurname(Vec1);
            for (const Stud &student : Vec1) {
                outputmed(student);
            }

            char viewAverage;
            do {
                cout << "Do you want to view the Average as well? (y/n): ";
                cin >> viewAverage;
                if (viewAverage == 'y' || viewAverage == 'Y') {
                    printHeaderavg();
                    sortsurname(Vec1);
                    for (const Stud &student : Vec1) {
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
    return 0;
}
