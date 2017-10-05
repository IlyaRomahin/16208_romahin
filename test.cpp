#include "Hashtable.cpp"
#include <gtest/gtest.h>

TEST(HashTableTest, Insert){
	HashTable a;
	Value val;
	ASSERT_EQ(a.size(), 0);
	for (int i = 0; i < 9; ++i){
		ASSERT_EQ(a.size(), i);
		val.age = i;
		val.weight = 10*i;
		EXPECT_TRUE(a.insert("key"+std::to_string(i), val));
	}
	for (int i = 0; i < 9; ++i){
		EXPECT_TRUE(a.contains("key"+std::to_string(i)));
	}
}


TEST(HashTableTest, InsertRehashing){
	HashTable a;
	Value val;
	for (int i = 0; i < 53; ++i){
		val.age = i;
		val.weight = 10*i;
		EXPECT_TRUE(a.insert("key"+std::to_string(i), val));
	}
	for (int i = 0; i < 53; ++i){
		EXPECT_TRUE(a.contains("key"+std::to_string(i)));
	}
}


TEST(HashTableTest, Contains){
	HashTable a;
	Value val;
	for (int i = 0; i < 153; ++i){
		val.age = i;
		val.weight = 10*i;
		EXPECT_TRUE(a.insert("key"+std::to_string(i), val));
	}
	for (int i = 0; i < 153; ++i){
		EXPECT_TRUE(a.contains("key"+std::to_string(i)));
	}
	EXPECT_FALSE(a.contains("key"+std::to_string(154)));
}

TEST(HashTableTest, Erase){
	HashTable a;
	Value val;
	for (int i = 0; i < 253; ++i){
		val.age = i;
		val.weight = 10*i;
		EXPECT_TRUE(a.insert("key"+std::to_string(i), val));
	}
	for (int i = 0; i < 253; ++i){
		EXPECT_TRUE(a.contains("key"+std::to_string(i)));
	}
	for (int i = 89; i < 98; ++i){
		EXPECT_TRUE(a.erase("key"+std::to_string(i)));
	}
	for (int i = 89; i < 98; ++i){
		EXPECT_FALSE(a.contains("key"+std::to_string(i)));
	}
	EXPECT_TRUE(a.contains("key"+std::to_string(88)));
	EXPECT_TRUE(a.contains("key"+std::to_string(99)));
}





int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}