#include<bits/stdc++.h>

using namespace std;

#define mnemonic second.first
#define reg1 second.second.first
#define reg2 second.second.second
#define addr first

vector <pair <string , pair < string , pair < string , string > > > > code(100);

vector <string> registers(13);
bool ZF = 0, SF = 0, AC = 0, P = 0, C = 0;
int starting_address = 0 , length = 0;
vector <string> memory(29000);
map <string,int> mapp;
vector <string> a;

int hexToDec(string str)
{
    int y;
    stringstream stream;
    stream << str;
    stream >> hex >> y;
    return y;
}
string decToHex(int num)
{

    stringstream stream;
    stream << hex << num;
    return (stream.str());
}

void check_FF(string str,int i)
{
    int data = hexToDec(str);
    if(data > 256)
    {
        cout << "DATA GREATER THAN FF at line " << i;
        exit(0);
    }
}

void setflags(char c)
{
    int data = hexToDec(registers[c - 'A']);
    if(data == 0) ZF = 1;
    else ZF = 0;
    if(data > 256)
    {
        C = 1;
        registers[c - 'A'] = decToHex(data - 256);
    }
    else C = 0;
    if(data < 0) SF = 1;
    else SF = 0;
}

void display()
{
    cout << "Value of register A is " << registers[0] << "\n";
    cout << "Value of register B is " << registers[1] << "\n";
    cout << "Value of register C is " << registers[2] << "\n";
    cout << "Value of register D is " << registers[3] << "\n";
    cout << "Value of register E is " << registers[4] << "\n";
    cout << "Value of register H is " << registers[7] << "\n";
    cout << "Value of register L is " << registers[11] << "\n";
    cout << "\n";
    cout << "Value of Zero Flag is " << ZF << "\n";
    cout << "Value of Sign Flag is " << SF << "\n";
    cout << "Value of Parity Flag is " << P << "\n";
    cout << "Value of Carry Flag is " << C << "\n";
    cout << "Value of Auxillary Carry Flag is " << AC << "\n";
    cout << "\n";
    for(int i = 0; i < a.size(); i++)
    {
        cout << "Value at memory location " << a[i] << " is " << memory[hexToDec(a[i])] << "\n";
    }
}
