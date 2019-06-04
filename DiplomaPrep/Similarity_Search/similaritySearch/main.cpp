#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <list>
#include <set>
#include <stack>

using namespace std;

int similaritySearch(string text, string pattern, int maxNumberOfMismatches, int startPosition) {
   map<char, int> lookUpTable;

   //for(int i = 0; i < pattern.size(); i++) {
   for(int i = pattern.size() -1; i >= 0; i--){
       lookUpTable[pattern[i]] = pattern.size() -1 -i;
   }

//   for(auto &it : lookUpTable){
//       cout<<it.first<< " : "<<it.second<<endl;
//   }
   int startIndex = startPosition;
   int pIndex = pattern.size() -1;
   while(startIndex <=text.size() - pattern.size() ) {
       int tIndex = startIndex + pIndex;
       cout<<"tIndex: "<<tIndex<<endl;
       char pCh = pattern.at(pIndex);

       cout <<"pch " <<pCh<<endl;
       char tCh = text.at(tIndex);

       cout <<"tch " <<tCh<<endl;
       //1. check if the letters match. If no match continue at 4.
       if(pCh != tCh ) {
           int shift;
           cout <<" first if"<<endl;
           //1.1 check if other chars are matching
           if(lookUpTable.find(tCh) != lookUpTable.end()) {
               //1.2 if so then shift the whole pattern by the index-value where the match was found.
               shift = lookUpTable[tCh];
               cout<<"shift after lookup : " <<shift<<endl;
           }

               else {
                      shift = pattern.size();
                      cout <<"shift after else: "<<shift<<endl;
                    }

                   // 1.4 adjust start, indexes etc.
                    pIndex = pattern.size() -1;
                    startIndex += shift;
                    cout<<"startIndex: "<<startIndex<<endl;

           //1.3 if none matches are found the move the whole pattern by its size
       }
       else {
           if(pIndex == 0) {
               return startIndex;
           }
           //4. no match found, check the one on the left and... so own
           pIndex--;
       }
   }
 return -1;

}


int main()
{
    string text = "GDFGHJFFGJJGHJTREYWERWETYDSGF";
    string pattern = "HJF";
    int maxMismacht = 1;
    int startPos = 0;
    int result;

    result = similaritySearch(text, pattern, maxMismacht, startPos);
    cout<<"Your match starts at: " << result << endl;
    return 0;
}
