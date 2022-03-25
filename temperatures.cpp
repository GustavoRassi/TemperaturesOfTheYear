//Gustavo A. Rassi-Fuentes
//CCOM 3002 - MA5

#include <iostream>
#include <iomanip>

using namespace std;

double tempMax(double[12][2]);
double tempMin(double[12][2]);
void printReport(string[12], double[12][2], int);
void printHeaderTable();
double averageTempMax(double[12][2]);
double averageTempMin(double[12][2]);
void printHeaderProgram();

int main()
{
    double temp[12][2];
    double temp_max;
    double temp_min = 0;
    double av_tempMin = 0;
    double av_tempMax = 0;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July",
                "August", "September", "October", "November", "December"};
    int lenght1 = 12;
    int lenght2 = 85;
    char answer = ' ';
   
    do
    {
        system("cls");
        
        printHeaderProgram();
        
        cout << "Enter the highest and lowest temperature of the following month: " << endl;
        for(int i = 0; i < lenght1; i++)
        {
            cout << endl;
            cout << months[i] << ": ";
            cin >> temp[i][0] >> temp[i][1];
        }
        
        printHeaderTable();
        
        for (int i = 0; i < lenght1; i++)
        {
            temp_max = tempMax(temp);
            temp_min = tempMin(temp);
            av_tempMax = averageTempMax(temp);
            av_tempMin = averageTempMin(temp);
            printReport(months, temp, i);
        }
        
        for(int x = 0; x <= lenght2; x++)
            cout << "-";
        
        cout << endl << endl;
        cout << "Average of maximum temperatures: " << av_tempMax << endl;
        cout << "Average of minimum temperatures: " << av_tempMin << endl;
        cout << "The coldest month of the year is: ";
        
        for (int i = 0; i < 12; i++)
            if (temp_min == temp[i][1])
                cout << months[i];
        cout << endl;
        cout << endl;
        
        do
        {
            cout << "Re-attempt program? [Y/y/N/n]" << endl;
            cout << "> ";
            cin >> answer;
        }while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');
    }while (answer == 'y' || answer == 'Y');

    return 0;
}
double tempMax(double t[12][2])
{
    int lenght = 12;
    double x;
    x = t[0][0];
    
    for(int k = 0; k < lenght; k++)
        if(x < t[k][0])
            x = t[k][0];
    
    return x;
}
double tempMin(double tem[12][2])
{
    int lenght = 12;
    double x;
    x = tem[0][1];
    
    for(int k = 0; k < lenght; k++)
        if(x > tem[k][1])
            x = tem[k][1];
            
    return x;
}
void printReport(string month[12], double t[12][2], int a)
{
    cout << left;
    cout << setw(18);
    cout << fixed;
    cout << setprecision(1);
    cout << month[a];
    cout << setw(18);
    cout << t[a][0];
    cout << setw(18);
    cout << t[a][1];
    cout << setw(18);
    cout << (t[a][0] + t[a][1]) / 2;
    cout << endl;
}
void printHeaderTable()
{
    int lenght = 85;
    
    cout << endl;
    
    for(int x = 0; x <= lenght; x++)
        cout << "-";
    cout << endl;
    cout << "MONTH             MAX. TEMP.        MIN. TEMP.        AVER. TEMP." << endl;
    for(int x = 0; x <= lenght; x++)
        cout << "-";
    
    cout << endl;
}
double averageTempMax(double t[12][2])
{
    double av_max, sum_max = 0;
    int lenght = 12;
    
    for (int i = 0; i < lenght; i++)
    {
        sum_max += t[i][0];
    }
    av_max = sum_max / 12;
    
    return av_max;
}
double averageTempMin(double t[12][2])
{
    int lenght = 12;
    double min_av, sum_min = 0;
    
    for (int i = 0; i < lenght; i++)
    {
        sum_min += t[i][1];
    }
    min_av = sum_min / 12;
    
    return min_av;
}
void printHeaderProgram()
{
    cout << "Gustavo A. Rassi Fuentes          CCOM 3002 - MA5";
    cout << endl << endl;
    cout << "This is a program capable of analyzing the maximum and minimum temperature," << endl;
    cout << "of each month and calculate the average of each one, according to the temperatures" << endl;
    cout << "entered by the user. Then, the program will calculate the average of the" << endl;
    cout << "maximum and minimum temperatures, and finally, identify the coldest month" << endl;
    cout << "of the year." << endl;
    cout << endl;
}








