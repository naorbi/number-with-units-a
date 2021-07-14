#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
#include "NumberWithUnits.hpp"
using namespace ariel;
#include <string>
using namespace std;
    
    TEST_CASE("Good"){
        ifstream units_file{"units.txt"};
        NumberWithUnits::read_units(units_file);

        // checks the input and output operators
        std::stringstream buffer;
        NumberWithUnits n0{5000, "m"};
        cout << n0 << endl;
        std::string text = buffer.str();
        CHECK(text == "5000[m]");

        // checks the mathematical operators
        NumberWithUnits n2{200, "m"};
        NumberWithUnits n3{300, "m"};
        n2 + n3;
        CHECK(n2.get_number() == 500);
        NumberWithUnits n5{1, "km"};
        n5 + n2; //1km + 500m = 1.5km
        CHECK(n5.get_number() == 1.5);
        n2 + n5; //500m + 1.5km = 2000m
        CHECK(n2.get_number() == 2000);
        n2 += n3; //2000 + 300 = 2300
        CHECK(n2.get_number() == 2300);
        n2 -= n3; //2300 - 300 = 2000
        CHECK(n2.get_number() == 2000);
        NumberWithUnits k1{15, "ILS"};
        NumberWithUnits k2{3, "USD"};
        k1+k2;
        CHECK(k1.get_unit() == "ILS");
        k2+k1;
        CHECK(k2.get_unit() == "USD");

        // checks the comparison operators
        NumberWithUnits m1{60, "sec"};
        NumberWithUnits m2{1, "min"};
        CHECK_FALSE(m1 > m2);
        CHECK_FALSE(m1 < m2);
        CHECK(m1 == m2);
        CHECK(m1 >= m2);
        CHECK(m1 <= m2);
        3*m1;
        CHECK(m1.get_number() == 180);
        CHECK(m1 > m2);
        CHECK_FALSE(m1 < m2);
        CHECK_FALSE(m1 == m2);
        CHECK(m1 >= m2);
        CHECK_FALSE(m1 <= m2);
    }
  
    TEST_CASE("Bad - Units are not the same"){
        ifstream units_file{"units.txt"};
        NumberWithUnits::read_units(units_file);

        NumberWithUnits n{1500, "sec"};
        NumberWithUnits m{2, "USD"};
        bool ans;
        CHECK_THROWS_AS((n - m), const std::exception&);
        CHECK_THROWS_AS((n + m), const std::exception&);
        CHECK_THROWS_AS(ans=(n < m), const std::exception&);
        CHECK_THROWS_AS(ans=(n <= m), const std::exception&);
        CHECK_THROWS_AS(ans=(n > m), const std::exception&);
        CHECK_THROWS_AS(ans=(n >= m), const std::exception&);
        CHECK_THROWS_AS(ans=(n == m), const std::exception&);
    }
