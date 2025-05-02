#pragma once

namespace biv {
    struct MenuItem {
        const char* const title;
        const MenuItem* (*func)(const MenuItem* current);

        const MenuItem* parent;

        const MenuItem* const *children;
        const int children_count;
    };
}
