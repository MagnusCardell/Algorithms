#include<vector>
#include<iostream>
#include<fstream>
using namespace std;
 
vector<string> split(const string &line, const char *delim = " \t")
{
  vector<string> word;
  size_t loc0, loc1;
  loc0 = line.find_first_not_of(delim);
  if ( loc0 == string::npos ) return word;
  loc1 = line.find_first_of(delim, loc0);
  while ( loc1 != string::npos ) {
    word.push_back( line.substr(loc0, loc1-loc0) );
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
    // split the line into words
    vector<string> word = split(line);
    // print out the words, one at a time
    cout << "Line:";
    for ( unsigned i=0,i_end=word.size(); i<i_end; ++i )
      cout << "," << word[i];
    cout << endl;
  }
  f.close();
}