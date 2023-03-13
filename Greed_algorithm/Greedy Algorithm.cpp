#include <iostream>

using namespace std;


int num;

int main()

{
    while (true)
    {
        int change = 0;
        int inc =0;
        cout << "Enter Number: ";
        cin >> num;
        while (change <= num)
        {
            if((change+50) <= num)
            {
                cout << 50 << "\t";
                inc = 50;
            }
            else if((change+25) <= num)
            {
                cout << 25 << "\t";
                inc = 25;
            }
            else if((change+10) <= num)
            {
                cout << 10 << "\t";
                inc = 10;
            }
            else if((change+5) <= num)
            {
                cout << 5 << "\t";
                inc = 5;
            }
            else if((change+1) <= num)
            {
                cout << 1 << "\t";
                inc = 1;
            }

            change += inc;
            cout << endl;
        }
        
    }
    
      
}