#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
///////////////////////////////////----Student status----//////////////////////////////////////////////////////////////
struct Student 
{
    char name[MAX_NAME_LENGTH];
    char status; // 'p' for present, 'a' for absent
};

struct Student students[MAX_STUDENTS];
int totalStudents = 0;
///////////////////////////////////----File Output----//////////////////////////////////////////////////////////////
void saveData(char mode) 
{
    FILE *file;
    
    if (mode == '1') 
    {
        file = fopen("attendance.txt", "a"); // Append mode
    } 
    else if (mode == '2') 
    {
        file = fopen("attendance.txt", "w"); // Write mode (resets file)
    } 
    else 
    {
        printf("Invalid mode.\n");
        return;
    }

    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return;
    }

    // Print table header only if the file is initially empty or in reset mode
    if (ftell(file) == 0 || mode == '2') 
    {
        printf("| %-20s | %-8s |\n", "Name", "Status");
        printf("|----------------------|----------|\n");
    }

    for (int i = 0; i < totalStudents; i++) 
    {
        fprintf(file, "%s %c\n", students[i].name, students[i].status);
        printf("| %-20s | %-8c |\n", students[i].name, students[i].status);
    }

    fclose(file);
}
///////////////////////////////////----File Input----//////////////////////////////////////////////////////////////
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
///////////////////////////////////----login page----//////////////////////////////////////////////////////////////
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
///////////////////////////////////----Teacher Menu----//////////////////////////////////////////////////////////////
void teacherMenu() 
{
    int choice;

    printf("Choose an option:\n");
    printf("1. Add more names\n");
    printf("2. Reset file and write new names\n");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2) 
    {
        if (choice == 1) 
        {
            printf("Enter the number of additional students: ");
            int additionalStudents;
            scanf("%d", &additionalStudents);

            if (totalStudents + additionalStudents > MAX_STUDENTS) 
            {
                printf("Exceeded maximum limit of students.\n");
                return;
            }

            totalStudents += additionalStudents;
        } 
        else if (choice == 2) 
        {
            totalStudents = 0; // Reset the totalStudents count
        }

        // Print table header based on the user's choice
        if (choice == 2) 
        {
            printf("You chose to reset the file. Enter new names:\n");
        }
        else 
        {
            printf("| %-20s | %-8s |\n", "Name", "Status");
            printf("|----------------------|----------|\n");
        }

        for (int i = 0; i < totalStudents; i++) 
        {
            printf("Enter name of student %d: ", i + 1);
            scanf("%s", students[i].name);
            printf("Enter status for %s (p for present, a for absent): ", students[i].name);
            scanf(" %c", &students[i].status);

            // Print table row
            printf("| %-20s | %-8c |\n", students[i].name, students[i].status);
        }

        saveData(choice == 1 ? '1' : '2');
    } 
    else 
    {
        printf("Invalid choice.\n");
    }
}
///////////////////////////////////----Student Menu----//////////////////////////////////////////////////////////////
void studentMenu() 
{
    char name[MAX_NAME_LENGTH];
    printf("Enter your name: ");
    scanf("%s", name);

    printf("\n| %-20s | %-8s |\n", "Name", "Status");
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
///////////////////////////////////----Main interface----//////////////////////////////////////////////////////////////
int main() 
{
    char userType;

    while (1) 
    {
        loadData();

        printf("\n\nChoose user type (t for teacher, s for student, 3 to end): ");
        scanf(" %c", &userType);

        if (userType == '3') 
        {
            printf("\nEnding program.\n");
            break;
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
            printf("\nInvalid choice. Please enter t, s, or 3.\n");
        }
    }

    return 0;
}
///////////////////////////////////----End of Code----//////////////////////////////////////////////////////////////