#include "functions.h"

void createfile(const string &filename, int entries) {
    ofstream file(filename);


    if (!file) {
        cerr << "Failed  to open file: " << filename << endl;
        return;
    }

    srand(static_cast<unsigned int>(time(0))); // kiekviena karta sugeneruoja kitokius grades

    for (int i = 1; i <= entries; ++i) {
        file << "Vardas" << i << " Pavarde" << i << " " << (rand() % 10 + 1) << endl;
    }

    file.close();
    cout << "File created successfully: " << filename << " with " << entries << " entries." << endl;
}
