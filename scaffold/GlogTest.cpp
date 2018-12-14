#include <gmock/gmock.h>
#include <string>

#include <glog/logging.h>
#include<pthread.h>

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

    // Setup before Init, must exists before
    FLAGS_log_dir = "./log";
    google::InitGoogleLogging("glogtest");


    LOG(INFO) << "normal info log here!";
    DLOG(INFO) << "debug mode info log here!";

}


pthread_t ntid;

void printids(const char *s){
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	LOG(INFO) << s << ": pid " << pid << ", tid " << tid;
}

void *thr_fn(void *arg){
	printids("new thread:");
}

TEST(GLog, PthreadTest) {

	int err = pthread_create(&ntid,NULL,thr_fn,NULL);
	ASSERT_THAT(err, Eq(0));
	printids("main thread:");
	pthread_join(ntid, NULL);
}
