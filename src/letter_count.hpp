// letter_count.hpp
#include <cctype>
#include <string>

constexpr int N_CHARS = 26;

// converts a letter to its array index: 'A' or 'a' -> 0, 'B' or 'b' -> 1, ...
int char_to_index(char n){
    char uppercase = toupper(static_cast<unsigned char>(n));
    int index = uppercase - 'A';
    return index;
}

// converts an index back to its uppercase letter: 0 -> 'A', 1 -> 'B', ...
char index_to_char(int i){
    return i + 'A';
}

// given a line and the array of counts, increments the entry for each
// letter in the line, ignoring every character that is not a letter
void count(std::string s, int counts[]){
    for (int i=0; i<s.length();++i) {
        char c = s[i];

        if (isalpha(static_cast<unsigned char>(c))) {
            int index = char_to_index(c);
            counts[index] += 1;
        }
    }
}

// writes each letter with its count, one per line, A through Z, to cout
void print_counts(int counts[], int len){
    for (int i=0; i<len;++i) {
        std::cout << index_to_char(i) << " " << counts[i] << std::endl;
    }
}