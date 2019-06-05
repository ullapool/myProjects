#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <list>
#include <set>
#include <stack>

using namespace std;

int similaritySearch(string t, string p, int maxNumberOfMismatches, int startPosition) {

    // create lookup table
    map<char, long> lookuptable;
    // fill up table

    for (int i = 0; i < p.size() - 1; i++) {
        lookuptable[p.at(i)] = p.size() - 1 - i;
    }
  //  for(auto &it : lookuptable) {
  //      cout<<it.first<<" : "<<it.second<<endl;
  //  }

    int startIndex = startPosition;
    int pIndex = p.size() - 1;
    while (startIndex <= t.size() - p.size()) {
      // compare from right
      int tIndex = startIndex + pIndex;
      char pCh = p.at(pIndex);
      char tCh = t.at(tIndex);
      if (pCh != tCh) {
        int shift;
        // if not in table -> shift pattern.size()
        if (lookuptable.find(tCh) != lookuptable.end()) {
          shift = lookuptable[tCh];
        } else { // Falls Buchstabe aus Text nicht im Pattern vorkommt
          shift = p.size();
        }
        pIndex = p.size() - 1;
        startIndex += shift;
      }
      else {
          if (pIndex == 0) {
              // Falls alle Stellen des Patterns übereinstimmten
              return startIndex;
          }
        pIndex--;
      }
    }
    return -1;
  }


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
           if(j == pattern.length()- 1 && mismatchCounter >= 0){
                return i;
            }
        }

    }
    return -1;
}


int main()
{
    string text = "GDFGHJFFGJ";
    string pattern = "FGH";
    int maxMismacht = 1;
    int startPos = 0;
    int result;

    result = similaritySearch(text, pattern, maxMismacht, startPos);
    cout<<"Your match starts at: " << result << endl;

    int result2 = similarity(text, pattern, maxMismacht, startPos);
    cout<<"Your match starts at: " << result2 << endl;
    return 0;
}
