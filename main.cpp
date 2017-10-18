#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class FooTest : public ::testing::TestWithParam<const char*> {
};

string MyInfo(const ::testing::TestParamInfo<const char *>& info) {
	return info.param;
}

TEST_P(FooTest, cos) {
	std::cout << GetParam();
}

INSTANTIATE_TEST_CASE_P(InstantiationName,
                        FooTest,
                        ::testing::Values("test1", "test2"));

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS(); 

}
