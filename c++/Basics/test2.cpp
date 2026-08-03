#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

enum Category {
    ESSENTIAL,
    FOOD,
    GENERAL,
    LUXURY
};

struct Item {
    string name;
    float price;
    int quantity;
    Category category;
};

float getGST(Category category) {
    switch (category) {
        case ESSENTIAL: return 0.0f;
        case FOOD:      return 5.0f;
        case GENERAL:   return 18.0f;
        case LUXURY:    return 40.0f;
        default:        return 0.0f;
    }
}

int main() {
    int n;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> arr(n);

    // TODO fix this name multi line string reading for name effective solution
    for (int i = 0; i < n; i++) {
        cout << "\nItem " << i + 1 << '\n';

        cout << "Enter name: ";
        cin.ignore();  
       getline(cin, arr[i].name);

        cout << "Enter price: ";
        cin >> arr[i].price;

        cout << "Enter quantity: ";
        cin >> arr[i].quantity;

        cout << "\nSelect Category\n";
        cout << "0. Essential (0% GST)\n";
        cout << "1. Food (5% GST)\n";
        cout << "2. General (18% GST)\n";
        cout << "3. Luxury (40% GST)\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        while (choice < 0 || choice > 3) {
            cout << "Invalid choice. Enter again: ";
            cin >> choice;
        }

        arr[i].category = static_cast<Category>(choice);
    }

    float subtotal = 0;
    float totalGST = 0;

    cout << fixed << setprecision(2);

    cout << "\n---------------- BILL ----------------\n";

    for (int i = 0; i < n; i++) {

        float amount = arr[i].price * arr[i].quantity;
        float gstRate = getGST(arr[i].category);
        float gstAmount = amount * gstRate / 100.0f;

        subtotal += amount;
        totalGST += gstAmount;

        cout << "Item : " << arr[i].name << '\n';
        cout << "Amount : Rs. " << amount << '\n';
        cout << "GST (" << gstRate << "%) : Rs. " << gstAmount << "\n\n";
    }

    cout << "--------------------------------------\n";
    cout << "Subtotal   : Rs. " << subtotal << '\n';
    cout << "Total GST  : Rs. " << totalGST << '\n';
    cout << "Grand Total: Rs. " << subtotal + totalGST << '\n';
}