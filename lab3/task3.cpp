#include <iostream>
#include <string>
using namespace std;

const int MAX_CARS = 8;

class ParkingLot {
private:
    string cars[MAX_CARS];
    int topIndex;
    
public:
    ParkingLot() {
        topIndex = -1;
    }
    
    bool isFull() {
        return topIndex == MAX_CARS - 1;
    }
    
    bool isEmpty() {
        return topIndex == -1;
    }
    
    void parkCar(string carNumber) {
        if (isFull()) {
            cout << "Parking lot is FULL! Cannot park " << carNumber << endl;
            return;
        }
        cars[++topIndex] = carNumber;
        cout << "Car " << carNumber << " parked successfully." << endl;
    }
    
    void removeCar(string carNumber) {
        if (isEmpty()) {
            cout << "Parking lot is EMPTY! No cars to remove." << endl;
            return;
        }
        
        string tempStack[MAX_CARS];
        int tempTop = -1;
        bool found = false;
        
        while (!isEmpty()) {
            string currentCar = cars[topIndex--];
            
            if (currentCar == carNumber) {
                cout << "Car " << carNumber << " removed from parking lot." << endl;
                found = true;
                break;
            } else {
                tempStack[++tempTop] = currentCar;
            }
        }
        
        while (tempTop >= 0) {
            cars[++topIndex] = tempStack[tempTop--];
        }
        
        if (!found) {
            cout << "Car " << carNumber << " not found in parking lot." << endl;
        }
    }
    
    void displayCars() {
        if (isEmpty()) {
            cout << "Parking lot is EMPTY." << endl;
            return;
        }
        
        cout << "\nParked cars (from entrance to back): ";
        for (int i = 0; i <= topIndex; i++) {
            cout << cars[i];
            if (i < topIndex) cout << " -> ";
        }
        cout << endl;
        cout << "Total cars parked: " << (topIndex + 1) << "/" << MAX_CARS << endl;
    }
    
    string getTopCar() {
        if (isEmpty()) {
            return "No cars parked";
        }
        return cars[topIndex];
    }
    
    bool searchCar(string carNumber) {
        for (int i = 0; i <= topIndex; i++) {
            if (cars[i] == carNumber) {
                return true;
            }
        }
        return false;
    }
    
    int getCarCount() {
        return topIndex + 1;
    }
};

int main() {
    ParkingLot lot;
    int choice;
    string carNumber;
    
    do {
        cout << "1. Park a new car\n";
        cout << "2. Remove a car by number\n";
        cout << "3. Display all parked cars\n";
        cout << "4. Show car at entrance\n";
        cout << "5. Search for a car\n";
        cout << "6. Show total cars parked\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter car number/plate: ";
                cin >> carNumber;
                lot.parkCar(carNumber);
                break;
                
            case 2:
                cout << "Enter car number to remove: ";
                cin >> carNumber;
                lot.removeCar(carNumber);
                break;
                
            case 3:
                lot.displayCars();
                break;
                
            case 4:
                cout << "Car at entrance: " << lot.getTopCar() << endl;
                break;
                
            case 5:
                cout << "Enter car number to search: ";
                cin >> carNumber;
                if (lot.searchCar(carNumber))
                    cout << "Car " << carNumber << " is in the parking lot." << endl;
                else
                    cout << "Car " << carNumber << " NOT found." << endl;
                break;
                
            case 6:
                cout << "Total cars parked: " << lot.getCarCount() << "/8" << endl;
                break;
                
            case 7:
                cout << "Exiting parking system. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while(choice != 7);
    
    return 0;
}