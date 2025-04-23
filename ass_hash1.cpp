#include <iostream>
using namespace std;


class Music {
public:
    int id;
    string title,singer;

    Music() {
        id = -1;
        title = "";
        singer = "";
    }

    Music(int id1, string title1, string singer1) {
        id=id1;
        title=title1;
        singer=singer1;
    }
};


class hashing{
public:
    Music table[10];
    int table_size;

    hashing(int size) {
        table_size = size;
        for (int i = 0; i < table_size; i++) {
            table[i] = Music(); 
        }
    }

    int hash_function(int key) {
        return key % table_size;
    }

    void insert_data(int key, string m_title, string m_singer) {
        int index = hash_function(key);
        for (int i = 0; i < table_size; i++) {
            int probe = (index + i) % table_size;
            if (table[probe].id == -1) {
                table[probe] = Music(key, m_title, m_singer);
                cout << "\n\nInserted Music ID " << key << " at index " << probe << endl;
                return;
            }
            else{
                cout<<"\n\nCollision occurs at index: "<<probe<<endl;
            }
        }
        cout << "Hash Table is full! Cannot insert music.\n";
    }

    void display() {
        cout << "\nMusic Library:\n";
        for (int i = 0; i < table_size; i++) {
            cout << i << " : ";
            if (table[i].id != -1) {
                cout << "ID: " << table[i].id << ", Title: " << table[i].title << ", Singer: " << table[i].singer << endl;
            } else {
                cout << "Empty" << endl;
            }
        }
    }

    void search(int key) {
        int index = hash_function(key);
        for (int i = 0; i < table_size; i++) {
            int probe = (index + i) % table_size;
            if (table[probe].id == key) {
                cout << "Music found at index " << probe << endl;
                cout << "ID: " << table[probe].id << ", Title: " << table[probe].title << ", Singer: " << table[probe].singer << endl;
                return;
            }
        }
        cout << "Music not found\n";
    }

    void update(int key, int newkey, string new_ti, string new_sin) {
        int index = hash_function(key);
        for (int i = 0; i < table_size; i++) {
            int probe = (index + i) % table_size;
            if (table[probe].id == key) {
                table[probe] = Music(); 
                insert_data(key, new_ti, new_sin); 
                return;
            }
        }
        cout << "Music not found\n";
    }

    void delete_ele(int key) {
        int index = hash_function(key);
        for (int i = 0; i < table_size; i++) {
            int probe = (index + i) % table_size;
            if (table[probe].id == key) {
                table[probe] = Music();
                cout << "Element " << key << " is deleted from index " << probe << endl;
                return;
            }
        }
        cout << "Music not found\n";
    }
};


int main() {
    int n, key, k, old, newkey, dele, ch, choice, table_size;
    string title, singer;

    cout << "Enter the table size: ";
    cin >> table_size;
    hashing H(table_size);

    do {
        cout << "\nMenu:\n1. Insert\n2. Display\n3. Search\n4. Update\n5. Delete\n6. Exit\n\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
                cout << "Enter Music ID,title,singer: ";
                cin >> key>>title>>singer;
                H.insert_data(key, title, singer);
            break;

        case 2:
            H.display();
            break;

        case 3:
            cout << "Enter key to search: ";
            cin >> k;
            H.search(k);
            break;

        case 4:
            cout << "Enter existing Music ID to update: ";
            cin >> old;
            cout << "Enter new Music ID,title,singer: ";
            cin >> newkey>>title>>singer;
            H.update(old, newkey, title, singer);
            break;

        case 5:
            cout << "Enter Music ID to delete: ";
            cin >> dele;
            H.delete_ele(dele);
            break;

        case 6:
        cout<<"\nExiting from the code!";    

        default:
            cout << "Invalid choice\n";
        }

    } while (ch!=6);

    return 0;
}