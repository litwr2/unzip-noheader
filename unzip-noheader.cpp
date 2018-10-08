#include <iostream>
#include "base64-string.h"
#include "unzip-noheader.h"

int main() {
    std::string s;
    int n = 0;
    for(;;) {
        try {
            while (!std::cin.eof()) {
                ++n;
                std::getline(std::cin, s);
                if (s.empty()) break;
                std::string se = ZipNoHeader::decompress(base64::decode(s));
                std::cout << se << "\n";
            }
            return 0;
        }
        catch (const std::exception &e) {
            std::cout << "Error (" << e.what() << ") in line #" << n << ": [" << s << "]\n"; 
        }
    }
}
