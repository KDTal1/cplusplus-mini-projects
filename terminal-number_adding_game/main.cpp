#include <iostream> // To use input
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
#include <thread> // To work while the program is working.
#include <chrono> // For the pause.
#include <string> // Based on which is the one adding the value.

using namespace std;

int checkNum(int &num, int input, string incrementor) { // This checks the value of the pointer.
    if (num != 100) { // It checks if it reached about 100 yet, if not, it proceeds to do the if statement
        if (num > 100) { // It checks if the variable reached over 100, if it does, it resets the number.
            num = 0;
            cout << "Number has restarted, please try again." << endl;
        } else {
            cout << incrementor + " added " << input << " to the total, now total is around " << num << endl;
        }
    } else { // Else statement if the value reached exactly 100.
        cout << "Thank you for participating in this program, you may now relax." << endl;
    }
    cout << string(30, '=') << endl;

    return num;
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

void user_increment(int &num, int input) { // Function that happens if the user is the one incrementing the value.
    cout << string(30, '=') << endl;

    if (input <= 3 && input > 0) {
        cout << "User has added a number." << endl;
    } else {
        cout << "Cheating now, are we" << endl;
        input = 0;
    }

    num += input;

    checkNum(num, input, "User");
}

void system_increment(int &num) { // Function that happens if the program is the one incrementing the value.
    int randomNumber = rand() % 9 + 1; // We make the program be unfair, so that the game is challenging.
    num += randomNumber;
    cout << string(30, '=') << endl;
    cout << "Program has added a number." << endl;
    
    checkNum(num, randomNumber, "Program");
}

void show_current_value(int &num) {
    cout << string(30, '=') << endl;
    cout << "!! NUMBER INCREMENTOR GAME !!" << endl;
    cout << "Current number value: " << num << endl;
    cout << string(30, '=') << endl;
}

int main() {
    srand(time(0));
    int number, user_input;
    number = 0;

    // Proceed with making a while loop.
    while (number != 100) {
        user_input = 0;
        clear();
        show_current_value(number);
        cout << "Add a number from 1 - 3 to make it 100: ";
        cin >> user_input;

        if (!cin) {
            cout << "That's not an integer." << endl;
            cin.clear();               // reset cin state
            cin.ignore(10000, '\n');   // discard bad input
        }

        user_increment(number, user_input);
        this_thread::sleep_for(chrono::seconds(1));
    
        if (number != 100) {
            system_increment(number);
        } else {
            cout << "Exiting program..." << endl;
            
            break;
        }

        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}