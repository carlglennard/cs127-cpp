/*
* Programmer: ONATE, Carl Glennard H.
* Date Created: 1/8/2022
* Program: BSIT
* Course / Section: CS127L-8/BM5
*/

#include<iostream> 
#include<iomanip> 
#include<cstring> 
#include<algorithm> 
#include<cstdlib> 
#include<conio.h>
#include<windows.h>
using namespace std;  
 
string sort(string str);//reaaranging the orders of string to test if its anagram
bool areAnagrams(string str1,string str2);//process the strgin if anagram anf returns the value 1 or 0
string RemSpacePunct(string str);//function that removes space and punctation in aa string
///////////////////////////////
void palindrome(char sal[120]);//testing whether the c-string value is palindrome or not 
void password();//asking the user to enter the password
char menu(char ch);//displaying choices a,b, and c then returns the answer 
void quit();//asking the user if he/she wants to quit
string EnterPassword(string password);//processing if the password is correct and diplaying it with "*" sign
 
int main()
{
    system("cls");
    password();
    char let,ans, sal[120];
    string s1, s2;
    do 
    {
        ans = menu(ans);
        cin.ignore();
        switch(ans)
        {
            case 'a':
            {    
                system("cls");
                cout << "[a] Check the palindrome" << endl;                
                cout << "Input the word: ";
                cin >> sal;
                palindrome(sal);
                break;
            }
            case 'b':
            {
                system("cls");
                cout << "[b] Testing if strings are anagrams" << endl;
 
                cout << "Enter string1: ";
                getline(cin, s1);
 
                cout << "Enter string2: ";
                getline(cin, s2);
                
                if (areAnagrams(RemSpacePunct(s1),RemSpacePunct(s2)))
                {
                    cout << "They are anagrams" << endl;
                }
                else
                {
                    cout << "They are NOT anagrams." << endl;
                }
                break;
            }
            case 'c': 
            {
                quit();  
            }
        } 
        do{
            cout<<"Do you want to try again? [y/n]"<<endl
                <<"Choice: "; 
                cin>>let; 
                let=tolower(let);
            if (let == 'y')
            {
                system("cls");
                break;
            }
            else if (let == 'n')
            {
                system("cls");
                password();
                break;
            }
            else
            {
                cout << "Invalid input!" << endl;
            }
        }while(let!='N'&&let!='Y');
    }while (true);
}
void quit()
{
    char choice;
    while (true)
    {
        cout << "Do you want to quit now? [y/n]: ";
        cin >> choice;
        choice = tolower(choice);
 
        if (choice == 'n')
        {
            main();
        }
        else if (choice == 'y')
        {
            cout << "thank you and God bless!" << endl;
            system("pause");
            exit(0);
        }
        else
        {
            cout << "invalid input!" << endl;
        }
    }
}
//////////////////////////////
string EnterPassword(string password)
{
    string key = "exer_03";
    if (password==key) 
    {
        return password;
    }
    else
    {
        return "wrong";
    } 
}
 
//////////////////////////////
char menu(char ch)
{
 
    char choice;
    while (true)
    {
        try
        {
            cout << "---------CHOICES---------" << endl
                << "[a] Check the palindrome" << endl
                << "[b] Testing if strings are anagrams" << endl
                << "[c] Quit" << endl
                << "Your choice: ";
            cin >> choice;
            if (choice == 'a' || choice == 'b' || choice == 'c')
            {
                return choice;
            }
            else
            {
                throw 0;
            }  
 
        } catch(...) {
            system("cls");
            cout << "invalid!" << endl;
        }      
    }
    return choice;
}
 
//////////////////////////////
void password()
{
    string HAHA;
    string password; 
 
    int trycount = 0;
    int trylimit = 3;
 
    for (trycount; trycount < trylimit; trycount++)
    {        
        // cout << "Enter password: ";
        // getline(cin, password);
        string password;
        cout << "enter password: ";
        char temp = getch();
 
        while(temp != '\r')
        {
            cout << '*';
            password += temp;
            temp = getch();
        }
    
        if (EnterPassword(password) == "exer_03")
        {
            cout << endl;
            cout << "logged in" << endl;
            break;
        }
        else
        {
            cout << endl;
            cout << "sorry incorrect password...." << endl;
        }  
    }
    if (trycount == trylimit)
    {
         cout << "you have reached the maximum attempt for password";  
         exit(0);
    }
}
//////////////////////////////
string sort(string str)
{
    sort(str.begin(), str.end());
    return str;
}
//////////////////////////////
bool areAnagrams(string str1,string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
 
    str1 = sort(str1);
    str2 = sort(str2);
 
    if (n1 != n2)
        return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] != str2[i])
            return false;
    return true;
}
//////////////////////////////
string RemSpacePunct(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (!(isalpha(str[i])))
        {
            str.erase(i, 1);
            i--;
        }
    }
   return str;
}
//////////////////////////////
void palindrome(char sal[120])
{
    //add code here
    RemSpacePunct(sal);
    string P = sal;
    
    reverse(P.begin(), P.end());
    
    cout << "In reverse order: " << P << endl;
 
    for (int i = 0; i < P.length(); i++)
    {
        P[i] = tolower(P[i]);
    }
    
    for (int i = 0; i < P.length(); i++)
    {
        sal[i] = tolower(sal[i]);
    }
 
    if (sal == P) {
        cout << "The word is a palindrome" << endl;
    }
 
    else {
         cout <<"The word is not a palindrome" << endl;
    }
}
