#include "base/log.h"
#include "base/time.h"

DEF_bool(perf, false, "performance testing");

int main(int argc, char** argv) {
    flag::init(argc, argv);

    if (FLG_perf) {
        // test performance by writting 100W logs
        COUT << "print 100W logs, every log is about 50 bytes";

        Timer t;
        for (int k = 0; k < 1000000; k++) {
            LOG << "hello world " << 3;
        }
        int64 write_to_cache = t.us();

        log::close();
        int64 write_to_file = t.us();

        COUT << "All logs written to cache in " << write_to_cache << " us";
        COUT << "All logs written to file in " << write_to_file << " us";

    } else {
        // usage of other logs. 
        DLOG << "This is DLOG (debug).. " << 23;
        LOG  << "This is LOG  (info).. " << 23;
        WLOG << "This is WLOG (warning).. " << 23;
        ELOG << "This is ELOG (error).. " << 23;
        //FLOG << "This is FLOG (fatal).. " << 23;
    }

    return 0;
}
