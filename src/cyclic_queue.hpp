#ifndef CYCLIC_QUEUE_HPP
#define CYCLIC_QUEUE_HPP

#include <initializer_list>

/**
 * @brief Cyclic Queue
 *
 * @details
 * This container holds values in a C-style array.
 * The array loops back on itself to allow a cyclic pattern.
 * The array can be accessed as a queue but can also pop the latest addition out.
 */
template <typename T, uint32_t size>
class CyclicQueue {
  private:
    T *start, *end;
    T *head, *tail;
    T values[size];
    uint32_t count = 0;
    /**
     * @brief Increment tail pointer
     *
     * @description
     * Increments the tail pointer or loops it around. If the head is replaced, increment head.
     */
    void incrementTail() {
        if (tail == end) {
            tail = start;
        } else {
            tail++;
        }
        count++;
        if (tail == head && count > 1) {
            incrementHead();
        }
    }
    /**
     * @brief Increment head pointer
     *
     * @description
     * Increments the tail pointer or loops it around.
     */
    void incrementHead() {
        if (head == end) {
            head = start;
        } else {
            head++;
        }
        count--;
    }
    /**
     * @brief Decrement tail pointer
     *
     * @description
     * Decrements the tail pointer or loops it around.
     */
    void decrementTail() {
        if (tail == start) {
            tail = end;
        } else {
            tail--;
        }
        count--;
    }

  public:
    CyclicQueue(std::initializer_list<T> init) : start(values), end(values + size - 1), head(start), tail(end) {
        for (T value : init) {
            enqueue(value);
        }
    }
    CyclicQueue() : start(values), end(values + size - 1), head(start), tail(end) {
    }
    /**
     * @brief Square bracket operator
     *
     * @description
     * Allows array-style access to the queue.
     * The queue is counted from the head and looped around accordingly.
     *
     * @param[in] T other The index of the container value we wish to get
     * @return T Requested value in the container
     */
    T &operator[](T other) const {
        while (head + other > end) {
            other -= size;
        }
        return head[other];
    }
    /**
     * @brief Enqueue
     *
     * @description
     * Enqueues the given value into the queue.
     *
     * @param[in] T &value The value we wish to enqueue
     */
    void enqueue(const T &value) {
        incrementTail();
        *tail = value;
    }
    /**
     * @brief Pop
     *
     * @description
     * Pops the last added element from the container.
     *
     * @return T The last added value
     */
    T pop() {
        T return_value = *tail;
        decrementTail();
        return return_value;
    }
    /**
     * @brief Dequeue
     *
     * @description
     * Dequeues the first element from the queue.
     * This is the value currently at head.
     *
     * @return T The value we wish to dequeue.
     */
    T dequeue() {
        T return_value = *head;
        incrementHead();
        return return_value;
    }
    /**
     * @brief peakNext
     *
     * @description
     * Returns the next item to be dequeued without actually dequeueing it.
     *
     * @return T The value we wish to peak.
     */
    const T peakNext() {
        return *head;
    }
    /**
     * @brief peakNewest
     *
     * @description
     * Returns the next item to be popped without actually popping it.
     *
     * @return T The value we wish to peak.
     */
    T peakNewest() {
        return *tail;
    }
    /**
     * @brief
     * getCount
     *
     * @description
     * Returns the amount of items in the container.
     *
     * @return uint32_t The amount of items in the queue.
     */
    const uint32_t getCount() {
        return count;
    }
};
#endif // CYCLIC_QUEUE_HPP