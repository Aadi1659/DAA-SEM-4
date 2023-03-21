/*
horsepool algorithm
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> shiftTable(vector<char> myChar);
int horsepool(vector<char> pattern, vector<char> text);

int main() {
    string textString, patternString;
    cout << "Enter text: ";
    getline(cin, textString);
    cout << "Enter pattern: ";
    getline(cin, patternString);

    vector<char> text(textString.begin(), textString.end());
    vector<char> pattern(patternString.begin(), patternString.end());

    int result = horsepool(pattern, text);
    
    if (result == -1) {
        cout << "Pattern not found in text." << endl;
    } else {
        cout << "Pattern found at index " << result << endl;
    }
    
    return 0;
}

vector<int> shiftTable(vector<char> myChar){
    vector<int> answer(256,myChar.size());
    int patternSize = myChar.size();
    for (int j = 0; j < patternSize; j++) answer[(int)myChar[j]] = patternSize-j-1;
    return answer;
}

int horsepool(vector<char> pattern, vector<char> text){
    vector<int> myShiftTable = shiftTable(pattern);
    int patternSize = pattern.size();
    int textSize = text.size();
    if (patternSize > textSize) return -1;
    int i = patternSize - 1;
    while (i<textSize)
    {
        int k = 0;
        while ((k<=patternSize-1) && (pattern[patternSize-1-k] == text[i-k])) k++;
        if (k==patternSize) return i-patternSize+1;
        else i = i + myShiftTable[(int)text[i-patternSize+1]];
    }
    return -1; 
}
