#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

/*
 Keys:
 A/Left arrow = previous month, D/Right arrow = next month
 W/Down arrow = previous year, S/Up arrow = next year
 P = search a specific date
 E = exit
*/

#define EVENT_COUNT (sizeof(events) / sizeof(events[0]))

typedef struct {
    int day, month, year;
    int endDay, endMonth, endYear;
    char title[100];
    char category[30];
} Event;

Event events[] = {
    {1,1,2026,1,1,2026,"New Year","Holiday"},
    {4,1,2026,8,1,2026,"Final Exam (Year 2025)","Exam"},
    {9,1,2026,24,1,2026,"Result Preparation","Academic"},
    {17,1,2026,17,1,2026,"Shab-e-Miraj","Govt Holiday"},
    {23,1,2026,23,1,2026,"Saraswati Puja","Holiday"},
    {25,1,2026,31,1,2026,"Year 2026 Semester Preparation","Academic"},
    {29,1,2026,29,1,2026,"BUP Cricket Tournament (Officers/Teachers/Staffs)","Sports"},

    {1,2,2026,1,2,2026,"Semester 1 Classes Start","Academic"},
    {4,2,2026,4,2,2026,"Shab-e-Barat","Govt Holiday"},
    {17,2,2026,17,2,2026,"Inter Department Cricket Tournament","Sports"},
    {21,2,2026,21,2,2026,"International Mother Language Day","Govt Holiday"},
    {26,2,2026,28,2,2026,"Inter-Batch Moot Court Competition 2026 (LAW)","University Event"},

    {17,3,2026,17,3,2026,"Shab-e-Qadr","Govt Holiday"},
    {18,3,2026,25,3,2026,"Eid-ul-Fitr Holiday (calendar range)","Govt Holiday"},
    {26,3,2026,26,3,2026,"Independence Day","Govt Holiday"},
    {28,3,2026,29,3,2026,"BUP Techsurgence 4.0 (ICT)","University Event"},
    {30,3,2026,31,3,2026,"Workshop (LAW)","University Event"},
    {9,3,2026,15,3,2026,"AvaLaunch (MKT)","University Event"},
    {16,3,2026,16,3,2026,"Workshop (PCHR)","University Event"},

    {5,4,2026,5,4,2026,"Easter Sunday","Holiday"},
    {6,4,2026,12,4,2026,"Semester 1 Mid Term Exam","Exam"},
    {13,4,2026,13,4,2026,"Chaitra Sankranti","Holiday"},
    {14,4,2026,14,4,2026,"Bangla New Year","Holiday"},
    {15,4,2026,16,4,2026,"Seminars (Engineering / ES)","University Event"},
    {19,4,2026,20,4,2026,"Devcruitment (DS)","University Event"},
    {23,4,2026,23,4,2026,"BUP Film Fest-26 (MCJ)","University Event"},
    {28,4,2026,28,4,2026,"Disaster Drill (DMR)","University Event"},
    {30,4,2026,30,4,2026,"Advent HR 5.0 (MGT)","University Event"},

    {1,5,2026,1,5,2026,"May Day","Govt Holiday"},
    {1,5,2026,1,5,2026,"Buddha Purnima","Holiday"},
    {2,5,2026,2,5,2026,"Research Project Contest-5.0 (ENG)","University Event"},
    {3,5,2026,3,5,2026,"Workshop (MCJ)","University Event"},
    {4,5,2026,4,5,2026,"Seminar (PCHR)","University Event"},
    {6,5,2026,6,5,2026,"Career Fest","University Event"},
    {9,5,2026,9,5,2026,"Research Project Contest-5.0 (ENG)","University Event"},
    {12,5,2026,12,5,2026,"POMAC 6.0 (Econ)","University Event"},
    {17,5,2026,17,5,2026,"Seminar (MGT)","University Event"},
    {18,5,2026,18,5,2026,"Workshop (DS)","University Event"},
    {21,5,2026,23,5,2026,"Capitalizer 2025 (F&B)","University Event"},
    {26,5,2026,4,6,2026,"Eid-ul-Azha Holiday (calendar range)","Govt Holiday"},

    {11,6,2026,11,6,2026,"Semester 1 Academic Classes End","Academic"},
    {12,6,2026,20,6,2026,"Semester 1 Preparatory Leave (PL)","Preparatory Leave"},
    {21,6,2026,9,7,2026,"Semester 1 Final Exam","Exam"},
    {11,6,2026,11,6,2026,"BUP PSC / Amplify 3.0 (MKT)","University Event"},
    {26,6,2026,26,6,2026,"Ashura (calendar label)","Govt Holiday"},

    {12,7,2026,16,7,2026,"Monsoon Vacation","Vacation"},
    {17,7,2026,25,7,2026,"Result & Next Semester Preparation","Academic"},
    {23,7,2026,23,7,2026,"Inter Dept Indoor Games Tournament","Sports"},
    {26,7,2026,26,7,2026,"Semester 2 Classes Start","Academic"},
    {27,7,2026,31,7,2026,"BizQuest (MKT)","University Event"},

    {2,8,2026,2,8,2026,"Seminar (FMS)","University Event"},
    {5,8,2026,5,8,2026,"July Mass Uprising Day (calendar label)","Govt Holiday"},
    {11,8,2026,13,8,2026,"BUP Inter Dept Self Defense Competition (PEC)","Sports"},
    {12,8,2026,12,8,2026,"Akhiri Chahar Shambah","Govt Holiday"},
    {17,8,2026,20,8,2026,"Folk and Cultural Fest (SOC)","University Event"},
    {18,8,2026,18,8,2026,"Workshop (LAW)","University Event"},
    {24,8,2026,24,8,2026,"Sfuron 6.0 (MCJ)","University Event"},
    {26,8,2026,26,8,2026,"Eid-e-Milad-un-Nabi (calendar label)","Govt Holiday"},
    {31,8,2026,31,8,2026,"Inter Dept Indoor Games Tournament","Sports"},

    {4,9,2026,4,9,2026,"Janmashtami (calendar label)","Govt Holiday"},
    {13,9,2026,17,9,2026,"Semester 2 Mid Term Exam","Exam"},
    {20,9,2026,20,9,2026,"Seminar (CSE)","University Event"},
    {21,9,2026,21,9,2026,"Seminar (F&B)","University Event"},
    {22,9,2026,22,9,2026,"Seminar (PCHR)","University Event"},
    {23,9,2026,23,9,2026,"Media Communication Summit (MCJ)","University Event"},
    {24,9,2026,24,9,2026,"Fateha-i-Yajdaham (calendar label)","Holiday"},
    {27,9,2026,28,9,2026,"DMX 5.0 (DMR)","University Event"},
    {29,9,2026,30,9,2026,"CSE Tech Carnival (CSE)","University Event"},

    {1,10,2026,1,10,2026,"Cyber Security Awareness Month","University Event"},
    {5,10,2026,5,10,2026,"Accfinity 2026 (AIS)","University Event"},
    {7,10,2026,7,10,2026,"Inter Dept Football Tournament","Sports"},
    {9,10,2026,10,10,2026,"Inter University Debate Competition (PA)","University Event"},
    {12,10,2026,12,10,2026,"Devthon 7.0 (DS)","University Event"},
    {15,10,2026,15,10,2026,"Band Fest (SOC)","University Event"},
    {20,10,2026,21,10,2026,"Durga Puja (calendar range)","Govt Holiday"},
    {24,10,2026,24,10,2026,"Workshop & Lit Fest-9.0 (ENG)","University Event"},
    {25,10,2026,25,10,2026,"Probarona Purnima (calendar label)","Holiday"},
    {27,10,2026,27,10,2026,"Excel Maestros 2026 (F&B)","University Event"},

    {1,11,2026,1,11,2026,"PSC Speak Up 6.0 (MKT)","University Event"},
    {3,11,2026,3,11,2026,"Seminar (AIS)","University Event"},
    {8,11,2026,8,11,2026,"Shyama Puja","Holiday"},
    {11,11,2026,11,11,2026,"Inter Dept Handball Tournament","Sports"},
    {20,11,2026,28,11,2026,"Semester 2 Preparatory Leave (PL)","Preparatory Leave"},
    {29,11,2026,17,12,2026,"Semester 2 Final Exam","Exam"},

    {16,12,2026,16,12,2026,"Victory Day","Govt Holiday"},
    {20,12,2026,31,12,2026,"Winter Vacation","Vacation"},
    {25,12,2026,25,12,2026,"Christmas Day","Govt Holiday"},

    {1,1,2027,31,1,2027,"Result & Next Year Preparation","Academic"},
    {1,2,2027,1,2,2027,"Semester 1 of 2027 Starts (calendar label)","Academic"}
};

char *monthNames[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

char *weekdayNames[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"
};

int isLeapYear(int y) {
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

/*Each months have how many days*/

int daysInMonth(int m, int y) {
    int d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeapYear(y)) return 29;
    return d[m - 1];
}

/*
   Months 1st date which day
   Sunday = 0, Monday = 1, ..., Saturday = 6
*/
int firstWeekday(int m, int y) {
    int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};
    if (m < 3) y--;
    return (y + y/4 - y/100 + y/400 + t[m-1] + 1) % 7;
}

/*weekday of a specific date.*/

int getWeekday(int d, int m, int y) {
   return (firstWeekday(m, y) + d - 1) % 7;
}

/*
   program can calculate the difference between two dates easily by it.
   how many dates from 1/1/1 to this date.
*/

long dateNumber(int d, int m, int y) {
    int i;
    long n = 0;
    for (i = 1; i < y; i++)
        n += isLeapYear(i) ? 366 : 365;
    for (i = 1; i < m; i++)
        n += daysInMonth(i, y);
    return n + d;
}

/* Specific date has any event runing.*/

int eventOccursOn(Event e, int d, int m, int y) {
    long target = dateNumber(d, m, y);
    long start = dateNumber(e.day, e.month, e.year);
    long end = dateNumber(e.endDay, e.endMonth, e.endYear);
    return target >= start && target <= end;
}

/* cheak any event govt holiday.*/

int isGovtHolidayCategory(const char category[]) {
    return strcmp(category, "Govt Holiday") == 0;
}

/* cheak Specific date that have govt holiday.*/


int isGovtHolidayOnDate(int d, int m, int y) {
    int i;
    for (i = 0; i < (int)EVENT_COUNT; i++) {
        if (eventOccursOn(events[i], d, m, y) &&
            isGovtHolidayCategory(events[i].category)) {
            return 1;
        }
    }
    return 0;
}

/* cheak Specific date that friday or saturday.*/

int isWeekend(int d, int m, int y) {
    int weekday = getWeekday(d, m, y);
    return (weekday == 5 || weekday == 6); /* Friday = 5, Saturday = 6 */
}

void showEventsOnDate(int d, int m, int y) {
    int i, found = 0;
    int govtHoliday = isGovtHolidayOnDate(d, m, y);
    int weekend = isWeekend(d, m, y);

    printf("\n=============================================\n");
    printf("              DATE INFORMATION\n");
    printf("=============================================\n");
    printf("Date       : %02d %s %d\n", d, monthNames[m-1], y);
    printf("Day        : %s\n", weekdayNames[getWeekday(d, m, y)]);

    /* Government holiday takes priority over the weekly weekend status. */
    if (govtHoliday) {
        printf("Status     : OFF\n");
        printf("\nGovernment Holiday:\n");
        printf("---------------------------------------------\n");
        for (i = 0; i < (int)EVENT_COUNT; i++) {
            if (eventOccursOn(events[i], d, m, y) &&
                isGovtHolidayCategory(events[i].category)) {
                printf("[Govt Holiday] %s\n", events[i].title);
                found = 1;
            }
        }
        printf("\nUniversity Closed - No Classes or Exams\n");
        return;
    }

    /* Friday and Saturday are weekly university holidays.
       If there is no government holiday, show only University Closed. */
    if (weekend) {
        printf("Status     : OFF\n");
        printf("\nUniversity Closed - Weekly Holiday\n");
        printf("No classes, exams, or other university events.\n");
        return;
    }

    /* On regular working days, show all scheduled events. */
    printf("\nEvents:\n");
    printf("---------------------------------------------\n");
    for (i = 0; i < (int)EVENT_COUNT; i++) {
        if (eventOccursOn(events[i], d, m, y)) {
            printf("[%s] %s\n", events[i].category, events[i].title);
            found = 1;
        }
    }
    if (!found) printf("No event recorded for this date.\n");
}

  /* Specific day has any events. */

int hasEvent(int d, int m, int y) {
    int i;
    for (i = 0; i < (int)EVENT_COUNT; i++)
        if (eventOccursOn(events[i], d, m, y)) return 1;
    return 0;
}

void showMonthEvents(int m, int y) {
    int i, found = 0;
    printf("\nEVENTS THIS MONTH\n");
    printf("---------------------------------------------\n");
    for (i = 0; i < (int)EVENT_COUNT; i++) {
        if ((events[i].month == m && events[i].year == y) ||
            (events[i].endMonth == m && events[i].endYear == y) ||
            (dateNumber(events[i].day, events[i].month, events[i].year)
             <= dateNumber(1, m, y) &&
             dateNumber(events[i].endDay, events[i].endMonth, events[i].endYear)
             >= dateNumber(1, m, y))) {
            printf("%02d/%02d/%04d", events[i].day, events[i].month, events[i].year);
            if (events[i].endDay != events[i].day ||
                events[i].endMonth != events[i].month ||
                events[i].endYear != events[i].year) {
                printf(" - %02d/%02d/%04d", events[i].endDay,
                       events[i].endMonth, events[i].endYear);
            }
            printf("  [%s] %s\n", events[i].category, events[i].title);
            found = 1;
        }
    }
    if (!found) printf("No events recorded.\n");
}

void drawCalendar(int m, int y) {
    int first, total, day, i, col;
    char mark;
    system("cls");     /*Clear consol screen. */
    printf("============================================================\n");
    printf("          BANGLADESH UNIVERSITY OF PROFESSIONALS\n");
    printf("                 BUP ACADEMIC CALENDAR\n");
    printf("============================================================\n\n");
    printf("                         %s %d\n\n", monthNames[m-1], y);
    printf("  Sun       Mon       Tue       Wed       Thu       Fri       Sat\n");
    printf("-------------------------------------------------------------------\n");
    first = firstWeekday(m, y);
    total = daysInMonth(m, y);
    col = 0;
    for (i = 0; i < first; i++) {
        printf("%10s", "");
        col++;
    }
    for (day = 1; day <= total; day++) {
       if (hasEvent(day, m, y))
    mark = '*';
else
    mark = ' ';
        printf("%5d%c    ", day, mark);
        col++;
        if (col == 7) {
            printf("\n");
            col = 0;
        }
    }
    if (col != 0) printf("\n");
    printf("\n* = event/holiday/exam on this date\n");
    showMonthEvents(m, y);
    printf("\nNAVIGATION:");
    printf("\n  LEFT/RIGHT ARROW = Previous/Next Month");
    printf("\n  UP/DOWN ARROW    = Next/Previous Year");
    printf("\n  P = Search Date   E = Exit   A/D/W/S = Shortcuts\n");
    printf("Press a key: ");
}

 /*Start execution.*/

int main(void) {
    int month = 11, year = 2026, d, m, y, choice, key, ch;

    while (1)  /*condition continue while user don't exit.*/
    {
        drawCalendar(month, year);
        choice = _getch();  /*Input key from keyboard.*/

        /* Arrow-key codes for common Windows consoles */
        if (choice == 0 || choice == 224) {
            key = _getch();
            switch (key) {
                case 75: month--; if (month < 1) { month = 12; year--; } break;
                case 77: month++; if (month > 12) { month = 1; year++; } break;
                case 72: year++; break;
                case 80: year--; break;
            }
            continue;
        }

        choice = toupper((unsigned char)choice);  /*Exchange small letter to capital letter.*/
        switch (choice) {
            case 'A': month--; if (month < 1) { month = 12; year--; } break;
            case 'D': month++; if (month > 12) { month = 1; year++; } break;
            case 'W': year--; break;
            case 'S': year++; break;
            case 'P':
                printf("\nEnter date as DD MM YYYY: ");
                if (scanf("%d %d %d", &d, &m, &y) == 3) {
                    while ((ch = getchar()) != '\n' && ch != EOF) { }
                    if (y >= 1 && m >= 1 && m <= 12 && d >= 1 &&
                        d <= daysInMonth(m, y)) {
                        system("cls");  /*Clear consol screen. */
                        showEventsOnDate(d, m, y);
                    } else {
                        printf("\nInvalid date.");
                    }
                } else {
                    while ((ch = getchar()) != '\n' && ch != EOF) { }
                    printf("\nInvalid input. Enter numbers only.");
                }
                printf("\nPress any key to return to the calendar...");
                _getch();
                break;
            case 'E':
                printf("\nThank you for using BUP Event Calendar!\n");
                return 0;
            default:
                printf("\nInvalid choice. Press any key to continue...");
                _getch();
        }
    }
    return 0;
}