#include<iostream>
#include "letter_count.hpp"
using namespace std;

int main(){
    int counts[N_CHARS]={0};
    string s;
    while(getline(cin,s)){
        count(s,counts);
    }
    print_counts(counts, N_CHARS);
    return 0;
}