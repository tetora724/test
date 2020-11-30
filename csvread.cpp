#include <iostream>
#include <string>
#include <fstream>

int main() {
  using namespace std;
  ifstream stream("test.csv");
  string line;
  float data[10000][5000];
  const string delim = ",";

  int row = 0;
  int col;
  while ( getline(stream, line) ) {
    col = 0;
    // delimを区切り文字として切り分け、intに変換してdata[][]に格納する
    for ( string::size_type spos, epos = 0;
        (spos = line.find_first_not_of(delim, epos)) != string::npos;) {
      string token = line.substr(spos,(epos = line.find_first_of(delim, spos))-spos);
      data[row][col++] = stof(token);
    }
    ++row;
  }

  std::cout << data[0][0] <<endl;
  // よめたかな?
  /*
  for ( row = 0; row < 3; ++row ) {
    for ( col = 0; col < 3; ++col ) {
      cout << data[row][col] << " ";
    }
    cout << endl;
  }
  */\
}