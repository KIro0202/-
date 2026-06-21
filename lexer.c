#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

//насрано зато руками сам всё сделал

char text[] = "L 50 T 20 I 0.0 O I 2.0";
char copy[sizeof text];
char delimiter[] = " ";
char *endptr;
int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    strcpy(copy, text);

    char literal_buffer[60];

    char lex;

    char *litera = strtok(copy, delimiter);

    token_T tokens[100] = {0};

    for (int j = 0; j<strlen(text);)
    {
        char lex = text[j];

        switch (lex)
        {
        case 'L':
            tokens[i].TokenType = TOKEN_L;
            i++; j++;
            break;
        case 'T':
            tokens[i].TokenType = TOKEN_T;
            i++; j++;
            break;
        case 'A':
            if (text[j+1] == 'N')
                {
                tokens[i].TokenType = TOKEN_AN; j=j+2;
                break; 
                }
            tokens[i].TokenType = TOKEN_A;
            i++; j++;
            break;
        case 'O':
            if (text[j+1] == 'N')
                {
                tokens[i].TokenType = TOKEN_ON; j = j+2;
                break;
                }
            tokens[i].TokenType = TOKEN_O;
            i++; j++;
            break;
        case 'X':
            tokens[i].TokenType = TOKEN_X;
            i++; j++;
            break;
        case 'S':
            tokens[i].TokenType = TOKEN_S;
            i++; j++;
            break;
        case 'R':
            tokens[i].TokenType = TOKEN_R;
            i++; j++;
            break;
        case '=':
            tokens[i].TokenType = TOKEN_ASSIGN;
            i++; j++;
            break;
        default:   
         if (isalnum(lex))
            {
                while (isalnum(text[j]))
                {
                    literal_buffer[k++] = text[j++];
                }

                literal_buffer[k] = '\0';
                k = 0;
            }
            else{
                j++;
            }
        }
   
    }
    print_tokens(tokens, 20);
}

    // while (litera!=NULL){

    //     long value = strtol(litera, &endptr, 10);

    //     if (*endptr == '\0'){
    //         int value = atoi(litera);
    //         tokens[i].TokenType = TOKEN_NUMBER;
    //         tokens[i].value = value;
    //         i++;
    //     }

    //     switch (litera[0]){
    //         case 'L':
    //         tokens[i].TokenType = TOKEN_L; i++;
    //         break;
    //         case 'T':
    //         tokens[i].TokenType = TOKEN_T; i++;
    //         break;
    //     }
    //     printf("%s\n", litera);
    //     litera = strtok(NULL, delimiter);

    //     switch (litera[0+1]){

    //     }

    // }

    // for (int j = 0; j < i; j++)
    // {
    //     printf("type=%d value=%d\n",
    //            tokens[j].type,
    //            tokens[j].value);
    // }

    // }

    // L 50
    // L 25
    //+I
    // T MW10
    //
    
    
    
    
     //начиная отсюда идёт нейрокал для дебага


    const char* token_type_to_string(int type)
{
    switch (type)
    {
        case TOKEN_UNKNOWN: return "TOKEN_UNKNOWN";

        case TOKEN_L: return "TOKEN_L";
        case TOKEN_T: return "TOKEN_T";
        case TOKEN_A: return "TOKEN_A";
        case TOKEN_AN: return "TOKEN_AN";
        case TOKEN_O: return "TOKEN_O";
        case TOKEN_ON: return "TOKEN_ON";
        case TOKEN_X: return "TOKEN_X";
        case TOKEN_XN: return "TOKEN_XN";
        case TOKEN_S: return "TOKEN_S";
        case TOKEN_R: return "TOKEN_R";
        case TOKEN_ASSIGN: return "TOKEN_ASSIGN";

        case TOKEN_ADD_I: return "TOKEN_ADD_I";
        case TOKEN_SUB_I: return "TOKEN_SUB_I";
        case TOKEN_MUL_I: return "TOKEN_MUL_I";
        case TOKEN_DIV_I: return "TOKEN_DIV_I";

        case TOKEN_LPAREN: return "TOKEN_LPAREN";
        case TOKEN_RPAREN: return "TOKEN_RPAREN";

        case TOKEN_NUMBER: return "TOKEN_NUMBER";

        case TOKEN_I: return "TOKEN_I";
        case TOKEN_Q: return "TOKEN_Q";
        case TOKEN_M: return "TOKEN_M";

        case TOKEN_B: return "TOKEN_B";
        case TOKEN_W: return "TOKEN_W";
        case TOKEN_D: return "TOKEN_D";

        case TOKEN_DOT: return "TOKEN_DOT";
        case TOKEN_COMMA: return "TOKEN_COMMA";

        case TOKEN_EOF: return "TOKEN_EOF";

        default: return "INVALID_TOKEN";
    }
}


void print_tokens(token_T tokens[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (tokens[i].TokenType == TOKEN_NUMBER)
        {
            printf("token #%d : %s (%d)\n",
                   i,
                   token_type_to_string(tokens[i].TokenType),
                   tokens[i].value);
        }
        else
        {
            printf("token #%d : %s\n",
                   i,
                   token_type_to_string(tokens[i].TokenType));
        }
    }
}