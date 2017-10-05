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


TEST(HashTableTest, Clear){
	HashTable a;
	Value val;
		for (int i = 0; i < 353; ++i){
		val.age = i;
		val.weight = 10*i;
		EXPECT_TRUE(a.insert("key"+std::to_string(i), val));
	}
	for (int i = 0; i < 353; ++i){
		EXPECT_TRUE(a.contains("key"+std::to_string(i)));
	}		
	ASSERT_EQ(a.size(), 353);
	a.clear();
	ASSERT_EQ(a.size(), 0);
}


TEST(HashTableTest, Size){
	HashTable a;
	Value val;
		for (int i = 0; i < 453; ++i){
		val.age = i;
		val.weight = 10*i;
		ASSERT_EQ(a.size(), i);
		EXPECT_TRUE(a.insert("key"+std::to_string(i), val));
	}
	for (int i = 0; i < 453; ++i){
		EXPECT_TRUE(a.contains("key"+std::to_string(i)));
	}
}


TEST(HashTableTest, Empty){
	HashTable a;
	Value val;
		EXPECT_TRUE(a.empty());
		for (int i = 0; i < 553; ++i){
		val.age = i;
		val.weight = 10*i;
		EXPECT_TRUE(a.insert("key"+std::to_string(i), val));
		EXPECT_FALSE(a.empty());
	}
	for (int i = 0; i < 553; ++i){
		EXPECT_TRUE(a.contains("key"+std::to_string(i)));
	}	
}


TEST(HashTableTest, OperatorEq){
	HashTable a;
	HashTable b;
	Value val1;
	Value val2;
		for (int i = 0; i < 653; ++i){
		val1.age = i;
		val1.weight = 10*i;
		EXPECT_TRUE(a.insert("key"+std::to_string(i), val1));
		EXPECT_TRUE(b.insert("key"+std::to_string(i), val1));	
	}
	for (int i = 0; i < 653; ++i){
		EXPECT_TRUE(a.contains("key"+std::to_string(i)));
		EXPECT_TRUE(b.contains("key"+std::to_string(i)));
	}
	EXPECT_TRUE(a==b);
	for (int i = 0; i < 653; ++i){
		val2.age = i*3;
		val2.weight = 10*i*3;
		EXPECT_TRUE(a.insert("key"+std::to_string(i), val1));
		EXPECT_TRUE(b.insert("key"+std::to_string(i*3), val2));
		
	}
	for (int i = 0; i < 653; ++i){
		EXPECT_TRUE(a.contains("key"+std::to_string(i)));
		EXPECT_TRUE(b.contains("key"+std::to_string(i*3)));
	}
	EXPECT_FALSE(a==b);
}

TEST(HashTableTest, OperatorNotEq){
	HashTable a;
	HashTable b;
	Value val1;
	Value val2;
		for (int i = 0; i < 653; ++i){
		val1.age = i;
		val1.weight = 10*i;
		EXPECT_TRUE(a.insert("key"+std::to_string(i), val1));
		EXPECT_TRUE(b.insert("key"+std::to_string(i), val1));	
	}
	for (int i = 0; i < 653; ++i){
		EXPECT_TRUE(a.contains("key"+std::to_string(i)));
		EXPECT_TRUE(b.contains("key"+std::to_string(i)));
	}
	EXPECT_FALSE(a!=b);
	for (int i = 0; i < 653; ++i){
		val2.age = i*3;
		val2.weight = 10*i*3;
		EXPECT_TRUE(a.insert("key"+std::to_string(i), val1));
		EXPECT_TRUE(b.insert("key"+std::to_string(i*3), val2));
		
	}
	for (int i = 0; i < 653; ++i){
		EXPECT_TRUE(a.contains("key"+std::to_string(i)));
		EXPECT_TRUE(b.contains("key"+std::to_string(i*3)));
	}
	EXPECT_TRUE(a!=b);
}


TEST(HashTableTest, Constructor){
	ASSERT_NO_THROW(HashTable a);	
}


TEST(HashTableTest, CopyConstructor){
	HashTable a;
	ASSERT_NO_THROW(HashTable b = a);	
}


TEST(HashTableTest, Swap){
	HashTable a;
	HashTable b;
	Value val1;
	Value val2;
		EXPECT_TRUE(a.empty());
		for (int i = 0; i < 753; ++i){
		val1.age = i;
		val1.weight = 10*i;
		val2.age = i*3;
		val2.weight = 10*i*3;	
		EXPECT_TRUE(a.insert("key"+std::to_string(i), val1));
		EXPECT_TRUE(b.insert("key"+std::to_string(i*3), val2));
	}
	for (int i = 0; i < 753; ++i){
		EXPECT_TRUE(a.contains("key"+std::to_string(i)));
		EXPECT_TRUE(b.contains("key"+std::to_string(i*3)));
	}
	HashTable buf1 = a;
	HashTable buf2 = b;
	a.swap(b);
	EXPECT_TRUE(a == buf2);
	EXPECT_TRUE(b == buf1);
}


TEST(HashTableTest, At){
	HashTable a;
	Value val;
	val.age = 20;
	val.weight = 80;
	//ASSERT_THROW(a.at("Key"), "Empty List");
	a.insert("Key", val);
	ASSERT_NO_THROW(a.at("Key"));
	EXPECT_EQ(val.age, a.at("Key").age);
	EXPECT_EQ(val.weight, a.at("Key").weight);
}


TEST(HashTableTest, SquBr){
	HashTable a;
	Value val;
	val.age = 20;
	val.weight = 80;
	a.insert("Key", val);
	ASSERT_NO_THROW(a["Key"]);
	EXPECT_EQ(val.age, a["Key"].age);
	EXPECT_EQ(val.weight, a["Key"].weight);
}


TEST(HashTableTest, Assignment){
	HashTable a;
	HashTable b;
	Value val;
	val.age = 20;
	val.weight = 80;
	b.insert("Key", val);
	a = b;
	EXPECT_TRUE(a==b);
}	
	
	
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}