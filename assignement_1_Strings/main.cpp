#include <iostream>
#include <vector>
using namespace std;

void ParseExtensionAndSize(string line);

int sizez[4]={0};

int main() {

    int i=0,j=0,tCases;
    string line;
    cin>>tCases;

    vector<int> nCases (tCases);
    while(i<tCases){
        cin>>nCases[i++];
    }
    getline(cin,line);
    while(tCases--){
        for(int i=0;i<nCases[j];i++){
            getline(cin,line);
            ParseExtensionAndSize(line);
        }
        cout<<"music "<<sizez[0]<<"b images "<<sizez[1]<<"b movies "<<sizez[2]<<"b other "<<sizez[3]<<"b"<<endl;
        for(i=0;i<4;i++){
          sizez[i]=0;
        }
        j++;
    }
}

void ParseExtensionAndSize(string line){

    size_t fDot = line.rfind(".");
    size_t fSpace = line.rfind(" ");
    int last = fSpace-fDot ;

    string ext = line.substr(fDot+1,last-1) ;
    string size = line.substr(fSpace+1,line.size()-fSpace-2);
    int sz = stoi(size);

    if(ext == "mp3" || ext == "aac" || ext == "flac"){
        sizez[0]+=sz;
      }
    else if (ext == "jpg" || ext == "bmp" || ext == "gif"){
        sizez[1]+=sz;
      }
    else if (ext == "mp4" || ext == "avi" || ext == "mkv"){
        sizez[2]+=sz;
      }
    else{
        sizez[3]+=sz;
    }
}
