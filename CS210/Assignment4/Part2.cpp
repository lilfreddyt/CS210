#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

struct Property;

struct Player {
    string name;
    int money;
    Property* position;
};

struct Property {
    string name;
    int cost;
    Player* owner;
    Property* next;
};

int rollDice() {
   return rand() % 6 + 1;
}

class Board {
    private:
        Property* head;
        Property* tail;
    public:
        vector<Player> players;

        Board() {
            head = nullptr;
            tail = nullptr;
        }

        void addProperty(string name, int cost) {
            Property* newProperty = new Property();
            newProperty->name = name;
            newProperty->cost = cost;

            if (head == nullptr) {
                head = newProperty;
                tail = newProperty;
                newProperty->next = head;
                newProperty->owner = nullptr;
                return;
            }
            tail->next = newProperty;
            tail = newProperty;
            newProperty->next = head;
            newProperty->owner = nullptr;
        }

        void addPlayer(string name, int money) {
            Player newPlayer;

            newPlayer.name = name;
            newPlayer.money = money;
            newPlayer.position = head;
            players.push_back(newPlayer);
        }

        int move(Player& player) {
            int spotsMoved = rollDice();
            
            for (int i = 0; i < spotsMoved; i++) {
                player.position = player.position->next;
            }
            return spotsMoved;
        }

        void buyProperty(Player& player) {
            if (player.money >= player.position->cost && player.position->owner == nullptr) {
                player.money -= player.position->cost;
                player.position->owner = &player;
            }
        }
};

int main() {
    srand(time(0));

    Board board;

    board.addProperty("Mediterranean Avenue", 60);
    board.addProperty("Baltic Avenue", 60);
    board.addProperty("Oriental Avenue", 100);
    board.addProperty("Vermont Avenue", 100);
    board.addProperty("Connecticut Avenue", 120);
    board.addProperty("St. Charles Place", 140);
    board.addProperty("States Avenue", 140);
    board.addProperty("Virginia Avenue", 160);
    board.addProperty("St. James Place", 180);
    board.addProperty("Tennessee Avenue", 180);


    board.addPlayer("Fredric", 1500);
    board.addPlayer("Luna", 1500);


    for (int turn = 1; turn <= 10; turn++) {
        int playerIndex = turn % board.players.size();

        Player& currentPlayer = board.players[playerIndex];

        cout << "Turn " << turn << endl;

        int roll = board.move(currentPlayer);

        cout << currentPlayer.name << " rolled a " << roll << endl;

        cout << currentPlayer.name << " landed on "
             << currentPlayer.position->name << endl;

        board.buyProperty(currentPlayer);

        cout << currentPlayer.name << " has $"
             << currentPlayer.money << endl;

        cout << endl;
    }

    return 0;
}