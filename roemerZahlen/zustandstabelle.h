//
// Created by admin on 1/2/26.
//

#ifndef ROEMERZAHLEN_ZUSTANDSTABELLE_H
#define ROEMERZAHLEN_ZUSTANDSTABELLE_H

#include <iostream>
#include <map>
using namespace std;

/*  -------------------------------------------------------------
    Eingabe Alphabtet   |     I   |     V   |    X    |    /n   |
    --------|-----------|---------|---------|---------|---------|
    Zustand |   Q0      |   Q1    |   Q5    |   Q10   |   err   |
            |   Q1      |   Q2    |   Q4    |   err   |    1    |
            |   Q2      |   Q3    |   err   |   err   |    2    |
            |   Q3      |   err   |   err   |   err   |    3    |
            |   Q4      |   err   |   err   |   err   |    4    |
            |   Q5      |   Q6    |   err   |   err   |    5    |
            |   Q6      |   Q7    |   err   |   err   |    6    |
            |   Q7      |   Q8    |   err   |   err   |    7    |
            |   Q8      |   err   |   err   |   err   |    8    |
            |   Q9      |   err   |   err   |   err   |    9    |
            |   Q10     |   err   |   err   |   err   |   10    |
            |   err     |   err   |   err   |   err   |   err    |
    ------------------------------------------------------------*/

map<pair<string,string>,string> zustandsTabelle = {
    {{"Q0","I"}, "Q1"}, {{"Q0","V"}, "Q5"}, {{"Q0","X"}, "Q10"},
    {{"Q1","I"}, "Q2"}, {{"Q1","V"}, "Q4"}, {{"Q1","X"}, "Q9"},
    {{"Q2","I"}, "Q3"}, {{"Q2","V"}, "err"},{{"Q2","X"}, "err"},
    {{"Q3","I"}, "err"},{{"Q3","V"}, "err"},{{"Q3","X"}, "err"},
    {{"Q4","I"}, "err"},{{"Q4","V"}, "err"},{{"Q4","X"}, "err"},
    {{"Q5","I"}, "Q6"}, {{"Q5","V"}, "err"},{{"Q5","X"}, "err"},
    {{"Q6","I"}, "Q7"}, {{"Q6","V"}, "err"},{{"Q6","X"}, "err"},
    {{"Q7","I"}, "Q8"}, {{"Q7","V"}, "err"},{{"Q7","X"}, "err"},
    {{"Q8","I"}, "err"},{{"Q8","V"}, "err"},{{"Q8","X"}, "err"},
    {{"Q9","I"}, "err"},{{"Q9","V"}, "err"},{{"Q9","X"}, "err"},
    {{"Q10","I"}, "err"},{{"Q10","V"}, "err"}, {{"Q10","X"}, "err"},
    {{"err","I"}, "err"}, {{"err","V"}, "err"},{{"err","X"}, "err"}
};

/// Map für Endzustände zu arabischen Zahlen
std::map<std::string,int> endzustaende = {
    {"Q1", 1}, {"Q2", 2}, {"Q3", 3}, {"Q4", 4}, {"Q5", 5},
    {"Q6", 6}, {"Q7", 7}, {"Q8", 8}, {"Q9", 9}, {"Q10", 10}
};

#endif //ROEMERZAHLEN_ZUSTANDSTABELLE_H