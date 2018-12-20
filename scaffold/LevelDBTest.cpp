#include <gmock/gmock.h>

#include <leveldb/db.h>
#include <leveldb/comparator.h>
#include <leveldb/write_batch.h>
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

    // clean up
    status = leveldb::DestroyDB(levelDBPath, leveldb::Options()); 
	ASSERT_THAT(status.ok(), Eq(true));
}


TEST(LevelDB, ReadWriteTest) {

    leveldb::DB* db;
	std::string levelDBPath = "./leveldb_tests";
	
    leveldb::Options c_options;
    c_options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(c_options, levelDBPath, &db);
	ASSERT_THAT(status.ok(), Eq(true));

    const std::string key = "xtra_test_key_xxx";
    const std::string val = "xtra_test_value";
    
    status = db->Put(leveldb::WriteOptions(), key, val);
    ASSERT_THAT(status.ok(), Eq(true));

    std::string r_val;
    status = db->Get(leveldb::ReadOptions(), key, &r_val);
    ASSERT_THAT(status.ok(), Eq(true));
    ASSERT_THAT(val, Eq(r_val));

    status = db->Delete(leveldb::WriteOptions(), key);
    ASSERT_THAT(status.ok(), Eq(true));

    status = db->Get(leveldb::ReadOptions(), key, &r_val);
    ASSERT_THAT(status.ok(), Eq(false));
    std::cout << "get nonexists: " << status.ToString() << std::endl;
	
	delete db;

    // clean up
    status = leveldb::DestroyDB(levelDBPath, leveldb::Options()); 
	ASSERT_THAT(status.ok(), Eq(true));
}

TEST(LevelDB, BatchOperationTest) {

    //Read and Write atomic
    
    leveldb::DB* db;
	std::string levelDBPath = "./leveldb_tests";
	
    leveldb::Options c_options;
    c_options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(c_options, levelDBPath, &db);
	ASSERT_THAT(status.ok(), Eq(true));

    const std::string key = "xtra_test_key_xxx";
    const std::string val = "xtra_test_value";
    db->Put(leveldb::WriteOptions(), key, val);


    const std::string key2 = "xtra_test_key2";

    std::string r_val;
    status = db->Get(leveldb::ReadOptions(), key, &r_val);
    ASSERT_THAT(status.ok() && r_val == val, Eq(true));

    {
        leveldb::WriteBatch batch;
        batch.Delete(key);
        batch.Put(key2, val);
        status = db->Write(leveldb::WriteOptions(), &batch);
        ASSERT_THAT(status.ok(), Eq(true));
    }

    r_val = "";
    status = db->Get(leveldb::ReadOptions(), key, &r_val);
    ASSERT_THAT(status.ok(), Eq(false));

    status = db->Get(leveldb::ReadOptions(), key2, &r_val);
    ASSERT_THAT(status.ok() && r_val == val, Eq(true));

	delete db;

    // clean up
    status = leveldb::DestroyDB(levelDBPath, leveldb::Options()); 
	ASSERT_THAT(status.ok(), Eq(true));
}

TEST(LevelDB, SnapshotReadTest) {
    // the same leveldb::DB object may be safely shared by multiple concurrent threads. 
    // Snapshots provide consistent read-only views 

    leveldb::DB* db;
	std::string levelDBPath = "./leveldb_tests";
	
    leveldb::Options c_options;
    c_options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(c_options, levelDBPath, &db);
	ASSERT_THAT(status.ok(), Eq(true));

    const std::string key = "xtra_test_key_xxx";
    const std::string val = "xtra_test_value";
    db->Put(leveldb::WriteOptions(), key, val);

    // create snapshot here
    leveldb::ReadOptions s_options;
    s_options.snapshot = db->GetSnapshot();

    // do write
    const std::string val2 = "xtra_test_vvvvv";
    leveldb::WriteOptions w_options;
    w_options.sync = true;
    db->Put(w_options, key, val2);

    // r_read, get new value
    std::string r_val;
    status = db->Get(leveldb::ReadOptions(), key, &r_val);
    ASSERT_THAT(status.ok() && r_val == val2, Eq(true));

    leveldb::Iterator* iter = db->NewIterator(s_options);
    for (iter->SeekToFirst(); iter->Valid(); iter->Next()) {
        if(iter->key().ToString() == key) {
            ASSERT_THAT(iter->value().ToString(), Eq(val));
            std::cout << "snapshot read:" << iter->key().ToString() << ": "  << iter->value().ToString() << std::endl;
        }
    }

    db->ReleaseSnapshot(s_options.snapshot);


	delete db;

    // clean up
    status = leveldb::DestroyDB(levelDBPath, leveldb::Options()); 
	ASSERT_THAT(status.ok(), Eq(true));
}
