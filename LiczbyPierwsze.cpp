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
    fstream file("primeNumbers.txt", ios::in | ios::out | ios::app | ios::ate);
    if (!(file.is_open())) {
        return false;
    }
    else if (!(file.tellg() == 0)) {
        return false;
    }
    else
    {
        return true;
    }
    file.close();
}

int main()
{
    if (!fileCheck()) {
        cout << "error | delete file to continiue";
        cin.ignore();
        cin.get();
        return 0;
    }
    fstream file("primeNumbers.txt", ios::in | ios::out | ios::app); // opening a file

    vector<int> primeNumbers;
    int limit = 0;
    cout << "enter a limit >> ";
    cin >> limit;
    for (int i{ 1 }; i <= limit; i=i+2) {
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
    cout << "numbers were saved in \"primeNumbers.txt\", to display them in the console, type \"show\"" << endl;
    cout << ">> ";
    cin >> answer;
    if (answer == "show") {
        string line;
        while (getline(file, line)){
            cout << line << " ";
        }
    }
    cin.ignore();
    cin.get();
    file.close();
    
}