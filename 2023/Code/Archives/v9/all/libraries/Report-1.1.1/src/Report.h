#include <Arduino.h>

class Report
{
    public:
        Report(Stream *stream, bool iDebug = false, int iStep = 5);
        void print();
        void prettyPrint();
        Stream *serial;
        bool debug = false;
        int step = 5;
        int cmp = 0;
        int num = 0;
        double ok;
        double ntr;
        double inv;
        double ko;
        double tot;
        int prob;
};
