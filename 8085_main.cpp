#include "all.h"
#include "opcode.h"
#include "inputs.h"
#include "run.h"
#include "compiler.h"

using namespace std;

int main()
{
    int ch = 1;
    cout << "Enter 1 to type the code \n2 to get code from file \n3 to exit \n";
    cin >> ch;
    if(ch == 1) get_code_write();
    else if(ch == 2)
    {
        cout << "Enter file name \n";
        string temp;
        cin >> temp;
        get_code_file(temp);
    }
    else
    {
        cout << "Thank You\n";
        return 0;
    }
    compile();
    cout << "Enter 1 to run in debugger mode 2 to run in normal mode \n";
    cin >> ch;
    if(ch == 1) debugger();
    else if(ch == 2)
    {
        non_debugger();
    }
    else
    {
        cout << "WRONG CHOICE";
        return 0;
    }
    display();
}
