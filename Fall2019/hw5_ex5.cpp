#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

vector<int> process_line1(string line);
vector<int> process_line2(string line);
vector<int> process_line(string line);

int main() {

  string file_name = "hmwk_5_ex_5_data.txt";
  ifstream ifs;
  ifs.open(file_name);

  vector<vector<int>> ai;

  string line;
  while(getline(ifs,line)){
    ai.push_back(process_line(line));
  }
  ifs.close();
  ifs.clear();

  vector<double> cont_frac;
  double an;
  for(int i = 0; i < ai.size(); i++){
    an = ai[i][ai[i].size()-1];
    cont_frac.push_back(an);
    for(int j = ai[i].size()-2; j >= 0; j--){
      an = ai[i][j];
      cont_frac[i] = an + 1./cont_frac[i];
    }
  }

  ofstream ofs;
  ofs.open("hmwk_5_ex_5_data_new.txt");
  if(!ofs.is_open()){
    cout << "The file failed to open!" << '\n';
    return 0;
  }
  for(int i = 0; i < cont_frac.size(); i++){
    ofs << fixed << setprecision(15) << cont_frac[i] << '\n';
  }
  ofs << flush;
  ofs.close();

  return 0;

}

vector<int> process_line(string line){

        vector<int> el1 = process_line1(line);
        vector<int> el2 = process_line2(line);

        vector<int> processed_line = el1;

        for(int i = 1; i < el2.size(); i++){
          processed_line.push_back(el2[i]);
        }

        return processed_line;
}

vector<int> process_line1(string line){
        // Create a new input string stream, opening up the string line to use
        istringstream iss(line);

        string elem;

        vector<int> processed_line;


        // use getline to get a "line" from the stream, delimited by the comma character
        while(getline(iss,elem, ';')){
                processed_line.push_back(stoi(elem));
        }

        return processed_line;
}

vector<int> process_line2(string line){
        // Create a new input string stream, opening up the string line to use
        istringstream iss(line);

        string elem;

        vector<int> processed_line;


        // use getline to get a "line" from the stream, delimited by the comma character
        while(getline(iss,elem, ',')){
                processed_line.push_back(stoi(elem));
        }

        return processed_line;
}
