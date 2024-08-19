#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char name[20],father[20],address[30],enquiry[20],academic[20],percentage[10],course[20],branch[20],academicyear[20];
    long int contact,coursfee;
    int enquiryy,x,y;
    int eligibility;
    int total;
    char student_type;
    char fee;
    char admission;
    char subject;

    for(;;) 
    {
        printf("\nPress 1 for enquiry in college\n");
        printf("Press 2 for fee details of all years\n");
        printf("Press 3 for admission process in college\n");
        printf("Press 4 for all semester subject\n");
        printf("Press 0 for exit from program\n");
        scanf("%d", &enquiryy);

        switch (enquiryy) 
        {
            case 1:
                printf("Press 1 for eligibility criteria for B-tech course\n");
                scanf("%d", &eligibility);

                switch (eligibility) 
                {
                    case 1:
                        printf("Press a for regular student\n");
                        printf("Press b for diploma to degree student\n");
                        
                        scanf(" %c", &student_type);  // Use a space before %c to skip leading whitespace

                        switch (student_type) 
                        {
                            case 'a':
                                

                                printf("REGULAR STUDENT\n");
                                printf("\n\nRegular students have to take admission in first year only.\n");
                                printf("Eligibility criteria for regular student is 10+2 with Math subject, and average marks should be 70%%.\n");
                                printf("\nEnter your marks here:");

                                scanf("%d",&total);
                                
                                int per=(total*100)/500;
                                
                                printf("\n%f",per);
                                
                                if(per>70)
                                {                                                                                     
                                    printf("\nPress 1 for 1st year enquiry\n");
                                    printf("Press 2 for 2nd year enquiry\n");
                                    printf("Press 3 for 3rd year enquiry\n");
                                    printf("Press 4 for 4th year enquiry\n");
                                    scanf("%d",&enquiryy);

                                    switch (enquiryy)
                                    {
                                        case 1:
                                            printf("1st year enquiry\n");
                                        break;

                                        case 2:
                                            printf("2nd year enquiry\n");
                                        break;

                                        case 3:
                                            printf("3rd year enquiry\n");
                                        break;

                                        case 4:
                                            printf("4th year enquiry\n");
                                        break;

                                        default:
                                            printf("Invalid eligibility option\n");
                                
                                    }
                                }
                                else
                                {
                                    printf("\nyou are not eligible for admission.\n");
                                }

                            break;

                            case 'b':
                                printf("DIPLOMA TO DEGREE STUDENT\n");

                                 printf("Diploma to degree student can take admission in 2nd year directly. No need to take admission in first year.\n");
                                        printf("Eligibility criteria for diploma to degree students is 10+2+1 with IT, and average marks should be 80%%.\n");
                                        printf("Enter your marks here(out of 500):");

                                        scanf("%d",&x);

                                        per=(x*100)/500;

                                        printf("%.2f",per);

                                        if(per<80)
                                        {
                                            printf("\nyou are not eligible for admission\n");
                                        }
                                        else
                                        {
                                            printf("\nPress<2> for 2nd year enquiry");
                                            printf("\nPress<3> for 3rd year enquiry");
                                            printf("\nPress<4> for 4th year enquiry\n");

                                            scanf("%d",&y);

                                        }
                                switch (eligibility)
                                {

                                    case 1:
                                        printf("2nd year enquiry\n");
                                    break;

                                    case 2:
                                        printf("3rd year enquiry\n");
                                    break;

                                    case 3:
                                        printf("4th year enquiry\n");
                                    break;

                                    default:
                                        printf("Invalid eligibility option\n");
                                }

                            break;

                            printf("\nEnquiry Form\n");
                            printf("\nstudent name:");
                            scanf("%s",name);
                            printf("\nfather name:");
                            scanf("%s",father);
                            printf("\nAddress:");
                            scanf("%s",address);
                            printf("\nEnquiry for:");
                            scanf("%s",enquiry);
                            printf("\nacademic:");
                            scanf("%s",academic);
                            printf("\npercentage:");
                            scanf("%s",percentage);
                            //printf("\n%c\n%c\n%c\n%c\n%c\n%c",name,father,address,enquiry,academic,percentage);//

                        }

                    break;

                    default:
                        printf("Plz enter valied number");
                }

            break;

            case 2:
                printf("Press a for fee details of first year\n");
                printf("Press b for fee details of second year\n");
                printf("Press c for fee details of third year\n");
                printf("Press d for fee details of fourth year\n");
                scanf(" %c", &fee);  // Use a space before %c to skip leading whitespace

                switch (fee) 
                {
                    case 'a':
                        printf("\n1st year fee portal is 2,00,000 yen\n");
                    break;

                    case 'b':
                        printf("\n2nd year fee portal is 2,20,000 yen\n");
                    break;

                    case 'c':
                        printf("\n3rd year fee portal is 2,60,000 yen\n"); 
                    break;

                    case 'd':
                        printf("\n4th year fee portal is 2,70,000 yen\n");
                    break;

                    default:
                        printf("\nInvalid fee option\n");
                }

            break;

            case 3:
                printf("Press a for first year admission\n");
                printf("Press b for second year admission\n");
                printf("Press c for third year admission\n");
                printf("Press d for fourth year admission\n");
                scanf(" %c", &admission);  // Use a space before %c to skip leading whitespace

                switch (admission) 
                {
                    case 'a':
                        printf("\n1st year admission portal\n");
                    break;

                    case 'b':
                        printf("\n2nd year admission portal\n");
                    break;

                    case 'c':
                        printf("\n3rd year admission portal\n");
                    break;

                    case 'd':
                        printf("\n4th year admission portal\n");
                    break;

                    default:
                        printf("\nInvalid admission option\n");
                }

                printf("\nstudent name:");
                scanf("%s",name);
                printf("\nfather name:");
                scanf("%s",father);
                printf("\naddress:");
                scanf("%s",address);
                printf("\ncontact number:");
                scanf("%ld",&contact);
                printf("\ncourse admission for:");
                scanf("%s",course);
                printf("\nspecialization branch:");
                scanf("%s",branch);
                printf("\nacadmic year:");
                scanf("%s",academicyear);
                printf("\nlast academic certificate:");
                scanf("%s",academic);
                printf("\ncourse fee:");
                scanf("%ld",&coursfee);
                 
            break;

            case 4:
                printf("Press a for 1st semester subject\n");
                printf("Press b for 2nd semester subject\n");
                printf("Press c for 3rd semester subject\n");
                printf("Press d for 4th semester subject\n");
                scanf(" %c", &subject);  // Use a space before %c to skip leading whitespace

                switch (subject) 
                {
                    case 'a':
                        printf("\n1st semester subject\n");
                    break;

                    case 'b':
                        printf("\n2nd semester subject\n");
                    break;

                    case 'c':
                        printf("\n3rd semester subject\n");
                    break;

                    case 'd':
                        printf("\n4th semester subject\n");
                    break;

                    default:
                        printf("\nInvalid subject option\n");
                }

            break;

            case 0:
                printf("Exiting pro0gram...\n");
                exit(0);  // Terminate the program
            break;

            default:
                printf("\nInvalid option\n");
        }
    }

    return 0;
}
/*
int main()
{
    char a;
    
    printf("Enter character\n");
    scanf(%s,&a);

  return 0;  
}

-->Why use %s instaded of %c
                                goto start;

*/