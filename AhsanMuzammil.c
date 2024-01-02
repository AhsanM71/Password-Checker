#include <stdio.h>
#include <ctype.h>
#include <string.h>

int hasLowerCase(char pass[], int len){
	int i;
	for (i = 0; i < len; i++){
		if (islower(pass[i])){
			return 1;
		}
	}
	return 0;
}

int hasUpperCase(char pass[], int len){
        int i;
	for (i = 0; i < len; i++){
                if (isupper(pass[i])){
                        return 1;
                }
        }
	return 0;
}

int hasDigit(char pass[], int len){
	int i;
	for (i = 0; i < len; i++){
                if (isdigit(pass[i])){
                        return 1;
                }
        }
	return 0;
}

int hasSpecialChar(char pass[], int len){
        int i;
	for (i = 0; i < len; i++){
                if (!isalnum(pass[i])){
                        return 1;
                }
        }
	return 0;
}

int evaluateStrength(int lower, int upper, int digit, int special, int len){
	int pointForlen = 0;
	if (len > 12){
		pointForlen = 1;
	}
	int ans = lower + upper + digit + special + pointForlen;
	return ans;
}

int main(){

	while(1){
        char c[500];
		int choice = 50;
		char password[256];
    	int length = 0;
		int length1 = 0;
		printf("Password Resilience Analyzer\n");
        printf("1. Test a new password\n");
        printf("2. View strength of the last tested password\n");
        printf("3. Exit\n");

    	printf("Enter you choice: ");
		fgets(c, 500, stdin);
		c[strlen(c) - 1] = '\0';
    	//scanf("%s", c);
		length1 = strlen(c);
		
		if (hasDigit(c, length1)){
			sscanf(c, "%d", &choice);
		}
		else{
			printf("Incorrect input try again, type 1,2 or 3.\n");
		}
			

		if (choice == 1){
			printf("Enter the password: ");
			fgets(password, 256, stdin);
			password[strlen(password) - 1] = '\0';
			//scanf("%s", password);
			length = strlen(password);
			if (strlen(password) < 8){
				printf("Error: Password should be at least 8 characters long.\n");
			}
			else{
				int checkLowerCase = hasLowerCase(password, length);
				int checkUpperCase = hasUpperCase(password, length);
				int checkDigits = hasDigit(password, length);
				int checkSpecial = hasSpecialChar(password, length);
				int evalStrength = evaluateStrength(checkLowerCase, checkUpperCase, checkDigits, checkSpecial, length);
				if (evalStrength >= 0 && evalStrength <= 2){
					printf("Password Strength: Weak\n");
				}
				else if (evalStrength >= 3 && evalStrength <= 4){
                                        printf("Password Strength: Moderate\n");
                                }
				else if (evalStrength == 5){
                                        printf("Password Strength: Strong\n");
                                }
			}
		}
		else if (choice == 2){
			length = strlen(password);
			int checkLowerCase = hasLowerCase(password, length);
                        int checkUpperCase = hasUpperCase(password, length);
                        int checkDigits = hasDigit(password, length);
                        int checkSpecial = hasSpecialChar(password, length);
                        int evalStrength = evaluateStrength(checkLowerCase, checkUpperCase, checkDigits, checkSpecial, length);
                        if (evalStrength >= 0 && evalStrength <= 2){
                                printf("Last Tested Password Strength: Weak\n");
                        }
                        else if (evalStrength >= 3 && evalStrength <= 4){
                                printf("Last Tested Password Strength: Moderate\n");
                        }
                        else if (evalStrength == 5){
                                printf("Last Tested Password Strength: Strong\n");
                        }
		}
		else if (choice == 3){
			printf("Exiting...\n");
			break;
		}
		printf("\n");
		
	}
	return 0;
}
