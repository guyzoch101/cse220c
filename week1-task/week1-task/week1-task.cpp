// week1-task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void displayAccountInfo(int accountID, string name, float balance) {
    // prints account ID, name, and account balance
    // Parameters: accountID, name, balance
    // Return: void

    std::cout << "Account ID: " << accountID << " Name: " << name << "Balance: $" << balance << endl;
}

float GetAmount(int indicator) {
    // prompts for user input of the deposit / withdrawal amount, and returns the float amount
    // Parameters: indicator
    // Return: float amount
    float amount = 0;

    if (indicator == 2) {
        std::cout << "Enter the amount of deposit: $";
    }
    else if (indicator == 3) {
        std::cout << "Enter the amount of withdrawal: $";
    }
    cin >> amount;

    return amount;
}

int main()
{
    int identificationNumber = 0;
    std::string name = "";
    float balance = 0;

    // Name (user input)
    // Clear the input buffer to remove the leftover newline character
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    std::cout << "Enter the name: ";
    getline(cin, name); // reads the whole line

    // Balance (user input)
    std::cout << "Enter the balance: $";
    cin >> balance;

    int choice = 1;
    while (choice != 0) {
        std::cout << "\n"; // prints empty line
        // std::cout << endl;

        std::cout << "Account Menu:" << endl;
        std::cout << "  0. Quit Program" << endl;
        std::cout << "  1. Display Account Information" << endl;
        std::cout << "  2. Deposit" << endl;
        std::cout << "  3. Withdrawal" << endl;

        std::cout << "Your choice: ";
        cin >> choice;

        if (choice == 0) {
            std::cout << "Exiting...";
            break;
        }
        else if (choice == 1) {
            // function for displaying account details
            displayAccountInfo(identificationNumber, name, balance);
        }
        else if (choice == 2) {
            // function for adding deposit
            float depositAmount = GetAmount(2);

            balance += depositAmount; // new balance = balance + deposit
        }
        else if (choice == 3) {
            float withdrawalAmount = GetAmount(3);

            balance -= withdrawalAmount; // new balance = balance - withdrawal
        }
        else {
            std::cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
