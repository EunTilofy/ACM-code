#ifndef __DEFS_H
#define __DEFS_H

#include <iostream>

void ___dbg()
{
  std::cerr << std::endl;
}

template<typename T, typename... Args>
void ___dbg(T first, Args... args) {
  std::cerr << first << " ";
  ___dbg(args...);
}

void ___dbg2()
{
  std::cout << std::endl;
}

template<typename T, typename... Args>
void ___dbg2(T first, Args... args) {
  std::cout << first << " ";
  ___dbg2(args...);
}

#define dbg(...) { std::cerr << "DEBUG at Line " << __LINE__ << " : "; ___dbg(__VA_ARGS__); }
#define dbgx(...) { std::cout << "DEBUG at Line " << __LINE__ << " : "; ___dbg2(__VA_ARGS__); }

#define dbg1(x) std::cerr << #x << "=" << x << " "
#define dbg2(x) std::cerr << #x << "=" << x << "\n"
#define dbg3(x) std::cerr << #x << "\n"
#define DEBUG(msg) std::cerr << "DEBUG at Line " << __LINE__ << " : " << msg << "\n";


#endif
