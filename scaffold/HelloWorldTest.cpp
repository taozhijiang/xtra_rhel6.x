#include <gmock/gmock.h>
#include <string>

using namespace ::testing;

TEST(HelloWorld, DemoTest) {
    ASSERT_THAT("123", Eq("123"));
}
