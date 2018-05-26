
#include<iostream>
#include<ios>
#include<iomanip>

using namespace std;

int getLength(int n )
{
    if(n == 0) return 1;
    int max = n * n;
    int length = 0;
    while(max > 0){
        max = max/10;
        length++;
    }
    return length;
}

int main()
{
    cout << "This program computes squares up to and including n. "
         << "Please enter n ";
    
    int n;
    cin >> n;
    const int limit = n;

    const int padding = 10;
    
    const int sec_col = getLength(limit * limit) + padding;

    for(int i = 0; i <= limit; ++i){
        int len = getLength(i);
        int spaces = sec_col;
        int square = i * i;
        cout << i <<  setw(spaces) << square << endl;
    }

    return 0;


}
