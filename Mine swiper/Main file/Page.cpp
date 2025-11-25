#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip> 
using namespace std;

struct info{
    string name, score;
};

void Print_Logo();
void Player_info_display(string name);

int main(){
    Print_Logo();
    cout << '\n' << '\n' << endl;
    Player_info_display("Abel");
    return 0;
}

void Print_Logo(){
    ifstream p_out;
    string i;
    p_out.open("Logo.txt");
    while(getline(p_out,i)){
        cout << i << endl;;
    }
    p_out.close();
}

void Player_info_display(string name){
    info p1;
    ifstream p_out, player;
    player.open(name);
    string s;
    int b = 0;
    while(getline(player,s)){
        b++;
        if(b == 1){
            p1.name = s;
        }else{
            p1.score = s;
        }
    }
    player.close();
    string i, j;
    int a = 0;
    player.open(name);
    p_out.open("PlayerICOM.txt");
    while(getline(p_out,i) || getline(p_out, j)){
        a++;
        if(a == 18){    
            cout << i << setw(33) << "# Player :: " << p1.name << setw(35) << "# Score :: " << p1.score << endl;
        }else{
            cout << i << endl;
        }
    }
    player.close();
    p_out.close();
}