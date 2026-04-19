#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==========================================
// 1. Task for [ Amany Hossam ]
// ==========================================
class Contact {
private:
    string name, phone, email, address;

public:
    Contact(string n, string p, string e = "no", string a = "no") 
        : name(n), phone(p), email(e), address(a) {}

    // Getters for searching and displaying
    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getEmail() const { return email; }
    string getAddress() const { return address; }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;
        cout << "--------------------------------" << endl;
    }
};

// =========================================================
// 2. Tasks for [ Abdelrhman Osama ] & [ Alaa Mohamed ]
// =========================================================
class ContactsManager {
private:
    vector<Contact> contacts;

public:
    // [ Abdelrhman Osama ] - Addition & Basic View
    void addContact(const Contact& c) {
        contacts.push_back(c);
        std::cout << "Contact added successfully!\n";
    }

    void displayAll() const {
        if (contacts.empty()) {
            cout << "No contacts found!" << endl;
            return;
        }
        std::cout << "\n=== ALL CONTACTS ===\n";
        for (const auto& c : contacts) {
            c.display();
        }
    }
    
    void showContactCount() const {
        cout << "Total Contacts: " << contacts.size() << endl;
    }

    // [ Alaa Mohamed ] - Search & Update Logic
    void searchContact(string targetName) {
        // Search logic goes here
    }

    void updateContact(string targetName) {
        // Update logic goes here
    }
};

#endif
