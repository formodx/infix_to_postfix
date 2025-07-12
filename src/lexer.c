#include "lexer.h"


void token_free(struct token *token){
    free(token->string);
}


char lexer_peek(const struct lexer *lexer){
    return lexer->source[lexer->position];
}


char lexer_get(struct lexer *lexer){
    return lexer->source[lexer->position++];
}


void lexer_init(struct lexer *lexer, const char *source){
    lexer->source = source;
    lexer->position = 0;
}


void lexer_next_token(struct lexer *lexer, struct token *token){
    while(isspace(lexer_peek(lexer))) lexer_get(lexer);

    char symbol = lexer_get(lexer);
    switch(symbol){
        case '\0':
            token->type = TOKEN_EOF;
            token->string = strdup("");
            break;

        case '+':
            token->type = TOKEN_PLUS;
            token->string = strdup("+");
            break;

        case '-':
            token->type = TOKEN_MINUS;
            token->string = strdup("-");
            break;

        case '*':
            token->type = TOKEN_MULTIPLY;
            token->string = strdup("*");
            break;

        case '/':
            token->type = TOKEN_DIVIDE;
            token->string = strdup("/");
            break;

        case '(':
            token->type = TOKEN_LEFT_PARENTHESIS;
            token->string = strdup("(");
            break;

        case ')':
            token->type = TOKEN_RIGHT_PARENTHESIS;
            token->string = strdup(")");
            break;

        default:
            if(isdigit(symbol)){
                token->type = TOKEN_INTEGER;

                int cnt = 1;
                struct stack stack;
                stack_init(&stack, sizeof(char), 100);
                while(isdigit(lexer_peek(lexer))){
                    char c = lexer_get(lexer);
                    stack_push(&stack, &c);
                    cnt++;
                }

                token->string = malloc(cnt + 1);
                token->string[0] = symbol;
                for(int i=cnt-1; i>0; --i){
                    char c;
                    stack_top(&stack, &c);
                    stack_pop(&stack);

                    token->string[i] = c;
                }
                token->string[cnt] = '\0';

                stack_free(&stack);
            }
            else{
                token->type = TOKEN_UNKNOWN;
                token->string = strdup("UNKNOWN");
            }
    }
}