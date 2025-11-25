#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;
void selection();

int main()
{
    selection();
}


void selection()
{
    string column, row, in_case_of_10;
    int row_num = 0;
    back:
    cout << " pick column(from A-J): ";
    getline(cin, column);
    if((column[0] <'A' || column[0] > 'A'+10) && (column[0] < 'a' || column[0] > 'a'+10))
    {
        system("cls");
        cout << "Invalid selection" <<endl;
        goto back;
    }
    back2:
    cout << "Enter in a row (from 1-10) : ";
    getline(cin, row);
    if((row[0] <'1' || row[0] > '9'))  
    {   
        system("cls");
        cout << "Invalid selection" <<endl;
        goto back2;
    }
    if(row.length() >= 2)
    {
        if(row[0] == '1' && row[1] == '0')
        {
            in_case_of_10 = row[0];
            row_num = (row_num*10) + stoi(in_case_of_10);
            in_case_of_10 = row[1];
            row_num = (row_num*10) + stoi(in_case_of_10);
        }
        else
        {
            row = row[0];
            row_num = stoi(row);
        }
        cout << "you are a bitch for pickng more than 10!!!\n";
    }
    else
    {
        row_num = stoi(row);
    }

    cout << "selected position is: " << column[0] << row_num;
}