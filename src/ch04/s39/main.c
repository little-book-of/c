#include <stdio.h>
#include <stdlib.h>

typedef struct Counter Counter; // forward declaration

struct Counter {
    int value;

    // methods (function pointers)
    void (*inc)(Counter *self);
    void (*reset)(Counter *self);
    void (*print)(const Counter *self);
};

void counter_inc(Counter *self) { self->value++; }
void counter_reset(Counter *self) { self->value = 0; }
void counter_print(const Counter *self) { printf("Value: %d\n", self->value); }

Counter* new_counter(void) {
    Counter *c = malloc(sizeof(Counter));
    c->value = 0;
    c->inc = counter_inc;
    c->reset = counter_reset;
    c->print = counter_print;
    return c;
}

void free_counter(Counter *c) { free(c); }

int main(void) {
    Counter *c = new_counter();
    c->inc(c);
    c->inc(c);
    c->print(c);
    c->reset(c);
    c->print(c);
    free_counter(c);
    return 0;
}
