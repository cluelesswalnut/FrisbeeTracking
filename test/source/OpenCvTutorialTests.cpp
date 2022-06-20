#include <doctest/doctest.h>
#include <frisbeetracker/OpenCvTutorial.hpp>
#include <frisbeetracker/version.h>

#include <string>

TEST_CASE("Show Image") {
  std::string pic = "1200.jpeg";
  OpenCvTutorial::showImage(pic);
}