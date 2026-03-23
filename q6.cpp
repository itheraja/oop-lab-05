#include <iostream>
using namespace std;

class Player {
private:
    string name;

public:
    static int totalPlayers; // static member to track total players

    // Constructor
    Player(string n) {
        name = n;
        totalPlayers++;
        cout << name << " has joined the game. Total players: " << totalPlayers << endl;
    }

    // Destructor
    ~Player() {
        cout << name << " has left the game. ";
        totalPlayers--;
        cout << "Total players now: " << totalPlayers << endl;
    }

    // Static function to show total players
    static void showPlayers() {
        cout << "Total players online: " << totalPlayers << endl;
    }
};

// Initialize static member
int Player::totalPlayers = 0;

int main() {
    cout << "Game Server Simulation\n\n";

    Player::showPlayers(); // initially 0

    // Players created inside a block
    {
        Player p1("Ali");
        Player p2("Sara");
        Player p3("Hamza");

        Player::showPlayers(); // should show 3
    } 

    cout << "\nAfter block ends:\n";
    Player::showPlayers(); // should show 0

    return 0;
}
