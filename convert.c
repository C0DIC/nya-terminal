#include "convert.h"

const char *getWeekDay(int week_day_number) {
    switch (week_day_number)
    {
        case 0: return "sun";
        case 1: return "mon";
        case 2: return "tues";
        case 3: return "wed";
        case 4: return "thurs";
        case 5: return "fri";
        case 6: return "sat";
    
        default: return "Error\n";
    }
};

const char *getYearMonth(int month_number) {
    switch (month_number)
    {
        case 0: return "jan";
        case 1: return "feb";
        case 2: return "mar";
        case 3: return "apr";
        case 4: return "may";
        case 5: return "jun";
        case 6: return "jul";
        case 7: return "aug";
        case 8: return "sep";
        case 9: return "oct";
        case 10: return "nov";
        case 11: return "dec";
    
        default: return "Error\n";
    }
};