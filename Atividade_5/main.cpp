#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>


int main() {

    std::string archive_name;

    std::map<std::string,int> words;
    std::vector<std::string> keys;


    std::cin >> archive_name; 


    std::ifstream in(archive_name, std::fstream::in); 

    if (!in.is_open()) {
        std::cerr << "Error. Archive can't be open." << std::endl;
        return 1;
    }

    std::string word = "";
    char c;

    while (in.get(c)) {
        c = (char)tolower(c);

        if(std::isalnum(c)){
            word += c;
        }

        else if(!word.empty()){
            if(words.find(word)==words.end()){
                words[word] = 1;
                keys.push_back(word);
            }
            else
                words[word]++;

            word = "";
        }

        
    }

    in.close();  

    std::sort(keys.begin(),keys.end());

    for (auto &key : keys){
        std::cout << key << " " << words[key] << std::endl;
    }
    


    return 0;
}
