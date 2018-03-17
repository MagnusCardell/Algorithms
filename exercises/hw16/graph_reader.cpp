#include<vector>
#include<iostream>
#include<fstream>
using namespace std;
 
vector<string> split(const string &line, const char *delim = "\t")
{
  vector<string> word;
  size_t loc0, loc1;
  loc0 = line.find_first_not_of(delim); //location of non-delim word
  if ( loc0 == string::npos ) return word; //if initial position=newline - return empty vector
  loc1 = line.find_first_of(delim, loc0); // else find first position of this first non-newline char
  while ( loc1 != string::npos ) { //while position != newline
    cout<<"new delim"<<endl;
    word.push_back( line.substr(loc0, loc1-loc0) ); //get string between first char and delimiter
    loc0 = line.find_first_not_of(delim, loc1);
    if ( loc0 == string::npos ) break;
    loc1 = line.find_first_of(delim, loc0);
  }
  if ( loc0 != string::npos && loc1 == string::npos ) // one more
    word.push_back( line.substr(loc0, line.size()-loc0) );
  return word;
}
 
int main()
{
  ifstream f("graph.txt");
  string line;

  while ( getline(f, line) ) {
    // split the line by specific delimiter
    vector<string> word = split(line);
    cout << "Line:";

    for ( unsigned i=0,i_end=word.size(); i<i_end; ++i )
      cout << "," << word[i];

    cout << endl;
  }
  f.close();
}