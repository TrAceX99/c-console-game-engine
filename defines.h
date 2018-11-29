#ifndef DEFINES_H
#define DEFINES_H

#define _UNICODE
#define NULL 0

#define WINDOW_WIDTH 120
#define WINDOW_HEIGHT 40

const int screenSize = WINDOW_WIDTH * WINDOW_HEIGHT;

struct ipoint_t {
    int x, y;
};
struct fpoint_t {
    float x, y;
};

inline int round(double x) {
    return x + 0.5;
}
inline int bufferLocation(int x, int y) {
    return x + WINDOW_WIDTH * y;
}

#endif