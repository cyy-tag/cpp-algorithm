#include <vector>
#include <random>
#include <algorithm>
#include <gtest/gtest.h>
#include "BinSearch.h"
#include <debug/PrintVec.h>

class SearchTest : public testing::Test{
protected:
    void SetUp() override {
        int count = 10000;

        for(int i = 0; i < count; ++i) {
            test_data_.push_back(mt_());
        }
        std::sort(test_data_.begin(),  test_data_.end());
        std::uniform_int_distribution<int> dis(0, count-1);
        result_index = dis(mt_);
        search_target_ = test_data_[result_index];
        auto iter = std::lower_bound(test_data_.begin(), test_data_.end(), search_target_);
        if(iter == test_data_.end()) {
            lower_bound_result_ = -1;
        } else {
            lower_bound_result_ = iter - test_data_.begin();
        }
    }
    std::random_device rd_;
    std::mt19937 mt_{rd_()};
    std::vector<int64_t> test_data_;
    int result_index = -1;
    int64_t search_target_ = -1;
    int lower_bound_result_ = -1;
};

TEST_F(SearchTest, TestBinSearch) {
    ASSERT_EQ(BinSearch(test_data_, search_target_), result_index);
}

TEST_F(SearchTest, TestLowerBound) {
    ASSERT_EQ(LowerBound(test_data_, search_target_), lower_bound_result_);
}

TEST_F(SearchTest, TestLowerBoundCmp) {
    auto cmp = [&](const int64_t& val, const int64_t & target) -> bool {
        return val < target;
    };
    ASSERT_EQ(LowerBound(test_data_, search_target_, cmp), lower_bound_result_);
}

TEST_F(SearchTest, TestLowerBoundCmp1) {
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};
    auto iter = std::lower_bound(nums.begin(), nums.end(), 0);
    if(iter != nums.end()) {
        std::cout << " != " << std::endl;
    }
}
