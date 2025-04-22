#include <iostream>
#include <string>

using namespace std;

struct Member {  
   string name;  
   int membershipNumber = 0;  
   int credits = 0;  
};

void createAccount(Member& member) {
    cout << "Enter your name: ";
    cin >> member.name;
    cout << "Enter your membership number: ";
    cin >> member.membershipNumber;
    do {
        cout << "Enter initial session credits (at least 1): ";
        cin >> member.credits;
    } while (member.credits < 1);
}

void addSessionCredits(Member& member) {
    int additionalCredits;
    do {
        cout << "Enter the number of credits to add (positive integer): ";
        cin >> additionalCredits;
    } while (additionalCredits <= 0);
    member.credits += additionalCredits;
}

void bookSession(Member& member) {
    if (member.credits > 0) {
        member.credits--;
        cout << "Session booked successfully. Remaining credits: " << member.credits << endl;
    }
    else {
        cout << "Insufficient credits to book a session." << endl;
    }
}

void checkCredits(const Member& member) {
    cout << "Remaining session credits: " << member.credits << endl;
}

void displayAccountDetails(const Member& member) {
    cout << "Name: " << member.name << endl;
    cout << "Membership Number: " << member.membershipNumber << endl;
    cout << "Remaining Credits: " << member.credits << endl;
}

void displayMenu() {
    cout << "1. Create Account" << endl;
    cout << "2. Add Session Credits" << endl;
    cout << "3. Book Session" << endl;
    cout << "4. Check Credits" << endl;
    cout << "5. Display Account Details" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Member member;
    int choice;
    bool accountCreated = false;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            createAccount(member);
            accountCreated = true;
            break;
        case 2:
            if (accountCreated) {
                addSessionCredits(member);
            }
            else {
                cout << "Please create an account first." << endl;
            }
            break;
        case 3:
            if (accountCreated) {
                bookSession(member);
            }
            else {
                cout << "Please create an account first." << endl;
            }
            break;
        case 4:
            if (accountCreated) {
                checkCredits(member);
            }
            else {
                cout << "Please create an account first." << endl;
            }
            break;
        case 5:
            if (accountCreated) {
                displayAccountDetails(member);
            }
            else {
                cout << "Please create an account first." << endl;
            }
            break;
        case 6:
            cout << "Exiting the system." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
