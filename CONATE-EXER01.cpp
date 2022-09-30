/*
* Programmer: ONATE, Carl Glennard H.
* Date Created: 11/19/2021
* Program: BSIT
* Course / Section: CS127L-8
*/
#include <iostream>
#include <iomanip> 
#include <cctype>
using namespace std;

//global
int i;
int row,col;
const int sizeRow=4;
const int sizeCol=5;
const int dim = 20;
const int dim2 = 10;

//function
char getmenu(char sagot); //returns the correct choice 
void getInput(int list[],int dim);//input for both option 1 and 2
void getBubble(int list[],int dim);//perform the bubble sorting
void getSelect(int list[],int dim);//perform the selection sorting
void convert2DimSort(int list[],int dim);//convert one dimensional to 2-dimensional for both option 1 and 2
void get2DOut(int list1[][sizeCol]);//displaying the values in ascending and descending order 2-D
void getHeap(int list3[],int dimen);//process heapyfication or heap sort 1-D
void swapper(int *xp, int *yp); //using array swap thru the use of pointers
void again();//try again function for looping the entire code

int main() 
{
	system("Color 70"); //for better visual effects
    char choice;
    char sagot;
    int array[dim];
    do
    {
        system("cls");
        cout << "-------SORTING-------" << endl;
        cout << "[1]bubble sort" << endl;
        cout << "[2]selection sort" << endl;
        cout << "[3]heap sort" << endl;
        cout << "[4]QUIT" << endl;
        cout << "---------------------" << endl;
        sagot = getmenu(choice);

        switch (sagot)
        {
            case '1': //bubblesort
            {
                system("cls");
	            cout<<"Processing Bubble sorting Technique\n"; 
                getInput(array,dim);
                getBubble(array,dim);
                convert2DimSort(array,dim);
                break;
            } 
            case '2': //selection sort
            {
                system("cls");
                cout << "Processing Selection Sorting Technique..." << endl;
                getInput(array,dim);
                getSelect(array,dim);
                convert2DimSort(array,dim);
                break;
            }
            case '3': //heapsort
            {
                system("cls");
                getHeap(array,dim2);
                break;
            }           
            case '4':cout<<"end of program.....\n";
                exit(1);
        }
    again();    
    } while (true);
}     

char getmenu(char sagot) 
{
    char choice;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == '1' || choice == '2' || choice == '3' || choice == '4')
    {
        return choice;     
    }
    else
    {
        return -1;
    }
}
///////////////////////////////////////////////
void getInput(int list[],int dim)// for both option 1 and 2 only
{
    cout << "enter " << dim << " elements" << endl;
    for (int i = 0; i < dim; i++)
    {
        cout << "loc" << "["<<i<<"]: ";
        cin >> list[i];
    }
}
///////////////////////////////////////////////
void convert2DimSort(int list[],int dim)
{
    int i, j, ctr = 0;
	int inList[sizeRow][sizeCol];

	cout<<"Ascending Order...\n";
	for(i = 0; i < sizeRow; i++)
	{
		for(j = 0; j < sizeCol; j++)
		{
			inList[i][j] = list[ctr++];
		}
	}
	get2DOut(inList); 
	
	cout<<"Descending Order...\n";
	for (i = 0; i < sizeRow; i++)
	{
		for (j = 0; j < sizeCol; j++)
		{
			if (list[j] < list[j + 1])
			{
				inList[i][j] = list[--ctr];
			}
		}
	}
	get2DOut(inList);
}
///////////////////////////////////////////////
void get2DOut(int list1[][sizeCol])  
{
	for (int i = 0; i < sizeRow; i++)
	{
		for (int a = 0; a < sizeCol; a++)
		{
			cout << "   " << setw(4) << list1[i][a];
		}
		cout << endl;
	}
}
///////////////////////////////////////////////
void swapper(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
///////////////////////////////////////////////
void getBubble(int list[],int dim)
{
	int j,temp;
	for (i = 0; i < dim; i++)
	{		
		for (j=i+1; j<dim; j++)
		{
			if (list[i]>list[j])
			{
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
}
///////////////////////////////////////////////
void getSelect(int list[], int dim)
{
    int i, j, min_idx;
    for (i = 0; i < dim-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < dim; j++)
        if (list[j] < list[min_idx])
            min_idx = j;
        swapper(&list[min_idx], &list[i]);
    }
}
///////////////////////////////////////////////
void heapify(int array[], int dim2, int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < dim2 && array[left] > array[largest])
    {
        largest = left;
    }    
    if (right < dim2 && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != i) 
    {
        swap(array[i], array[largest]);
        heapify(array, dim2, largest);
    }
}
///////////////////////////////////////////////
void getHeap(int list[], int dim2)
{
    cout << "Processing Heap Sorting Technique....." << endl << endl;

    for (int x = 0; x < dim2; x++)
    {
        cout << "Array [" << x << "]: ";
        cin >> list[x];
    }
    cout << endl;
    cout << "Heapified Values....." << endl << endl;
    for (int i = dim2 / 2 - 1; i >= 0; i--) 
    {
        heapify(list, dim2, i);
    }
    // Heap sort
    for (int i = dim2 - 1; i >= 0; i--) 
    {
        swap(list[0], list[i]);
        heapify(list, i, 0);
    }
    for (int x = 0; x < dim2; x++)
    {
        cout << "Arr[" << x+1 << "]: " << list[x] << endl;
    }
}
///////////////////////////////////////////////
void again()
{
	char prompt;
	while(true)
	{
		cout<<"Do you want to try again[y/n]";
		cin>>prompt;
		if(prompt == 'Y'||prompt =='y'){
			system("cls");
			break;
		}
		if(prompt == 'N'||prompt =='n'){
			cout << "leaving the program now....";
        	exit(0);
		}
	}
}
