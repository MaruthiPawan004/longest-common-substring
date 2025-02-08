#include <iostream>
#include <vector>
#include <string>
using namespace std;


string longestCommonSubstring(string str1, string str2) {
    int len1 = str1.length();
    int len2= str2.length();

    vector<vector<int>> dp(len1, vector<int>(len2, 0));
    int maxLen = 0;
    int endIndexOfStr1 = 0;

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) { 
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndexOfStr1 = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    int startIndexOfStr1 = endIndexOfStr1 - maxLen + 1;
    return str1.substr(startIndexOfStr1, maxLen);
}

int main() {
    string str1, str2;

    
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;
    while(str1.length() != str2.length())
    {
        cout << "Error: Strings must be of equal length." << endl;
        cout << "Enter the first string: ";
        cin >> str1;
        cout << "Enter the second string: ";
        cin >> str2;

    }   
    string result = longestCommonSubstring(str1, str2);   
    cout << "The Resultant Longest Common Substring: " << result << endl;
    return 0;
}