#ifndef CYCLIC_QUEUE_TEST_HPP
#define CYCLIC_QUEUE_TEST_HPP

#include "cyclic_queue.hpp"

TEST_CASE("Cyclic queue test") {
    CyclicQueue<int, 5> cq = CyclicQueue<int, 5>();
    SECTION("Saving and getting first element") {
        cq.enqueue(5);
        REQUIRE(cq.dequeue() == 5);
    }
    SECTION("Filling up and emptying out") {
        for (int i = 0; i < 5; i++) {
            cq.enqueue(i);
        }
        for (int i = 0; i < 5; i++) {
            REQUIRE(cq.dequeue() == i);
        }
    }
    SECTION("Filling up, popping latest and emptying out") {
        for (int i = 0; i < 5; i++) {
            cq.enqueue(i);
        }
        REQUIRE(cq.pop() == 4);
        for (int i = 0; i < 4; i++) {
            REQUIRE(cq.dequeue() == i);
        }
    }
}

TEST_CASE("Cyclic queue test") {
    CyclicQueue<int, 5> cq = CyclicQueue<int, 5>();
    SECTION("Filling up beyond max size and emptying out (testing cyclicity)") {
        for (int i = 0; i < 6; i++) {
            cq.enqueue(i);
        }
        ///< Queue is {5, 1, 2, 3, 4} with head starting at 1.
        for (int i = 1; i < 6; i++) {
            REQUIRE(cq.dequeue() == i);
        }
    }
    SECTION("Filling up beyond max size, popping and emptying out (testing cyclicity)") {
        for (int i = 0; i < 6; i++) {
            cq.enqueue(i);
        }
        ///< Queue is {5, 1, 2, 3, 4} and pop takes the latest element 5.
        REQUIRE(cq.pop() == 5);
        for (int i = 1; i < 5; i++) {
            REQUIRE(cq.dequeue() == i);
        }
    }
}

TEST_CASE("Operator tests") {
    CyclicQueue<int, 5> cq = CyclicQueue<int, 5>();
    SECTION("Square bracket operator") {
        for (int i = 0; i < 5; i++) {
            cq.enqueue(i);
        }
        ///< Queue is {0, 1, 2, 3, 4}
        for (int i = 0; i < 5; i++) {
            REQUIRE(cq[i] == i);
        }
        cq.enqueue(5);
        ///< Queue is {5, 1, 2, 3, 4} with head at 1.
        for (int i = 0; i < 5; i++) {
            REQUIRE(cq[i] == i + 1);
        }
    }
}

#endif // CYCLIC_QUEUE_TEST_HPP
