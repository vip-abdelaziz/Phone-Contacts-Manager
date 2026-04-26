#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>   
#include <algorithm> 

using namespace std;

// ==========================================
// 1. كلاس البيانات - مسؤولة عنه: [ Amany Hossam ]
// ==========================================
class Contact {
private:
    string name, phone, email, address;

public:
    // الـ Constructor لتجهيز بيانات جهة الاتصال
    Contact(string n = "", string p = "", string e = "no", string a = "no")
        : name(n), phone(p), email(e), address(a) {}

    // دوال الـ Getters (أساسية لعمل باقي الفريق في البحث والتعديل)
    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getEmail() const { return email; }
    string getAddress() const { return address; }

    // دالة العرض المنظم للبيانات
    void display() const {
        cout << "-----------------------------------" << endl;
        cout << "Name    : " << name << endl;
        cout << "Phone   : " << phone << endl;
        cout << "Email   : " << email << endl;
        cout << "Address : " << address << endl;
        cout << "-----------------------------------" << endl;
    }

    // دالة مساعدة لتحويل الكائن لسطر نصي (Abdelaziz)
    string toFileData() const {
        return name + "|" + phone + "|" + email + "|" + address;
    }
};

// =========================================================
// 2. كلاس الإدارة - المسؤول عنه: [ Abdelaziz ] (دمجاً لعمل الفريق)
// =========================================================
class ContactsManager {
private:
    vector<Contact> contacts; // المخزن الأساسي (مسؤولية عبدالرحمن أسامة)
    const string fileName = "contacts_db.txt"; // ملف قاعدة البيانات

public:
    // Constructor (Abdelaziz): يقوم بتحميل البيانات فور تشغيل البرنامج
    ContactsManager() {
        loadFromFile();
    }

    // [ Abdelrhman Osama ]: دالة إضافة جهة اتصال جديدة
    void addContact(const Contact& c) {
        contacts.push_back(c);
        saveToFile(); // (Abdelaziz) حفظ تلقائي لضمان عدم ضياع البيانات
        cout << "Contact added successfully!\n";
    }

    // [ Abdelrhman Osama ]: دالة عرض كافة الأسماء المسجلة
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

    // [ Abdelrhman Osama ]: دالة عرض إحصائية عدد جهات الاتصال
    void showContactCount() const {
        cout << "Total Contacts: " << contacts.size() << endl;
    }

    // [ Ahmad Abdelsalam ]: دالة البحث عن جهة اتصال بالاسم
    // (Abdelaziz): جعل البحث غير حساس لحالة الأحرف (Case Insensitive)
    void searchContact(string target) {
        bool found = false;
        // تحويل نص البحث لحروف صغيرة
        transform(target.begin(), target.end(), target.begin(), ::tolower);
        
        for (const auto& c : contacts) {
            string currentName = c.getName();
            transform(currentName.begin(), currentName.end(), currentName.begin(), ::tolower);
            
            if (currentName == target) {
                c.display();
                found = true;
            }
        }
        if (!found) cout << "Contact not found." << endl;
    }

    // [ Omnia Ahmed ]: دالة تعديل بيانات جهة اتصال موجودة
    // (Abdelaziz) "Enter للإبقاء على القديم" واستبدال cin بـ getline
    void updateContact(string targetName) {
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts[i].getName() == targetName) {
                string p, e, a;
                cout << "Contact found! (Press Enter to keep current value)\n";
                
                cin.ignore(); 
                cout << "New Phone [" << contacts[i].getPhone() << "]: "; getline(cin, p);
                cout << "New Email [" << contacts[i].getEmail() << "]: "; getline(cin, e);
                cout << "New Address [" << contacts[i].getAddress() << "]: "; getline(cin, a);

                //  إذا كان الإدخال فارغاً استخدم القيمة القديمة
                string finalP = (p.empty()) ? contacts[i].getPhone() : p;
                string finalE = (e.empty()) ? contacts[i].getEmail() : e;
                string finalA = (a.empty()) ? contacts[i].getAddress() : a;

                contacts[i] = Contact(targetName, finalP, finalE, finalA);
                saveToFile(); // حفظ التغييرات في الملف فوراً
                cout << "Update successful!" << endl;
                return;
            }
        }
        cout << "Contact not found." << endl;
    }

    // =======================================================
    // دوال إدارة الملفات (File Handling) -  [ Abdelaziz ]
    // =======================================================
    
    // دالة لحفظ محتويات الـ Vector في ملف خارجي
    void saveToFile() {
        ofstream outFile(fileName);
        for (const auto& c : contacts) {
            outFile << c.toFileData() << endl;
        }
        outFile.close();
    }

    // دالة لقراءة البيانات من الملف عند بداية البرنامج
    void loadFromFile() {
        ifstream inFile(fileName);
        if (!inFile) return; // إذا كان الملف غير موجود لا تفعل شيئاً
        string line;
        while (getline(inFile, line)) {
            // تقسيم السطر بناءً على علامة | (Abdelaziz)
            size_t pos1 = line.find('|');
            size_t pos2 = line.find('|', pos1 + 1);
            size_t pos3 = line.find('|', pos2 + 1);
            
            string n = line.substr(0, pos1);
            string p = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string e = line.substr(pos2 + 1, pos3 - pos2 - 1);
            string a = line.substr(pos3 + 1);
            
            contacts.push_back(Contact(n, p, e, a));
        }
        inFile.close();
    }
};

#endif
