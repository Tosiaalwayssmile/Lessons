#include "ex1Functions.cpp"
#include "ex2Functions.cpp"
#include "ex3Functions.cpp"
#include "ex4Functions.cpp"
#include "ex5Functions.cpp"
#include <gtest/gtest.h>
 
 /*********************************   Ex.1    *********************************/

 TEST(SetTo0Test, Byvalue) 
{ 
    float a = 5.0, b = 12.5;
    setTo0Value(a, b);

    ASSERT_EQ(5,a);
    ASSERT_EQ(12.5,b);

    ASSERT_NE(0,a);
    ASSERT_NE(0,b);
}

 TEST(SetTo0Test, ByReference) 
{ 
    float a = 550, b = 60;
    setTo0Ref(a, b);

    ASSERT_EQ(0,a);
    ASSERT_EQ(60,b);

    ASSERT_NE(5,a);
    ASSERT_NE(0,b);
}

 TEST(SetTo0Test, ByPointer) 
{ 
    float a = 50, b = 12.5;
    setTo0Ptr(&a, &b);
    
    ASSERT_EQ(0,a);
    ASSERT_EQ(0,b);

    ASSERT_NE(50,a);
    ASSERT_NE(12.5,b);
}

/*********************************   Ex.2    *********************************/

TEST(MultiplyTest, PositiveIntegers) 
{ 
    ASSERT_EQ(60, multiply(5.0, 12.0));
    ASSERT_NE(15, multiply(6.0, 3.0));
}
 
TEST(MultiplyTest, NegativeFloats) 
{
    ASSERT_EQ(-60, multiply(-5.0, 12.0));
    ASSERT_NE(15, multiply(5.5, -3.0));
    // const bool result = f();
    // EXPECT_EQ(true,result) << "result equals" << result;
}

/*********************************   Ex.3    *********************************/

TEST(nFactorialTest, negativeInput) 
{ 
    ASSERT_EQ(120, nFactorial(-5));
    ASSERT_EQ(120, nFactorial(5));
    ASSERT_NE(120, nFactorial(0));
    ASSERT_EQ(1, nFactorial(0));
    ASSERT_EQ(120, nFactorial(5.5));
}
 
int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }
    