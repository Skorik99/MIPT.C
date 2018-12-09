// 1.4 Скобки
// алгоритмическая сложность: O(N), где N -- длина скобочной последовательности
#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 10 // Начальный размер стека
#define MULTIPLIER 2 // Динамическое увеличение стека
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

typedef struct Stack_tag {  // создаем стек
    char *data;
    size_t size;
    size_t top;
} Stack_t;

Stack_t* createStack() {
    Stack_t *out = NULL;
    out = (Stack_t *) malloc(sizeof(Stack_t));
    if (out == NULL) {
        exit(OUT_OF_MEMORY);
    }
    out->size = INIT_SIZE;
    out->data = (char *)malloc(out->size * sizeof(char));
    if (out->data == NULL) {
        free(out);
        exit(OUT_OF_MEMORY);
    }
    out->top = 0;
    return out;
}

void deleteStack(Stack_t **stack) {
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}

void resize(Stack_t *stack) {
    stack->size += MULTIPLIER;
    stack->data = (char *)realloc(stack->data, stack->size * sizeof(char));
    if (stack->data == NULL) {
        exit(STACK_OVERFLOW);
    }
}


void push(Stack_t *stack, char value) {
    if (stack->top >= stack->size) {
        resize(stack);
    }
    stack->data[stack->top] = value;
    stack->top++;
}

char pop(Stack_t *stack) {
    if (stack->top == 0) {
        exit(STACK_UNDERFLOW);
    }
    stack->top--;
    return stack->data[stack->top];
}

char peek(const Stack_t *stack) {
    if (stack->top <= 0) {
        exit(STACK_UNDERFLOW);
    }
    return stack->data[stack->top - 1];
}


int main()
{
    Stack_t *sk = createStack();
    int i, j = 1, tmp;
    char Skob[102402]; // Размер скобочной последовательности не указан, поэтому введем максимально допустимую длинну для чтения с помощью fgets
    fgets(Skob, 102402, stdin);
    while(fgets(Skob, 102402, stdin) == NULL)
    {
        printf("Please, input correct values");
        fgets(Skob, 102402, stdin);
    }
    char mass[4] = {'(', '{', '[', '<'};
    char pass[4] = {')', '}', ']', '>'};
    for(i = 0; i <= 3; i++)
    {
        if(mass[i] == Skob[0])  //сканирование первого эл-та на проверку того, открывающая ли это скобка
        {
            push(sk, Skob[0]);
            break;
        }
    }
    if(sk->top == 0)   // Если скобка закрывающая, то функция push не сработает и в стеке top == 0
    {
        printf("NO");
        deleteStack(&sk); // удаляем стэк
        return 0;
    }
    while(Skob[j] != '\n')
    {
        tmp = j; // переменная tmp служит проверкой того, что скобка закрывающая(т.е. в цикле ниже функция push не задействована)
        for(i = 0; i <= 3; i++)
        {
            if(mass[i] == Skob[j])
            {
                push(sk, Skob[j]);
                j++; // если push сработал, то переменная tmp != j и поэтому условие ниже(которое необходимо для закрывающих скобок) не выполняется
                break;
            }
        }
        if(tmp == j)  // условие на то, что скобка -- закрывающая
        {
            i = 0;
            while(sk->data[sk->top - 1] != mass[i]) // этот цикл необходим, чтобы получить номер i-го элемента mass, который лежит вверху стэка, поскольку в pass содержатся соответствующие скобки(только закрывающие) под тем же индексом, которые мы будем сравнивать
                i++;
            if(Skob[j] == pass[i])
                pop(sk);
            else // если закрывающей скобке не ставится в соответствие открывающая, которая лежит на верху стека, то это гарантирует то, что скобочная последовательность неправильная.
            {
                printf("NO");
                deleteStack(&sk);
                return 0;
            }
            j++;
        }
    }
    if(sk->top == 0) // Эта проверка необходима для того, чтобы проверить, что количество открывающих скобок(операция push, top++) равно количеству закрывающих(операция pop, top--)
        printf("YES");
    else
        printf("NO");
    deleteStack(&sk);
    return 0;
}
