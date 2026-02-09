#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Declare and initialize a global variable called `count` to keep track of the products
int count = 0;

// Prototype the functions
void ReadFromFile(string names[], float prices[], int quantities[]);
void AddProduct(string names[], float prices[], int quantities[], int maxSize);
void DisplayItems(string names[], float prices[], int quantities[]);
void ProductValue(string names[], float prices[], int quantities[], float values[]);
void LowStockProducts(string names[], int quantities[]);
void SearchProduct(string names[], float prices[], int quantities[], float values[]);
void SortProducts(string names[], float prices[], int quantities[], float values[]);
void EditInfo(string names[], float prices[], int quantities[]);
void RemoveProduct(string names[], float prices[], int quantities[], float values[]);
void SaveProducts(string names[], float prices[], int quantities[]);

int main()
{
    // Declare arrays, size, and the user input
    string option;
    const int size = 50;

    string names[size];
    float prices[size];
    int quantities[size], maxSize = size;
    float values[size] = {0};

    // Display the Cafe Menu
    cout << R"(=== Cafe Inventory Management System ===

    Welcome to the cafe inventory management system!
    Below you can see what the program can do: 
    
    1. Display the Items
    2. Add a Product
    3. Calculate the Inventory Value of Each Product
    4. Display the Low-Stock Products
    5. Search for a Specific Product
    6. Sort the Products based on their Prices
    7. Modify the Product's Price / Quantity
    8. Remove and item
    9. Exit the Program and Save the Sorted Products in the File

    Feel free to choose an option and play around with the program! 
    
    )";

    ReadFromFile(names, prices, quantities);

    // Call the functions based on the user input
    while (true)
    {
        cout << "Enter an option (add, display, value, low-stock, search, sort, modify, remove, exit): ";
        cin >> option;

        if (option == "exit")
        break;

        else if (option == "add")
        AddProduct(names, prices, quantities, maxSize);

        else if (option == "display")
        DisplayItems(names, prices, quantities);

        else if (option == "value")
        ProductValue(names, prices, quantities, values);

        else if (option == "low-stock")
        LowStockProducts(names, quantities);

        else if (option == "search")
        SearchProduct(names, prices, quantities, values);

        else if (option == "sort")
        SortProducts(names, prices, quantities, values);

        else if (option == "modify")
        EditInfo(names, prices, quantities);

        else if (option == "remove")
        RemoveProduct(names, prices, quantities, values);

        else
        cout << "Invalid option.\n";
    }

    // If the user enters 'exit', store the product information and quit the program
    SaveProducts(names, prices, quantities);

    return 0;
}

void ReadFromFile(string names[], float prices[], int quantities[])
{
    // This function reads data from the text file and stores it in the arrays (parallel arrays).
    ifstream read_file("products.txt");

    while (read_file >> names[count] >> prices[count] >> quantities[count])
    {
        count ++;
    }

    read_file.close();
}

void AddProduct(string names[], float prices[], int quantities[], int maxSize)
{
    // This function gets a product as input and adds its information to the arrays.
    string product;
    float price;
    int quantity;

    // If the array has reached the maximum size (i.e. 50 items), exit the function
    if (count == maxSize)
    {
        cout << "You reached the maximum size of addition. Choose another option: " << endl;
        return ;
    }

    cout << "Enter the name of the product: ";
    cin >> product;

    // Increment the quantity if the product already exists
    for (int item = 0; item < count; item++)
    {
        if (names[item] == product)
        {
            cout << "The product already exists. Enter the quantity: ";
            cin >> quantity;
            quantities[item] += quantity;
            return ;
        }
    }

    // Otherwise, add the product to the array
    cout << "Enter its price and quantity: ";
    cin >> price >> quantity;

    names[count] = product;
    prices[count] = price;
    quantities[count] = quantity;

    // For each new product increment `count` by one.
    count ++;
}

void DisplayItems(string names[], float prices[], int quantities[])
{
    // This function displays all information about the products.
    if (count == 0)
    cout << "No products available. Try adding a few items. " << endl;

    else
    cout << "Product | Price | Quantity " << endl;

    for (int item = 0; item < count; item++)
    {
        cout << names[item] << " | " << prices[item] << " | " << quantities[item] << endl;
    }
}

void ProductValue(string names[], float prices[], int quantities[], float values[])
{
    // This function calculates and displays the inventory value of each product.
    string product;

    for (int item = 0; item < count; item++)
    {
        values[item] = prices[item] * quantities[item];
    }

    // Display the value of a specific product
    cout << "Enter the name of the product: ";
    cin >> product;

    for (int item = 0; item < count; item++)
    {
        if (names[item] == product)
        cout << product << " has an inventory value of " << values[item] << endl;
    }
}

void LowStockProducts(string names[], int quantities[])
{
    // This function displays the products that have a quantity below a certain threshold (5 units).
    int threshold = 15;
    bool LowStock = false;

    cout << "Products that have a quantity below 15: " << endl;
    for (int item = 0; item < count; item++)
    {
        if (quantities[item] < threshold)
        {
            LowStock = true;
            cout << names[item] << " | " << quantities[item] << endl;
        }
    }

    // No low-stock items
    if (!LowStock)
    cout << "No low-stock products" << endl;
}

void SearchProduct(string names[], float prices[], int quantities[], float values[])
{
    // This function gets the name of a product from the user and prints its information.
    string product;
    bool isPresent;

    cout << "Which product are you looking for?: ";
    cin >> product;

    // Use Linear Search to find the matching item
    for (int item = 0; item < count; item++)
    {
        isPresent = false;
        if (names[item] == product)
        {
            isPresent = true;
            cout << "Product | Price | Quantity | Value: " << endl;
            cout << names[item] << " | " << prices[item] << " | " << quantities[item] << " | " << values[item] << endl;
            break;
        }
    }

    // Non-existent product
    if (!isPresent)
    cout << "Product not found" << endl;
}

void SortProducts(string names[], float prices[], int quantities[], float values[])
{
    // This function uses Bubble Sort to sort the products based on their prices in ascending order.
    bool swapped;

    for (int i = 0; i < (count - 1); i++)
    {
        swapped = false;

        for (int j = 0; j < (count - i - 1); j++)
        {
            if (prices[j] > prices[j+1])
            {
                swap(names[j], names[j+1]);
                swap(prices[j], prices[j+1]);
                swap(quantities[j], quantities[j+1]);
                swap(values[j], values[j+1]);

                swapped = true;
            }
        }

        // If the two elements were in the correct order break from the loop
        if (!swapped)
        break;
    }

    // Display the sorted array
    cout << "Product | Price | Quantity | Value: " << endl;
    for (int item = 0; item < count; item++)
    {
        cout << names[item] << " | " << prices[item] << " | " << quantities[item] << " | " << values[item] << endl;
    }
}

void EditInfo(string names[], float prices[], int quantities[])
{
    // This function gets the name of the product and edits either its price, or its quantity.
    string product, option;
    float price;
    int quantity;

    cout << "Enter the product name: ";
    cin >> product;

    cout << "Which property do you want to modify?: (price / quantity) ";
    cin >> option;

    // Update and edit the product info based on the user's input.
    if (option == "price")
    {
        cout << "Enter the new price: ";
        cin >> price;
    }

    else if (option == "quantity")
    {
        cout << "Enter the new quantity: ";
        cin >> quantity;
    }

    // Search for the product and update its info.
    for (int item = 0; item < count; item++)
    {
        if (names[item] == product && option == "price")
        prices[item] = price;

        else if (names[item] == product && option == "quantity")
        quantities[item] = quantity;
    }
}

void RemoveProduct(string names[], float prices[], int quantities[], float values[])
{
    // This function gets the name of a product and removes its information.
    string product;

    cout << "Which product do you want to remove?: ";
    cin >> product;

    // Find the index of the product to be removed and move the elements that are on the right side of it towards the left.
    for (int i = 0; i < count; i++)
    {
        if (names[i] == product)
        {
            count --;

            for (int j = i; j < count; j++)
            {
                names[j] = names[j + 1];
                prices[j] = prices[j + 1];
                quantities[j] = quantities[j + 1];
                values[j] = values[j + 1];
            }

            break;
        }
    }
}

void SaveProducts(string names[], float prices[], int quantities[])
{
    // This function saves and stores all the modifications on the products in the text file.
    ofstream write_file("products.txt");

    for (int item = 0; item < count; item++)
    {
        write_file << names[item] << " " << prices[item] << " " << quantities[item] << " " << "\n";
    }

    write_file.close();
}
