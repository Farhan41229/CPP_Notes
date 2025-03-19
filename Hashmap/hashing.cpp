#include <iostream>
#define SIZE 10
#define PRIME 7

using namespace std;

class HashTable {
private:
    int H[SIZE] = {0};

    int Hash(int key) {
        return key % SIZE;
    }

    int LinearProbe(int key, int &attempts) {
        int idx = Hash(key);
        int i = 0;
        while (H[(idx + i) % SIZE] != 0) {
            cout << "Collision: Index-" << (idx + i) % SIZE << endl;
            i++;
            attempts++;
            if (attempts >= 6) return -1;
        }
        return (idx + i) % SIZE;
    }

    int QuadraticProbe(int key, int &attempts) {
        int idx = Hash(key);
        int i = 0;
        while (H[(idx + i * i) % SIZE] != 0) {
            cout << "Collision: Index-" << (idx + i * i) % SIZE << endl;
            i++;
            attempts++;
            if (attempts >= 6) return -1;
        }
        return (idx + i * i) % SIZE;
    }

    int PrimeHash(int key) {
        return PRIME - (key % PRIME);
    }

    int DoubleHash(int key, int &attempts) {
        int idx = Hash(key);
        int i = 0;
        while (H[(idx + i * PrimeHash(key)) % SIZE] != 0) {
            cout << "Collision: Index-" << (idx + i * PrimeHash(key)) % SIZE << endl;
            i++;
            attempts++;
            if (attempts >= 6) return -1;
        }
        return (idx + i * PrimeHash(key)) % SIZE;
    }

    float CalculateLoadFactor() {
        int filled = 0;
        for (int i = 0; i < SIZE; i++) {
            if (H[i] != 0) filled++;
        }
        return static_cast<float>(filled) / SIZE;
    }

public:
    void Insert(int key, int choice) {
        int idx, attempts = 0;
        switch (choice) {
            case 1: // Linear Probing
                idx = LinearProbe(key, attempts);
                break;
            case 2: // Quadratic Probing
                idx = QuadraticProbe(key, attempts);
                break;
            case 3: // Double Hashing
                idx = DoubleHash(key, attempts);
                break;
            default:
                cout << "Invalid choice!" << endl;
                return;
        }
        
        if (idx != -1) {
            H[idx] = key;
            cout << "Inserted : Index-" << idx << " (L.F = " << CalculateLoadFactor() << ")" << endl;
        } else {
            cout << "Input Abandoned" << endl;
        }
    }

    void Print_Table(string s) {
        cout << s << ": [";
        for (int i = 0; i < SIZE; i++) {
            cout << H[i];
            if (i < SIZE - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main() {
    int choice, n, key;
    cout << "Enter choice (1: Linear, 2: Quadratic, 3: Double): ";
    cin >> choice;
    cout << "Enter number of elements: ";
    cin >> n;

    HashTable ht;
    for (int i = 0; i < n; i++) {
        cout << "Enter key to insert: ";
        cin >> key;
        ht.Insert(key, choice);
    }

    ht.Print_Table("Hash Table");
    return 0;
}
