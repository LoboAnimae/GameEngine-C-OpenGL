//
// Created by yagdrassyl on 7/26/22.
//

#ifndef PONG_OPENGL_MISC_H
#define PONG_OPENGL_MISC_H

#include <cstdio>

class Misc {
public:
    template<class T>
    static T firstOrDefault(T first, T orDefault);
};

template<class T>
T Misc::firstOrDefault(T first, T orDefault) {
    if (first) { return first; }
    return orDefault;
}


#endif //PONG_OPENGL_MISC_H
