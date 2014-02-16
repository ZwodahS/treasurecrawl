#ifndef _GAME_HELPER_H_
#define _GAME_HELPER_H_
#include "../z_framework/zf_common/Grid.hpp"
#include <vector>
std::vector<zf::Grid> getLine(const zf::Grid& start, const zf::Grid& end);
std::vector<zf::Grid> getSquareVisionBoundary(int range, const zf::Grid& source, const zf::Grid& maxSize);
#endif
