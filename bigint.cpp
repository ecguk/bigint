#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void addNumbers(const char* num1, const char* num2) {
    int carry = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxSize = std::max(len1, len2);
    char result[maxSize + 2]; 

    int idx = 0;
    for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry; i--, j--) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result[idx++] = '0' + (sum % 10);
        carry = sum / 10;
    }

    for (int i = idx - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;
}

void subtractNumbers(const char* num1, const char* num2) {
    int borrow = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxSize = max(len1, len2);
    char result[maxSize + 1]; 

    int idx = 0;
    for (int i = len1 - 1, j = len2 - 1; i >= 0; i--, j--) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[idx++] = '0' + diff;
    }

    bool leadingZero = true; 
    for (int i = idx - 1; i >= 0; i--) {
        if (result[i] != '0' || !leadingZero) {
            cout << result[i];
            leadingZero = false;
        }
    }
    if (leadingZero) cout << '0'; 
    cout << endl;
}

int main() {
    string num1, num2;
    cout << "First number  >> ";
    cin>> num1;
    cout << "Second number >> ";
    cin >> num2;
    cout << "Sum           >> ";
    addNumbers(num1.c_str(), num2.c_str());

    cout << "Sub           >> ";
    subtractNumbers(num1.c_str(), num2.c_str());

    return 0;
}