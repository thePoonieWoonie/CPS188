
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *data = fopen("g2023_2024_ice.dat", "r");
    FILE *sup = fopen("supdailyavg.txt", "w");
    FILE *mich = fopen("michdailyavg.txt", "w");
    FILE *huron = fopen("hurondailyavg.txt", "w");
    FILE *erie = fopen("eriedailyavg.txt", "w");
    FILE *on = fopen("ondailyavg.txt", "w");
    FILE *cl = fopen("cldailyavg.txt", "w");
    FILE *combine = fopen("combinedailyavg.txt", "w");

    char row[100];
    int year, count =0;
    double day, savg, mavg, havg, eavg, oavg, clavg, total;
    

    for(int i = 0; i<=7; i++){
        fgets(row, 100, data);
        //printf("%s", row);
    }

    /*
    for(int i = 0; i<44; i++){
        fgets(row, 100, data);
        sscanf(row, "%i %lf %lf %lf %lf %lf %lf %lf %lf", &year, &day, &savg, &mavg, &havg, &eavg, &oavg, &clavg, &total);
        //printf("%i %i %lf %lf %lf %lf %lf %lf %lf \n", year, day, savg, mavg, havg, eavg, oavg, clavg, total);
    }
    */
    
    /*
    fgets(row, 100, data);
    printf("%s", row);
    sscanf(row, "%i %lf", &year, &day);
    printf("%i %lf\n", year, day);
    */

    while (!feof(data)){
        count++;
        fgets(row, 100, data);
        sscanf(row, "%i %lf %lf %lf %lf %lf %lf %lf %lf", &year, &day, &savg, &mavg, &havg, &eavg, &oavg, &clavg, &total);
        //printf("%i %.0lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf %.2lf \n", year, day, savg, mavg, havg, eavg, oavg, clavg, total);

        if (count != 153){
            fprintf(sup, "%i %lf\n", count, savg);
            fprintf(mich, "%i %lf\n", count, mavg);
            fprintf(huron, "%i %lf\n", count, havg);
            fprintf(erie, "%i %lf\n", count, eavg);
            fprintf(on, "%i %lf\n", count, oavg);
            fprintf(cl, "%i %lf\n", count, clavg);
            fprintf(combine, "%i %lf %lf %lf %lf %lf %lf \n", count, savg, mavg, havg, eavg, oavg, clavg);
        }
        
    }
}
