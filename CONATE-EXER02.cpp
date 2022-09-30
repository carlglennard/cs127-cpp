/*
* Programmer: ONATE, Carl Glennard H.
* Date Created: 12/2/2021
* Program: BSIT
* Course / Section: CS127L-8/BM5
*/
 
#include<iostream>
#include<iomanip>
using namespace std;
 
//global declaration
int i;
const int size=10;
typedef double *pointers;//typedefinition used for miles per gallon pointer variables
//prototype
//for grade elimination
void getInput(double *input);//prompt the user to input 10 grades
double getLow(double *low);//compute and returns the value of the lowest grade
double getSum(double *sum);//compute for the sum of 10 grades
//choices and try again
char getChoice(char *ch);//display the menu of choices and input the choice of the user
 
//miles per gallon
void MilesPerrGallon(double *ptr1,double *ptr2,int sz);//final output of the computer miles
//and gallons
void MperG();//prompts the user to specify the size of the array for miles and gallons
//verify and validate the input for miles and gallons using exception handling
 
int main()
{
    //add only declaration here 
    char *chr;
    char opt;
    char choice;
 
    do{
        chr=&choice;
        opt=getChoice(chr);
        *chr = opt;
        
        switch(*chr)
        {
            case '1':  
            {
                //add declaration here
                double grade[size];
                double *ptr;
                double *plow, *psum, *pave;
                double gsum,glow;
                double ave;         
                system("cls");
                 // input
                ptr = &grade[0];
                getInput(ptr);
                //sum
                ptr = &grade[0];
                gsum = getSum(ptr);
                psum = &gsum;
                // lowest grade
                ptr = &grade[0];
                glow = getLow(ptr);
                plow = &glow;
                //average grade
                ave = (*psum-*plow)/9;
                pave = &ave;     
                
                cout << "Sum: " <<*psum << endl;
                cout << "Lowest grade: " << *plow << endl;
                cout << fixed << setprecision(2);
                cout << "Average: " << *pave << endl;
                //add code here
            }       
            //NOTE ALL CODES MUST USE pointer variables –input,process and //output            
            break;
            case '2':  MperG();
            break;
            case '3': 
                cout<<"goodbye for now....\n";
                system("pause");
                exit(1);
            break;
        }   
        //Add code here
        char cont;
        do {
            cout << "Do you want to try again? [y/n] ";
            cin >> cont;
            cont = tolower(cont);
            if (cont == 'y') {
                system("cls");
                break;
            }
            else if (cont == 'n') { 
                cout<<endl;
                system("pause");
                return 0;
            }
            else {
                cout << "invalid input!" << endl;
            }        
        } while (cont !=  'Y'|| cont != 'N');
    } while(true);
}
///////////////////////////
char getChoice(char *ch)
{
    //add code here
    cout << "<<<<<<<<<<MENU>>>>>>>>>>" << endl
             << "[1] score of 10 quizzes" << endl
             << "[2] miles per gallon" << endl
             << "[3] to quit" << endl;
    cout << "enter your choice: ";
    cin >> *ch;
    if (*ch == '1' || *ch == '2' || *ch == '3')
    {
        return *ch;     
    }
    else
    {
        return -1;
    }
}
//////////////////////////////
void getInput(double *input)
{
      //add code here
      cout << "Choice [1]: Grade Elimination" << endl;
    for (i = 0; i < size; i++)
    {
        try{
            cout << "grade[" << i+1 << "]: ";
            cin >> *(input+i); 
            if (*(input+i) < 0 || *(input+i) > 100)
            {
                throw 0;   
            } 
        } catch (...){
            cout << "INVALID. Grade must only be in the range of 0-100." << endl;
            if (i == 0)
            {
                i = i-1;
            }
            if (i >= 1)
            {
               i = i-1; 
            }        
        }  
    }
}
/////////////////////////////
double getSum(double *sum)
{
    double add=0;
    //add code here
    for (i=0; i < size; i++)
    {
        add += *(sum+i);
       
    }  
      return add;
}
////////////////////////////////
double getLow(double *low)
{
    double *xlow, baba;
    //add code here
    baba= *(low+0);//25
    xlow=&baba; 
    for(i=0;i<size;i++)
        {
            //low
            if( *(low+i)< *xlow)  //num[0]<low
              *xlow= *(low+i);
        }   
    return *xlow;   
}
/////////////////////////
void MperG()
{   
    int ctr;
    pointers milPtr,galPtr;
    int msize;
    double mil, gal;
    system("cls");
    //add code here
    cout << "COMPUTING FOR MPG: miles per gallon..." << endl;
    while (true){
       try {
        cout << "Specify the size of the array: ";
        cin >> msize;
        if (msize < 5 || msize > 15)
        {
            throw 0;
        }
        else
        {
            break;
        }
        } catch(...) {
            cout << "Size 5-15 only" << endl;
            continue;
        }
    }
    milPtr = new double[msize];
    galPtr = new double[msize];
    system("cls");
    cout << "MILES" << endl;
 
    for(ctr=0;ctr<msize;ctr++)
    {
        //add code here
        try{
                //add code here
            cout << "miles[" << ctr << "]: ";
            cin >> milPtr[ctr]; 
            if (milPtr[ctr] < 100 || milPtr[ctr] > 250)
            {
               throw milPtr[ctr]; 
            } 
        }//end try
        catch(double e)
        {
             cout << e << " is invalid!... 100-250 only" << endl;
            cout << "reenter a new value" << endl;
            if (ctr == 0)
            {
                ctr = ctr-1;
            }
            if (ctr >= 1)
            {
               ctr = ctr-1; 
            }  
            //add code here
        }//end catch 
             //add code here
    }//end while
//loop for miles
/*********************************************************/
system("cls");
cout<<"GALLONS\n";
    
    for(ctr=0;ctr<msize;ctr++)
    {
        bool ans=true;
        while(ans){
        //add code here
        try
        {   
        //add code here
        cout << "gallons[" << ctr << "]: ";
                cin >> galPtr[ctr]; 
                if (galPtr[ctr] < 5 || galPtr[ctr] > 25)
                {
                    throw galPtr[ctr]; 
                } 
                else
                {
                    ans = false;
                }
 
        }//end try
        catch(double e)
        {
            //add code here
            cout << e << " is invalid!... 5-25 only" << endl;
                cout << "reenter a new value" << endl;
                if (ctr == 0)
                {
                    ctr = 0;
                }
                if (ctr >= 1)
                {
                    ctr = ctr; 
                }  
        }//end catch    
             //add code here
        }//end while
    }//loop for gallons
 
MilesPerrGallon(milPtr,galPtr,msize);
delete[] milPtr;
delete[] galPtr; 
}
 
////////////////////////
void MilesPerrGallon(double *ptr1,double *ptr2,int sz)
{
    double mpg[sz];
    pointers mpgPtr;
    mpgPtr = new double[sz];
    int index;
    //add code here
    cout << endl;
    cout << "miles" << setw(7) <<"/"<< "   gallon" << "     =" << setw(7) << "  MPG" << endl;
    for (index = 0; index < sz; index++)
    {
        cout << fixed << setprecision(2);
        cout << *(ptr1+index) << setw(7) << "/" << setw(7) << *(ptr2+index) << setw(7) << " =" << setw(7) <<  (*(ptr1+index)) / (*(ptr2+index)) << endl;
    }
}
