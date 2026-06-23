#ifndef TOKEN_H
#define TOKEN_H
typedef struct TOKEN_STRUCT
{
    enum
{
    TOKEN_UNKNOWN = 0,

    // инструкции
    TOKEN_L,
    TOKEN_T,
    TOKEN_A,
    TOKEN_AN,
    TOKEN_O,
    TOKEN_ON,
    TOKEN_X,
    TOKEN_XN,
    TOKEN_S,
    TOKEN_R,
    TOKEN_ASSIGN,   // =

    // арифметика
    TOKEN_ADD_I,
    TOKEN_SUB_I,
    TOKEN_MUL_I,
    TOKEN_DIV_I,

    // скобки
    TOKEN_LPAREN,
    TOKEN_RPAREN,

    // данные
    TOKEN_DIGITS,
    TOKEN_ADDRESS,

    // адреса/области
    TOKEN_I,
    TOKEN_Q,
    TOKEN_M,

    // размер
    TOKEN_B,
    TOKEN_W,
    TOKEN_D,

    // спец
    TOKEN_DOT,
    TOKEN_COMMA,

    TOKEN_EOF
} TokenType;

    int value, bit_offset, byte_offset;
} token_T;

token_T* init_token(int type, char* value);
#endif