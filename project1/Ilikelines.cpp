#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

vector<char> grid;
vector<int> BMB, players_moves;
bool END = false;
void Set_space(int n);
void Display_Grid(int n);
void selection(int n);
void random_genrator(string mode);
void checker();
int main(){
    string type;
    cout << "please chose a gird option" << endl;
    cout << "1) 5 by 5" << endl;
    cout << "2) 7 by 7 " << endl;
    cout << "3) 10 by 10 " << endl;
        do{
            cout << "Selection : ";
            getline(cin, type);
            if(type[0] >= '1' && type[0] <= '3'){
                break;
            }
            cout << "Invalid selection" << endl;
        }while(true);
    system("cls");
    cout << '\n' << '\n' << '\n' << '\n' << endl;
    bool set = false;
    do{
    if(type[0] == '1'){
        Set_space(5);
        if(!set){
            random_genrator("easy");
            set = true;
        }
        Display_Grid(5);
        cout << endl;
        selection(5);
        system("cls");
    }else if(type[0] == '2'){
        Set_space(7);
        if(!set){
            random_genrator("easy");
            set = true;
        }
        Display_Grid(7);
        cout << endl;
        selection(7);
        system("cls");
        Display_Grid(7);
    }else{
        Set_space(10);
        if(!set){
            random_genrator("easy");
            set = true;
        }
        Display_Grid(10);
        cout << endl;
        selection(10);
        system("cls");
        Display_Grid(10);
    }
    }while(true);
    return 0;
}
void Set_space(int n){
    for(int a = 0; a < n*n; a++){
        grid.push_back(' ');
    }
}



void selection(int n)
{
    string column, row, in_case_of_10;
    int row_num = 0;
    back:
    cout << " pick column(from A-" << 'A'+n << ") :";
    getline(cin, column);
    if((column[0] <'A' || column[0] > 'A'+n) && (column[0] < 'a' || column[0] > 'a'+n))
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
    char choice = column[0];
    int v;
    if(column[0] >= 'A' && column[0] <= 'A' + n){
        v = choice - 64;
    }else{
         v = choice - 91;
         row_num--;
    }
        players_moves.push_back(((n*(row_num-1)+v))-1);
        checker();
}

void checker(){
    bool BOMB = false;
    int n = players_moves[players_moves.size() - 1];
    for(int a = 0; a < BMB.size(); a++){
        if(n == BMB[a]){
            BOMB = true;
            break;
        }
    }
    if(BOMB){
        for(int a = 0; a < BMB.size(); a++){
            grid[BMB[a]] = 'X';
        }
        END = true;
    }else{
        grid[n] = 'O';
    }
}

void Display_Grid(int n){
    int b = 1;
    cout << setw(62);
    for(char alph = 'A'; alph < 'A' + n; alph++){
        cout << alph << setw(4);
    }
    for(int a = 0; a < n*n; a++){
        if(a%n == 0){
            cout << endl;
            cout << setw(60);
                for(int b = 0; b < 4*n +1; b++){
                    cout << "-";
                }
            cout << '\n' << setw(58) << b << " | ";
            b++;
            }
        cout << grid[a] << " | ";
    }
    cout << endl;
    cout << setw(60);
    for(int b = 0; b < 4*n +1; b++){
                    cout << "-";
                }
}

void random_genrator(string mode){
    int range;
    if(mode == "Easy" || mode == "easy"){
        range = grid.size() * 0.25;
    }else if(mode == "Medium" || mode == "medium"){
        range = grid.size() * 0.5;
    }else if(mode == "Hard" || mode == "hard"){
        range = grid.size() * 0.75;
    }
    for(int a = 0; a < range; a++){
        srand(static_cast<unsigned>(time(0)));
        redo:
        int r = rand() % grid.size();
        
        if(!(BMB.empty())){
            for(int b = 0; b < BMB.size(); b++){
                if(r  == BMB[b]){
                    goto redo;
                }
            }
        }
        BMB.push_back(r);
    }
    for(int a = 0; a < BMB.size(); a++){
        cout << BMB[a] << " ";
    }   
    cout << endl; 

}