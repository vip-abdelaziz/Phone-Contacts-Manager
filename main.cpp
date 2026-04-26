#include "contact.h"

// =========================================================
// واجهة المستخدم والـ Main Loop - قام بها: [ Lujy Ali ]
// =========================================================

int main() {
    // ( Abdelaziz ) إنشاء كائن الإدارة الذي سيحمل البيانات تلقائياً 
    ContactsManager myManager;
    int choice;

    while (true) {
        // تصميم القوائم (Lujy Ali)
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
        
        // التحقق من صحة مدخلات المستخدم ( Abdelaziz )
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        // توزيع الاختيارات على دوال الفريق (Lujy Ali)
        switch (choice) {
            case 1: {
                // استقبال البيانات (Amany & Abdelrhman )
                string n, p, e, a;
                cin.ignore(); 
                cout << "Enter Name: "; getline(cin, n);
                cout << "Enter Phone: "; getline(cin, p);
                cout << "Enter Email (Optional): "; getline(cin, e);
                cout << "Enter Address (Optional): "; getline(cin, a);

                myManager.addContact(Contact(n, p, e, a));
                break;
            }
            case 2:
                myManager.displayAll();
                break;

            case 3: {
                string sName;
                cout << "Enter name to search: ";
                cin.ignore();
                getline(cin, sName);
                myManager.searchContact(sName);
                break;
            }
            case 4: {
                string uName;
                cout << "Enter name to update: ";
                cin.ignore();
                getline(cin, uName);
                myManager.updateContact(uName);
                break;
            }
            case 5:
                myManager.showContactCount();
                break;

            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    }

    return 0;
}
