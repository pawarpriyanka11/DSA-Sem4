
#include <iostream>
using namespace std;

// Medical Record class
class MedicalRecord {
public:
    int id;
    string name;
    int age;
    string disease;

    MedicalRecord() {
        id = -1;
        name = "";
        age = 0;
        disease = "";
    }

    MedicalRecord(int _id, string _name, int _age, string _disease) {
        id = _id;
        name = _name;
        age = _age;
        disease = _disease;
    }
};

// Hash Table using double hashing
class HashTable {
public:
MedicalRecord table[10];
    int table_size;

    HashTable(int size) {
        table_size = size;
        table = new MedicalRecord[table_size];
    }

    int hash1(int key) {
        return key % table_size;
    }

    int hash2(int key) {
        return 1 + (key % (table_size - 1)); // Ensures step size is always < table_size and coprime with table_size if it's prime
    }
    

    void insert(int key, string name, int age, string disease) {
        int index = hash1(key);
        int step = hash2(key);

        for (int i = 0; i < table_size; i++) {
            int probe = (index + i * step) % table_size;
            if (table[probe].id == -1) {
                table[probe] = MedicalRecord(key, name, age, disease);
                cout << "Inserted record at index " << probe << endl;
                return;
            }
        }
        cout << "Hash table is full! Cannot insert record.\n";
    }

    void display() {
        cout << "\nMedical Records:\n";
        for (int i = 0; i < table_size; i++) {
            cout << i << " : ";
            if (table[i].id != -1) {
                cout << "ID: " << table[i].id << ", Name: " << table[i].name
                     << ", Age: " << table[i].age << ", Disease: " << table[i].disease << endl;
            } else {
                cout << "Empty\n";
            }
        }
    }

    void search(int key) {
        int index = hash1(key);
        int step = hash2(key);

        for (int i = 0; i < table_size; i++) {
            int probe = (index + i * step) % table_size;
            if (table[probe].id == key) {
                cout << "Record found at index " << probe << ":\n";
                cout << "ID: " << table[probe].id << ", Name: " << table[probe].name
                     << ", Age: " << table[probe].age << ", Disease: " << table[probe].disease << endl;
                return;
            }
        }
        cout << "Record not found.\n";
    }

    void update(int old_id, int new_id, string new_name, int new_age, string new_disease) {
        int index = hash1(old_id);
        int step = hash2(old_id);

        for (int i = 0; i < table_size; i++) {
            int probe = (index + i * step) % table_size;
            if (table[probe].id == old_id) {
                table[probe] = MedicalRecord(); // Clear old
                insert(new_id, new_name, new_age, new_disease); // Reinsert updated
                return;
            }
        }
        cout << "Record not found.\n";
    }

    void delete_record(int key) {
        int index = hash1(key);
        int step = hash2(key);

        for (int i = 0; i < table_size; i++) {
            int probe = (index + i * step) % table_size;
            if (table[probe].id == key) {
                table[probe] = MedicalRecord();
                cout << "Record deleted from index " << probe << endl;
                return;
            }
        }
        cout << "Record not found.\n";
    }
};

// Main function
int main() {
    int table_size, choice, id, age, new_id;
    string name, disease, new_name, new_disease;

    cout << "Enter hash table size: ";
    cin >> table_size;
    HashTable ht(table_size);

    do {
        cout << "\nMenu:\n1. Insert\n2. Display\n3. Search\n4. Update\n5. Delete\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Disease: ";
                cin >> disease;
                ht.insert(id, name, age, disease);
                break;

            case 2:
                ht.display();
                break;

            case 3:
                cout << "Enter ID to search: ";
                cin >> id;
                ht.search(id);
                break;

            case 4:
                cout << "Enter existing ID to update: ";
                cin >> id;
                cout << "Enter new ID: ";
                cin >> new_id;
                cout << "Enter new Name: ";
                cin >> new_name;
                cout << "Enter new Age: ";
                cin >> age;
                cout << "Enter new Disease: ";
                cin >> new_disease;
                ht.update(id, new_id, new_name, age, new_disease);
                break;

            case 5:
                cout << "Enter ID to delete: ";
                cin >> id;
                ht.delete_record(id);
                break;

            default:
                cout << "Invalid choice.\n";
        }

        cout << "Do you want to continue? (1-Yes / 0-No): ";
        cin >> choice;
    } while (choice == 1);

    return 0;
}
