#include <iostream>
using namespace std;
bool put(int ar[9][9],int r,int c,int n)
{
    for(int i=0; i<9; i++)
        if(ar[r][i]==n)
            return false;

    for(int i=0; i<9; i++)
        if(ar[i][c]==n)
            return false;

    int ro=r-r%3;
    int co=c-c%3;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(ar[ro+i][co+j]==n)
                return false;

    return true;
}
void print(int ar[9][9])
{
    cout<<endl<<"The solved sudoku is : "<<endl;
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
            cout << ar[i][j] << " ";
        cout << endl;
    }
}
bool solve(int ar[9][9], int r, int c)
{
    if (r == 8 && c == 9)
        return true;

    if (c == 9)
    {
        r++;
        c = 0;
    }
    if (ar[r][c] > 0)
        return solve(ar, r, c + 1);

    for (int i = 1; i <= 9; i++)
    {
        if (put(ar, r, c, i))
        {
            ar[r][c] = i;

            if (solve(ar, r, c + 1))
                return true;
        }

        ar[r][c] = 0;
    }
    return false;
}
int main()
{
    int ar[9][9]= {0};
    cout<<"Enter the sudoku elements and input 0 in place of blank spaces : "<<endl;

    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            cin>>ar[i][j];

    if (solve(ar, 0, 0))
        print(ar);
    else
        cout << "no solution  exists " << endl;
    return 0;
}
