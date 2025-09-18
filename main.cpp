#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

int ifPrime(int n) {
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool fileCheck() {
    ifstream file("primeNumbers.txt");
    return !file.is_open();
}

int main()
{
    if (!fileCheck()) {
        cout << "\033[31m" << "error | delete file \"primeNumbers.txt\" to continiue" << "\033[0m";
        cin.ignore();
        cin.get();
        return 0;
    }
    while (true) {
        system("cls");
        fstream file("primeNumbers.txt", ios::in | ios::out | ios::app); // opening a file

        vector<int> primeNumbers;
        int limit = 0;
        cout << "enter a limit >> ";
        if (!(cin >> limit)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "\033[31m" << "wrong input type" << "\033[0m" << endl;
            cin.get();
            continue;
        }
        for (int i{ 1 }; i <= limit; i = i + 2) {
            if (ifPrime(i)) {
                primeNumbers.push_back(i);
            }
        }
        primeNumbers.erase(primeNumbers.begin() + 0); // deleting first letter in the file



        for (int x : primeNumbers) {
            file << x << " "; // saving elements
        }
        file.seekg(0); //move the "cursor" to the beginning of the file
        system("cls");
        string answer;
        cout << "\033[32m" << "numbers were saved in \"primeNumbers.txt\"" << "\033[0m" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "to display them in the consoletype \"show\"" << endl;
        cout << "to exit program type \"exit\"" << endl;
        cout << ">> ";
        cin >> answer;
        if (answer == "show") {
            cout << endl;
            string line;
            while (getline(file, line)) {
                cout << "\033[32m" << line << " " << "\033[0m";
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