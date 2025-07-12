#include <stdio.h>
#include "lexer.h"
#include "stack.h"
#include "utils.h"


int main(){
    char str[1000];
    fgets(str, sizeof(str), stdin);

    struct stack stack;
    stack_init(&stack, sizeof(char), 100);

    struct lexer lexer;
    lexer_init(&lexer, str);

    for(;;){
        struct token token;
        lexer_next_token(&lexer, &token);

        log_message("INFO", "token(type: %d, string: '%s')", token.type, token.string);

        if(token.type == TOKEN_INTEGER){
            printf("%s ", token.string);
        }
        else if(token.type==TOKEN_PLUS || token.type==TOKEN_MINUS || token.type==TOKEN_MULTIPLY || token.type==TOKEN_DIVIDE){
            while(!stack_is_empty(&stack)){
                char c;
                stack_top(&stack, &c);

                if(c == '(') break;
                if((token.type==TOKEN_MULTIPLY || token.type==TOKEN_DIVIDE) && (c=='+' || c=='-')) break;

                stack_pop(&stack);

                printf("%c ", c);
            }

            stack_push(&stack, token.string);
        }
        else if(token.type == TOKEN_LEFT_PARENTHESIS){
            stack_push(&stack, token.string);
        }
        else if(token.type == TOKEN_RIGHT_PARENTHESIS){
            while(!stack_is_empty(&stack)){
                char c;
                stack_top(&stack, &c);
                stack_pop(&stack);

                if(c == '(') break;

                printf("%c ", c);
            }
        }

        token_free(&token);

        if(token.type == TOKEN_EOF) break;
    }

    while(!stack_is_empty(&stack)){
        char c;
        stack_top(&stack, &c);
        stack_pop(&stack);

        printf("%c ", c);
    }

    stack_free(&stack);

    return 0;
}