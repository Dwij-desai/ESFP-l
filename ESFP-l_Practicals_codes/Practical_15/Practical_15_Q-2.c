#include <stdio.h>
#include <string.h>

int factorial(int n) 
{
    if (n == 0 || n == 1) 
    {
        return 1;
    } 
    else 
    {
        return n * factorial(n - 1);
    }
}

int isPalindrome(int n) 
{
    int originalNumber = n;
    int reversedNumber = 0;

    while (n > 0) 
    {
        int digit = n % 10;

        reversedNumber = reversedNumber * 10 + digit;
        n /= 10;
    }

    if (originalNumber == reversedNumber) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }

}

int isArmstrong(int n) 
{
    int originalNumber = n;
    int sum = 0;

    while (n > 0) 
    {
        int digit = n % 10;

        sum += (digit * digit * digit);
        n /= 10;
    }
    if (originalNumber == sum) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

int isPerfect(int n) 
{
    int sum = 0;

    for (int i = 1; i < n; i++) 
    {
        if (n % i == 0) 
        {
            sum += i;
        }
    }
    if (sum == n) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

int main() 
{
    char username[20];
    char password[20];
    printf("Login:\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    if (strcmp(username, "Dwij") != 0 || strcmp(password, "3547") != 0) 
    {
    printf("Login failed. Incorrect username or password.\n");
    return 1;
    }
    int choice, num;
    while (1) 
    {
    printf("\nChoose an option:\n");
    printf("1. Find factorial of a number\n");
    printf("2. Check if a number is a palindrome\n");
    printf("3. Check if a number is an Armstrong number\n");
    printf("4. Check if a number is a perfect number\n");
    printf("5. Exit\n");
    scanf("%d", &choice);
    if (choice == 5) 
    {
    break;
    }
    switch (choice) 
    {
    case 1:
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d\n", num, factorial(num));
    break;
    case 2:
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPalindrome(num)) 
    {
    printf("%d is a palindrome number\n", num);
    } 
    else 
    {
    printf("%d is not a palindrome number\n", num);
    }
    break;
    case 3:
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isArmstrong(num)) 
    {
    printf("%d is an Armstrong number\n", num);
    } 
    else 
    {
    printf("%d is not an Armstrong number\n", num);
    }
    break;
    case 4:
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPerfect(num)) 
    {
    printf("%d is a perfect number\n", num);
    } 
    else 
    {
    printf("%d is not a perfect number\n", num);
    }
    break;
    default:
    printf("Invalid choice. Please select a valid option.\n");
    break;
    }
    }
    return 0;
}