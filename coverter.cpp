#include <fstream>
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <map>
#include <vector>
#include <string>
#include <limits>

const std::map<std::string, std::vector<std::string>> range = {
    {"Audero-MD5-Rainbow-Table/md5_rainbow_table_part_1.csv", 
    {"0000005ec43798404240e1f700343445", 
    "17189b1125eaf176e1956824cafb1075"}
    },
    {"Audero-MD5-Rainbow-Table/md5_rainbow_table_part_2.csv", 
    {"17189d9438d9749039c0de1045af1732", 
    "2e1e6501c18fc410f2bdc4a85f7d14b9"}
    },
    {"Audero-MD5-Rainbow-Table/md5_rainbow_table_part_3.csv", 
    {"2e1e662a18b5229228259e19dd06f9c0", 
    "452a1a8d33c6ce869ee47256d5fdc6d8"}
    },
    {"Audero-MD5-Rainbow-Table/md5_rainbow_table_part_4.csv", 
    {"452a1afc305c356d08e87d3e15e35eea", 
    "5c375ad44e40a1cca6708dfd144cc89a"}
    },
    {"Audero-MD5-Rainbow-Table/md5_rainbow_table_part_5.csv", 
    {"5c375cb724ec999f609b2f19f8280e15", 
    "734341759c562b880db6c292b793e7d9"}
    },
    {"Audero-MD5-Rainbow-Table/md5_rainbow_table_part_6.csv", 
    {"734342d2da75a392c678851c6e9f8b38", 
    "8a4808db7f5c8b81166ec26fb46533c6"}
    },
    {"Audero-MD5-Rainbow-Table/md5_rainbow_table_part_7.csv", 
    {"8a480904c7187f4fb01daba1de53e29a", 
    "a149ce04fe3e5886bab91c18efb94a4b"}
    },
    {"Audero-MD5-Rainbow-Table/md5_rainbow_table_part_8.csv", 
    {"a149d342b250eb704723fff1f47e1a84", 
    "b8597eaa72ec7f00fd115683a647d642"}
    },
    {"Audero-MD5-Rainbow-Table/md5_rainbow_table_part_9.csv", 
    {"b8597eae9162293ebab8e5278f991ff0", 
    "cf691dffb1d9abbb6f7834db06e22e33"}
    },
    {"Audero-MD5-Rainbow-Table/md5_rainbow_table_part_10.csv", 
    {"cf691e0db25406e787ffc34a7495dccb", 
    "e67335a7b9aed819da1a022f67394afe"}
    },
    {"Audero-MD5-Rainbow-Table/md5_rainbow_table_part_11.csv", 
    {"e673391fa486b00fe325dcf4736e764b", 
    "fd778d693d56669f5a19e83ba4e7601b"}
    },
    {"Audero-MD5-Rainbow-Table/md5_rainbow_table_part_12.csv", 
    {"fd778f621f39d831e350b981a153a406", 
    "fffffe7f65e2dce722f279e4573310cb"}
    }
};

int main(){
    std::string value = "17189b1125eaf176e1956824cafb1075";
    std::string fileName = "";
    //std::string value;
    //std::cin >> value;
    std::string right, left;
    for (auto i = range.begin(); i != range.end(); ++i){
        if ((value >= i->second[0]) && (value <= i->second[1])){
            fileName = i->first;
            right = i->second[1];
            left = i->second[0];
            break;
        }
    }
    if (fileName == ""){
        std::cout << "Not found" << std::endl;
        return 0;
    }
    std::ifstream file(fileName);
    assert(file.is_open());
    bool flag = false;
    int a = 0, b = 1000001, c = b/2;
    std::string middle, result, line;
    while(!flag){
        if (c == a){
            break;
        }
        file.seekg(std::ios::beg);
        for(int i = 0; i < c - 1; ++i){
            file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        std::getline(file, line);
        middle = line.substr(1, 32);
        std::cout << middle;
        if (value.compare(middle) < 0){
            left = middle;
            b = c;
        }
        else if(value.compare(middle) == 0){
            flag = true;
            result = line.substr(36, line.find_last_not_of('"') - 1);
        }
        else{
            right = middle;
            a = c;
        }
        std::cout << " " << c << std::endl;
        c = (b - a) / 2 + a;
    }
    if (flag) {
        std::cout << result << std::endl;
    }
    else {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}