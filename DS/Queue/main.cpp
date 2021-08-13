// Kevin Wunderlich
// CS501 Spring 2018
// Project 3

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxqueuechar = 24;
class queuechar_type            // declaration of class//
{
public:
    void clear_queuechar();    //member functions//
    bool empty_queuechar(); //    of class queue_type//
    bool full_queuechar();
    void insert_queuechar(char ch);
    void delete_queuechar(char& ch);
    char queuechar[25];
    int frontch,rearch;
};

int main()
{
    queuechar_type ked;
    queuechar_type beu;
    queuechar_type strt;
    queuechar_type tempq;
    queuechar_type checkq;
    
    char lic[7], temp, ans;
    int i, n, feerand, tempcount(0), match(0), kedcount(0),beucount(0),strtcount(0),notfound(0);
    int fee[5] = {0, 15, 30, 45, 60};
    bool found;
    
    ked.clear_queuechar();
    beu.clear_queuechar();
    strt.clear_queuechar();
    checkq.clear_queuechar();
    tempq.clear_queuechar();
    
    srand(time(0));
    
    do
    {
        
        cout << "Enter six character license number, indicate 'a' for an arrival and 'd' for a departure: ";
        cin >> lic;
        //-------------------------------------------------------------------------------------
        
        //-----------------------------------Arrivals------------------------------------------
        
        //-------------------------------------------------------------------------------------
        
        if(lic[0] == 'a')
        {
            if(!(ked.full_queuechar()))
            {
                for(i=1;i<=6;i++)
                    ked.insert_queuechar(lic[i]);
                
                kedcount++;
                cout << "\nNew arrival at Knock Em Dead.\n";
            }
            else if (!(beu.full_queuechar()))
            {
                for(i=1;i<=6;i++)
                    beu.insert_queuechar(lic[i]);
                
                beucount++;
                cout << "\nNew arrival at Bash Em Up.\n";
            }
            else if (!(strt.full_queuechar()))
            {
                for(i=1;i<=6;i++)
                    strt.insert_queuechar(lic[i]);
                
                strtcount++;
                cout << "\nCar is waiting in the street.\n";
            }
            else
                cout << "Everything is full.\n";
        }
        
        //-------------------------------------------------------------------------------------
        
        //--------------------------------Departures-------------------------------------------
        
        //-------------------------------------------------------------------------------------
        
        
        if (lic[0] == 'd')
        {
            found = false;
            checkq.clear_queuechar();
            
            // check if car is in Knockemdead
            
            for(n=1;n<=kedcount;n++)
            {
                match = 0;
                for(i=1;i<=6;i++)
                {
                    ked.delete_queuechar(temp);
                    if(lic[i] == temp)
                        match++;
                    checkq.insert_queuechar(temp);
                }
                
                if(match == 6)
                {
                    cout << "\nDeparture from Knock Em Dead.\n";
                    feerand = rand() % 6;
                    cout << "They were charged a parking fee of $" << fee[feerand] << ".\n";
                    checkq.clear_queuechar();
                    found = true;
                }
                else
                {
                    for(i=1;i<=6;i++)
                    {
                        checkq.delete_queuechar(temp);
                        tempq.insert_queuechar(temp);
                    }
                    tempcount++;
                    checkq.clear_queuechar();
                }
            }
            for(n=1;n<=tempcount;n++)
            {
                for(i=1;i<=6;i++)
                {
                    tempq.delete_queuechar(temp);
                    ked.insert_queuechar(temp);
                }
            }
            if(found == true)
            {
                kedcount--;
                if(!(strt.empty_queuechar()))
                {
                    for(i=1;i<=6;i++)
                    {
                        strt.delete_queuechar(temp);
                        ked.insert_queuechar(temp);
                    }
                    cout << "\nCar waiting in street moved into Knock Em Dead.\n";
                    kedcount++;
                    strtcount--;
                }
            }
            else
                notfound++;
            checkq.clear_queuechar();
            tempq.clear_queuechar();
            found = false;
            tempcount = 0;
            
            // check if car is in bash em up
            for(n=1;n<=beucount;n++)
            {
                match = 0;
                for(i=1;i<=6;i++)
                {
                    beu.delete_queuechar(temp);
                    if(lic[i] == temp)
                        match++;
                    checkq.insert_queuechar(temp);
                }
                
                if(match == 6)
                {
                    cout << "\nDeparture from Bash Em Up.\n";
                    feerand = rand() % 6;
                    cout << "They were charged a parking fee of $" << fee[feerand] << ".\n";
                    checkq.clear_queuechar();
                    found = true;
                }
                else
                {
                    for(i=1;i<=6;i++)
                    {
                        checkq.delete_queuechar(temp);
                        tempq.insert_queuechar(temp);
                    }
                    tempcount++;
                    checkq.clear_queuechar();
                }
            }
            for(n=1;n<=tempcount;n++)
            {
                for(i=1;i<=6;i++)
                {
                    tempq.delete_queuechar(temp);
                    beu.insert_queuechar(temp);
                }
            }
            if(found == true)
            {
                beucount--;
                if(!(strt.empty_queuechar()))
                {
                    for(i=1;i<=6;i++)
                    {
                        strt.delete_queuechar(temp);
                        beu.insert_queuechar(temp);
                    }
                    cout << "\nCar waiting in street moved into Bash Em Up.\n";
                    beucount++;
                    strtcount--;
                }
            }
            else
                notfound++;
            checkq.clear_queuechar();
            tempq.clear_queuechar();
            found = false;
            tempcount = 0;
            
            // Check if car is in street
            
            for(n=1;n<=strtcount;n++)
            {
                match = 0;
                for(i=1;i<=6;i++)
                {
                    strt.delete_queuechar(temp);
                    if(lic[i] == temp)
                        match++;
                    checkq.insert_queuechar(temp);
                }
                
                if(match == 6)
                {
                    cout << "\nDeparture from Street.\n";
                    checkq.clear_queuechar();
                    found = true;
                }
                else
                {
                    for(i=1;i<=6;i++)
                    {
                        checkq.delete_queuechar(temp);
                        tempq.insert_queuechar(temp);
                    }
                    tempcount++;
                    checkq.clear_queuechar();
                }
            }
            for(n=1;n<=tempcount;n++)
            {
                for(i=1;i<=6;i++)
                {
                    tempq.delete_queuechar(temp);
                    strt.insert_queuechar(temp);
                }
            }
            if(found == true)
                strtcount--;
            else
                notfound++;
            checkq.clear_queuechar();
            tempq.clear_queuechar();
            found = false;
            tempcount = 0;
            
            if(notfound == 3)
                cout << "\nCar not found.\n";
        }
        cout << "\nEnter another car? ";
        cin >> ans;
        cout << "\n";
    }while((ans == 'y') || (ans == 'Y'));
    
    cout << "\n";
    cout << "Total number of cars parked in Knock Em Dead is " << kedcount << "\n";
    cout << "Total number cars parked in Bash Em Up is " << beucount << "\n";
    cout << "Total number of cars waiting in the street is " << strtcount << "\n";
    cout << "\n";
    for(n=1;n<=kedcount;n++)
    {
        cout << "Car number " << n << " in Knock Em Dead has License Number: ";
        for(i=1;i<=6;i++)
        {
            ked.delete_queuechar(temp);
            cout << temp;
        }
        cout << "\n";
    }
    
    for(n=1;n<=beucount;n++)
    {
        cout << "Car number " << n << " in Bash Em Up has License Number: ";
        for(i=1;i<=6;i++)
        {
            beu.delete_queuechar(temp);
            cout << temp;
        }
        cout << "\n";
    }
    
    for(n=1;n<=strtcount;n++)
    {
        cout << "Car number " << n << " in the street has License Number: ";
        for(i=1;i<=6;i++)
        {
            strt.delete_queuechar(temp);
            cout << temp;
        }
        cout << "\n";
    }
    cout << "\n";
}


void queuechar_type::clear_queuechar()
{
    frontch = maxqueuechar;
    rearch = maxqueuechar;
}
//----------------------------------------------------------------------
bool queuechar_type::empty_queuechar()
{
    if (rearch == frontch)
        return true;
    else
        return false;
}
//----------------------------------------------------------------------
bool queuechar_type::full_queuechar()
{
    int querear;
    if (rearch == maxqueuechar)
        querear = 0;
    else
        querear = rearch + 1;
    if (querear == frontch)
        return true;
    else
        return false;
}
//----------------------------------------------------------------------
void queuechar_type::insert_queuechar(char ch)
{
    if (rearch == maxqueuechar)
        rearch = 0;
    else
        rearch = rearch + 1;
    queuechar[rearch] = ch;
}
//----------------------------------------------------------------------
void queuechar_type::delete_queuechar(char& ch)
{
    if (frontch == maxqueuechar)
        frontch = 0;
    else
        frontch = frontch + 1;
    ch = queuechar[frontch];
}

    

