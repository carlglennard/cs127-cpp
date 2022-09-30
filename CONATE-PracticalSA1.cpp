/*
* Programmer: ONATE, Carl Glennard H.
* Date Created: 12/14/2021
* Program: BSIT
* Course / Section: CS127L-8/BM5
*/
#include <iostream>
#include <iomanip>
using namespace std;
 
char getMenu(char ch); //for menu navigation
void getBinDisplay(int *ptr, int *xsize); //for displaying binary values
int getLoc(int *ptr, int size,int *xtarget); //for getting the address
int getSize(); //asks the user how many grades he/she would like to input
void getInput(double *ptr, int xsize); //asking the user to enter the grades
double getElim(double *ptr, int xsize); //for eliminating the lowest score
void getTry(); //asking the user to try again if he/she input a wrong value
 
int main()
{
    char choice;
    while (true)
    {
        choice = getMenu(choice);
        switch (choice)
        {
            case '1': 
            {
                system("cls");
                cout << "option 1: binary searching" << endl;
                int size = 12; int target;
                int binNum[] = {4, 7, 8, 10, 14, 21, 22, 36, 62, 77, 81, 91};
                int *binPtr, *sizePtr;
                int *targetPtr = new int;
                binPtr = &binNum[0];
                sizePtr = &size;
                targetPtr = &target;
                getBinDisplay(binPtr, sizePtr);
                cout << "enter your target key: ";
                cin >> target;
                int loc = getLoc(binPtr, size, targetPtr);
                if(loc == -1)
                {
                    cout << target << " is not in list" << endl;
                }
                else
                {
                    cout << target << " is at position " << loc << endl;
                }
                break;
            }         
 
            case '2': 
            {
                system("cls");
                cout << "option 2: grade elimination" << endl;
                int size = getSize();
                double *gradesPtr;
                gradesPtr = new double[size];
                getInput(gradesPtr, size);
                double lowestGrade = getElim(gradesPtr, size);
                double sum = 0;
                for (int i = 0; i < size; i++)
                {
                    sum += *(gradesPtr+i);
                }
                cout << lowestGrade << " is eliminated" << endl;
                double average = (sum-lowestGrade)/(size-1);
                cout << fixed << setprecision(2);
                cout << "average is " << average << endl;
                break;
            }   
            case '3':
            {
                cout << "thank you for using this program. have a nice day!" << endl;
                exit(0);
            }   
        }    
        getTry();
    }
}
 
char getMenu(char ch)
{
    char choice;
    while (true)
    {
        try
        {
            cout << "---------CHOICES---------" << endl
                << "[1] binary searching" << endl
                << "[2] grade elimination" << endl
                << "[3] exit" << endl
                << "please enter your choice: ";
            cin >> choice;
            if (choice == '1' || choice == '2' || choice == '3')
            {
                return choice;
            }
            else
            {
                throw 0;
            }  
 
        } catch(...) {
            system("cls");
            cout << "invalid option/input please try again." << endl;
 
        }      
    }
}
 
void getBinDisplay(int *ptr, int *xsize)
{
    cout << "displaying elements in the array" << endl;
    for (int i = 0; i < *xsize; i++)
    {
        cout << *(ptr+i) << setw(7);
    }
    cout << endl;
}
 
int getLoc(int *ptr, int size,int *xtarget)
{
    int index, power;
   
    for (power = 1; power < size; power <<= 1);
 
 
    for (index = 0; power; power >>= 1){
       
        if (index + power < size && *((ptr)+index + power) <= *xtarget)
           index += power; 
    }
   
    if(*(ptr+index) == *xtarget)
        return index;
   
      //else the value is not present in the array
    return -1;
}
 
int getSize()
{
    int size;
    while (true)
    {
        try
        {
            cout << "enter your desired number of grades [5-10 only]: ";
            cin >> size;
            if (size < 5 || size > 10)
            {
                throw 0;
            }
            else
            {
                return size;
                break;
            }
        } catch(...) {
            cout << size << " is invalid... please re-enter" << endl;
            continue;
        }
    }
}
 
void getInput(double *ptr, int xsize)
{
    cout << "enter " << xsize << " grades: " << endl;
    for (int i = 0; i < xsize; i++)
    {
        cout << "grade [" << i << "]: ";
        cin >> *(ptr+i);
    }
}
 
double getElim(double *ptr, int xsize)
{
    double smallest = *(ptr+0) ;
    for (int i=1; i < xsize; i++)
        if ( *(ptr+i) < smallest )
             smallest = *(ptr+i) ;
 
    return smallest;
 
}
 
void getTry()
{
    char repeat;
    while (true)
    {
        try
        {
            cout << "do you want to try again? [y/n]: ";
            cin >> repeat;
            repeat = toupper(repeat);
            if (repeat == 'Y')
            {
                system("cls");
                break;
            }
            else if (repeat == 'N')
            {
                cout << "thank you for using this program. have a nice day!" << endl;
                exit(0);
            }
            else
            {
                throw 0;
                break;
            }
        } catch (...) {
            cout << "invalid option/input please try again." << endl;
            continue;
        }
    }
}
