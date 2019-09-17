#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <list>
#include <set>
#include <stack>

using namespace std;


int similarity(string text, string pattern, int maxNumberOfMismatches, int startPosition) {

    for(int i = startPosition; i < text.length() - pattern.length(); i++) {
        int mismatchCounter = maxNumberOfMismatches;
        for(int j = 0; j < pattern.length(); j++) {
            if(mismatchCounter < 0) {
                break;
            }
            if(text[i + j] != pattern[j]) {
                mismatchCounter--;

            }
           if(j == pattern.length() - 1 && mismatchCounter >= 0){
                return i;
            }
        }

    }
    return -1;
}

int sim(string text, string patter, int maxNumOfMis, int startPosition) {
    int pSize = patter.length();
    int mSize = text.length();
    cout << pSize << endl;


    for(int i = 0; i < mSize - pSize;  i++) {
        for(int j = 0; j < pSize; j++) {
            if(text[i + j] != patter[j] )
                break;

            if( j == pSize -1)
               return i;


        }
    }
    return -1;
}


int main()
{
    string text =    "GDFGHJFFGJ";
    string pattern = "FGH";
    int maxMismacht = 0;
    int startPos = 0;
    int result;

    int result2 = similarity(text, pattern, maxMismacht, startPos);
    cout<<"Your match starts at: " << result2 << endl;
    cout << sim(text, pattern, maxMismacht, startPos) <<endl;

    return 0;
}
