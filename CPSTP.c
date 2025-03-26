
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *data = fopen("g2023_2024_ice.dat", "r");
    FILE *sup = fopen("supdailyavg.txt", "w");
    FILE *mich = fopen("muchdailyavg.txt", "w");
    FILE *huron = fopen("hurondailyavg.txt", "w");
    FILE *erie = fopen("eriedailyavg.txt", "w");
    FILE *on = fopen("ondailyavg.txt", "w");
    FILE *cl = fopen("cldailyavg.txt", "w");

    char row[100];
    int year, day;
    double savg, mavg, havg, eavg, oavg, clavg, total;
    

    for(int i = 0; i<=7; i++){
        fgets(row, 100, data);
        //printf("%s", row);
    }

    fgets(row, 100, data);
    sscanf(row, "%i %i %lf %lf %lf %lf %lf %lf %lf", &year, &day, &savg, &mavg, &havg, &eavg, &oavg, &clavg, &total);
    //printf("%s", row);
    //sscanf(row, "%i", &year);
    printf("%i %i %lf %lf %lf %lf %lf %lf %lf", year, day, savg, mavg, havg, eavg, oavg, clavg, total);

/*
    while (!feof(data)){
        fgets(row, 100, data);
        sscanf(row, "%i %i %lf %lf %lf %lf %lf %lf %lf", year, day, savg, mavg, havg, eavg, oavg, clavg, total);
        printf("%i", day);
    }

*/
    




}
