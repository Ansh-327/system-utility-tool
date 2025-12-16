#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>   // for remove()
using namespace std;

int main() {
    int choice;
    string filename = "test.txt";
    string line, word;

    while (true) {
        cout << "\n===== SYSTEM UTILITY TOOL =====\n";
        cout << "1. Create File\n";
        cout << "2. Read File\n";
        cout << "3. Delete File\n";
        cout << "4. Search Word\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            ofstream file(filename);
            file << "Hello Linux\nWelcome to File Handling";
            file.close();
            cout << "File created successfully.\n";
        }

        else if (choice == 2) {
            ifstream file(filename);
            if (!file) {
                cout << "File not found!\n";
            } else {
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            }
        }

        else if (choice == 3) {
            if (remove(filename.c_str()) == 0)
                cout << "File deleted successfully.\n";
            else
                cout << "Error deleting file.\n";
        }

        else if (choice == 4) {
            ifstream file(filename);
            if (!file) {
                cout << "File not found!\n";
            } else {
                cout << "Enter word to search: ";
                cin >> word;
                bool found = false;
                string text;

                while (file >> text) {
                    if (text == word) {
                        found = true;
                        break;
                    }
                }

                if (found)
                    cout << "Word FOUND in file.\n";
                else
                    cout << "Word NOT found.\n";

                file.close();
            }
        }

        else if (choice == 5) {
            cout << "Exiting program...\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

