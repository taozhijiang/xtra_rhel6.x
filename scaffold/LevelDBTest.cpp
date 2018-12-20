#include <gmock/gmock.h>

#include <leveldb/db.h>
#include <leveldb/comparator.h>
#include <string> 


using namespace ::testing;

TEST(LevelDB, OpenCreateTest) {

    leveldb::DB* db;
	std::string levelDBPath = "./leveldb_tests";
	
    leveldb::Options c_options;
    c_options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(c_options, levelDBPath, &db);
	
	ASSERT_THAT(status.ok(), Eq(true));
	delete db;
	
	// 
	leveldb::Options o_options;
    o_options.error_if_exists = true;
    status = leveldb::DB::Open(o_options, levelDBPath, &db);
	
	ASSERT_THAT(status.ok(), Eq(false));
}


TEST(LevelDB, ReadWriteTest) {
}

TEST(LevelDB, SnapshotReadTest) {
}