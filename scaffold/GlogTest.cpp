#include <gmock/gmock.h>
#include <string>
#include <memory>

#include <glog_syslog/logging.h>
#include<pthread.h>

#include <syslog.h>

using namespace ::testing;

// refer: http://rpg.ifi.uzh.ch/docs/glog.html

// LEVEL => INFO, WARNING, ERROR, and FATAL(terminate when NDEBUG not defined), 0,1,2,3
//

// FLAGS_logtostderr = false
// FLAGS_stderrthreshold = 2
// FLAGS_minloglevel = 0
// FLAGS_log_dir
// FLAGS_

TEST(GLog, DemoTest) {

    // init syslog firstly
    ::openlog(program_invocation_short_name, LOG_PID , LOG_LOCAL6);
    setlogmask (LOG_UPTO ( 7 ));

    // Setup before Init, must exists before
    FLAGS_log_dir = "./log";
    google::InitGoogleLogging("glogtest");


    LOG(INFO) << "normal info log here!";
    DLOG(INFO) << "debug mode info log here!";

}


pthread_t ntid;

void printids(const char *s){

	pid_t pid = getpid();
	pthread_t tid = pthread_self();

	LOG(INFO) << s << ": pid " << pid << ", tid " << tid;
}

void* thr_fn(void *arg){
	printids("new thread:");
    return NULL;
}

TEST(GLog, PthreadTest) {

	int err = pthread_create(&ntid,NULL,thr_fn,NULL);
	ASSERT_THAT(err, Eq(0));
	printids("main thread:");
	pthread_join(ntid, NULL);
}


TEST(GLog, ConditionLogTest) {
    int num = 23;
    std::string str = "nicol";

    LOG_IF(INFO, num > 10) << "good, expected num > 10";

    for (int i = 0; i < 20; ++i) {
        LOG_EVERY_N(INFO, 5) << "Got the " << google::COUNTER << "th message";
    }
}

// CHECK_EQ, CHECK_NE, CHECK_LE, CHECK_LT, CHECK_GE, and CHECK_GT
// CHECK_NOTNULL
// CHECK_STREQ, CHECK_STRNE, CHECK_STRCASEEQ, and CHECK_STRCASENE
//
// Will always be evalued, not controlled by NDEBUG.
// for CHECK_xxx, no output is good !!!
TEST(GLog, CheckTest) {

    long num = 2;
    CHECK_EQ(2, num) << "bad, num eq 2" ;
    CHECK_NE(23,num) << "bad, num ne 23" ;

    std::string str = "nicol";
    CHECK_EQ("nicol", str) << "bad, str is \"nicol\"";

    std::shared_ptr<int> ptr = std::make_shared<int>(200);
    // glog googletest.h polluted this ...
    //CHECK_NOTNULL(ptr);

    const char* name = "nicol";
    CHECK_STRCASEEQ("NIcol", name) << "bad, incase equel for nicol";
}

// PLOG() and PLOG_IF() and PCHECK() behave same with better errorno explain 
TEST(GLog, PerrorTest) {

    PLOG_IF(ERROR, ::write(1, NULL, 2) < 0 ) << "Write null source failed";
}


// SYSLOG, SYSLOG_IF, and SYSLOG_EVERY_N macros are available
// impact performance
// need to modified source, for facility change
TEST(GLog, SyslogTest) {
    
    FLAGS_syslog_facility = LOG_LOCAL6;
    
    SYSLOG(INFO) << "good, this is message to syslog, but from glog ";
}


TEST(GLog, SyslogWithLogTest) {
    
    FLAGS_syslog_facility = LOG_LOCAL6;
    
    LOG(INFO) << "good, this is usually info, but also to rsyslog from glog";
    LOG(WARNING) << "warning info here";
    LOG(ERROR)  << "haha, error info here!";
}