/*
* Programmer: ONATE, Carl Glennard H.
* Date Created: 1/22/2022
* Program: BSIT
* Course / Section: CS127L-8/BM5
* username: admin
* password: exer_04
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
 
struct item
{
    string product;
    string name[420];
 
    int subClassNum;
    double price[420];
    int stock[420];
    int sold[420];
};
 
 
int main()
{
	system("Color 70"); //SYSTEM COLOR (BACKGROUND)
    int attemptCount = 3;
    string inputUser;
    string keyUsername = "admin";
    string keyPassword = "exer_04"; 
 
    system("cls");
    //LOOPING STATEMENT FOR USERNAME
    for (int i = 0; i <= attemptCount; i++)
    {
        //CHECKS IF ATTEMPT LIMIT IS REACHED
        if (i == attemptCount)
        {
            cout << "ATTEMPT LIMIT REACHED." << endl;
            return 0; //PROGRAM ENDS WHEN THE USER HAS REACHED THE LIMIT
        }
        try
        {
        	cout<< "PRODUCT INVENTORY SYSTEM CS127L" <<endl;
            cout << "USERNAME: ";
            cin >> inputUser;
 
            //INPUT VALIDATION FOR USERNAME
            if (inputUser == keyUsername)
            {
                system("cls");
                break;
            }
            else
            {
                throw inputUser;
            }     
        }
        catch(...)
        {
            //ERROR MESSAGE WHEN INPUT IS NOT EQUIVALENT TO THE STORED VALUE
            cout << "INVALID USERNAME!" << endl;
        }        
    }
 
    //LOOPING STATEMENT FOR PASSWORD
    for (int i = 0; i <= attemptCount; i++)
    {
        //PROGRAM ENDS WHEN THE USER HAS REACHED THE LIMIT
        if (i == attemptCount)
        {
            cout << "OUT OF ATTEMPTS. CLOSING PROGRAM." << endl;
            return 0;
        }
        try
        {
        	cout<< "PRODUCT INVENTORY SYSTEM CS127L" <<endl;
            cout << "PASSWORD: ";
            cin >> inputUser;
            
            if (inputUser == keyPassword)
            {
                system("cls");
                break;
            }
            else
            {
                throw inputUser;
            }
        }
        catch(...)
        {
            cout << "INVALID PASSWORD!" << endl; //ERROR MESSAGE WHEN USER SUPPLIES A WRONG PASSWORD
        }   
    }
    while (true)
    {
        int size;
        int subsize;
        cout << " ***** INVENTORY SYSTEM C++.2 *****" << endl;
        cout << endl;
        cout << "ENTER NUMBER OF PRODUCTS FOR INVENTORY: "; //ASKS USER FOR THE QUANTITY OF PRODUCTS TO INPUT IN THE INVENTORY
        if (!(cin >> size)) {
            system("cls");
            cout << "INVALID INPUT! PLEASE ENTER A NUMBER! " << endl; //ERROR MESSAGE WHEN USER DOESN'T INPUT A NUMBER
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;                   
        }
 
        item productX[size];
 
        cout << endl;
        cout << "ENTER " << size << " PRODUCTS" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << endl;
            cout << "Product " << i+1 << ": "; //ASKS USER FOR THE NAME OF THE PRODUCT
            cin.ignore();
            getline(cin, productX[i].product);
 
            cout << endl;
            while (true)
            {
                try
                {
                    cout << "How many " << productX[i].product << "? "; //ASKS USER FOR THE QUANTITY OF SUBPRODUCT
                    if (!(cin >> productX[i].subClassNum)) {
                        cout << "INVALID INPUT! PLEASE ENTER A NUMBER." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;                   
                    }
                    if (productX[i].subClassNum < 1)
                    {
                        throw 100;
                        continue;
                    }
                    else
                    {
                        break;
                    }  
                }
                catch(...)
                {
                    cout << "INPUT CANNOT BE LESS THAN 1!" << endl; //ERROR MESSAGE WHEN USER INPUTS LESS THAN THE VALUE OF 1
                }
                
  
            }     
 
            for (int a = 0; a < productX[i].subClassNum; a++)
            {
                cout << endl;
                cout << productX[i].product << "[" << a+1 << "]: "; //ASKS USER REGARDING THE SUB CLASS PRODUCTS
                cin.ignore();
                getline(cin, productX[i].name[a]);
 
                //ASKS USER FOR THE DETAILS ABOUT THE SUB CLASS PRODUCTS
                while (true)
                {
                    cout << "Price: ";
                    if (!(cin >> productX[i].price[a])) {
                        cout << "INVALID INPUT! PLEASE ENTER A NUMBER. " << endl; //ERROR MESSAGE WHEN USER DOESN'T INPUT A NUMBER
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
                    cout << "Stock: ";
                    if (!(cin >> productX[i].stock[a])) {
                        cout << "INVALID INPUT! PLEASE ENTER A NUMBER. " << endl; //ERROR MESSAGE WHEN USER DOESN'T INPUT A NUMBER
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
                    cout << "Sold: ";
                    if (!(cin >> productX[i].sold[a])) {
                        cout << "INVALID INPUT! PLEASE ENTER A NUMBER. " << endl; //ERROR MESSAGE WHEN USER DOESN'T INPUT A NUMBER
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;                   
                    }
                    else
                    {
                        break;
                    }           
                }
            }
        }
 
        system("cls");
        cout << " ***** INVENTORY SYSTEM C++.2 *****" << endl;
        cout << endl;
 
        cout << "PROD. NO       PRODUCT       NAME        PRICE       STOCK       SOLD        LEFT" << endl;
 
        // 
 
        for (int i = 0; i < size; i++)
        {
            if (productX[i].subClassNum == 1) //PROGRAM EXECUTION WHEN THERE IS 1 SUB CATERGORY
            {
                cout << left;
                cout << setw(15) << i+1
                    << setw(14) << productX[i].product;
                    
                for (int j = 0; j < productX[i].subClassNum; j++)
                {
                    cout << setw(14) << productX[i].name[j]
                        << setw(12) << productX[i].price[j]
                        << setw(11) << productX[i].stock[j]
                        << setw(11) << productX[i].sold[j]
                        << setw(12) << productX[i].stock[j] - productX[i].sold[j] << endl;
                }
                cout << endl;
            }
            if (productX[i].subClassNum > 1) //PROGRAM EXECUTION WHEN THERE IS MORE THAN 1 SUB CATEGORY
            {                
                    for (int j = 0; j < productX[i].subClassNum; j++)
                    {
                        cout << left << setw(15) << i+1 << setw(14) << productX[i].product;
                        cout << setw(14) << productX[i].name[j]
                            << setw(12) << productX[i].price[j]
                            << setw(11) << productX[i].stock[j]
                            << setw(11) << productX[i].sold[j]
                            << setw(12) << productX[i].stock[j] - productX[i].sold[j] << endl; 
                    }
                    cout << endl;   
            }
        }
        break;
    }
}
