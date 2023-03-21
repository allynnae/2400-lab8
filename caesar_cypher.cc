/**
 *   @file: caesar_cypher.cc
 * @author: Allison McKee
 *   @date: 03-07-2023
 *  @brief: Caesar Cypher
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

void displayMenu();
int keyValue();
void encrypt(int key);
void decrypt(int key);

int main() 
{
    int choice, key;
    key = 3; // default
    do 
    {
        displayMenu();
        cin >> choice;
        if (choice == 1)
        {
            key = keyValue();
            cout << "Key value is: " << key << endl;
            // call the set key function and assign to key
        }
        else if (choice == 2)
        {
            encrypt(key);
            // call the ecryption function
        }
        else if (choice == 3)
        {
            decrypt(key);
            // call the decryption function
        }
    }
    while (choice != 4);
    return 0;
}

 void displayMenu() // function 1
 {
     cout << "1. Set the shift key value (default is 3)" << endl;
     cout << "2. Encrypt a file" << endl;
     cout << "3. Decrypt a file" << endl;
     cout << "4. Quit" << endl;
 }

int keyValue() // function 2
{
    int key;
    cout << "Enter a new shift key value (1-10): ";
    cin >> key;
    while (key < 1 || key > 10)
    {
        cout << "Invalid key value. Please enter another number: ";
        cin >> key;
    }
    return key;
}

void encrypt(int key) // function 3
{
    string inputFileName, outputFileName;
    cout << "Enter the input file name: ";
    cin >> inputFileName;
    cout << "Enter the output file name: ";
    cin >> outputFileName;

    ifstream inputStream(inputFileName);
    if (!inputStream.is_open())
    {
        cout << "Error: Unable to open input file.\n";
        return;
    }

    ofstream outputStream(outputFileName);
    if (!outputStream.is_open())
    {
        cout << "Error: Unable to open output file.\n";
        return;
    }

    char ch;
    while (inputStream.get(ch))
    {
        ch += key;
        outputStream << ch;
    }

    inputStream.close();
    outputStream.close();

    cout << "Encryption successful!\n";
}

void decrypt(int key) // function 4
{
    string inputFileName, outputFileName;
    cout << "Enter the input file name: ";
    cin >> inputFileName;
    cout << "Enter the output file name: ";
    cin >> outputFileName;

    ifstream inputStream(inputFileName);
    if (!inputStream.is_open())
    {
        cout << "Error: Unable to open input file.\n";
        return;
    }

    ofstream outputStream(outputFileName);
    if (!outputStream.is_open())
    {
        cout << "Error: Unable to open output file.\n";
        return;
    }

    char ch;

    while (inputStream.get(ch))
    {
        ch -= key;
        outputStream << ch;
    }

    inputStream.close();
    outputStream.close();

    cout << "Decryption successful!\n";
}