#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Prototype the functions
void ReadFromFile(string names[], float prices[], int quantities[], int& count);
void AddProduct(string names[], float prices[], int quantities[], int& count, int maxSize);
void DisplayItems(string names[], float prices[], int quantities[], int& count);
float InventoryValue(string names[], float prices[], int quantities[], float values[], int& count);
void LowStockProducts(string names[], int quantities[], int& count);
void SearchProduct(string names[], float prices[], int quantities[], float values[], int& count);
void SortProducts(string names[], float prices[], int quantities[], float values[], int& count);
void SaveProducts(string names[], float prices[], int quantities[], int& count);

int main()
{
    // Declare arrays, size, and the user input
    string option;
    const int size = 50;

    string names[size];
    float prices[size];
    int quantities[size];
    float values[size];
    int count = 0;
    int maxSize = size;

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
    7. Exit the Program and Save the Sorted Products in the File

    Feel free to choose an option and play around with the program! 
    
    )";

    ReadFromFile(names, prices, quantities, count);

    // Call the functions based on the user input
    while (true)
    {
        cout << "Enter an option (add, display, value, low-stock, search, sort, exit): ";
        cin >> option;

        if (option == "exit")
        break;

        else if (option == "add")
        AddProduct(names, prices, quantities, count, maxSize);

        else if (option == "display")
        DisplayItems(names, prices, quantities, count);

        else if (option == "value")
        InventoryValue(names, prices, quantities, values, count);

        else if (option == "low-stock")
        LowStockProducts(names, quantities, count);

        else if (option == "search")
        SearchProduct(names, prices, quantities, values, count);

        else if (option == "sort")
        SortProducts(names, prices, quantities, values, count);

        else
        cout << "Invalid option.\n";
    }

    // If the user enters 'exit', store the product information and quit the program
    SaveProducts(names, prices, quantities, count);

    return 0;
}

void ReadFromFile(string names[], float prices[], int quantities[], int& count)
{
    // This function reads data from the text file and stores it in the arrays (parallel arrays).
    ifstream read_file("products.txt");

    while (read_file >> names[count] >> prices[count] >> quantities[count])
    {
        // Read the next product
        count ++;
    }

    read_file.close();
}

void AddProduct(string names[], float prices[], int quantities[], int& count, int maxSize)
{
    // This function gets a product as input and adds it with its information to the array.
    string name;
    float price;
    int quantity;

    // If the array has reached the maximum size (i.e. 50 items), exit the function
    if (count == maxSize)
    {
        cout << "You reached the maximum size of addition. Choose another option. " << endl;
        return ;
    }

    cout << "Enter the name of the product: ";
    cin >> name;

    // Increment the quantity if the product already exists
    for (int item = 0; item < count; item++)
    {
        if (names[item] == name)
        {
            cout << "The product already exists. Enter the quantity: ";
            cin >> quantity;
            quantities[item] += quantity;
            return ; // Avoid adding the product to the array by exiting the function
        }
    }

    // Otherwise, add the product to the array
    cout << "The product does not exist in the array. Enter its price and quantity: ";
    cin >> price >> quantity;

    names[count] = name;
    prices[count] = price;
    quantities[count] = quantity;

    // For each new product increment `count` by one.
    count ++;
}

void DisplayItems(string names[], float prices[], int quantities[], int& count)
{
    // This function displays all information about the products. If the file is empty, it will print a clear message.
    if (count == 0)
    {
        cout << "No products available. Try adding a few items. " << endl;
    }

    else
    cout << "Product Name | Product Price | Product Quantity " << endl;

    for (int i = 0; i < count; i++)
    {
        cout << names[i] << " | " << prices[i] << " | " << quantities[i] << endl;
    }
}

float InventoryValue(string names[], float prices[], int quantities[], float values[], int& count)
{
    // This function calculates and displays the inventory value of each product.
    string product;
    float value;

    for (int i = 0; i < count; i++)
    {
        value = prices[i] * quantities[i];
        values[i] = value;
    }

    // Display the value of a specific product
    cout << "Enter the name of the product: ";
    cin >> product;

    for (int item = 0; item < count; item++)
    {
        if (names[item] == product)
        {
            cout << product << " has an inventory value of " << values[item] << endl;
        }
    }

    return value;
}

void LowStockProducts(string names[], int quantities[], int& count)
{
    // This function displays the products that have a quantity below a certain threshold (5 units).
    int threshold = 5;
    bool low_stock = false;

    cout << "Products that have a quantity below 5: " << endl;
    for (int item = 0; item < count; item++)
    {
        if (quantities[item] < threshold)
        {
            low_stock = true;
            cout << "Quantity of \'" << names[item] << "\' is " << quantities[item] << endl;
        }
    }

    // No low-stock items
    if (!low_stock)
    cout << "No low-stock products" << endl;
}

void SearchProduct(string names[], float prices[], int quantities[], float values[], int& count)
{
    // This function gets the name of a product from the user and prints the information about that item.
    string product;
    bool isPresent;

    cout << "Enter the product name: ";
    cin >> product;

    // Use Linear Search to find the matching item
    for (int item = 0; item < count; item++)
    {
        isPresent = false;
        if (names[item] == product)
        {
            isPresent = true;
            cout << endl << "Product Name | Product Price | Product Quantity | Product Value: " << endl;
            cout << names[item] << " | " << prices[item] << " | " << quantities[item] << " | " << values[item] << endl;
            break;
        }
    }

    // Non-existent product
    if (!isPresent)
    cout << "Product not found" << endl;
}

void SortProducts(string names[], float prices[], int quantities[], float values[], int& count)
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

        // If the two elements were not swapped (they were in the correct order), then break from the loop
        if (!swapped)
        {
            break;
        } 
    }

    // Display the sorted array
    cout << "Product Name | Product Price | Product Quantity | Product Value: " << endl;
    for (int item = 0; item < count; item++)
    {
        cout << names[item] << " | " << prices[item] << " | " << quantities[item] << " | " << values[item] << endl;
    }
}

void SaveProducts(string names[], float prices[], int quantities[], int& count)
{
    // This function saves and stores all the modifications on the products to the text file.
    ofstream write_file("products.txt");

    for (int item = 0; item < count; item++)
    {
        write_file << names[item] << " " << prices[item] << " " << quantities[item] << " " << '\n';
    }

    // Close the file
    write_file.close();
}