#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word = "Thomi";
    string output = "";
    int failed = 0;
    int limit = 5;
    for(int i = 0; i < word.length(); i++){
       output.append("X");

    }
    cout<<"**##Game information: Every word starts with a CAPITOL letter, followed by lowercase letters.##**"<<endl;
    cout<<"You can try "<<limit<<" times! *Good Luck*"<<"\n\n";
    cout<<"Looking for following word: "<<output<<endl;


    while(output.find("X") != string::npos  && failed < limit){
        cout<<"Gib ein Buchstabe ein: ";
        char input;
        cin>>input;

        if(word.find(input) == string::npos){
            failed++;
        }
        else{
            for(int i = 0; i < word.length(); i++){

                if(word[i] == input){
                    output[i] = input;
                }
            }

        }
        if(limit >failed){
          cout<<"Looking for a word: "<<output<<" You have "<<limit - failed<<" tries!"<<"\n\n";
        }
        else{
            cout<<"\n\n";
        }
    }

    if(output.find("X") == string::npos){
        cout<<"****Yeah, You cracked it****"<<"\n\n";
    }else{
        cout<<"Sorry you lost!"<<"\n\n";
    }



    return 0;
}
