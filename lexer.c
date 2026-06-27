#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

// плохо зато руками сам всё сделал

char text[] = "L  1a.3  50 T 20 +I 0.0 O 2.0 I  \" ";
char delimiter[] = ".";
char *endptr;
int error_code = 0;
int main()
{
    int i = 0;
    int j = 0;
    int k = 0;

    char literal_buffer[60];
    char* left;
    char* right;
    char lex;


    token_T tokens[100] = {0};

    for (int j = 0; j < strlen(text);)
    {
        char lex = text[j];

        switch (lex)
        {
        case 'L':
            tokens[i].TokenType = TOKEN_L;
            i++;
            j++;
            break;
        case 'T':
            tokens[i].TokenType = TOKEN_T;
            i++;
            j++;
            break;
        case 'A':
            if (text[j + 1] == 'N')
            {
                tokens[i].TokenType = TOKEN_AN;
                j = j + 2;
                i++;
                break;
            }
            tokens[i].TokenType = TOKEN_A;
            i++;
            j++;
            break;
        case 'O':
            if (text[j + 1] == 'N')
            {
                tokens[i].TokenType = TOKEN_ON;
                j = j + 2;
                i++;
                break;
            }
            tokens[i].TokenType = TOKEN_O;
            i++;
            j++;
            break;
        case 'X':
            tokens[i].TokenType = TOKEN_X;
            i++;
            j++;
            break;
        case 'S':
            tokens[i].TokenType = TOKEN_S;
            i++;
            j++;
            break;
        case 'R':
            tokens[i].TokenType = TOKEN_R;
            i++;
            j++;
            break;
        case '=':
            tokens[i].TokenType = TOKEN_ASSIGN;
            i++;
            j++;
            break;
        case '+':
            if (text[j + 1] == 'I')
            {
                tokens[i].TokenType = TOKEN_ADD_I;
                j = j + 2;
                i++;
                break;
            }
         case '"':
            tokens[i].TokenType = TOKEN_QUOTE;
            i++;
            j++;
            break;

        default:
            if (isalnum(lex))
            {
                while (isalnum(text[j]) || text[j] == '.')
                {
                    literal_buffer[k++] = text[j++];
                }

                literal_buffer[k] = '\0';
                if (strchr(literal_buffer, '.'))
                {    
                    tokens[i].TokenType = TOKEN_ADDRESS;
                    tochkenyzer(literal_buffer, &left, &right);
                    if (strchecker(left) && strchecker(right))
                    {
                    tokens[i].byte_offset = atoi(left);
                    tokens[i].bit_offset = atoi(right);
                    i++;
                    free(left); free(right);
                    }
                    else {tokens[i].TokenType = TOKEN_UNKNOWN; i++;}
                }
                else if (isdigit(literal_buffer[0]))
                {
                    tokens[i].TokenType = TOKEN_DIGITS;
                    tokens[i].value = atoi(literal_buffer);
                    i++;
                }
                k = 0;
            }
            else
            {
                j++;
            }
        }
    }
    print_tokens(tokens, 20);

}

// начиная отсюда идёт нейрокал для дебага

const char *token_type_to_string(int type)
{
    switch (type)
    {
    case TOKEN_UNKNOWN:
        return "TOKEN_UNKNOWN";

    case TOKEN_L:
        return "TOKEN_L";
    case TOKEN_T:
        return "TOKEN_T";
    case TOKEN_A:
        return "TOKEN_A";
    case TOKEN_AN:
        return "TOKEN_AN";
    case TOKEN_O:
        return "TOKEN_O";
    case TOKEN_ON:
        return "TOKEN_ON";
    case TOKEN_X:
        return "TOKEN_X";
    case TOKEN_XN:
        return "TOKEN_XN";
    case TOKEN_S:
        return "TOKEN_S";
    case TOKEN_R:
        return "TOKEN_R";
    case TOKEN_ASSIGN:
        return "TOKEN_ASSIGN";

    case TOKEN_ADD_I:
        return "TOKEN_ADD_I";
    case TOKEN_SUB_I:
        return "TOKEN_SUB_I";
    case TOKEN_MUL_I:
        return "TOKEN_MUL_I";
    case TOKEN_DIV_I:
        return "TOKEN_DIV_I";

    case TOKEN_LPAREN:
        return "TOKEN_LPAREN";
    case TOKEN_RPAREN:
        return "TOKEN_RPAREN";

    case TOKEN_DIGITS:
        return "TOKEN_DIGITS";
    case TOKEN_ADDRESS:
        return "TOKEN_ADDRESS";
    case TOKEN_I:
        return "TOKEN_I";
    case TOKEN_Q:
        return "TOKEN_Q";
    case TOKEN_M:
        return "TOKEN_M";

    case TOKEN_B:
        return "TOKEN_B";
    case TOKEN_W:
        return "TOKEN_W";
    case TOKEN_D:
        return "TOKEN_D";

    case TOKEN_DOT:
        return "TOKEN_DOT";
    case TOKEN_COMMA:
        return "TOKEN_COMMA";
    case TOKEN_QUOTE:
        return "TOKEN_QUOTE";

    case TOKEN_EOF:
        return "TOKEN_EOF";

    default:
        return "INVALID_TOKEN";
    }
}

void print_tokens(token_T tokens[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (tokens[i].TokenType == TOKEN_DIGITS)
        {
            printf("token #%d : %s (%d)\n",
                   i,
                   token_type_to_string(tokens[i].TokenType),
                   tokens[i].value);
        }
        else if (tokens[i].TokenType == TOKEN_ADDRESS)
        {
            printf("token #%d : %s (%d, %d)\n",
                   i,
                   token_type_to_string(tokens[i].TokenType),
                   tokens[i].byte_offset,
                   tokens[i].bit_offset);
        }
        else
        {
            printf("token #%d : %s\n",
                   i,
                   token_type_to_string(tokens[i].TokenType));
        }
    }
}

void error_hanndler(error_code, i)
{
}




//strtok подвёл
void tochkenyzer (char *str, char** left_p, char** right_p){
char *p = strchr(str, '.');
int left_len = (p - str);
*left_p = malloc (left_len + 1);
int right_len = strlen(p + 1);
*right_p = malloc(right_len + 1);



strncpy(*left_p, str, left_len);
strncpy(*right_p, p+1, right_len);
(*left_p)[left_len] = '\0';
(*right_p)[right_len] = '\0';

}

int strchecker(char *a){
    {
    while (*a) {
        if (isdigit(*a++) == 0) return 0;
    }

    return 1;
}
}