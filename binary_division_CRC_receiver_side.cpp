//RECEIVER SIDE
#include<iostream>
using namespace std;

int n, m, i, j, k, flag=0, temp[50];
int d[50], g[50], codeword[50];

// Define a function to perform division (CRC Receiver side)
void div(int d[], int g[])
{
    cout<<endl<<"DIVIDING DATA BY g(x)"<<endl<<endl;

    // Copying data to temporary array
    for(int i=0;i<j;i++)
    {
        temp[i]=d[i];
    }

    // Perform division
    for(int i=0;i<j-m+1;i++)
    {
        int k=0;
        int z=i;
        // Checking if the first bit matches the polynomial's first bit
        if (temp[i] == g[0])
        {
            // Performing XOR operation for division
            while (k < m)
            {
                temp[z] = temp[z] == g[k] ? 0 : 1;
                z++;
                k++;
            }
        }
        else
        {
            // Shifting and performing XOR operation
            while (k < m)
            {
                temp[z] = temp[z] == 0 ? 0 : 1;
                z++;
                k++;
            }
        }

    }

    cout<<"REMAINDER: ";
        for(int a=j-4;a<j;a++)
        {
            cout<<temp[a];
        }
        cout<<endl;


    for(i=0;i<j;i++)
    {
        if (temp[i] == 1)
        {
            flag = 1; // Setting flag to indicate error
        }
    }

      // Displaying result based on flag
    if (flag == 1)
    {
        cout << "CODEWORD CONTAINS ERROR" << endl;
    }
    else
    {
        cout<<"CODEWORD DOES NOT CONTAINS ERROR"<<endl;

        // Display the codeword
        cout<<"CODEWORD: ";
        for(int i=0;i<n-(m-1);i++)
        {
            cout<<d[i];
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"Enter the number of bits in the codeword: ";
    cin>>n;

    cout<<"Enter the codeword: ";
    for(int i=0;i<n;i++)
    {
        cin>>d[i];
    }



    cout<<"Enter the number of bits in g(x): ";
    cin>>m;

    cout<<"Enter the bit in g(x): ";
    for (int i=0;i<m; i++)
    {
        cin>>g[i];
    }
    cout<<endl;
    cout<<endl;

    cout<<"Entered data is: ";
    for(int i=0;i<n;i++)
        {
            cout<<d[i];
        }
        cout<<endl;

     cout<<"Entered g(x) is: ";
    for(int i=0;i<m;i++)
        {
            cout<<g[i];
        }
        cout<<endl;

    j = n+m - 1; // Size of the temp array
    for(int i=0;i<j;i++)
    {
        temp[i]=0;
    }

    div(d, g); // Calling the division function
    cout << endl;

    return 0;
}
