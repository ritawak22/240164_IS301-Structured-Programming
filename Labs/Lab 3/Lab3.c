
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inFile, *outFile;
    char empNo[10], dept[10], exempt[5];
    float payRate;
    int hoursWorked;
    float basePay;

    // Open input file
    inFile = fopen("employee.txt", "r");
    if (inFile == NULL) {
        printf("Error opening employee.txt\n");
        return 1;
    } else {
        printf("employee.txt opened successfully.\n");
    }

    // Open output file
    outFile = fopen("payroll_register.txt", "w");
    if (outFile == NULL) {
        printf("Error creating payroll_register.txt\n");
        fclose(inFile);
        return 1;
    } else {
        printf("payroll_register.txt created successfully.\n");
    }

    // Read and discard header line from input
    char header[100];
    if (fgets(header, sizeof(header), inFile) != NULL) {
        printf("Header skipped: %s\n", header);
    } else {
        printf("No header found in employee.txt\n");
    }

    // Write headers to output file
    fprintf(outFile, "%-12s %-10s %-10s %-8s %-12s %-10s\n",
            "EmployeeNo", "Dept", "PayRate", "Exempt", "HoursWorked", "BasePay");

    // Loop through each employee record
int result;
while ((result = fscanf(inFile, "%s %s %f %s %d", empNo, dept, &payRate, exempt, &hoursWorked)) != EOF) {
    if (result == 5) {
        // Debug print to confirm data is being read
        printf("Read: %s %s %.2f %s %d\n", empNo, dept, payRate, exempt, hoursWorked);

        basePay = payRate * hoursWorked;
        fprintf(outFile, "%-12s %-10s %-10.2f %-8s %-12d %-10.2f\n",
                empNo, dept, payRate, exempt, hoursWorked, basePay);
    } else {
        // If fscanf didn’t read all 5 values, show what happened
        printf("Line skipped (result=%d)\n", result);
    }
}

    fclose(inFile);
    fclose(outFile);

    printf("Payroll register has been created.\n");
    return 0;
}