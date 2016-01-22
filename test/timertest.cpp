#include "timer.h"
#include <gtest/gtest.h>
#include <thread>
#include <chrono>

using Seconds = std::chrono::seconds;

TEST(ClassTest, StartTimer)
{
        timer t;
        ASSERT_FALSE(t.is_started());

        t.start();
        ASSERT_TRUE(t.is_started());
        ASSERT_FALSE(t.is_paused());

        t.start();
        ASSERT_TRUE(t.is_started());
}

TEST(ClassTest, StopTimer)
{
        timer t;
        t.start();
        ASSERT_TRUE(t.is_started());
        t.stop();
        ASSERT_FALSE(t.is_started());
}

TEST(ClassTest, PauseTimer)
{
        timer t;

        t.pause();
        ASSERT_FALSE(t.is_paused());

        t.start();
        ASSERT_FALSE(t.is_paused());
        
        t.pause();
        ASSERT_TRUE(t.is_paused());

        t.pause();
        ASSERT_TRUE(t.is_paused());
}

TEST(TimerTest, StartTimer)
{
        timer t;
        ASSERT_DOUBLE_EQ(0.0, t.elapsed_seconds());
        t.start();

        std::this_thread::sleep_for(Seconds(2));
        double el1 = t.elapsed_seconds();
        ASSERT_TRUE(el1 > 0.0);

        t.start();
        double el2 = t.elapsed_seconds();
        ASSERT_TRUE(el2 < el1);
}

TEST(TimerTest, StopTimer)
{
        timer t;
        t.start();
        // some time passes...
        t.stop();

        double dt = t.elapsed_seconds();
        std::this_thread::sleep_for(Seconds(1));
        ASSERT_DOUBLE_EQ(dt, t.elapsed_seconds());
}

TEST(TimerTest, RunTimerExact)
{
        timer t;
        t.start();
        // some time passes...
        std::this_thread::sleep_for(Seconds(2));
        t.stop();

        // tolerate an delay rate of max. 0.1%
        ASSERT_NEAR(t.elapsed_seconds(), 2.0, 0.001);
}

TEST(TimerTest, PauseTimer)
{
        timer t;
        t.start();
        // some time passes...
        t.pause();
        double el1 = t.elapsed_seconds();
        t.start();
        // some time passes...
        t.pause();

        double el2 = t.elapsed_seconds();
        ASSERT_TRUE(el1 < el2);

        t.stop();
        ASSERT_TRUE(el2 < t.elapsed_seconds());
}

TEST(TimerTest, PauseTimer2)
{
        timer t;
        t.start();
        // some time passes...
        t.stop();
        double el1 = t.elapsed_seconds();
        t.pause();
        ASSERT_DOUBLE_EQ(el1, t.elapsed_seconds());
}

TEST(TimerTest, ResetTimer)
{
        timer t;
        t.start();
        // some time passes...
        t.stop();
        ASSERT_TRUE(t.elapsed_seconds() > 0.0);
        ASSERT_FALSE(t.is_paused());
        ASSERT_FALSE(t.is_started());

}

int main(int argc, char *argv[])
{
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
