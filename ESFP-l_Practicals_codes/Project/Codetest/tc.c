#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Student 
{
    char name[MAX_NAME_LENGTH];
    char status; // 'p' for present, 'a' for absent
};

struct Student students[MAX_STUDENTS];
int totalStudents = 0;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void saveData() 
{
    FILE *file = fopen("attendance.txt", "w");

    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }

    // Print table header
    printf("| %-20s | %-8s |\n", "Name", "Status");
    printf("|----------------------|----------|\n");

    for (int i = 0; i < totalStudents; i++) 
    {
        fprintf(file, "%s %c\n", students[i].name, students[i].status);
        
        // Print table row
        printf("| %-20s | %-8c |\n", students[i].name, students[i].status);
    }

    fclose(file);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loadData() 
{
    FILE *file = fopen("attendance.txt", "r");

    if (file == NULL) 
    {
        printf("No saved data found.\n");
        return;
    }

    while (fscanf(file, "%s %c", students[totalStudents].name, &students[totalStudents].status) != EOF) 
    {
        totalStudents++;
    }

    fclose(file);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool authenticate(char userType) 
{
    char username[20], password[20];

    if (userType == 't') 
    {
        printf("Teacher Login\n");
    } 
    else if (userType == 's') 
    {
        printf("Student Login\n");
    } 
    else 
    {
        printf("Invalid user type\n");
        return false;
    }

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Perform authentication logic here (dummy check for demonstration)
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) 
    {
        printf("Login successful!\n");
        return true;
    } 
    else 
    {
        printf("Login failed. Incorrect username or password.\n");
        return false;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void teacherMenu() 
{
    printf("Enter the number of students: ");
    scanf("%d", &totalStudents);

    if (totalStudents > MAX_STUDENTS) 
    {
        printf("Exceeded maximum limit of students.\n");
        return;
    }

    // Print table header
    printf("| %-20s | %-8s |\n", "Name", "Status");
    printf("|----------------------|----------|\n");

    for (int i = 0; i < totalStudents; i++) 
    {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter status for %s (p for present, a for absent): ", students[i].name);
        scanf(" %c", &students[i].status);

        // Print table row
        printf("| %-20s | %-8c |\n", students[i].name, students[i].status);
    }

    saveData();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void studentMenu() 
{
    char name[MAX_NAME_LENGTH];
    printf("Enter your name: ");
    scanf("%s", name);

    // Print table header
    printf("| %-20s | %-8s |\n", "Name", "Status");
    printf("|----------------------|----------|\n");

    for (int i = 0; i < totalStudents; i++) 
    {
        if (strcmp(students[i].name, name) == 0) 
        {
            printf("| %-20s | %-8c |\n", students[i].name, students[i].status);
            return;
        }
    }

    printf("Student not found.\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() 
{
    char userType;  // Change from int to char

    while (1) // Infinite loop
    {
        loadData();

        printf("\n\nChoose user type (t for teacher, s for student, 3 to end): ");
        scanf(" %c", &userType);  // Use %c for a character

        if (userType == '3') 
        {
            printf("Ending program.\n");
            break; // Exit the loop and end the program
        }

        if (userType == 't' || userType == 's') 
        {
            if (authenticate(userType)) 
            {
                if (userType == 't') 
                {
                    teacherMenu();
                } 
                else if (userType == 's') 
                {
                    studentMenu();
                }
            }
        } 
        else 
        {
            printf("Invalid choice. Please enter t, s, or 3.\n");
        }
    }

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////