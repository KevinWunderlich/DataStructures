// Kevin Wunderlich

#include <iostream>
using namespace std;

void bubblesort(float array[26], float sArray[26], int arraySize);
int search(float searchValue, float sArray[26], int arraySize);

int main()
{
    float array[26], sArray[26], searchValue, value;
    int arraySize, found[4], i, c, d;
    char ans;
    
    do
    {
        i = 1;
        do
        {
            cout << "Enter Search Value: ";
            cin >> searchValue;
            
            do
            {
                cout << "Enter Values for Array " << i << " (up to 25 values, enter -999 to finish): ";
                cin >> value;
                
                c = 0;
                while (c < 25 && value != -999.0)
                {
                    c++;
                    array[c] = value;
                    if (c<25)
                        cin >> value;
                }
                
                arraySize = c;
                
                bubblesort(array, sArray, arraySize);
                found[i] = search(searchValue, sArray, arraySize);
                
                i++;
            } while (i <= 3);
            
        } while (i != 4);
        
        for (d = 1; d <= 3; d++)
        {
            if (found[d] == -1)
                cout << "Value not found in array " << d << ".\n";
            else
                cout << "Value found at index " << found[d] << " in array " << d << endl;
        }
        
        cout << "Perform another search? (Y/N) ";
        cin >> ans;
        
    } while (ans == 'y' || ans == 'Y');
    
    system("pause");
    return 0;
    
}

int search(float searchValue, float sArray[26], int arraySize)
{
    int i, foundIndex;
    foundIndex = 0;
    
    for (i = 1; i <= arraySize; i++)
        if (sArray[i] == searchValue)
            foundIndex = i;
    
    if (foundIndex == 0)
        return -1;
    else
        return foundIndex;
    
}

void bubblesort(float array[26], float sArray[26], int arraySize)
{
    int i, j;
    float temp;
    for (i = 1; i <= arraySize; i++)
        sArray[i] = array[i];
    for (j = 1; j <= arraySize - 1; j++)
        for (i = 1; i <= arraySize - j; i++)
            if (sArray[i] > sArray[i + 1])
            {
                temp = sArray[i];
                sArray[i] = sArray[i + 1];
                sArray[i + 1] = temp;
            }
}
