#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==========================================
// 1. Task for [ Amany ] - The Data Model
// ==========================================
class Contact {
private:
    string name, phone, email, address;
public:
    Contact(string n, string p, string e = "no", string a = "no") 
        : name(n), phone(p), email(e), address(a) {}

    string getName() { return name; }
    
    void display() {
        cout << "--------------------------------" << endl;
        cout << "Name: " << name << "\nPhone: " << phone << endl;
        cout << "Email: " << email << "\nAddress: " << address << endl;
    }
};

// =========================================================
// 2. Tasks for [ Abdelrhman ] & [ Alaa Mohamed ] - Logic
// =========================================================
class ContactsManager {
private:
    vector<Contact> contacts;

public:
    // Abdelrhman will write addContact & displayAll here
    void addContact() {
        cout << "[System]: Abdelrhman will implement this." << endl;
    }

    void displayAll() {
        cout << "[System]: Abdelrhman will implement this." << endl;
    }

    // Alaa Mohamed will write search & update here
    void search(string name) {
        cout << "[System]: Alaa Mohamed will implement this." << endl;
    }
};

// ==========================================
// 3. Task for [ Alaa Mosbah ] - UI & Menu
// ==========================================
int main() {
    ContactsManager myManager;
    cout << "Welcome to Phone Contacts Manager!" << endl;
    // Alaa Mosbah will implement the while loop and switch case here
    
    return 0;
}
