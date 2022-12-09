#include "errorHandling.h"

#include <iostream>

void
LogError(const char* lineText, const char* fileName, const int lineNr)
{
  std::cout << fileName << ':' << lineNr << ':' << 0 << ": [Allegro Error] in " << lineText
            << std::endl;
  ASSERT(false);
}
