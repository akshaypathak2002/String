/*
In this we have to return the longest common prefix. That means we are given the words in a vector.
strs=["flower","flow","flight"]
Here our answer is fl.
Algorithm:
step-1: Find the minimum length of all given words. And store them in the variable.
step-2: Run a loop till the minimum length of the word we found . That is outer loop.
step-3: And then compare each character of the word1 till minimum length with the character at that position
of each string .
*/
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
class Solution
{
private:
    int n;
    vector<string> strs;

public:
    Solution()
    {
        cout << "Enter the number of words you want in array " << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            strs.push_back(str);
        }
    }
    int minLength()
    {
        int res = INT_MAX;
        for (int i = 0; i < strs.size(); i++)
        {
            int len = strs[i].length();
            res = min(res, len);
        }
        return res;
    }
    string sln()
    {
        int minLen = minLength();
        string res = "";
        for (int i = 0; i < minLen; i++)
        {
            char ch = strs[0][i]; // Taking character from the frist string
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] != ch)
                    return res; // return the result
            }
            res += ch;
        }
        return res;
    }
};

int main()
{
    Solution *s1 = new Solution(); // creating the instance of the object
    cout << s1->sln() << endl;
    return 0;
}