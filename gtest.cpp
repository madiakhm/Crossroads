#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "crossroads.h"

TEST(IntersectionTest, ValidDirectionAndTime) {
    testing::internal::CaptureStdout();
    drive(1, "North", 1);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_THAT(output, testing::HasSubstr("Car 1 going North"));
    EXPECT_THAT(output, testing::HasSubstr("Car number 1 has passed the intersection"));
}

TEST(IntersectionTest, InvalidDirection) {
    EXPECT_THROW(drive(2, "InvalidDirection", 2), std::invalid_argument);
}

TEST(IntersectionTest, NegativeTime) {
    EXPECT_THROW(drive(3, "South", -1), std::invalid_argument);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
