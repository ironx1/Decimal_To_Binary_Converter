#include <iostream>
#include <string>

using namespace std;

int *decToBin(int);
int decimalToBinary(int);

int main(int argc, char const *argv[])
{
    cout << "#############################" << endl;
    cout << "#Decimal To Binary Converter#" << endl;
    cout << "#          ironx1           #" << endl;
    cout << "#############################" << endl;
    bool _bool = true;
    while (_bool)
    {
        int choice;
        int num;
        cout << "1.\tConvert Dec to Bin\n2.\tExit\nChoice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        error:
            cout << "Enter the Number You Want to Convert: ";
            cin >> num;
            if (num < 0 || num > 255)
            {
                cout << "The entered value cannot be less than 0 and greater than 255!" << endl;
                goto error;
            }
            cout << "(" << num << ")"
                 << "(10)= " << decimalToBinary(num) << "(2)" << endl;
            break;
        case 2:
            _bool = false;
            break;
        default:
            cout << "Incorrect Entry!" << endl;
            break;
        }
    }

    return 0;
}

int *decToBin(int Val)
{
    static int Bit[8];
    int i = 7;
    while (Val > 0)
    {
        int Binary = Val % 2;
        Val /= 2;
        Bit[i] = Binary;
        i--;
    }
    return Bit;
}

int decimalToBinary(int val)
{
    int *ptr = decToBin(val);
    string strVal = "";
    string strArr[8] = {""};
    for (int i = 0; i < 8; i++)
    {
        strArr[i] = to_string(ptr[i]);
        strVal.append(strArr[i]);
    }
    int binNum = stoi(strVal);
    return binNum;
}