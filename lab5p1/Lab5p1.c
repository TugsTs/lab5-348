#include <stdio.h>

#define MONTHS 12

//function definitions
//need *months[] because we need to store our months as strings.
void MonthlyReport(float sales[], char *months[]){
    printf("\nMonthly Sales Report for 2026: \n");

    printf("Month:\t    Sales:\n");
    for(int i=0;i<MONTHS;i++){
        printf("%-12s %.2f\n", months[i], sales[i]);
    }
}

void salesSummary(float sales[], char *months[]){
    int minindex = 0;
    int maxindex = 0;
    float min = sales[0];
    float max = sales[0];
    float Total = 0;
    float AverageSale = 0;

    for(int i=0;i<MONTHS;i++){
        Total = Total + sales[i];

        if(sales[i] > max){
            max = sales[i];
            maxindex = i;
        }
        if(sales[i] < min){
            min = sales[i];
            minindex = i;
        }
        
    }

    AverageSale = Total/MONTHS;

    printf("\nSales Summary Report \n");

    printf("Minimum sales: %.2f (%s)\n", min,months[minindex]);
    printf("Maximum sales: %.2f (%s)\n", max, months[maxindex]);
    printf("Average sales: %.2f\n",AverageSale);
}

void movingAverage(float sales[], char *months[]){
    printf("\nSix-Month Moving Average Report:\n");

    for(int i=0;i<=6;i++){
        float sum = 0;

        for(int j=i;j<i+6;j++){
            sum = sum + sales[j];
        }
        printf("%s-%s: %.2f\n", months[i], months[i+5], sum/6);
    }
}

void saleSORT(float sales[], char *months[]){
    char *tempMonth;
    float tempsale;
    float sortedSales[MONTHS];
    char *sortedMonths[MONTHS];

    for(int i=0;i<MONTHS;i++){
        sortedSales[i] = sales[i];
        sortedMonths[i] = months[i];
    }
    // 
    for(int i=0;i<MONTHS-1;i++){
        for(int j=i+1;j<MONTHS;j++){
            if(sortedSales[j] > sortedSales[i]){
                tempsale = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = tempsale;

                tempMonth = sortedMonths[i];
                sortedMonths[i] = sortedMonths[j];
                sortedMonths[j]= tempMonth;
            }
        }
    }

    printf("\nSales Report (max to min): \n");
    printf("Month:\t\tSales:\n");
    for(int i=0;i<MONTHS;i++){
        printf("%-10s\t%.2f\n", sortedMonths[i], sortedSales[i]);
    }
}
//we need to add a month array to help format our output to make it look like lab example
int main() 
{
    float sales[MONTHS] = {
        23458.01,40112.00,56011.85,37820.88,37904.67,60200.22,
        72400.31,56210.89,67230.84,68233.12,80950.34,95225.22};

    char *months[MONTHS] = {
        "January","February","March","April","May","June",
        "July","August","September","October","November","December"};

    //call our functions in main:
    MonthlyReport(sales,months);
    salesSummary(sales, months);
    movingAverage(sales,months);
    saleSORT(sales,months);

    return 0;
}

