// -------------------- Google Test Main - gtestmain.cpp -------------------- //
// :WARNING: DO NOT MODIFY THIS FILE AT ALL. :WARNING:
// This file runs Google Test with any of the unit tests you wrote in the
// test.cpp file.
// -------------------------------------------------------------------------- //

#include <gtest/gtest.h>

// The sanitizer runtime is linked only by a build that turns the sanitizers on. These
// declarations are weak so that a build without them still links -- `cmake --preset
// default-valgrind`, which leaves the sanitizers off because valgrind and they cannot both
// instrument the same program. With no runtime the symbol is null and the hook is never used.
extern "C" {

void __ubsan_get_current_report_data(const char** issue_kind, const char** message,
                                     const char** filename, unsigned* line, unsigned* col,
                                     char** memory_addr) __attribute__((weak));

void __ubsan_on_report() {
  if (!__ubsan_get_current_report_data) return;

  const char* issue_kind;
  const char* error_message;
  const char* filename;
  unsigned line;
  unsigned col;
  char* memory_addr;

  __ubsan_get_current_report_data(&issue_kind, &error_message, &filename, &line, &col,
                                  &memory_addr);
  FAIL() << "Undefined behavior detected in \"" << filename << ":" << line << ":" << col << '\n'
         << error_message << '\n';
}

void asan_report_callback(const char* report) {
  FAIL() << "Memory error detected:\n" << report << '\n';
}

void __asan_set_error_report_callback(void (*callback)(const char*)) __attribute__((weak));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  if (__asan_set_error_report_callback) __asan_set_error_report_callback(asan_report_callback);
  return RUN_ALL_TESTS();
}
