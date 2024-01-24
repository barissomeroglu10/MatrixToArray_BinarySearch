/*
In this code we will convert 2x2 matrix to an array and use binary search to find an element which user entered.
Of course we must sort array firstly. I used bubble sort for it.

Developer: Barış Someroğlu
Date: 24.01.2024 / 8:00 p.m.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int A[2][2], B[4], ara;

    // get value from user
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Please Enter A[" << i << "][" << j << "]: ";
            cin >> A[i][j];

            B[i * 2 + j] = A[i][j]; // here is important
        }
    }

    // use bubble sort
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (B[j + 1] < B[j])
            {
                swap(B[j], B[j + 1]);
            }
        }
    }

    cout << endl;

    // write sorted array
    cout << "Sorted Array is: ";
    for (int i = 0; i < 4; i++)
    {
        cout << B[i] << " ";
    }

    cout << endl;

    // get search element from user
    cout << "Please Enter Element You Want to Find: ";
    cin >> ara;

    // use binary search
    int ilk = 0, son = 3, k = 0, orta;

    while (ilk < son && k != 1)
    {
        orta = (ilk + son) / 2;

        if (ara < B[orta])
        {
            son = orta - 1;
        }
        else if (ara > B[orta])
        {
            ilk = orta + 1;
        }
        else
        {
            k = 1;
        }
    }

    cout << endl;

    if (k == 1)
    {
        cout << "Your Searching Element at " << orta << ". Index" << endl;
    }
    else
    {
        cout << "There is no Searching Element!" << endl;
    }

    return 0;
}
