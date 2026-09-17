#include <stdio.h>

typedef struct block {
    int x;
    int y;
} block;

typedef struct form {
    block blocks[4];
} form;

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



void configure_forms() {
    int block_height = 25;
    int block_width = 25;
    
    block minimal_block = set_block(25, 25);
}