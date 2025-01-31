#ifndef PROBLEM933_MAIN_H
#define PROBLEM933_MAIN_H
#include <queue>

class RecentCounter {
    private:
    std::queue<int> calls{};
public:
    RecentCounter();
    int ping(int t);
};


#endif // PROBLEM933_MAIN_H
