#include <iostream>
#include <vector>
using namespace std;

int choice;
int b;
float hours;
float sum;
string car_plate;
string input;
string price_list = "First 3 hours = Rm 5.00, \nEvery subsequent hour = Rm1.00, \nMore than 24 hours stay will be charged with Rm50.00\n"; 

vector<string> UMcarPlate;

void Edit_plate_number() {
    cout << "Number of UM car plates to be added: ";
    cin >> b;

    for (int i = 0; i < b; i++) {
        cout << "Enter plate number: ";
        cin >> car_plate;
        UMcarPlate.push_back(car_plate);
    }

    cout << "\nUM car plates successfully added!" << endl;
    
    cout << "Updated list of Registered Car Plates:" <<endl;
    for (int i = 0; i < UMcarPlate.size(); i++) {
        cout << "Plate " << i+1 << ": " << UMcarPlate[i] << endl;
    }
}

void Start_programme(){
    cout << "\nWelcome to UM Parking Management System!" << endl;
    start:
    while (true) {
        cout << "Enter Car Plate Number (or enter 'q' to quit): ";
        cin >> input;
        
        if (input == "q") {
            cout << "Exiting program..." << endl;
            break;
        }

        bool matchFound = false;
        for (int i = 0; i < UMcarPlate.size(); i++) {
            if (input == UMcarPlate[i]) {
                cout << "------------------------------" << endl;
                cout << "Match found!: " << input << endl;
                cout << "Welcome UM Residence!" << endl;
                cout << "------------------------------" << endl;
                matchFound = true;
                break; 
            }
        }

        if (matchFound) {
            goto start;
        }

        cout << "No match found! We assume that you are a visitor" << endl;
        cout << "------------------------------" << endl;
        cout << price_list;
        cout << "------------------------------" << endl;
        cout << "Please enter the duration of your stay in hours: "; // time of which car entered
        cin >> hours;

        if (hours <= 3){
            sum = 5;
        } else if (3 < hours && hours <= 24){
            sum = 5 + 1 * (hours - 3);
        } else if (hours > 24){
            sum = 50;
        }
        cout << "Your total is: RM "<< sum << endl;
        cout << "Please pay the given amount" << endl;
        cout << "Thank you! Have a safe journey\n " << endl;
        
        goto start; 
    }
}

int main() {
    while (true) {
        cout << "\nUM Parking Management System" << endl;
        cout << "------------------------------" << endl;
        cout << "[1] Add UM Car Plate Number" << endl;
        cout << "[2] Start Program" << endl;
        cout << "[0] Exit" << endl;
        cout << "------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Edit_plate_number();
                break;
            case 2:
                Start_programme();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
}
