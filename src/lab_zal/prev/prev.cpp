#include "prev.h"

#include <algorithm>
#include <climits>
#include <memory>

#define DEPTH 32

class Interval {
   public:
    int low;
    int high;

    Interval(int l, int h) : low(l), high(h) {}
};

class Node {
   public:
    int index;
    Interval interval;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(int ind, Interval i) : index(ind), interval(i), left(nullptr), right(nullptr) {}
};

std::vector<std::shared_ptr<Node>> IntervalTree;

void pushBackRoot() {
    IntervalTree.push_back(std::make_shared<Node>(IntervalTree.size(), Interval(INT_MIN, INT_MAX)));
}

// val \in Interval
bool directionLeft(Interval inter, int val) {
    return val <= inter.low / 2 + inter.high / 2;
}

std::shared_ptr<Node> getChild(std::shared_ptr<Node> node, bool left) {
    if (node == nullptr)
        return nullptr;

    return left ? node->left : node->right;
}

void link(std::shared_ptr<Node> currNode, std::shared_ptr<Node> prevNode, bool left) {
    if (left)
        currNode->left = getChild(prevNode, true);
    else
        currNode->right = getChild(prevNode, false);
}

void createChild(std::shared_ptr<Node> currNode, bool left) {
    int mid = currNode->interval.low / 2 + currNode->interval.high / 2;

    if (left)
        currNode->left = std::make_shared<Node>(IntervalTree.size() - 1, Interval(currNode->interval.low, mid));
    else
        currNode->right = std::make_shared<Node>(IntervalTree.size() - 1, Interval(mid + 1, currNode->interval.high));
}

int getIndexOfChild(std::shared_ptr<Node> node, bool left) {
    if ((left && node->left == nullptr) || (!left && node->right == nullptr))
        return 0;

    return left ? node->left->index : node->right->index;
}

void init(const std::vector<int> &seq) {
    pushBackRoot();

    for (int el : seq)
        pushBack(el);
}

int prevInRange(int i, int lo, int hi) {
    std::shared_ptr<Node> node = IntervalTree[i + 1];
    bool left;
    int maxIndex = 0;
    for (int depth = 0; depth < DEPTH; depth++) {
        if (node == nullptr)
            break;

        if (lo == node->interval.low) {
            maxIndex = std::max(maxIndex, node->index);
            break;
        }

        left = directionLeft(node->interval, lo);
        if (left && hi > node->interval.high)
            maxIndex = std::max(maxIndex, getIndexOfChild(node, false));
        node = getChild(node, left);
    }

    node = IntervalTree[i + 1];
    for (int depth = 0; depth < DEPTH; depth++) {
        if (node == nullptr)
            break;

        if (hi == node->interval.high) {
            maxIndex = std::max(maxIndex, node->index);
            break;
        }

        left = directionLeft(node->interval, hi);
        if (!left && lo < node->interval.low)
            maxIndex = std::max(maxIndex, getIndexOfChild(node, true));
        node = getChild(node, left);
    }
    return maxIndex - 1;
}

// current index: IntervalTree.size() - 1
// previous index: IntervalTree.size() - 2
void pushBack(int value) {
    pushBackRoot();
    std::shared_ptr<Node> currNode = IntervalTree[IntervalTree.size() - 1];
    std::shared_ptr<Node> prevNode = IntervalTree[IntervalTree.size() - 2];
    bool left;

    for (int depth = 0; depth < DEPTH; depth++) {
        left = directionLeft(currNode->interval, value);
        link(currNode, prevNode, !left);
        createChild(currNode, left);
        currNode = getChild(currNode, left);
        prevNode = getChild(prevNode, left);
    }
}

void done() {
    IntervalTree.clear();
}