#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Method definition
void importSeqs(string inputFile);
void printSeqs();

// Vectors to store ids and seqs
vector<string> ids;
vector<string> seqs;

int main(int argc, char **argv) {
    // absolute path of the input data
    string file = "/Users/ulisesolivares2/CLionProjects/examenGPUs/plant.fasta";
    importSeqs(file);
    printSeqs();
    return 0;
}

void importSeqs(string inputFile){
    ifstream input(inputFile);
    if (!input.good()) {
        std::cerr << "Error opening: " << inputFile << " . Check your file or path." << std::endl;
        exit(0);
    }

    string line;
    // Don't loop on good(), it doesn't allow for EOF!!

    // Iterate over all secuences
    while (getline(input, line)) {

        // line may be empty so you *must* ignore blank lines
        // or you have a crash waiting to happen with line[0]
        if(line.empty())
            continue;

        //read the header of
        if (line[0] == '>') {
            // store id
            ids.push_back(line);

        }
        else {
            // store seqs
            seqs.push_back(line);
        }
    }
}

void printSeqs(){
    for (int i = 0; i<seqs.size(); i++){
        cout << ids[i] << "\n" <<  seqs[i] << endl;
    }
}