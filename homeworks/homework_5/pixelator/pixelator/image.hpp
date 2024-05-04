#ifndef PIXELATOR_IMAGE_HPP
#define PIXELATOR_IMAGE_HPP

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
  Image(/* args */) = default;

  Image(const int row, const int col);
  Image(const Image& ref_obj);
  Image(pixelator::Size size);
  Image(Image&& other_image);
  int rows() const;
  int cols() const;
  bool empty() const;
  pixelator::Size size() const;
  ftxui::Color& at(int row, int col);
  const ftxui::Color& at(int row, int col) const;
  ~Image();
};

}  // namespace pixelator

#endif /* PIXELATOR_IMAGE_HPP */