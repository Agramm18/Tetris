#ifndef FORMS_H
#define FORMS_H

typedef struct block {
    int x;
    int y;
} block;

typedef struct form {
    block blocks[4];
} form;

block set_block(int x, int y);

form laying_stroke(void);
form four_blocks(void);
form laying_t(void);
form standing_l(void);
form standing_l_mirrored(void);
form zick_zack(void);
form zick_zack_mirrored(void);

void configure_forms(form forms[7]);

#endif