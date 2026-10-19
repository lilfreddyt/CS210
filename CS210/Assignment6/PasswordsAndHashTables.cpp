#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <list>

using namespace std;

uint64_t demoHash(const std::string& s) {
    uint64_t h = 1469598103934665603ULL;
    for (unsigned char c : s) {
        h = (h ^ c) * 1099511628211ULL;
    }
    return h;
}

struct User {
    string username;
    string salt;
    uint64_t passwordHash;
};

const string pepper = "chocolate";


class ChainingHashTable {
private:
    vector<list<User>> table;
    int userCount;

public:
    ChainingHashTable(int size) {
        table.resize(size);
        userCount = 0;
    }

    int hashFunction(string username) {
        uint64_t hash = demoHash(username);
        return hash % table.size();
    }

    void insert(User user) {
        int i = hashFunction(user.username);
        table[i].push_back(user);
        userCount++;
        if (loadFactor() > 0.75) {
            rehash();
        }
    }

    User* find(string username) {
        int i = hashFunction(username);
        list<User>& bucket = table[i];
        for (User& user : bucket) {
            if (user.username == username) {
                return &user;
            }
        }
        return nullptr;
    }

    void remove(string username) {
        int i = hashFunction(username);
        list<User>& bucket = table[i];
        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            if (it->username == username) {
                bucket.erase(it);
                userCount--;
                return;
            }
        }
    }

    double loadFactor() {
        return (double)userCount / table.size();
    }

    void rehash() {
        vector<list<User>> oldTable = table;
        int newSize = table.size() * 2;
        table.clear();
        userCount = 0;
        table.resize(newSize);
        for (list<User>& bucket : oldTable) {
            for (User& user : bucket) {
                insert(user);
            }
        }
        cout << "Rehashing table..." << endl;
        cout << "Old size: " << oldTable.size() << endl;
        cout << "New size: " << table.size() << endl;   
    }
};

class LinearHashTable {
private:
    vector<User> table;
    vector<bool> occupied;
    vector<bool> deleted;
    int userCount;

public:
    LinearHashTable(int size) {
        table.resize(size);
        occupied.resize(size, false);
        deleted.resize(size, false);
        userCount = 0;
    }

    int hashFunction(string username) {
        uint64_t hash = demoHash(username);
        return hash % table.size();
    }

    void insert(User user) {
        int index = hashFunction(user.username);

        for (int i = 0; i < table.size(); i++) {
            if (!occupied[index]) {
                table[index] = user;
                occupied[index] = true;
                deleted[index] = false;
                userCount++;

                if (loadFactor() > 0.5) {
                    rehash();
                }

                return;
            }

            index = (index + 1) % table.size();
        }
    }

    User* find(string username) {
        int index = hashFunction(username);

        for (int i = 0; i < table.size(); i++) {
            if (!occupied[index] && !deleted[index]) {
                return nullptr;
            }

            if (occupied[index] && table[index].username == username) {
                return &table[index];
            }

            index = (index + 1) % table.size();
        }

        return nullptr;
    }

    void remove(string username) {
        int index = hashFunction(username);

        for (int i = 0; i < table.size(); i++) {
            if (!occupied[index] && !deleted[index]) {
                return;
            }

            if (occupied[index] && table[index].username == username) {
                occupied[index] = false;
                deleted[index] = true;
                userCount--;
                return;
            }

            index = (index + 1) % table.size();
        }
    }

    double loadFactor() {
        return (double)userCount / table.size();
    }

    void rehash() {
        vector<User> oldTable = table;
        vector<bool> oldOccupied = occupied;

        int newSize = table.size() * 2;

        table.clear();
        occupied.clear();
        deleted.clear();

        table.resize(newSize);
        occupied.resize(newSize, false);
        deleted.resize(newSize, false);

        userCount = 0;

        for (int i = 0; i < oldTable.size(); i++) {
            if (oldOccupied[i]) {
                insert(oldTable[i]);
            }
        }
    }
};

class QuadraticHashTable {
private:
    vector<User> table;
    vector<bool> occupied;
    vector<bool> deleted;
    int userCount;

public:
    QuadraticHashTable(int size) {
        table.resize(size);
        occupied.resize(size, false);
        deleted.resize(size, false);
        userCount = 0;
    }

    int hashFunction(string username) {
        uint64_t hash = demoHash(username);
        return hash % table.size();
    }

    void insert(User user) {
        int startIndex = hashFunction(user.username);

        for (int i = 0; i < table.size(); i++) {
            int index = (startIndex + i * i) % table.size();

            if (!occupied[index]) {
                table[index] = user;
                occupied[index] = true;
                deleted[index] = false;
                userCount++;

                if (loadFactor() > 0.5) {
                    rehash();
                }

                return;
            }
        }
    }

    User* find(string username) {
        int startIndex = hashFunction(username);

        for (int i = 0; i < table.size(); i++) {
            int index = (startIndex + i * i) % table.size();

            if (!occupied[index] && !deleted[index]) {
                return nullptr;
            }

            if (occupied[index] && table[index].username == username) {
                return &table[index];
            }
        }

        return nullptr;
    }

    void remove(string username) {
        int startIndex = hashFunction(username);

        for (int i = 0; i < table.size(); i++) {
            int index = (startIndex + i * i) % table.size();

            if (!occupied[index] && !deleted[index]) {
                return;
            }

            if (occupied[index] && table[index].username == username) {
                occupied[index] = false;
                deleted[index] = true;
                userCount--;
                return;
            }
        }
    }

    double loadFactor() {
        return (double)userCount / table.size();
    }

    void rehash() {
        vector<User> oldTable = table;
        vector<bool> oldOccupied = occupied;

        int newSize = table.size() * 2 + 1;

        table.clear();
        occupied.clear();
        deleted.clear();

        table.resize(newSize);
        occupied.resize(newSize, false);
        deleted.resize(newSize, false);

        userCount = 0;

        for (int i = 0; i < oldTable.size(); i++) {
            if (oldOccupied[i]) {
                insert(oldTable[i]);
            }
        }
    }
};

class DoubleHashTable {
private:
    vector<User> table;
    vector<bool> occupied;
    vector<bool> deleted;
    int userCount;

public:
    DoubleHashTable(int size) {
        table.resize(size);
        occupied.resize(size, false);
        deleted.resize(size, false);
        userCount = 0;
    }

    int hashFunction(string username) {
        uint64_t hash = demoHash(username);
        return hash % table.size();
    }

    int secondHash(string username) {
        uint64_t hash = demoHash("second" + username);
        return 1 + hash % (table.size() - 1);
    }

    void insert(User user) {
        int startIndex = hashFunction(user.username);
        int step = secondHash(user.username);

        for (int i = 0; i < table.size(); i++) {
            int index = (startIndex + i * step) % table.size();

            if (!occupied[index]) {
                table[index] = user;
                occupied[index] = true;
                deleted[index] = false;
                userCount++;

                if (loadFactor() > 0.5) {
                    rehash();
                }

                return;
            }
        }
    }

    User* find(string username) {
        int startIndex = hashFunction(username);
        int step = secondHash(username);

        for (int i = 0; i < table.size(); i++) {
            int index = (startIndex + i * step) % table.size();

            if (!occupied[index] && !deleted[index]) {
                return nullptr;
            }

            if (occupied[index] && table[index].username == username) {
                return &table[index];
            }
        }

        return nullptr;
    }

    void remove(string username) {
        int startIndex = hashFunction(username);
        int step = secondHash(username);

        for (int i = 0; i < table.size(); i++) {
            int index = (startIndex + i * step) % table.size();

            if (!occupied[index] && !deleted[index]) {
                return;
            }

            if (occupied[index] && table[index].username == username) {
                occupied[index] = false;
                deleted[index] = true;
                userCount--;
                return;
            }
        }
    }

    double loadFactor() {
        return (double)userCount / table.size();
    }

    void rehash() {
        vector<User> oldTable = table;
        vector<bool> oldOccupied = occupied;

        int newSize = table.size() * 2 + 1;

        table.clear();
        occupied.clear();
        deleted.clear();

        table.resize(newSize);
        occupied.resize(newSize, false);
        deleted.resize(newSize, false);

        userCount = 0;

        for (int i = 0; i < oldTable.size(); i++) {
            if (oldOccupied[i]) {
                insert(oldTable[i]);
            }
        }
    }
};

bool login(ChainingHashTable& users, string username, string password){
    User* user = users.find(username);
    if (user != nullptr) {
        string s = user->salt + password + pepper;
        uint64_t hash = demoHash(s);
        if (hash == user->passwordHash) {
            return true;
        }
        return false;
    }
    else {
        return false;
    }
}

int main() {
    User fredric = {
    "fredric",
    "xK7pQ2",
    demoHash("xK7pQ2" + string("fredric123") + pepper)
    };

    User luna = {
    "luna",
    "m9ZaL4",
    demoHash("m9ZaL4" + string("luna123") + pepper)
    };

    User vincent = {
    "vincent",
    "B3qW8n",
    demoHash("B3qW8n" + string("vincent123") + pepper)
    };

    User andrew = {
    "andrew",
    "rT5vP1",
    demoHash("rT5vP1" + string("andrew123") + pepper)
    };

    User seth = {
    "seth",
    "Y6cJ0s",
    demoHash("Y6cJ0s" + string("seth123") + pepper)
    };

    ChainingHashTable users(5);
    users.insert(fredric);
    users.insert(luna);
    users.insert(vincent);
    users.insert(andrew);
    users.insert(seth);

    cout << "Successful Login Test:" << endl;
    if (login(users, "luna", "luna123")) {
        cout << "Login successful" << endl;
    }
    else {
        cout << "Login failed" << endl;
    }

    cout << "\nWrong Password Test:" << endl;
    if (login(users, "luna", "wrongpassword")) {
        cout << "Login successful" << endl;
    }
    else {
        cout << "Login failed" << endl;
    }

    cout << "\nUnknown User Test:" << endl;
    if (login(users, "john", "john123")) {
        cout << "Login successful" << endl;
    }
    else {
        cout << "Login failed" << endl;
    }

    cout << "\nRemoval Test:" << endl;

    users.remove("vincent");

    if (users.find("vincent") == nullptr) {
        cout << "Vincent was successfully removed" << endl;
    }
    else {
        cout << "Vincent was not removed" << endl;
    }
}