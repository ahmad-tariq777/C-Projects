#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

const int MAX = 100;

struct Trip {
    string id;
    string destination;
    string date;
    string time;
    string vehicle;
    string driver;
    float fare;
};

struct Passenger {
    string id;
    string name;
    string contact;
    string tripId;
    string payment;
};

struct Driver {
    string id;
    string name;
    string contact;
    string license;
};

struct Vehicle {
    string id;
    string name;
    string number;
    int seats;
};

class TripManagement {
    Trip trips[MAX];
    int total = 0;

public:
    void load() {
        ifstream file("trips.txt");
        total = 0;

        while (total < MAX && file >> trips[total].id
        >> trips[total].destination
        >> trips[total].date
        >> trips[total].time
        >> trips[total].vehicle
        >> trips[total].driver
        >> trips[total].fare) {
            total++;
        }
        file.close();
    }

    void save() {
        ofstream file("trips.txt");

        for (int i = 0; i < total; i++) {
            file << trips[i].id << " "
            << trips[i].destination << " "
            << trips[i].date << " "
            << trips[i].time << " "
            << trips[i].vehicle << " "
            << trips[i].driver << " "
            << trips[i].fare << endl;
        }
        file.close();
    }

    void add() {
        if (total >= MAX) {
            cout << "Trip storage is full.\n";
            return;
        }

        cout << "Enter Trip ID: ";
        cin >> trips[total].id;

        for (int i = 0; i < total; i++) {
            if (trips[i].id == trips[total].id) {
                cout << "Trip ID already exists.\n";
                return;
            }
        }

        cout << "Enter Destination: ";
        cin >> trips[total].destination;
        cout << "Enter Date: ";
        cin >> trips[total].date;
        cout << "Enter Time: ";
        cin >> trips[total].time;
        cout << "Enter Vehicle ID: ";
        cin >> trips[total].vehicle;
        cout << "Enter Driver ID: ";
        cin >> trips[total].driver;
        cout << "Enter Fare: ";
        cin >> trips[total].fare;

        total++;
        save();
        cout << "Trip added successfully!\n";
    }

    void show() {
        if (total == 0) {
            cout << "No trips available.\n";
            return;
        }

        for (int i = 0; i < total; i++) {
            cout << "\nTrip ID: " << trips[i].id;
            cout << "\nDestination: " << trips[i].destination;
            cout << "\nDate: " << trips[i].date;
            cout << "\nTime: " << trips[i].time;
            cout << "\nVehicle ID: " << trips[i].vehicle;
            cout << "\nDriver ID: " << trips[i].driver;
            cout << "\nFare: " << trips[i].fare << endl;
        }
    }

    void search() {
        string id;
        cout << "Enter Trip ID: ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (trips[i].id == id) {
                cout << "\nTrip Found!\n";
                cout << trips[i].destination << " "
                << trips[i].date << " "
                << trips[i].time << " "
                << trips[i].fare << endl;
                return;
            }
        }

        cout << "Trip not found.\n";
    }

    void update() {
        string id;
        cout << "Enter Trip ID: ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (trips[i].id == id) {
                cout << "Enter New Destination: ";
                cin >> trips[i].destination;
                cout << "Enter New Date: ";
                cin >> trips[i].date;
                cout << "Enter New Time: ";
                cin >> trips[i].time;
                cout << "Enter New Vehicle ID: ";
                cin >> trips[i].vehicle;
                cout << "Enter New Driver ID: ";
                cin >> trips[i].driver;
                cout << "Enter New Fare: ";
                cin >> trips[i].fare;

                save();
                cout << "Trip updated!\n";
                return;
            }
        }

        cout << "Trip not found.\n";
    }

    void remove() {
        string id;
        cout << "Enter Trip ID: ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (trips[i].id == id) {
                for (int j = i; j < total - 1; j++) {
                    trips[j] = trips[j + 1];
                }

                total--;
                save();
                cout << "Trip deleted!\n";
                return;
            }
        }

        cout << "Trip not found.\n";
    }
};

class PassengerManagement {
    Passenger passengers[MAX];
    int total = 0;

public:
    void load() {
        ifstream file("passengers.txt");
        total = 0;

        while (total < MAX && file >> passengers[total].id
        >> passengers[total].name
        >> passengers[total].contact
        >> passengers[total].tripId
        >> passengers[total].payment) {
            total++;
        }
        file.close();
    }

    void save() {
        ofstream file("passengers.txt");

        for (int i = 0; i < total; i++) {
            file << passengers[i].id << " "
            << passengers[i].name << " "
            << passengers[i].contact << " "
            << passengers[i].tripId << " "
            << passengers[i].payment << endl;
        }
        file.close();
    }

    void add() {
        if (total >= MAX) {
            cout << "Passenger storage is full.\n";
            return;
        }

        cout << "Enter Passenger ID: ";
        cin >> passengers[total].id;

        cout << "Enter Name: ";
        cin >> passengers[total].name;

        cout << "Enter Contact: ";
        cin >> passengers[total].contact;

        cout << "Enter Trip ID: ";
        cin >> passengers[total].tripId;

        cout << "Enter Payment Status (Paid/Pending): ";
        cin >> passengers[total].payment;

        total++;
        save();
        cout << "Passenger added successfully!\n";
    }

    void show() {
        for (int i = 0; i < total; i++) {
            cout << "\nPassenger ID: " << passengers[i].id;
            cout << "\nName: " << passengers[i].name;
            cout << "\nContact: " << passengers[i].contact;
            cout << "\nTrip ID: " << passengers[i].tripId;
            cout << "\nPayment: " << passengers[i].payment << endl;
        }

        if (total == 0)
            cout << "No passengers found.\n";
    }

    void search() {
        string id;
        cout << "Enter Passenger ID: ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (passengers[i].id == id) {
                cout << "\nPassenger Found!\n";
                cout << passengers[i].name << " "
                << passengers[i].contact << " "
                << passengers[i].tripId << " "
                << passengers[i].payment << endl;
                return;
            }
        }

        cout << "Passenger not found.\n";
    }

    void update() {
        string id;
        cout << "Enter Passenger ID: ";
        cin >> id;

        for (int i = 0; i < total; i++) {
            if (passengers[i].id == id) {
                cout << "Enter New Name: ";
                cin >> passengers[i].name;
                cout << "Enter New Contact: ";
                cin >> passengers[i].contact;
                cout << "Enter New Trip ID: ";
                cin >> passengers[i].tripId;
                cout << "Enter Payment Status: ";
                cin >> passengers[i].payment;

                save();
                cout << "Passenger updated!\n";
                return;
            }
        }

        cout << "Passenger not found.\n";
    }
};

class DriverManagement {
    Driver drivers[MAX];
    int total = 0;

public:
    void load() {
        ifstream file("drivers.txt");
        total = 0;

        while (total < MAX && file >> drivers[total].id
        >> drivers[total].name
        >> drivers[total].contact
        >> drivers[total].license) {
            total++;
        }
        file.close();
    }

    void save() {
        ofstream file("drivers.txt");

        for (int i = 0; i < total; i++) {
            file << drivers[i].id << " "
            << drivers[i].name << " "
            << drivers[i].contact << " "
            << drivers[i].license << endl;
        }
        file.close();
    }

    void add() {
        if (total >= MAX) {
            cout << "Driver storage is full.\n";
            return;
        }

        cout << "Enter Driver ID: ";
        cin >> drivers[total].id;
        cout << "Enter Name: ";
        cin >> drivers[total].name;
        cout << "Enter Contact: ";
        cin >> drivers[total].contact;
        cout << "Enter License Number: ";
        cin >> drivers[total].license;

        total++;
        save();
        cout << "Driver added!\n";
    }

    void show() {
        for (int i = 0; i < total; i++) {
            cout << "\nID: " << drivers[i].id;
            cout << "\nName: " << drivers[i].name;
            cout << "\nContact: " << drivers[i].contact;
            cout << "\nLicense: " << drivers[i].license << endl;
        }

        if (total == 0)
            cout << "No drivers found.\n";
    }
};

class VehicleManagement {
    Vehicle vehicles[MAX];
    int total = 0;

public:
    void load() {
        ifstream file("vehicles.txt");
        total = 0;

        while (total < MAX && file >> vehicles[total].id
        >> vehicles[total].name
        >> vehicles[total].number
        >> vehicles[total].seats) {
            total++;
        }
        file.close();
    }

    void save() {
        ofstream file("vehicles.txt");

        for (int i = 0; i < total; i++) {
            file << vehicles[i].id << " "
            << vehicles[i].name << " "
            << vehicles[i].number << " "
            << vehicles[i].seats << endl;
        }
        file.close();
    }

    void add() {
        if (total >= MAX) {
            cout << "Vehicle storage is full.\n";
            return;
        }

        cout << "Enter Vehicle ID: ";
        cin >> vehicles[total].id;
        cout << "Enter Vehicle Name: ";
        cin >> vehicles[total].name;
        cout << "Enter Registration Number: ";
        cin >> vehicles[total].number;
        cout << "Enter Total Seats: ";
        cin >> vehicles[total].seats;

        total++;
        save();
        cout << "Vehicle added!\n";
    }

    void show() {
        for (int i = 0; i < total; i++) {
            cout << "\nVehicle ID: " << vehicles[i].id;
            cout << "\nName: " << vehicles[i].name;
            cout << "\nNumber: " << vehicles[i].number;
            cout << "\nSeats: " << vehicles[i].seats << endl;
        }

        if (total == 0)
            cout << "No vehicles found.\n";
    }
};

void tripMenu(TripManagement &t) {
    int choice;

    do {
        cout << "\n--- TRIP MANAGEMENT ---\n";
        cout << "1. Add Trip\n";
        cout << "2. Show Trips\n";
        cout << "3. Search Trip\n";
        cout << "4. Update Trip\n";
        cout << "5. Delete Trip\n";
        cout << "6. Back\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: t.add(); break;
            case 2: t.show(); break;
            case 3: t.search(); break;
            case 4: t.update(); break;
            case 5: t.remove(); break;
            case 6: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

void passengerMenu(PassengerManagement &p) {
    int choice;

    do {
        cout << "\n--- PASSENGER MANAGEMENT ---\n";
        cout << "1. Add Passenger / Booking\n";
        cout << "2. Show Passengers\n";
        cout << "3. Search Passenger\n";
        cout << "4. Update Passenger\n";
        cout << "5. Back\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: p.add(); break;
            case 2: p.show(); break;
            case 3: p.search(); break;
            case 4: p.update(); break;
            case 5: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}

void driverMenu(DriverManagement &d) {
    int choice;

    do {
        cout << "\n--- DRIVER MANAGEMENT ---\n";
        cout << "1. Add Driver\n";
        cout << "2. Show Drivers\n";
        cout << "3. Back\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: d.add(); break;
            case 2: d.show(); break;
            case 3: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 3);
}

void vehicleMenu(VehicleManagement &v) {
    int choice;

    do {
        cout << "\n--- VEHICLE MANAGEMENT ---\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Show Vehicles\n";
        cout << "3. Back\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: v.add(); break;
            case 2: v.show(); break;
            case 3: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 3);
}

int main() {
    TripManagement trips;
    PassengerManagement passengers;
    DriverManagement drivers;
    VehicleManagement vehicles;

    trips.load();
    passengers.load();
    drivers.load();
    vehicles.load();

    int choice;

    do {
        cout << "\n================================\n";
        cout << "       TRIP MANAGEMENT SYSTEM\n";
        cout << "================================\n";
        cout << "1. Trip Management\n";
        cout << "2. Passenger and Booking Management\n";
        cout << "3. Driver Management\n";
        cout << "4. Vehicle Management\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: tripMenu(trips); break;
            case 2: passengerMenu(passengers); break;
            case 3: driverMenu(drivers); break;
            case 4: vehicleMenu(vehicles); break;
            case 5: cout << "Thank you for using the system!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}