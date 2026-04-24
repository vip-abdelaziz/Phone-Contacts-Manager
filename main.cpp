#include "Contact.h"

// ==========================================
// 3. Task for [ Ahmed abdelsalam]
// ==========================================
int main() {
    ContactsManager myManager;
    int choice;

    while (true) {
        cout << "\nWelcome to Phone Contacts Manager!" << endl;
        cout << "=== MAIN MENU ===" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display All Contacts" << endl;
        cout << "3. Search Contacts" << endl;
        cout << "4. Update Contact" << endl;
        cout << "5. Show Total Contacts" << endl;
        cout << "0. Exit" << endl;
        cout << "==================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Call Abdelrhman's add function
        } else if (choice == 2) {
            myManager.displayAll();
        } else if (choice == 0) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
