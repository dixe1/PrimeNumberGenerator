#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include "console_writer.h"
using namespace std;

bool ifPrime(long long& n) {
    double sq{ sqrt(n) };
    for (long long i = 2; i <= sq; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool fileExists() {
    ifstream file("primeNumbers.txt");
    return file.is_open();
}


int main()
{
    if (fileExists()) {
        cout << "\033[31m" << "error | delete file \"primeNumbers.txt\" to continiue" << "\033[0m" << endl;
        cout << "\033[32m" << "-- press enter to automatically delete the file --" << "\033[0m";
        cin.get();
        remove("primeNumbers.txt");
    }
    while (true) {
        system("cls");
        fstream file("primeNumbers.txt", ios::in | ios::out | ios::app); // opening a file

        vector<int> primeNumbers;
        int limit = 0;

        write("==== Prime Number Generator ====", 20, 50, 32); cout << endl;
        cout << "enter a limit >> ";
        if (!(cin >> limit)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\033[31m" << "wrong input type" << "\033[0m" << endl;
            cin.get();
            continue;
        }
        if (limit >= 2) {
            primeNumbers.push_back(2);
        }
        for (long long i{ 3 }; i <= limit; i = i + 2) {   //starting from 3 and adding 2 to skip even numbers
            if (ifPrime(i)) {
                primeNumbers.push_back(i);
            }
        }



        for (int x : primeNumbers) {
            file << x << " "; // saving elements
        }
        file.seekg(0); //move the "cursor" to the beginning of the file
        system("cls");
        string answer;
        cout << "\033[32m" << "numbers were saved in \"primeNumbers.txt\"" << "\033[0m" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "to display them in the consoletype \"show\"" << endl;
        cout << "to exit program type \"exit\"" << endl << endl;
        cout << "--------------- ";
        cout << "limit = " << "\033[32m" << limit << "\033[0m";
        cout << " ---------------" << endl;
        cout << ">> ";
        cin >> answer;
        if (answer == "show") {
            cout << endl;
            string line;
            while (getline(file, line)) {
                write(line, 0, 1);
            }
        }
        else {
            return 0;
        }
        cin.ignore();
        cin.get();
        file.close();
        return 0;
    }
}