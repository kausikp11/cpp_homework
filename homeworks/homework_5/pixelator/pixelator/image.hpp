#ifndef PIXELATOR_IMAGE_VIEW_HPP
#define PIXELATOR_IMAGE_VIEW_HPP

#include <ftxui/screen/color.hpp>
#include <pixelator/stb_image_data_view.hpp>
#include <vector>

namespace pixelator {

class Image {
 private:
  int cols_{0};
  int rows_{0};
  pixelator::Size size_;
  std::vector<ftxui::Color> pixels_;

 public:
  Image() = default;
  explicit Image(const int row, const int col);
  int rows();
  int cols();
  bool empty();
  pixelator::Size size();
  ftxui::Color at(int row, int col);
  ~Image();
};

}  // namespace pixelator

#endif /* PIXELATOR_IMAGE_VIEW_HPP */