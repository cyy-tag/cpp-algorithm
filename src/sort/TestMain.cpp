#include <vector>
#include <random>
#include <algorithm>
#include <gtest/gtest.h>
#include "InsertSort.h"
#include "QuickSort.h"

class SortTest : public  testing::Test {
protected:
    void SetUp() override {
        int count = 1000;

        for(int i = 0; i < count; ++i) {
            test_data_.push_back(mt_());
        }

        result_data_ = test_data_;
        std::sort(result_data_.begin(), result_data_.end());
    }

    std::vector<int64_t> test_data_;
    std::vector<int64_t> result_data_;
    std::random_device rd_;
    std::mt19937 mt_{rd_()};
};

TEST_F(SortTest, TestInserSort) {
    InsertSort(test_data_);
    ASSERT_EQ(test_data_.size(), result_data_.size());
    for(int i = 0; i < test_data_.size(); ++i)
    {
        ASSERT_EQ(test_data_[i], result_data_[i]);
    }
}

TEST_F(SortTest, TestQuickSort) {
    QuickSort(test_data_, 0, test_data_.size()-1);
    ASSERT_EQ(test_data_.size(), result_data_.size());
    for(int i = 0; i < test_data_.size(); ++i)
    {
        ASSERT_EQ(test_data_[i], result_data_[i]);
    }
}
