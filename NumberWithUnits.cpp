#include "NumberWithUnits.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <exception>
using namespace std;

namespace ariel{


        bool can_be_converted(string num_1_unit, string num_2_unit){
          return true;
        }

        long long converted(string unit, const NumberWithUnits &num){
            return 1;
        }

         void ariel::NumberWithUnits::read_units(std::ifstream &ufile){
            int amount;
            long long num;
            string unit1;
            string unit2;

            if (ufile.is_open()){
                while(ufile >> amount >> unit1 >> num >> unit2){
                    std::cout<<amount << unit1 << num << unit2 << '\n';
                }
                ufile.close();
            }
            else{
                std::cout << "File is not open" << '\n';
            }
         }

        NumberWithUnits& ariel::NumberWithUnits::operator +(const NumberWithUnits& num) const{
            return *(new NumberWithUnits(5,"m"));
        }

        NumberWithUnits& ariel::NumberWithUnits::operator +=(const NumberWithUnits& num) const{
            return *(new NumberWithUnits(5,"m"));
        }
        NumberWithUnits& ariel::NumberWithUnits::operator -(const NumberWithUnits& num) const{
            return *(new NumberWithUnits(5,"m"));
        }
        NumberWithUnits& ariel::NumberWithUnits::operator -=(const NumberWithUnits& num) const{
            if (this->unit == num.unit){
                return *(new NumberWithUnits(this->number - num.number, this->unit));
            }
            return *(new NumberWithUnits(this->number - num.number, this->unit));
        }

        bool ariel::NumberWithUnits::operator >(const NumberWithUnits& num) const{
            if (this->unit == num.unit){
                return (this->number > num.number);
            }
            else if (can_be_converted(this->unit, num.unit)){
                long long num_number_converted = converted(this->unit, num);
                return (this->number > num_number_converted);
            }
            else{
                throw std::exception();
                return false;
            }
        }
        
        bool ariel::NumberWithUnits::operator >=(const NumberWithUnits& num) const{
            return true;
        }
        bool ariel::NumberWithUnits::operator <(const NumberWithUnits& num) const{
            return true;
        }
        bool ariel::NumberWithUnits::operator <=(const NumberWithUnits& num) const{
            return true;
        }
        bool ariel::NumberWithUnits::operator ==(const NumberWithUnits& num) const{
            return true;
        }
        bool ariel::NumberWithUnits::operator !=(const NumberWithUnits& num) const{
            return true;
        }

        NumberWithUnits& ariel::NumberWithUnits::operator ++(){ 
            NumberWithUnits& new_num = *(new NumberWithUnits(this->number,this->unit));
            this->number = this->number + 1;
            return new_num;
        }
        NumberWithUnits& ariel::NumberWithUnits::operator --(){ 
            NumberWithUnits& new_num = *(new NumberWithUnits(this->number,this->unit));
            this->number = this->number - 1;
            return new_num;
        }

        NumberWithUnits& operator +(NumberWithUnits& num){
            return num; //*(new NumberWithUnits(num.number,num.unit));
        }
        NumberWithUnits& operator -(NumberWithUnits& num){
            return *(new NumberWithUnits(-num.number,num.unit));
        }
        NumberWithUnits& operator ++(NumberWithUnits& num){
            num.number = num.number + 1;
            return num;
        }
        NumberWithUnits& operator --(NumberWithUnits& num){
            num.number = num.number - 1;
            return num;        
        }
        NumberWithUnits& operator *(double d, NumberWithUnits& num){
            return *(new NumberWithUnits(d*num.number,num.unit));
        }
        ostream& operator <<(ostream& output, NumberWithUnits& num){
            output << num.number << "[" << num.unit << "]";
            return output;
        }
        istream& operator >>(istream& input, NumberWithUnits& num){
            return input;
        }
}
