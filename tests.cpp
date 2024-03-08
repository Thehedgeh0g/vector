#include "ProcessVector/ProcessVector.h"
#include <gtest/gtest.h>
#include <cmath>

TEST(ProcessVectorTest, EmptyVector) {
    std::vector<double> vec;
    ProcessVector(vec);
    EXPECT_TRUE(vec.empty());
}

TEST(ProcessVectorTest, VectorWithPositiveElements) {
    std::vector<double> vec = {1.0, 2.0, 3.0};
    ProcessVector(vec);
    EXPECT_EQ(vec, (std::vector<double>{3.0f, 4.0f, 5.0f}));
}

TEST(ProcessVectorTest, VectorWithNoPositiveElements) {
    std::vector<double> vec = {-1.0, -2.0, -3.0};
    ProcessVector(vec);
    EXPECT_EQ(vec, (std::vector<double>{-1.0f, -2.0f, -3.0f}));
}

TEST(ProcessVectorTest, VectorWithMixedElements) {
    std::vector<double> vec = {-1.0, 2.0, -3.0, 4.0};
    ProcessVector(vec);
    EXPECT_EQ(vec, (std::vector<double>{2.0f, 5.0f, 0.0f, 7.0f}));
}

GTEST_API_ int main(int argc, char **argv)
{
    std::cout << "Running tests" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}