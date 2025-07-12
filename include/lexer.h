#ifndef LEXER_H
#define LEXER_H


#include <ctype.h>
#include "stack.h"
#include "utils.h"


enum token_type{
    TOKEN_EOF,
    TOKEN_UNKNOWN,
    TOKEN_INTEGER,

    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,

    TOKEN_LEFT_PARENTHESIS,
    TOKEN_RIGHT_PARENTHESIS
};


struct token{
    char *string;
    enum token_type type;
};


struct lexer{
    const char *source;
    int position;
};


void token_free(struct token *);
char lexer_peek(const struct lexer *);
char lexer_get(struct lexer *);
void lexer_init(struct lexer *, const char *);
void lexer_next_token(struct lexer *, struct token *);


#endif