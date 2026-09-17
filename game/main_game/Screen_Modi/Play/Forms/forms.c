#include <stdio.h>
#include "forms.h"

block set_block(int x, int y) {
    block value;

    value.x = x;
    value.y = y;

    return value;
}

form laying_stroke() {
    form rows;

    rows.blocks[0] = set_block(0, 0);
    rows.blocks[1] = set_block(1, 0);
    rows.blocks[2] = set_block(2, 0);
    rows.blocks[3] = set_block(3, 0);

    return rows;
}

form four_blocks() {
    form rows;

    rows.blocks[0] = set_block(0, 0);
    rows.blocks[1] = set_block(1, 0);
    rows.blocks[2] = set_block(0, 1);
    rows.blocks[3] = set_block(1, 1);

    return rows;
}

form laying_t() {
    form rows;

    rows.blocks[0] = set_block(0, 0);
    rows.blocks[1] = set_block(1, 0);
    rows.blocks[2] = set_block(2, 0);
    rows.blocks[3] = set_block(1, 1);

    return rows;
}


form standing_l() {
    form rows;

    rows.blocks[0] = set_block(0, 0);
    rows.blocks[1] = set_block(0, 1);
    rows.blocks[2] = set_block(0, 2);
    rows.blocks[3] = set_block(1, 2);

    return rows;

}

form standing_l_mirrored() {
    form rows;

    rows.blocks[0] = set_block(1, 0);
    rows.blocks[1] = set_block(1, 1);
    rows.blocks[2] = set_block(1, 2);
    rows.blocks[3] = set_block(0, 2);

    return rows;
}

form zick_zack() {
    form rows;

    rows.blocks[0] = set_block(0, 0);
    rows.blocks[1] = set_block(0, 1);
    rows.blocks[2] = set_block(1, 1);
    rows.blocks[3] = set_block(1, 2);

    return rows;
}

form zick_zack_mirrored() {
    form rows;

    rows.blocks[0] = set_block(0, 0);
    rows.blocks[1] = set_block(1, 0);
    rows.blocks[2] = set_block(1, 1);
    rows.blocks[3] = set_block(2, 1);

    return rows;
}

void configure_forms(form forms[7]) {

    forms[0] = laying_stroke();
    forms[1] = four_blocks();
    forms[2] = laying_t();
    forms[3] = standing_l();
    forms[4] = standing_l_mirrored();
    forms[5] = zick_zack();
    forms[6] = zick_zack_mirrored();
}