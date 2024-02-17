//SENDER SIDE
#include<iostream>
using namespace std;

int n, m;
int d[50], g[50], codeword[50];

// Define a function to perform division (CRC Sender side)
void div(int d[], int g[])
{
    // Calculate the size of the dividend
    int j=n+(m - 1);
    int temp[50];

    // Append zeros at the end of the data
    for (int i=n;i<j;i++)
        {
            d[i]=0;
        }

    // Print the updated data with appended zeros
    cout<<"APPENDING ZEROS AT THE END OF THE DATA: ";
    for (int i=0;i<j;i++)
        {
            cout<<d[i];
        }

     // Copy the original data to the temporary array
    cout<<endl<<endl<<"DIVINDING UPDATED DATA BY g(x)"<<endl;

    for (int i=0;i<j;i++)
        {
            temp[i]=d[i];
        }

    // Perform division
    for(int i=0; i<j-m+1;i++)
        {
            int k=0;
            int z=i;

           // Checking if the first bit matches the polynomial's first bit
        if(temp[i] == g[0])
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

    cout<<endl<<"CRC obtained is: ";
    for (int i=n;i<j;i++)
        {
            cout<<temp[i];
        }

     // Copy original data bits to codeword
    for(int i=0;i<n;i++)
        {
            codeword[i]=d[i];
        }

    for (int i=n;i<j;i++)
        {
            codeword[i]=temp[i];
        }

     // Print the codeword (original data bits + CRC bits)
    cout<<endl<<"CODEWORD: ";
    for (int i=0;i<j;i++)
        {
            cout<<codeword[i];
        }
}

int main()
{
    cout<<"Enter the number of bits in the data stream: ";
    cin>>n;

    cout<<"Enter the bit stream transmitted for data: ";
    for(int i=0;i<n;i++)
        {
            cin>>d[i];
        }

    cout<<"Enter the number of bits in g(x): ";
    cin>>m;

    cout<<"Enter the bit in g(x): ";
    for(int i=0;i<m; i++)
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
     // Call the division function to perform CRC
    div(d, g);
    cout<<endl;

    return 0;
}
