#pragma once
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

namespace ariel{
    class NumberWithUnits{
        
        long long number;
        string unit;

        public:
            NumberWithUnits(){
                number = 0;
                unit = "";
            }
            NumberWithUnits(long long x, string y){
                number = x;
                unit = y;
            }

            long long get_number(){
                return number;
            }

            string get_unit(){
                return unit;
            }

            friend bool can_be_converted(string num_1_unit, string num_2_unit);
            friend long long converted(string unit, const NumberWithUnits &num);
            static void read_units(std::ifstream &ufile);

            NumberWithUnits& operator +(const NumberWithUnits& num) const;
            NumberWithUnits& operator +=(const NumberWithUnits& num) const;
            NumberWithUnits& operator -(const NumberWithUnits& num) const;
            NumberWithUnits& operator -=(const NumberWithUnits& num) const;

            bool operator >(const NumberWithUnits& num) const;
            bool operator >=(const NumberWithUnits& num) const;
            bool operator <(const NumberWithUnits& num) const;
            bool operator <=(const NumberWithUnits& num) const;
            bool operator ==(const NumberWithUnits& num) const;
            bool operator !=(const NumberWithUnits& num) const;

            NumberWithUnits& operator ++();
            NumberWithUnits& operator --();

            friend NumberWithUnits& operator *(double d, NumberWithUnits& num);

            friend NumberWithUnits& operator +(NumberWithUnits& num);
            friend NumberWithUnits& operator -(NumberWithUnits& num);

            friend ostream& operator <<(ostream& output, NumberWithUnits& num);
            friend istream& operator >>(istream& input, NumberWithUnits& num);
            
            friend NumberWithUnits& operator ++(NumberWithUnits& num);
            friend NumberWithUnits& operator --(NumberWithUnits& num);

    };
}
