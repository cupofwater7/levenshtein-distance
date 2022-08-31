#include <iostream>
#include <vector>


using namespace std;
int levenshteinDistance(string str1, string str2);


int main()
{
    cout << levenshteinDistance("abc", "yabd") <<  " ";
    return 0;
}

int levenshteinDistance(string str1, string str2) {
    // Write your code here.

    string small = str1.length() < str2.length() ? str1 : str2;
    string big = str1.length() >= str2.length() ? str1 : str2;
    vector<int> evenEdits(small.length() + 1);
    vector<int> oddEdits(small.length() + 1);

    for (int j = 0; j < small.length() + 1; j++)
    {
        evenEdits[j] = j;
    }

    vector<int>* currentEdits;
    vector<int>* previousEdits;

    for (int i = 1; i < big.length() + 1; i++)
    {
        if (i % 2 == 1)
        {
            currentEdits = &oddEdits;
            previousEdits = &evenEdits;
        }
        else
        {
            currentEdits = &evenEdits;
            previousEdits = &oddEdits;
        }
        (*currentEdits)[0] = i;
        for (int j = 1; j < small.length() + 1; j++)
        {
            if (big[i - 1] == small[j - 1])
            {
                (*currentEdits)[j] = previousEdits->at(j - 1);
            }
            else
            {
                (*currentEdits)[j] = 1 + min(previousEdits->at(j - 1)
                    , min(previousEdits->at(j), currentEdits->at(j - 1)));
            }
        }

    }
    return big.length() % 2 == 0 ? evenEdits[small.length()] : oddEdits[small.length()];
}
