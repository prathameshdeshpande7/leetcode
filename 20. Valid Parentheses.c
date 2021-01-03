#include <stdbool.h>
#define MAX_STACK_SIZE 10000

typedef struct stack
{
    char *stack_ptr;
    int top;
}stack;

void create_stack(stack *s)
{
    s->stack_ptr = (char *)malloc(MAX_STACK_SIZE * sizeof(char));
    assert(s->stack_ptr != NULL);
    s->top = -1;
}

bool is_full(stack *s)
{
    return s->top == MAX_STACK_SIZE;
}

bool is_empty(stack *s)
{
    return s->top == -1;
}

void push(stack *s, char c)
{
    assert(!is_full(s));
    
    s->top++;
    *(s->stack_ptr + s->top) = c;
}

char pop(stack *s)
{
    assert(!is_empty(s));

    char temp;
    temp = *(s->stack_ptr + s->top);
    s->top--;
    return temp;
}

int peek_top(stack *s)
{
    return s->top == -1 ? -1 : *(s->stack_ptr + s->top);
}

char match_brace(char closing_brace)
{
    char opening_brace;
    
    switch(closing_brace)
    {
        case ')':
            opening_brace = '(';
            break;
        case '}':
            opening_brace = '{';
            break;
        case ']':
            opening_brace = '[';
            break;
        default:
            break;
    }
    return opening_brace;
}

bool isValid(char * s){
    
    stack braces_stack;
    char temp;
    create_stack(&braces_stack);
    
    while (*s != '\0')
    {
        if (*s == '(' || *s == '{' || *s == '[')
            push(&braces_stack, *s);
        else if (peek_top(&braces_stack) == match_brace(*s))
            temp = pop(&braces_stack);
        else
            return false;
      
        s++;
    }
    if (is_empty(&braces_stack))
        return true;
    return false;
}
