//
// Created by User on 02/01/2020.
//

#ifndef BMPCLEAN03_POSITION_H
#define BMPCLEAN03_POSITION_H


class Position {
public:
    // Stores the Position components.
    unsigned int x, y;

    // Initializes a Position with a default (0,0) position.
    Position() : x(0), y(0) { }

    // Initializes a color Pixel with the specified RGB values.
    Position(int in_x, int in_y) : x(in_x), y(in_y){ }
};


#endif //BMPCLEAN03_POSITION_H
