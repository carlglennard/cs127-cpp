/*
* Programmer: ONATE, Carl Glennard H.
* Date Created: 02/08/2022
* Program: BSIT
* Course / Section: CS127L-8/BM5
* Purpose: This program will display a structure for shoe records.
*/

/*
https://www.onlinegdb.com/online_c++_compiler
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <fstream>
#include <sstream>
using namespace std;
 
const int SIZE = 10;
 
struct DatePurchase //THIS STRUCT IS FOR DATE OF PURCHASE
{
    int month;
    int day;
    int year;
};
 
struct ShoeRec //THIS STRUCT IS FOR SHOE RECORDS
{
    string StockNumber;
    string ShoeType;
    string ShoeBrand;
    int shoeQuantity;
    double shoeCost;
    DatePurchase date;
    double totalValue;
};
 
void inputShoe(ShoeRec getshoe[]); //REQUIRED VOID FUNCTION FOR SHOE DETAILS
void compVal(ShoeRec tValue[]); //REQUIRED VOID FUNCTION FOR SHOE VALUE
 
ofstream myFile;
 
int main()
{
	system("Color 70"); //FOR AESTHETIC AND DESIGN PURPOSES
    ShoeRec shoe[SIZE];
    inputShoe(shoe);
    compVal(shoe);
    system("cls");
 
    myFile.open("shoeInventory.txt"); //FOR FILE DISPLAY
    cout << "StockNumber        ShoeType       ShoeBrand        DatePurchase       ShoeQuantity        shoeCost        TotalValue" << endl;
    myFile << "StockNumber        ShoeType       ShoeBrand        DatePurchase       ShoeQuantity        shoeCost        TotalValue" << endl;
    myFile << endl;
    cout << endl;
    cout << left;
 
    for (int i = 0; i < SIZE; i++) 
    {
        myFile << left;
        myFile<< setw(19) << shoe[i].StockNumber
            << setw(16) << shoe[i].ShoeType
            << setw(17) << shoe[i].ShoeBrand 
            << setw(20) << to_string(shoe[i].date.month) + "-" + to_string(shoe[i].date.day) + "-" + to_string(shoe[i].date.year) 
            << setw(20) << shoe[i].shoeQuantity 
            << setw(16) << shoe[i].shoeCost 
            << shoe[i].totalValue << endl;
 
        cout << fixed << setprecision(2);
        cout<< setw(19) << shoe[i].StockNumber
            << setw(16) << shoe[i].ShoeType
            << setw(17) << shoe[i].ShoeBrand 
            << setw(20) << to_string(shoe[i].date.month) + "-" + std::to_string(shoe[i].date.day) + "-" + to_string(shoe[i].date.year) 
            << setw(20) << shoe[i].shoeQuantity 
            << setw(16) << shoe[i].shoeCost 
            << shoe[i].totalValue << endl;
    }
    myFile.close();
}
 
void inputShoe(ShoeRec getshoe[]) //VOID FUNCTION FOR INPUT SHOE
{
    system("cls");
    for (int i = 0; i < SIZE; i++)
    {
        cout << "***PRODUCT [" << i+1 << "] DETAILS***" << endl;
        while (true)
        {
            try
            {
                cout << "ENTER STOCK NUMBER: "; //ASKS USER TO ENTER STOCK NUMBER FOR THE PRODUCT
                getline(cin, getshoe[i].StockNumber);
                if (getshoe[i].StockNumber.size() != 8)
                {
                    throw 1;
                    continue;
                }  
                else
                {
                    break;
                }     
            }
            catch(...)
            {
                cout << "MUST HAVE A LENGTH OF 8!" << endl; //ERROR MESSAGE IF USER INPUT WRONG VALUE
            }
        }
 
        cout << "ENTER SHOE TYPE: "; //ASKS USER TO ENTER SHOE TYPE
        getline(cin, getshoe[i].ShoeType);
 
        cout << "ENTER SHOE BRAND: "; //ASKS USER TO ENTER SHOE BRAND
        getline(cin, getshoe[i].ShoeBrand);
 
        while (true) 
        {
            cout << "ENTER SHOE QUANTITY: ";
            if (!(cin >> getshoe[i].shoeQuantity)) {
                cout << "INVALID INPUT! PLEASE ENTER A NUMBER!" << endl; //ERROR MESSAGE IF USER INPUT WRONG VALUE
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;                   
            }
            if (getshoe[i].shoeQuantity < 1 || getshoe[i].shoeQuantity > 20)
            {
                cout << "SHOE QUANTITY MUST BE FROM 1-20 ONLY!" << endl; //ERROR MESSAGE IF USER INPUT WRONG VALUE
                continue;
            }       
            else
            {
                break;
            }
        }
 
        while (true) 
        {
            cout << "ENTER SHOE COST: "; //ASKS USER REGARDING THE COST OF THE SHOE PRODUCT
            if (!(cin >> getshoe[i].shoeCost)) {
                cout << "INVALID INPUT! PLEASE ENTER A NUMBER!" << endl; //ERROR MESSAGE IF USER INPUT WRONG VALUE
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;                   
            }      
            else
            {
                break;
            }
        }
 
        while (true) 
        {
            cout << "ENTER MONTH PURCHASED: "; //ASKS USER REGARDING THE PRODUCT MONTH OF PURCHASE
            if (!(cin >> getshoe[i].date.month)) {
                cout << "INVALID INPUT! PLEASE ENTER A NUMBER!" << endl; //ERROR MESSAGE IF USER INPUT WRONG VALUE
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;                   
            }
            if (getshoe[i].date.month < 1 || getshoe[i].date.month > 12)
            {
                cout << "MONTH SHOULD BE WITHIN 1-12 ONLY!" << endl; //ERROR MESSAGE IF USER INPUT WRONG VALUE
                continue;
            }       
            else
            {
                break;
            }
        }
 
        while (true) 
        {
            cout << "ENTER DAY PURCHASED: "; //ASKS USER REGARDING THE PRODUCT DAY OF PURCHASE
            if (!(cin >> getshoe[i].date.day)) {
                cout << "INVALID INPUT! PLEASE ENTER A NUMBER! " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;                   
            }
            if (getshoe[i].date.day < 1 || getshoe[i].date.day > 31)
            {
                cout << "DAY MUST BE WITHIN 1-31 ONLY!" << endl; //ERROR MESSAGE IF USER INPUT WRONG VALUE
                continue;
            }       
            else
            {
                break;
            }
        }
 
        while (true) 
        {
            cout << "ENTER YEAR PURCHASED: "; //ASKS USER REGARDING THE PRODUCT YEAR OF PURCHASE
            if (!(cin >> getshoe[i].date.year)) {
                cout << "INVALID INPUT! PLEASE ENTER A NUMBER! " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;                   
            }
            if (getshoe[i].date.year < 2000 || getshoe[i].date.year > 2021)
            {
                cout << "INPUT YEAR MUST BE WITHIN 2000-2021 ONLY!" << endl; //ERROR MESSAGE IF USER INPUT WRONG VALUE
                continue;
            }       
            else
            {
                break;
            }
        }
 
        cin.ignore();
        cout << endl;
    }
}
 
void compVal(ShoeRec tValue[]) //FOR CALCULATION OF VALUES OF PRICES INPUT BY THE USER
{
    for (int i = 0; i < SIZE; i++)
    {
        tValue[i].totalValue = (tValue[i].shoeCost) * (tValue[i].shoeQuantity);
    }
}
