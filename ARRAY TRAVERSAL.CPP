#include<iostream>
using namespace std;
int main()
{ 
    int n,m;
    cout<<"enter the no.of rows:";
    cin>>n;
    cout<<"enter the no. of columns:";
    cin>>m;
    int arr[n][m];//DECLARING 2D ARRAY
    // ENTERING THE ARRAY ELEMENTS
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
          cout<<endl;
    }
    //DISPLAYING THE RESULTANT ARRAY ELEMENTS
    cout<<"THE RESULTANT ARRAY:"<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}