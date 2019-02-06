#ifndef DEFINES_H
#define DEFINES_H

#define _UNICODE
#define UNICODE
#define NULL 0

#define WINDOW_WIDTH 120
#define WINDOW_HEIGHT 40

#define NOMINMAX

#include <vector>
#include <array>
#include <algorithm>

const int screenSize = WINDOW_WIDTH * WINDOW_HEIGHT;

struct ipoint_t {
    int x, y;
};
struct fpoint_t {
    double x, y;

    fpoint_t(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    fpoint_t& operator=(const fpoint_t& a) {
        x = a.x;
        y = a.y;
        return *this;
    }

    fpoint_t operator+(const fpoint_t& a) const {
        return fpoint_t(x + a.x, y + a.y);
    }

    fpoint_t operator-(const fpoint_t &a) const {
        return fpoint_t(x - a.x, y - a.y);
    }
};

inline int Round(const double& x) {
    return x < 0 ? x - 0.5 : x + 0.5;
}
inline int BufferLocation(const int& x, const int& y) {
    return x + WINDOW_WIDTH * y;
}
inline double Clamp(const double& n, const double& lower, const double& upper) {
    return std::max(lower, std::min(n, upper));
}
inline int Clamp(const int &n, const int &lower, const int &upper) {
    return std::max(lower, std::min(n, upper));
}
#endif