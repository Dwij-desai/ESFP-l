#include <stdio.h>
#include <string.h>
struct Employee 
{
    int Emp_Id;
    char Emp_Name[50];
    char Emp_Dept[50];
    char Emp_Designation[50];
    int Salary;
};

int main() 
{
    struct Employee emp;
    int choice, id;
    char name[50];
    FILE *file;
    file = fopen("C:/ICT/SEM-1/ESFP/code/Practical-18/employee.txt", "a+");
    
    if (file == NULL) 
    {
        printf("Unable to open the file.\n");
        return 1;
    }

    printf("1. Enter employee record\n2. Find employee record by ID\n3.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice != 3) 
    {
        switch (choice) 
        {
            case 1:

                printf("Enter employee details (Emp_Id, Emp_Name, Emp_Dept,Emp_Designation, Salary): ");
                scanf("%d %s %s %s %d", &emp.Emp_Id, emp.Emp_Name,emp.Emp_Dept, emp.Emp_Designation, &emp.Salary);
                fprintf(file, "%d %s %s %s %d\n", emp.Emp_Id, emp.Emp_Name,emp.Emp_Dept, emp.Emp_Designation, emp.Salary);

            break;

            case 2:

                printf("Enter the employee ID to find: ");
                scanf("%d", &id);
                rewind(file);

                int found = 0;
                while (fscanf(file, "%d %s %s %s %d\n", &emp.Emp_Id,
                emp.Emp_Name, emp.Emp_Dept, emp.Emp_Designation, &emp.Salary) != EOF) 
                {
                    if (emp.Emp_Id == id) 
                    {
                        printf("%d %s %s %s %d\n", emp.Emp_Id, emp.Emp_Name,
                        emp.Emp_Dept, emp.Emp_Designation, emp.Salary);
                        found = 1;
                        break;
                    }
                }
                if (!found) 
                {
                    printf("Employee not found with ID %d\n", id);
                }
            break;

            default:
            printf("Invalid choice. Please try again.\n");
        }

        printf("\n1. Enter employee record\n2. Find employee record by ID\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

    }
    fclose(file);
    return 0;
}