#include <iostream>
using namespace std;

bool isNumeric(string str)
{
    if (str.length() == 0)
        return false;

    for (int i = 0; i < str.length(); i++)
    {
        
        if (str[i] < 48 || str[i] > 57)
            return false;
    }

    return true;
}


bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=')
        return true;

    return false;
}

void findOperators(string input)
{
    int count = 0;

    for (int i = 0; i < input.length(); i++)
    {
        if (isOperator(input[i]))
        {
            count++;
            cout << "operator" << count << ": " << input[i] << endl;
        }
    }

    if (count == 0)
        cout << "No operator found." << endl;
}

void checkComment(string input)
{

    if (input.length() >= 2 &&
        input[0] == '/' && input[1] == '/')
    {
        cout << "Single Line Comment" << endl;
    }

    else if (input.length() >= 4 &&
             input[0] == '/' && input[1] == '*' &&
             input[input.length() - 2] == '*' &&
             input[input.length() - 1] == '/')
    {
        cout << "Multiple Line Comment" << endl;
    }

    else
    {
        cout << "Not a Comment" << endl;
    }
}


bool isIdentifier(string str)
{
    if (str.length() == 0)
        return false;

    if (!((str[0] >= 'A' && str[0] <= 'Z') ||
          (str[0] >= 'a' && str[0] <= 'z') ||
          str[0] == '_'))
    {
        return false;
    }

    for (int i = 1; i < str.length(); i++)
    {
        if (!((str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= 'a' && str[i] <= 'z') ||
              (str[i] >= '0' && str[i] <= '9') ||
              str[i] == '_'))
        {
            return false;
        }
    }

    return true;
}


int main()
{
    string input;

    
    cout << " Numeric Constant" << endl;
    cout << "Enter input: ";
    cin >> input;

    if (isNumeric(input))
        cout << "Numeric Constant" << endl;
    else
        cout << "Not Numeric" << endl;


    cout << " Operators " << endl;
    cout << "Enter expression: ";
    cin >> input;

    findOperators(input);


    cout << " Comment " << endl;
    cin.ignore();

    cout << "Enter comment: ";
    getline(cin, input);

    checkComment(input);


    cout << " Identifier" << endl;
    cout << "Enter input: ";
    cin >> input;

    if (isIdentifier(input))
        cout << "Identifier" << endl;
    else
        cout << "Not an Identifier" << endl;

    return 0;
}