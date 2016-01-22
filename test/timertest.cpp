#include "timer.h"
#include <gtest/gtest.h>

TEST(TimerTest, StartTimer)
{
        timer t;
        ASSERT_FALSE(t.is_running());

        t.start();
        ASSERT_TRUE(t.is_running());
        ASSERT_FALSE(t.is_paused());
}

TEST(TimerTest, StopTimer)
{
        timer t;
        t.start();
        ASSERT_TRUE(t.is_running());
        t.stop();
        ASSERT_FALSE(t.is_running());
}

TEST(TimerTest, PauseTimer)
{
        timer t;

        t.pause();
        ASSERT_TRUE(t.is_paused());

        t.start();
        ASSERT_FALSE(t.is_paused());
        
        t.pause();
        ASSERT_TRUE(t.is_paused());

        t.pause();
        ASSERT_TRUE(t.is_paused());
}

int main(int argc, char *argv[])
{
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
