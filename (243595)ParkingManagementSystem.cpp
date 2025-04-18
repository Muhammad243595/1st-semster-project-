#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;

const int maxSpots = 30;  // it can varry
const int spotsPerRow = 5;  
string parkingSpots[maxSpots];

// function Prototypes
void registerUser();
bool loginUser();
void displayMenu();
void parkingStatus();
void parkVehicle();
void removeVehicle();
void saveParking();
void loadParking();
string getPassword(); // password masking

int main() {
    int choice;

    cout << "===== LOGIN PAGE =====\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        if (!loginUser()) {
            cout << "Invalid Username or Password. Exiting...\n";
            return 0; 
        }
    } else {
        cout << "Invalid choice. Please try again.\n";
        return main(); // call main() 
    }

    // load parking data
    loadParking();

    // menu
    int option;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 1) {
            parkingStatus();
        } else if (option == 2) {
            parkVehicle();
        } else if (option == 3) {
            removeVehicle();
        } else if (option == 4) {
            saveParking();
            break; 
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    } while (true);

    cout << "\nClosing the program. Thanks for using the Parking Management System!\n";
    return 0;
}

void registerUser() {
    string username, password;

    cout << "Create a username: ";
    cin >> username;
    cout << "Create a password: ";
    password = getPassword();  // masked password input

    // open the user file to append new user data
    ofstream outFile("users.txt", ios::app);
    if (outFile.is_open()) {
        outFile << username << " " << password << "\n";
        outFile.close();
        cout << "Registration Successful!\n";
        cout << "You can now log in.\n";
    } else {
        cout << "Error: Could not open file for writing.\n";
        exit(1);
    }

    if (!loginUser()) {
        cout << "Authentication failed after registration. Exiting...\n";
        exit(1);
    }
}

bool loginUser() {
    string username, password;

    while (true) { // keep asking for credntials until they are correct
        cout << "Enter your username (or type 'exit' to quit): ";
        cin >> username;
        if (username == "exit") {
            return false;  
        }

        cout << "Enter your password: ";  
        password = getPassword();  // masked password

        ifstream inFile("users.txt");
        if (inFile.is_open()) {
            string savedUsername, savedPassword;
            while (inFile >> savedUsername >> savedPassword) { 
                if (savedUsername == username && savedPassword == password) {
                    inFile.close();
                    cout << "Login Successful! Welcome!\n";
                    return true;
                }
            }
            inFile.close();
        } else {
            cout << "Error: Could not open file for reading.\n";
        }

        cout << "Invalid Username or Password. Please try again.\n";
    }

    return false; 
}

string getPassword() {
    string password = "";
    char ch;
    while ((ch = _getch()) != '\r') {     // enter key
        if (ch == '\b') {                 // backspace key
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else {
            password += ch;
            cout << "*";
        }
    }
    cout << endl;
    return password;
}

void displayMenu() {
    cout << "\n=== Parking Management System ===\n";
    cout << "1. View Parking Status\n";
    cout << "2. Park Vehicle\n";
    cout << "3. Remove Vehicle\n";
    cout << "4. Exit (save)\n";
}

void parkingStatus() {
    cout << "\n--- Parking Status ---\n";
    // display parking spots in a column format
    for (int i = 0; i < maxSpots; i++) {
        cout << "Spot " << i + 1 << ": " << parkingSpots[i];
        
        // brwak line after the declared row
        if ((i + 1) % spotsPerRow == 0) {
            cout << endl;
        } else {
            cout << " | ";
        }
    }
    cout << endl;
}

void parkVehicle() {
    for (int i = 0; i < maxSpots; i++) {
        if (parkingSpots[i] == "Empty") {
            cout << "Enter vehicle number to park in spot " << i + 1 << ": ";
            cin >> parkingSpots[i];
            cout << parkingSpots[i] << " parked in spot " << i + 1 << ".\n";
            return;
        }
    }
    cout << "\nNo parking spots available!\n";
}

void removeVehicle() {
    int spot;
    cout << "\n--- Remove a Vehicle ---\n";
    cout << "Enter the spot number to remove the vehicle (1-" << maxSpots << "): ";
    cin >> spot;

    if (spot < 1 || spot > maxSpots) {
        cout << "Invalid spot number. Please try again.\n";
    } else if (parkingSpots[spot - 1] == "Empty") {
        cout << "The spot is already empty.\n";
    } else {
        cout << "Vehicle " << parkingSpots[spot - 1] << " removed from spot " << spot << ".\n";
        parkingSpots[spot - 1] = "Empty";
    }
}

void saveParking() {
    ofstream outFile("parkingData.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < maxSpots; i++) {
            outFile << parkingSpots[i] << "\n";
        }
        outFile.close();
        cout << "Parking status saved to file.\n";
    } else {
        cout << "Error: Could not open file for writing.\n";
    }
}

void loadParking() {
    ifstream inFile("parkingData.txt");
    if (inFile.is_open()) {
        for (int i = 0; i < maxSpots; i++) {
            getline(inFile, parkingSpots[i]);
            if (parkingSpots[i].empty()) {
                parkingSpots[i] = "Empty";
            }
        }
        inFile.close();
    } else {
        for (int i = 0; i < maxSpots; i++) {
            parkingSpots[i] = "Empty";
        }
        cout << "No previous parking data found. Initializing empty parking spots.\n";
    }
}