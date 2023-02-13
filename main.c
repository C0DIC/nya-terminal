#include "convert.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Greetings
const char *morning_greeting_text = "|| ღ Ohayo, %s~\n";
const char *greeting_text = "|| ღ Kon ni chi va, %s!\n";
const char *evening_greeting = "|| (๑> . <) Kon ba n va, %s\n";
const char *night_greeting_text = "|| (⌒ω⌒)ﾉ Oya sumi nasa i, %s >•<\n";

// Time formats
const char *time_text = "|| ☆ Time is |%02d:%02d| nya~\n|| Today is %s %d, %s ヽ(*・ω・)ﾉ☆\n||\n";

// Additional texts
const char *good_luck = "|| Have a goowd day, senpai~\n";
const char *good_code = "|| Good cowding, senpai (^ω~)\n";
const char *love_ya_sempai = "|| (o^ ^o) L..l..love you ♡\n";
const char *kitty = 
"   /ᐢ⑅ᐢ\\   ♡   ₊˚  \n"
"꒰ ˶• ༝ •˶꒱       ♡‧₊˚    ♡\n"
"./づ~ :¨·.·¨:     ₊˚  \n"
"           `·..·‘    ₊˚   ♡\n";

int main(int argc, const char *argv[]) {
    const char *USERNAME = getlogin();
    time_t nani = time(NULL);
    struct tm *local_time = localtime(&nani);

    srand(time(NULL));
    int choice = 1 + rand() % 4;
    const char *letter;

    if (choice == 1) { letter = good_luck; }
    if (choice == 2) { letter = good_code; }
    if (choice == 3) { letter = love_ya_sempai; }
    if (choice == 4) { letter = kitty; }

    system("clear");

    if (local_time->tm_hour < 11 && local_time->tm_hour >= 6) {
        printf(morning_greeting_text, USERNAME);
        printf(
            time_text, 
            local_time->tm_hour,
            local_time->tm_min, 
            getYearMonth(local_time->tm_mon),
            local_time->tm_mday,
            getWeekDay(local_time->tm_wday)
        );
        printf("%s", letter);
        return 0;
    }

    if (local_time->tm_hour >= 11 && local_time->tm_hour < 18) {
        printf(greeting_text, USERNAME);
        printf(
            time_text, 
            local_time->tm_hour,
            local_time->tm_min, 
            getYearMonth(local_time->tm_mon),
            local_time->tm_mday,
            getWeekDay(local_time->tm_wday)
        );
        printf("%s", letter);
        return 0;
    }

    if (local_time->tm_hour > 17 && local_time->tm_hour <= 22) {
        printf(evening_greeting, USERNAME);
        printf(
            time_text, 
            local_time->tm_hour,
            local_time->tm_min, 
            getYearMonth(local_time->tm_mon),
            local_time->tm_mday,
            getWeekDay(local_time->tm_wday)
        );
        printf("%s", letter);
        return 0;
    }

    if (local_time->tm_hour > 22 || local_time->tm_hour < 6) {
        printf(night_greeting_text, USERNAME);
        printf(
            time_text, 
            local_time->tm_hour,
            local_time->tm_min, 
            getYearMonth(local_time->tm_mon),
            local_time->tm_mday,
            getWeekDay(local_time->tm_wday)
        );
        printf("%s", letter);
        return 0;
    }

    return 0;
}
