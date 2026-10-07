#include<iostream>
#include "convert_knots.hpp"
using namespace std;

int main(){
    int knots = 0;
    cout << "Enter knots: ";
    cin >> knots;
    cout << knots << " knots is equal to " << knots_to_miles_per_minute(knots) << " miles per minute." << endl;
    return 0;
}
