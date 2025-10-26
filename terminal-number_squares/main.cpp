/*

Creative Coding - Number Squares
Initially finished on: 10/18/2025 - 7:51 PM GMT+8

Egg.

There may be others that have already done this before, but this is just me doing it out of boredom.

*/

#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <sstream>
#include <string>

using namespace std;

int randomNumber() { // Sets up the randomizer for the guessing game.
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(10, 99);

    return dist(gen);
}

void clear() { // Clears the screen.
#ifdef _WIN32 // It first checks if the operating system is Windows-based, thus initializes a bool variable to true.
    const bool isWindows = true;
#else
    const bool isWindows = false;
#endif

    if (isWindows) // If the operating system is Windows, it will run cls.
        system("cls");
    else // otherwise.
        system("clear");
}

void printSquare(int size) {
    while (true) {
        stringstream buffer; // store everything first

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                buffer << randomNumber() << " ";
            }
            buffer << '\n';
        }

        clear();
        cout << string(29, '=') << endl;
        cout << buffer.str(); // print all at once
        cout << string(29, '=') << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int decision(int &size) { // This part is to skip the first part, so that you don't have to input the size again.
     if (!size) {
        cout << string(30, '-') << endl;
        cout << "How large do you want your square to be? From 5 - 20?" << endl;
        cout << "Input: ";
        cin >> size;

        if (!cin) { // Runs when the input is not a number, or integer
            cout << string(45, '=') << endl;
            cout << "Is this actually a number?" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (size < 5) {
            cout << "We don't allow that here. Defaulting to 5." << endl;
            size = 5;
        }
     } else {
        return size;
     }

     return size;
}

int main() {
    string choice;
    choice = "Egg";
    int size = 0;

    while (choice != "N") {
        clear();
        decision(size);
        cout << string(30, '-') << endl;
        cout << "Are you sure you are ready to run the program? Y/N >> ";
        cin >> choice;

        if (choice == "N") {
            clear();
            cout << "Thank you for using this program, then.\nIt would be fun to see you again someday\n\nWhen you're ready to see a cube that runs in numbers, of course" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            break;
        } else if (choice == "Y") {
            printSquare(size);
        } else {
            cout << string(30, '-') << endl;
            cout << "Invalid input, try again." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }

    return 0;
}