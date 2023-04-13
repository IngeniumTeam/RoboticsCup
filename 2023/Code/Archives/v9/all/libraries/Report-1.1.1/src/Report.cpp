#include <Arduino.h>

#include "Report.h"

Report::Report (Stream *stream, bool iDebug = false, int iStep = 5)
{
    serial = stream;
    debug = iDebug;
    step = iStep;
}

void Report::print()
{
    if (debug && cmp % step == 0)
    {
        prettyPrint();
    }
    cmp++;
}

/**
 * Print the data
 */
void Report::prettyPrint()
{
    ko = ntr + inv;
    tot = ok + ko;
    char buffer[11][50];
    char values[10][50];
    dtostrf(num, 3, 0, values[0]);
    dtostrf(tot, 3, 0, values[1]);
    dtostrf(ok, 3, 0, values[2]);
    dtostrf(ok / tot * 100, 6, 2, values[3]);
    dtostrf(ko, 3, 0, values[4]);
    dtostrf(ko / tot * 100, 6, 2, values[5]);
    dtostrf(ntr, 3, 0, values[6]);
    dtostrf(ntr / tot * 100, 6, 2, values[7]);
    dtostrf(inv, 3, 0, values[8]);
    dtostrf(inv / tot * 100, 6, 2, values[9]);
    sprintf(buffer[0], " ----- Report n°%s ----- ", values[0]);
    sprintf(buffer[1], "|                        |");
    sprintf(buffer[2], "| name      abs      rel |");
    sprintf(buffer[3], "| tot       %s          |", values[1]);
    sprintf(buffer[4], "|                        |");
    sprintf(buffer[5], "| ok        %s   %s |", values[2], values[3]);
    sprintf(buffer[6], "| ko        %s   %s |", values[4], values[5]);
    sprintf(buffer[7], "|                        |");
    sprintf(buffer[8], "| ntr       %s   %s |", values[6], values[7]);
    sprintf(buffer[9], "| inv       %s   %s |", values[8], values[9]);
    sprintf(buffer[10], " ------------------------ ");
    for (int i = 0; i < 11; i++)
        serial -> println(buffer[i]);
    serial -> println();
    serial -> println();
    num++;
}