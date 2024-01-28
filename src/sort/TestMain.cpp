#include <vector>
#include <random>
#include <algorithm>
#include <gtest/gtest.h>
#include "InsertSort.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "CountSort.h"

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

class CountSortTest : public testing::Test {
protected:
    void SetUp() override {
        std::uniform_int_distribution<int> dis(-1000, 1000);
        int count = 10000;
        test_data_.resize(count);
        for(int i = 0; i < count; ++i)
        {
            test_data_.push_back(dis(mt_));
        }
        result_data_ = test_data_;
        std::sort(result_data_.begin(), result_data_.end());
    }

    std::vector<int> test_data_;
    std::vector<int> result_data_;
    std::random_device rd_;
    std::mt19937  mt_{rd_()};
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

TEST_F(SortTest, TestBubbleSort) {
    BubbleSort(test_data_);
    ASSERT_EQ(test_data_.size(), result_data_.size());
    for(int i = 0; i < test_data_.size(); ++i)
    {
        ASSERT_EQ(test_data_[i], result_data_[i]);
    }
}

TEST_F(SortTest, TestMergeSort) {
    MergeSort(const_cast<int64_t *>(test_data_.data()), 0, test_data_.size());
    ASSERT_EQ(test_data_.size(), result_data_.size());
    for (int i = 0; i < test_data_.size(); ++i) {
        ASSERT_EQ(test_data_[i], result_data_[i]);
    }
}

TEST_F(CountSortTest, TestCountSort) {
    int min_val = *std::min_element(test_data_.begin(), test_data_.end());
    int max_val = *std::max_element(test_data_.begin(), test_data_.end());
    CountSort(test_data_, max_val, min_val);
    ASSERT_EQ(test_data_.size(), result_data_.size());
    for(int i = 0; i < test_data_.size(); ++i)
    {
        ASSERT_EQ(test_data_[i], result_data_[i]);
    }
}
