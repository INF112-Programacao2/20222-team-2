#pragma once

#define ASSERT(x)                                                                                  \
  if (!(x))                                                                                        \
  __asm__ volatile("int $0x03")

#define EC_CALL(x)                                                                                 \
  if ((!(x)))                                                                                      \
  {                                                                                                \
    LogError(#x, __FILE__, __LINE__);                                                              \
    exit(1);                                                                                       \
  }

void
LogError(const char* lineText, const char* fileName, const int lineNr);
