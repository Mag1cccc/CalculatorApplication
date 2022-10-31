#include <iostream>
using namespace std;

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
}

int romanToDecimal(string& str)
{
    int res = 0;

    for (int i = 0; i < str.length(); i++)
    {

        int s1 = value(str[i]);

        if (i + 1 < str.length())
        {

            int s2 = value(str[i + 1]);


            if (s1 >= s2)
            {

                res = res + s1;
            }
            else
            {

                res = res + s2 - s1;
                i++;
            }
        }
        else {
            res = res + s1;
        }
    }
    return res;
}

string decimalToRoman(int num) {
    string roman = "";
    int decimal[] = { 100,90,50,40,10,9,5,4,1 };
    string symbol[] = { "C","XC","L","XL","X","IX","V","IV","I" };
    int i = 0;

    while (num) {
        while (num / decimal[i]) {
            roman += symbol[i];
            num -= decimal[i];
        }
        i++;
    }
    return roman;
}

string romanCalculator() {
    cout << " - - - Roman Calculator - - -\n";
    string number;
    string operand;
    int result = 0;

    while (true) {

        cout << "Input Operand:\t";
        cin >> operand;

        if (number == "exit" || operand == "exit") {
            break;
        }

        cout << "Input Roman Number:\t";
        cin >> number;

        if (number == "exit" || operand == "exit") {
            break;
        }
        if (operand == "+") {
            result += romanToDecimal(number);
            cout << result;
        }
        if (operand == "-") {
            result -= romanToDecimal(number);
            cout << result;
        }
        if (operand == "*") {
            result *= romanToDecimal(number);
            cout << result;
        }
        if (operand == "/") {
            result /= romanToDecimal(number);
            cout << result;
        }
        if (number == "exit" || operand == "exit") {
            break;
        }
        if (result < 0) {
            return "Error";
        }
    }

    return decimalToRoman(result);
}

int main()
{
    string result = romanCalculator();
    cout << result;

    return 0;
}




