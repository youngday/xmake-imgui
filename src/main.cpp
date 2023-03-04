#include "main.h"

using namespace std;

extern int folderTest();
extern int tcp_client();
extern int tcp_client_coro();
// extern int sqlite_orm_app();
extern int xtensor_test();
extern int cppzmq_app();

int main(int argc, char *argv[])
{
  auto time_str = mylocal_time();
  filesystem::path folder_path = "./log/";
  filesystem::create_directory(folder_path) ? LOG_S(INFO) << "mkdir sucess." << folder_path << endl : LOG_S(INFO) << "dir exist." << folder_path << endl;

  string logfilename = "log/everything-" + time_str + ".log";
  loguru::init(argc, argv);
  loguru::add_file(logfilename.c_str(), loguru::Append,
                   loguru::Verbosity_MAX); // Verbosity_INFO  Verbosity_MAX
  // Only log INFO, WARNING, ERROR and FATAL to "latest_readable.log":
  logfilename = "log/latest_readable-" + time_str + ".log";
  loguru::add_file(logfilename.c_str(), loguru::Truncate,
                   loguru::Verbosity_INFO);
  LOG_S(INFO) << fmt::format("Starting at {}!\n", time_str);

  // xtensor_test();

  //  tcp_client_coro();
  //  for(;;){
  //   co::sleep(10000);
  //  }
    // sqlite_orm_app();

//   cppzmq_app();
   for(;;){
    co::sleep(10000);
   }
  // return app.exec();
}
