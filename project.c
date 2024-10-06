#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_or_decrypt()
{
    char input_file[100], output_file[100], password[100];
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);
    printf("Enter encryption key: ");
    scanf("%s", password);
    FILE *inputted_f = fopen(input_file, "rb");
    FILE *outputted_f = fopen(output_file, "wb");
    if(inputted_f == NULL || outputted_f == NULL)
    {
        printf("Error opening input file!\n");
        exit(1);
    }
    if(outputted_f == NULL)
    {
        printf("Error opening output file!\n");
        exit(1);
    }
    size_t password_len = strlen(password);
    size_t i = 0;
    char ch;

    while((ch = fgetc(inputted_f)) != EOF)
    {
        fputc(ch ^ password[i % password_len], outputted_f);
        i++;
    }
    fclose(inputted_f);
    fclose(outputted_f);
    printf("File processed successfully.\n");
}

void check_hash()
{
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "rb");
    if(file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    unsigned long hash = 0;
    int ch;
    while((ch = fgetc(file)) != EOF)
    {
        hash = hash ^ ((hash << 5) + ch + (hash >> 2));
    }
    fclose(file);
    printf("Hash value: %lu\n", hash);
    printf("Do you want to save the hash value to a file? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if(choice == 'y')
    {
        char hash_filename[100];
        printf("Enter the file name to save the hash value: ");
        scanf("%s", hash_filename);
        FILE *hash_file = fopen(hash_filename, "w");
        if(hash_file == NULL)
        {
            printf("Error opening file!\n");
            exit(1);
        }
        fprintf(hash_file, "%lu", hash);
        fclose(hash_file);
        printf("Hash value saved to %s\n", hash_filename);
    }
}

void select(){
    int choice;
    printf("1. Encrypt/Decrypt\n");
    printf("2. Check Hash\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            encrypt_or_decrypt();
            break;
        case 2:
            check_hash();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            select();
    }
}
int main() {
    printf("\n");
    printf("**************************************************************\n");
    printf("*                       FILE ENCRYPTOR                       *\n");
    printf("**************************************************************\n");
    //welcome 
    printf("\n");
    printf("Welcome to File Encryptor!\n");
    select();
    return 0;
}
