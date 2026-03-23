#include <iostream>
using namespace std;

// Weapon Class (exists only as part of Player)
class Weapon {
public:
    string weaponName;
    int damage;

    Weapon() {} // default
    Weapon(string name, int dmg) {
        weaponName = name;
        damage = dmg;
    }

    void display() {
        cout << "Weapon: " << weaponName << ", Damage: " << damage << endl;
    }
};

// Player Class
class Player {
private:
    string playerName;
    int health;
    Weapon weapon; // Composition: Weapon exists only as part of Player

public:
    static int activePlayers; // Track active players

    // Constructor
    Player(string name, int hp, Weapon w) {
        playerName = name;
        health = hp;
        weapon = w;
        activePlayers++;
        cout << playerName << " joined the game. Active Players: " << activePlayers << endl;
    }

    // Const function to show player status
    void showStatus() const {
        cout << "\nPlayer: " << playerName << "\nHealth: " << health << endl;
        weapon.display();
        cout << "Active Players: " << activePlayers << endl;
    }

    // Destructor
    ~Player() {
        cout << playerName << " has left the game. ";
        activePlayers--;
        cout << "Active Players now: " << activePlayers << endl;
    }
};

// Initialize static member
int Player::activePlayers = 0;

int main() {
    cout << "Online Game Simulation\n\n";

    // Array of Player objects inside a block
    {
        Player players[3] = {
            Player("Ali", 100, Weapon("Sword", 25)),
            Player("Sara", 90, Weapon("Bow", 20)),
            Player("Hamza", 120, Weapon("Axe", 30))
        };

        // Show status of all players
        for (int i = 0; i < 3; i++) {
            players[i].showStatus();
        }
    } // All players destroyed here as block ends

    cout << "\nAfter block ends, active players: " << Player::activePlayers << endl;

    return 0;
}
