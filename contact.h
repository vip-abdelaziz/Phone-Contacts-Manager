#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==========================================
// 1. Task for [ Amany Hossam ] - Data Model
// ==========================================
class Contact {
private:
    string name, phone, email, address;

public:
    // Constructor باستخدام الـ Initialization List لسرعة الأداء
    Contact(string n = "", string p = "", string e = "no", string a = "no")
        : name(n), phone(p), email(e), address(a) {}

    // Getters للوصول للبيانات (مهمة لأحمد وأمنية في البحث والتعديل)
    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getEmail() const { return email; }
    string getAddress() const { return address; }

    // دالة العرض المنظم
    void display() const {
        cout << "-----------------------------------" << endl;
        cout << "Name    : " << name << endl;
        cout << "Phone   : " << phone << endl;
        cout << "Email   : " << email << endl;
        cout << "Address : " << address << endl;
        cout << "-----------------------------------" << endl;
    }
};

// =========================================================
// 2. Tasks for [ Abdelrhman, Omnia, Ahmad ] - Logic
// =========================================================
class ContactsManager {
private:
    vector<Contact> contacts;

public:
    // [ Abdelrhman Osama ] - إضافة وعرض إحصائيات
    void addContact(const Contact& c) {
        contacts.push_back(c);
        cout << "Contact added successfully!\n";
    }

    void displayAll() const {
        if (contacts.empty()) {
            cout << "No contacts found!" << endl;
            return;
        }
        cout << "\n=== ALL CONTACTS ===\n";
        for (const auto& c : contacts) {
            c.display();
        }
    }

    void showContactCount() const {
        cout << "Total Contacts: " << contacts.size() << endl;
    }

    // [ Ahmad Abdelsalam ] - محرك البحث
    void searchContact(string targetName) {
        bool found = false;
        for (const auto& c : contacts) {
            if (c.getName() == targetName) {
                c.display();
                found = true;
            }
        }
        if (!found) cout << "Contact not found." << endl;
    }

    // [ Omnia Ahmed ] - منطق التعديل
    void updateContact(string targetName) {
        bool found = false;
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts[i].getName() == targetName) {
                string p, e, a;
                cout << "Contact found! Enter new details:\n";
                cout << "New Phone: "; cin >> p;
                cout << "New Email: "; cin >> e;
                cout << "New Address: "; cin >> a;

                // تحديث الكائن بكائن جديد بنفس الاسم
                contacts[i] = Contact(targetName, p, e, a);

                cout << "Update successful!" << endl;
                found = true;
                break;
            }
        }
        if (!found) cout << "Contact not found." << endl;
    }
};

#endif
