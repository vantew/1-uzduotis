#include "libraries.h"
#include "functions.h"

int main() {
    createfile("studentai_1000.txt", 1000);
    createfile("studentai_10000.txt", 10000);
    createfile("studentai_100000.txt", 100000);
    createfile("studentai_1000000.txt", 1000000);
    createfile("studentai_10000000.txt", 10000000);

    system("pause");
    return 0;
}
