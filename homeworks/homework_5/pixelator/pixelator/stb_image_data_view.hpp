#ifndef PIXELATOR_STB_IMAGE_DATA_VIEW_HPP
#define PIXELATOR_STB_IMAGE_DATA_VIEW_HPP

#define STB_IMAGE_IMPLEMENTATION
#include <filesystem>
#include <iostream>

#include "ftxui/screen/color.hpp"
#include "ftxui/screen/screen.hpp"
#include "stb/stb_image.h"

namespace pixelator {
struct Size {
  int *row;
  int *col;
};
class StbImageDataView {
 public:
  StbImageDataView() = default;
  explicit StbImageDataView(std::filesystem::path image_path);

  pixelator::Size size();
  int rows();
  int cols();
  bool empty();
  ftxui::Color at(int row, int col);
  ~StbImageDataView();

 private:
  unsigned char *image_{nullptr};
  pixelator::Size size_of_image_{};
  int *channels_{};
};
}  // namespace pixelator

#endif /* PIXELATOR_STB_IMAGE_DATA_VIEW_HPP */