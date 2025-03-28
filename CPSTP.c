
#include <stdio.h>
#include <string.h>


int main()
{
    //Open files for reading and writing

    //Data files
    FILE *data3 = fopen("g2023_2024_ice.dat", "r");
    FILE *data1 = fopen("g2021_2022_ice.dat", "r");
    FILE *data2 = fopen("g2022_2023_ice.dat", "r");

    //Files for question 5 and 6
    FILE *sup = fopen("supdailyavg.txt", "w");
    FILE *mich = fopen("michdailyavg.txt", "w");
    FILE *huron = fopen("hurondailyavg.txt", "w");
    FILE *erie = fopen("eriedailyavg.txt", "w");
    FILE *on = fopen("ondailyavg.txt", "w");
    FILE *cl = fopen("cldailyavg.txt", "w");
    FILE *combine = fopen("combinedailyavg.txt", "w");

    //Files for question 8
    FILE *sup8 = fopen("superior8.txt", "w");
    FILE *mich8 = fopen("michigan8.txt", "w");
    FILE *huron8 = fopen("huron8.txt", "w");
    FILE *erie8 = fopen("erie8.txt", "w");
    FILE *on8 = fopen("ontario8.txt", "w");
    FILE *cl8 = fopen("stclair8.txt", "w");

    
    // Initialize variables for the row string, counting, average variables and arrays

    //Variable to store the entire row as a string
    char row[100];

    //counting variables, used in loops and calculating averages
    int year, count = 0, count21 = 0, count22 = -1, count221 = 0, count23 = -1 , count231 = 0, count24 = -1;

    //Reads the string and stores the numbers in these variables
    double day, savg, mavg, havg, eavg, oavg, clavg, total;

    //Variables for question 7 (calculating table)
    double avg21[7], avg22[7], avg221[7], avg23[7], avg231[7], avg24[7];

    //Skips the first 7 lines of data
    for(int i = 0; i<=7; i++){
        fgets(row, 100, data1);
        fgets(row, 100, data2);
        fgets(row, 100, data3);
    }

    //Reading from 2021-22 data
    while (!feof(data1)){
        fgets(row, 100, data1);
        sscanf(row, "%i %lf %lf %lf %lf %lf %lf %lf %lf", &year, &day, &savg, &mavg, &havg, &eavg, &oavg, &clavg, &total);
        //Summation of 2021 and 2022 data for q6
        if (year == 2021){
            count21++;
            avg21[0] += savg;
            avg21[1] += mavg;
            avg21[2] += havg;
            avg21[3] += eavg;
            avg21[4] += oavg;
            avg21[5] += clavg;
            avg21[6] += total;
        }
        if (year == 2022){
            count22++;
            avg22[0] += savg;
            avg22[1] += mavg;
            avg22[2] += havg;
            avg22[3] += eavg;
            avg22[4] += oavg;
            avg22[5] += clavg;
            avg22[6] += total;
        }
    }

    //Reading from 2022-23
    while (!feof(data2)){
        fgets(row, 100, data2);
        sscanf(row, "%i %lf %lf %lf %lf %lf %lf %lf %lf", &year, &day, &savg, &mavg, &havg, &eavg, &oavg, &clavg, &total);
        //Summation of 2022 and 2023 data for q6
        if (year == 2022){
            count221++;
            avg221[0] += savg;
            avg221[1] += mavg;
            avg221[2] += havg;
            avg221[3] += eavg;
            avg221[4] += oavg;
            avg221[5] += clavg;
            avg221[6] += total;
        }
        if (year == 2023){
            count23++;
            avg23[0] += savg;
            avg23[1] += mavg;
            avg23[2] += havg;
            avg23[3] += eavg;
            avg23[4] += oavg;
            avg23[5] += clavg;
            avg23[6] += total;
        }
    }

    //Reading from 2023-24
    while (!feof(data3)){
        count++;
        fgets(row, 100, data3);
        sscanf(row, "%i %lf %lf %lf %lf %lf %lf %lf %lf", &year, &day, &savg, &mavg, &havg, &eavg, &oavg, &clavg, &total);
        //Printing data to a file, for question 5
        if (count != 153){
            fprintf(sup, "%i %lf\n", count, savg);
            fprintf(mich, "%i %lf\n", count, mavg);
            fprintf(huron, "%i %lf\n", count, havg);
            fprintf(erie, "%i %lf\n", count, eavg);
            fprintf(on, "%i %lf\n", count, oavg);
            fprintf(cl, "%i %lf\n", count, clavg);
            fprintf(combine, "%i %lf %lf %lf %lf %lf %lf \n", count, savg, mavg, havg, eavg, oavg, clavg);
        }
        //Summation of 2023 and 2024 data for q6
        if (year == 2023){
            count231++;
            avg231[0] += savg;
            avg231[1] += mavg;
            avg231[2] += havg;
            avg231[3] += eavg;
            avg231[4] += oavg;
            avg231[5] += clavg;
            avg231[6] += total;
        }
        if (year == 2024){
            count24++;
            avg24[0] += savg;
            avg24[1] += mavg;
            avg24[2] += havg;
            avg24[3] += eavg;
            avg24[4] += oavg;
            avg24[5] += clavg;
            avg24[6] += total;
        }
    }

    //Turning from summation to average for 6
    for (int i = 0; i<= 6; i++){
        avg21[i] /= count21;
        avg22[i] /= count22;
        avg221[i] /= count221;
        avg23[i] /= count23;
        avg231[i] /= count231;
        avg24[i] /= count24;
        
    }

    //Printing the table (q6)
    printf("                        Data set 1                      Data set 2                      Data set 3\n");
    printf("                    2021        2022                2022        2023                2023        2024\n");
    for (int i = 0; i<=6; i++){
        if (i == 0){
            printf("Lake Superior:  ");
        }else if(i == 1){
            printf("Lake Michigan:  ");
        }
        else if(i == 2){
            printf("Lake Huron:     ");
        }
        else if(i == 3){
            printf("Lake Erie:      ");
        }
        else if(i == 4){
            printf("Lake Ontario:   ");
        }
        else if(i == 5){
            printf("Lake St Clair:  ");
        }
        else if(i == 6){
            printf("GL Average:     ");
        }
        printf("%10lf %13lf %17lf %12lf %18lf %11lf \n", avg21[i], avg22[i], avg221[i], avg23[i], avg231[i], avg24[i]);
    }
    
    //Reopening the data files for q8
    fclose(data1);
    fclose(data2);
    fclose(data3);
    data3 = fopen("g2023_2024_ice.dat", "r");
    data1 = fopen("g2021_2022_ice.dat", "r");
    data2 = fopen("g2022_2023_ice.dat", "r");
    count = 0;
    for(int i = 0; i<=7; i++){
        fgets(row, 100, data1);
        fgets(row, 100, data2);
        fgets(row, 100, data3);
    }

    //Printing data to files similar to q5, but with all 3 data sets
    while (!feof(data1) || !feof(data2) || !feof(data3)){
        count++;
        fprintf(sup8, "%i ", count);
        fprintf(mich8, "%i ", count);
        fprintf(huron8, "%i ", count);
        fprintf(erie8, "%i ", count);
        fprintf(on8, "%i ", count);
        fprintf(cl8, "%i ", count);
        fgets(row, 100, data1);
        sscanf(row, "%i %lf %lf %lf %lf %lf %lf %lf %lf", &year, &day, &savg, &mavg, &havg, &eavg, &oavg, &clavg, &total);
        fprintf(sup8, "%lf ", savg);
        fprintf(mich8, "%lf ", mavg);
        fprintf(huron8, "%lf ", havg);
        fprintf(erie8, "%lf ", eavg);
        fprintf(on8, "%lf ", oavg);
        fprintf(cl8, "%lf ", clavg);
        fgets(row, 100, data2);
        sscanf(row, "%i %lf %lf %lf %lf %lf %lf %lf %lf", &year, &day, &savg, &mavg, &havg, &eavg, &oavg, &clavg, &total);
        fprintf(sup8, "%lf ", savg);
        fprintf(mich8, "%lf ", mavg);
        fprintf(huron8, "%lf ", havg);
        fprintf(erie8, "%lf ", eavg);
        fprintf(on8, "%lf ", oavg);
        fprintf(cl8, "%lf ", clavg);
        fgets(row, 100, data3);
        sscanf(row, "%i %lf %lf %lf %lf %lf %lf %lf %lf", &year, &day, &savg, &mavg, &havg, &eavg, &oavg, &clavg, &total);
        fprintf(sup8, "%lf\n", savg);
        fprintf(mich8, "%lf\n", mavg);
        fprintf(huron8, "%lf\n", havg);
        fprintf(erie8, "%lf\n", eavg);
        fprintf(on8, "%lf\n", oavg);
        fprintf(cl8, "%lf\n", clavg);
    }
}
