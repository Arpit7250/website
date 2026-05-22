#include <iostream>
#include <fstream>
using namespace std;

int main() {

    int choice, payment, orderID, searchID;
    int productChoice;

    string name, mobile, address, item;
    float price;

    cout << "===== Flipkart Mini Shopping App =====\n";
    cout << "1. Buy Product\n";
    cout << "2. View All Orders\n";
    cout << "3. Check Order Status\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    
    if (choice == 1) {

        cout << "\nEnter Order ID: ";
        cin >> orderID;
        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Mobile Number: ";
        getline(cin, mobile);

        cout << "Enter Delivery Address: ";
        getline(cin, address);

        
        cout << "\n===== Available Products =====\n";
        cout << "1. Mobile Phone - Rs.15000\n";
        cout << "2. Laptop - Rs.55000\n";
        cout << "3. Headphones - Rs.2000\n";
        cout << "4. Smart Watch - Rs.5000\n";
        cout << "5. Bluetooth Speaker - Rs.3000\n";
        cout << "6. Keyboard - Rs.1200\n";
        cout << "7. Mouse - Rs.800\n";
        cout << "8. Power Bank - Rs.1800\n";

        cout << "\nChoose Product Number: ";
        cin >> productChoice;

       
        if (productChoice == 1) {
            item = "Mobile Phone";
            price = 15000;
        }
        else if (productChoice == 2) {
            item = "Laptop";
            price = 55000;
        }
        else if (productChoice == 3) {
            item = "Headphones";
            price = 2000;
        }
        else if (productChoice == 4) {
            item = "Smart Watch";
            price = 5000;
        }
        else if (productChoice == 5) {
            item = "Bluetooth Speaker";
            price = 3000;
        }
        else if (productChoice == 6) {
            item = "Keyboard";
            price = 1200;
        }
        else if (productChoice == 7) {
            item = "Mouse";
            price = 800;
        }
        else if (productChoice == 8) {
            item = "Power Bank";
            price = 1800;
        }
        else {
            cout << "Invalid Product Choice!\n";
            return 0;
        }


        cout << "\nChoose Payment Option:\n";
        cout << "1. Net Banking\n";
        cout << "2. UPI\n";
        cout << "3. QR Code\n";
        cout << "4. Cash on Delivery\n";
        cout << "Enter payment option: ";
        cin >> payment;

        string paymentMode;

        if (payment == 1)
            paymentMode = "Net Banking";
        else if (payment == 2)
            paymentMode = "UPI";
        else if (payment == 3)
            paymentMode = "QR Code";
        else if (payment == 4)
            paymentMode = "Cash on Delivery";
        else
            paymentMode = "Invalid";

        
        ofstream file("orders.txt", ios::app);

        file << orderID << endl;
        file << name << endl;
        file << mobile << endl;
        file << address << endl;
        file << item << endl;
        file << price << endl;
        file << paymentMode << endl;
        file << "Order Confirmed" << endl;

        file.close();

        cout << "\nOrder placed successfully!\n";
        cout << "Product: " << item << endl;
        cout << "Price: Rs. " << price << endl;
        cout << "Your Order ID is: " << orderID << endl;
    }

   
    else if (choice == 2) {

        ifstream file("orders.txt");

        string line;

        cout << "\n===== All Orders =====\n";

        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }

    
    else if (choice == 3) {

        cout << "\nEnter Order ID to check: ";
        cin >> searchID;

        ifstream file("orders.txt");

        int id;
        string cname, mob, addr, product, paymentMode, status;
        float amount;

        bool found = false;

        while (file >> id) {

            file.ignore();

            getline(file, cname);
            getline(file, mob);
            getline(file, addr);
            getline(file, product);

            file >> amount;
            file.ignore();

            getline(file, paymentMode);
            getline(file, status);

            if (id == searchID) {

                found = true;

                cout << "\n===== Order Found =====\n";
                cout << "Order ID: " << id << endl;
                cout << "Customer Name: " << cname << endl;
                cout << "Product: " << product << endl;
                cout << "Price: Rs. " << amount << endl;
                cout << "Payment Mode: " << paymentMode << endl;
                cout << "Status: " << status << endl;

                break;
            }
        }

        if (!found) {
            cout << "\nOrder not found!\n";
        }

        file.close();
    }

    else {
        cout << "Invalid choice!";
    }

    return 0;
}