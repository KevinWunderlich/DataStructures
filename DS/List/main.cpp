#include <iostream>
using namespace std;

void getdata(char& lastN,float& grade_value);

class node_type            // declaration of class//
{
public:
    char lName;
    float gpa;
    node_type *next;
};

int main()
{
    node_type *first,*q,*newnode,*r,*s,*uno,*duo,*newernode;
    int i,finalSize;
    float grade_value;
    char lastN;
    
    uno = new node_type;
    r = uno;
    
    // Create first list
    getdata(lastN,grade_value);
    (*uno).lName = lastN;
    (*uno).gpa = grade_value;
    (*uno).next = NULL;
    for (i=2; i <= 10; i++)
    {
        getdata(lastN,grade_value);
        newnode = new node_type;
        (*newnode).lName = lastN;
        (*newnode).gpa = grade_value;
        (*newnode).next = NULL;
        (*r).next = newnode;
        r = newnode;
    }
   
    // Sort First List
    for(i=1; i<=10; i++)
    {
        r = uno;
        q = NULL;
    
        while((*r).next != NULL)
        {
            s = (*r).next;
            if((*r).gpa > (*s).gpa)
            {
                (*r).next = (*s).next;
                (*s).next = r;
                if(q == NULL)
                    uno = s;
                else
                    (*q).next = s;
                q = s;
            }
            else
            {
                q = r;
                r = (*r).next;
            }
        }
    }
    
    // Print first list
    q = uno;
    cout << "The first list contains \n";
    while (q != NULL)
    {
        cout << "Last Name is " << (*q).lName << "\n";
        cout << "GRADE is " << (*q).gpa << "\n";
        q = (*q).next;
    }
    
    cout << endl;
    
    // Create Second List
    duo = new node_type;
    r = duo;
    getdata(lastN,grade_value);
    (*duo).lName = lastN;
    (*duo).gpa = grade_value;
    (*duo).next = NULL;
    for (i=2; i<=10; i++)
    {
        getdata(lastN,grade_value);
        newernode = new node_type;
        (*newernode).lName = lastN;
        (*newernode).gpa = grade_value;
        (*newernode).next = NULL;
        (*r).next = newernode;
        r = newernode;
    }
    
    // Sort Second List
    for(i=1; i<=10; i++)
    {
        r = duo;
        q = NULL;
        
        while((*r).next != NULL)
        {
            s = (*r).next;
            if((*r).gpa > (*s).gpa)
            {
                (*r).next = (*s).next;
                (*s).next = r;
                if(q == NULL)
                    duo = s;
                else
                    (*q).next = s;
                q = s;
            }
            else
            {
                q = r;
                r = (*r).next;
            }
        }
    }
   
    // Print out second list
    q = duo;
    cout << "The second list contains \n";
    while (q != NULL)
    {
        cout << "Last Name is " << (*q).lName << "\n";
        cout << "GRADE is " << (*q).gpa << "\n";
        q = (*q).next;
    }

    cout << endl;
    
    // Delete nodes from first list where GPA is above 3.0
    
    q = uno;
    while (q != NULL)
    {
        if((*uno).gpa > 3.0)
        {
            cout << "All grades in the first list are above 3.0.";
            uno = NULL;
            q = NULL;
        }
        else if ((*q).gpa <= 3.0)
        {
            r = q;
            q = (*q).next;
        }
        else if((*q).gpa > 3.0)
        {
            q = NULL;
            (*r).next = NULL;
        }
    }

    q = uno;
    cout << "The modified first list contains \n";
    while (q != NULL)
    {
        cout << "Last Name is " << (*q).lName << "\n";
        cout << "GRADE is " << (*q).gpa << "\n";
        q = (*q).next;
    }
    
    cout << endl;
    
    q = duo;
    while (q != NULL)
    {
        if ((*q).gpa <= 2.0)
        {
            q = (*q).next;
        }
        else if((*q).gpa > 2.0)
        {
            duo = q;
            q = NULL;
        }
    }
    q = duo;
    cout << "The modified second list contains \n";
    while (q != NULL)
    {
        cout << "Last Name is " << (*q).lName << "\n";
        cout << "GRADE is " << (*q).gpa << "\n";
        q = (*q).next;
    }

    cout << endl;
    
    q = uno;
    // Merge two lists together
    while(q != NULL)
    {
        r = q;
        q=(*q).next;
    }
    (*r).next = duo;
    first = uno;
    
    finalSize = 0;
    
    q = first;
    while(q != NULL)
    {
        q = (*q).next;
        finalSize++;
    }
    
    // Sort by last name
    for(i=1; i<=finalSize; i++)
    {
        r = first;
        q = NULL;
        
        while((*r).next != NULL)
        {
            s = (*r).next;
            if((*r).lName > (*s).lName)
            {
                (*r).next = (*s).next;
                (*s).next = r;
                if(q == NULL)
                    first = s;
                else
                    (*q).next = s;
                q = s;
            }
            else
            {
                q = r;
                r = (*r).next;
            }
        }
    }
    
    // Print out final merged and sorted list
    q = first;
    cout << "The final merged list sorted by last name contains: \n";
    while (q != NULL)
    {
        cout << "Last Name is " << (*q).lName << "\n";
        cout << "GRADE is " << (*q).gpa << "\n";
        q = (*q).next;
    }
    
}
void getdata(char& lastN,float& grade_value)
{
    cout << "Enter id and grade \n" ;
    cin >> lastN;
    cout << lastN << "\n";
    cin >> grade_value;
    cout << grade_value << "\n";
}



