#ifndef HCSR04_TEST_BENCH_HPP
#define HCSR04_TEST_BENCH_HPP

#include "wrap-hwlib.hpp"

#include <functional>

/**
 * @brief TestPinIn derived from hwlib::pin_in for hardware agnostic tests
 *
 * @details
 * This class is designed to be passed to classes that use hwlib::pin in.
 * That way these classes can be tested in a virtual environment without
 * requiring physical hardware.
 *
 * @tparam THIS_PTR_T Type (internally known as self) of the emulated environment
 */
template <class THIS_PTR_T>
class TestPinIn : public hwlib::pin_in {
    using Routine = std::function<bool(THIS_PTR_T *)>;

    THIS_PTR_T *self;
    Routine hardwareRoutine;

  public:
    /**
     * @brief Construct a new Test Pin In object
     *
     * @param self Pointer to the emulated environment for storing state
     * @param routine Routine to run when get is called
     */
    TestPinIn(THIS_PTR_T *self, const Routine &routine) : self(self), hardwareRoutine(std::move(routine)) {
    }

    /**
     * @brief Runs the hardwareRoutine with self and returns the determined value by hardwareRoutine
     *
     * @param buf Unused
     * @return true Pin_in is high
     * @return false Pin_in is low
     */
    bool get(hwlib::buffering buf = hwlib::buffering::unbuffered) override {
        return hardwareRoutine(self);
    }
};

/**
 * @brief TestPinOut derived from hwlib::pin_out for hardware agnostic tests
 *
 * @details
 * This class is designed to classes that use hwlib::pin_out.
 * That way these classes can be tested in a virtual environment without
 * requiring phyiscal hardware.
 *
 * @tparam THIS_PTR_T Type (internally known as self) of the emulated environment
 */
template <class THIS_PTR_T>
class TestPinOut : public hwlib::pin_out {
    using Routine = std::function<void(THIS_PTR_T *, bool)>;

    THIS_PTR_T *self;
    Routine hardwareRoutine;

  public:
    /**
     * @brief Construct a new Test Pin Out object
     *
     * @param self Pointer to the emulated environment for storing state
     * @param routine Routine to run when set is called
     */
    TestPinOut(THIS_PTR_T *self, const Routine &routine) : self(self), hardwareRoutine(std::move(routine)) {
    }

    /**
     * @brief Runs the hardwareRoutine with self and v
     *
     * @param v High/low representing the pin_out's output
     * @param buf Unused
     */
    void set(bool v, hwlib::buffering buf = hwlib::buffering::unbuffered) override {
        hardwareRoutine(self, v);
    }
};

class HCSR04TestBench {
  private:
    uint32_t duration;
    TestPinIn<HCSR04TestBench> echo;
    TestPinOut<HCSR04TestBench> trigger;
    uint32_t lastTriggerTime;
    bool lastTriggerLevel;
    uint32_t blastTime;

  public:
    /**
     * @brief Construct a new HCSR04TestBench object with 0 as duration
     */
    HCSR04TestBench()
        : duration(0), echo(this, echoRoutine), trigger(this, triggerRoutine), lastTriggerTime(0), lastTriggerLevel(false),
          blastTime(10000) {
    }

    /**
     * @brief Construct a new HCSR04TestBench with duration as travel time
     *
     * @param duration Sound wave travel time to configure
     */
    HCSR04TestBench(uint32_t duration)
        : duration(duration), echo(this, echoRoutine), trigger(this, triggerRoutine), lastTriggerTime(0), lastTriggerLevel(false),
          blastTime(10000) {
    }

    /**
     * @brief Copy constructor
     *
     * @param other HCSR04TestBench to copy
     */
    HCSR04TestBench(const HCSR04TestBench &other)
        : duration(other.duration), echo(this, echoRoutine), trigger(this, triggerRoutine), lastTriggerTime(0),
          lastTriggerLevel(false), blastTime(10000) {
    }

    /**
     * @brief Get the echo pin object
     *
     * @return hwlib::pin_in& Reference to echo pin
     */
    hwlib::pin_in &getEchoPin() {
        return echo;
    }

    /**
     * @brief Get the trigger pin object
     *
     * @return hwlib::pin_out& Reference to trigger pin
     */
    hwlib::pin_out &getTriggerPin() {
        return trigger;
    }

    /**
     * @brief Echo routine for emulating HCSR04's echo pin
     *
     * @details
     * Emulates the echo pin. If the HCSR04 should be receiving
     * an echo it returns true, otherwise false.
     *
     * @param self HCSR04TestBench for storing state
     * @return true When the current fly duration exceeds the configured test bench's duration.
     * It must also not exceed the configured duration plus blast time.
     * @return false When the time difference < 0 or the emulated sound wave has not returned yet.
     */
    static bool echoRoutine(HCSR04TestBench *self) {
        ///< Return true from lastTriggerTime + duration until lastTriggerTime + duration * 2.
        ///< In doing so, this routine returns true during 'duration'.
        return (hwlib::now_us() > self->lastTriggerTime + self->duration &&
                hwlib::now_us() < self->lastTriggerTime + self->duration * 2);
    }

    /**
     * @brief Trigger routine for emulating HCSR04's trigger pin
     *
     * @details
     * If v is true, sets the lastTriggerTime of self to hwlib::now_us().
     * If v is false, sets the blastTime of self to hwlib::now_us() - self->lastTriggerTime.
     *
     * @param self HCSR04TestBench for storing state
     * @param v High/low value from hwlib::pin_out binding
     */
    static void triggerRoutine(HCSR04TestBench *self, bool v) {
        if (v == true) {
            self->lastTriggerTime = hwlib::now_us();
        } else if (self->lastTriggerLevel == true) {
            self->lastTriggerLevel = false;
            self->blastTime = hwlib::now_us() - self->lastTriggerTime;
        }
    }
};

/**
 * @brief Test HCSR04TestBench Blast Time
 *
 * @details
 * This test case tests the ability of HCSR04TestBench to accurately measure blast time.
 */
TEST_CASE("Test HCSR04TestBench Blast Time") {

    unsigned int blastTime = 10000; ///< 10 ms
    HCSR04TestBench testBench = {blastTime};

    long long int elapsedTime = 0;

    hwlib::pin_in &echoPin = testBench.getEchoPin();
    hwlib::pin_out &triggerPin = testBench.getTriggerPin();
    triggerPin.set(false);
    triggerPin.set(true);
    hwlib::wait_us(10);
    triggerPin.set(false);
    while (!echoPin.get()) {
    }
    long long int startTime = hwlib::now_us();
    ///< After this while loop, echoPin.get() returns true.
    ///< While-loop until echoPin.get() returns false
    while (echoPin.get()) {
    }
    elapsedTime = hwlib::now_us() - startTime;
    ///< We allow the elapsed time to be off by a maximum of one microsecond.
    REQUIRE(elapsedTime >= blastTime - 1);
    REQUIRE(elapsedTime <= blastTime + 1);
}

#endif ///< HCSR04_TEST_BENCH_HPP