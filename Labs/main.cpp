#include <iostream>
#include <string>
using namespace std;

// setting array size
const int arraySize = 3;

// function prototypes
bool IsSentence(const string& str);
string Capitalize(const string& str);

int main() {

    // creating testing array with "sentences"
    string test[arraySize]{ "This is a valid sentence.","this is not a sentence","Is this a valid sentence?" };

    // for loop that runs IfSentence test
    for (int i = 0; i < arraySize; i++) {
        if (IsSentence(test[i]) == true) {
            cout << "String " << i + 1 << " is true!" << endl;
        } else {
            cout << "String " << i +1 << " is false!" << endl;
        }

    }
    
    cout << endl;

    // for loop that takes true values on IfSentences
    // and capatalizes the first letter in every word
    for (int i = 0; i < arraySize; i++) {
        cout << Capitalize(test[i]) << endl;
    }
}

//function definitions

// tests if the string is a sentence
bool IsSentence(const string& str) {
    if (str.empty()) {
        return false;
    }

    char firstChar = str[0];
    char lastChar = str[str.length() - 1];
    
    bool startsWithUppercase = (firstChar >= 'A' && firstChar <= 'z');
    bool endsWithpuncuation = (lastChar == '.' || lastChar == '?' || lastChar == '!');

    return startsWithUppercase && endsWithpuncuation;
}

// function that takes true values on IsSentences
// and returns a capitalized version of the string
string Capitalize(const string& str) {
    if (!IsSentence(str)) {
        return "";
    }

    string result = str;
    bool capitalizeNext = true;

    for (size_t i = 0; i < result.length(); i++) {
        if (capitalizeNext && isalpha(result[i])) {
            result[i] = toupper(result[i]);
            capitalizeNext = false;
        } else {
            result[i] = tolower(result[i]);
            }
        if (result[i] == ' ') {
            capitalizeNext = true;
        }
    }
    return result;
}


