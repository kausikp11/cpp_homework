#ifndef PIXELATOR_STB_IMAGE_DATA_VIEW_HPP
#define PIXELATOR_STB_IMAGE_DATA_VIEW_HPP

#include <filesystem>
#include <iostream>

#include "ftxui/screen/color.hpp"

namespace pixelator {
struct Size {
  int rows;
  int cols;
};
class StbImageDataView {
 public:
  StbImageDataView();
  explicit StbImageDataView(std::filesystem::path image_path);
  StbImageDataView(StbImageDataView&& other_image);
  StbImageDataView& operator=(StbImageDataView&& other);

  pixelator::Size size() const;
  int rows() const;
  int cols() const;
  bool empty() const;
  const ftxui::Color at(int row, int col) const;
  ~StbImageDataView();

 private:
  unsigned char * image_{nullptr};
  int rows_;
  int cols_;
  pixelator::Size size_of_image_{};
  int channels_;
};
}  // namespace pixelator

#endif /* PIXELATOR_STB_IMAGE_DATA_VIEW_HPP */